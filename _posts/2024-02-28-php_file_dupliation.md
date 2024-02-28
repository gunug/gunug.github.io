---
layout: post
title: php 파일 중복 방지
category: web
tags: php
---

# php 파일 중복 방지

## 폼태그 구성 
* file_form.html
  
```php
<!DOCTYPE html>
<html>
	<head>
	    <meta charset="utf-8"/>
	</head>   
	<body>
		<form enctype="multipart/form-data" action="file_result.php" method="POST">
		   <input type="hidden" name="MAX_FILE_SIZE" value="3000000" />
		   <input name="userfile" type="file" />
		   <input type="submit" value="upload" />
		</form>
	</body>
</html>
```

## 전송용 PHP 
* file_result.php

```php
<?php
 // uploads디렉토리에 파일을 업로드합니다. 
 $uploaddir = './files/'; 
 $uploadfile = $uploaddir . basename($_FILES['userfile']['name']); 

 echo '<pre>'; 
 if($_POST['MAX_FILE_SIZE'] < $_FILES['userfile']['size']){ 
      echo "업로드 파일이 지정된 파일크기보다 큽니다.\n"; 
 } else { 
     if(($_FILES['userfile']['error'] > 0) || ($_FILES['userfile']['size'] <= 0)){ 
          	echo "파일 업로드에 실패하였습니다.  <br />"; 
          	// 실패 내용을 출력
			switch ($_FILES['userfile']['error']) {
			case 1:
				echo 'php.ini 파일의 upload_max_filesize 설정값을 초과함(업로드 최대용량 초과)';
				break;
			case 2:
				echo 'Form에서 설정된 MAX_FILE_SIZE 설정값을 초과함(업로드 최대용량 초과)';
				break;
			case 3:
				echo '파일 일부만 업로드 됨';
				break;
			case 4:
				echo '업로드된 파일이 없음';
				break;
			case 6:
				echo '사용가능한 임시폴더가 없음';
				break;
			case 7:
				echo '디스크에 저장할수 없음';
				break;
			case 8:
				echo '파일 업로드가 중지됨';
				break;
			default:
				echo '시스템 오류가 발생';
				break;
		} // switch
		echo "<br />";
     } else { 
          // HTTP post로 전송된 것인지 체크합니다. 
          if(!is_uploaded_file($_FILES['userfile']['tmp_name'])) { 
                echo "HTTP로 전송된 파일이 아닙니다."; 
          } else { 
                // move_uploaded_file은 임시 저장되어 있는 파일을 ./uploads 디렉토리로 이동합니다. 
                if (move_uploaded_file($_FILES['userfile']['tmp_name'], $uploadfile)) { 
                     echo "성공적으로 업로드 되었습니다.\n"; 
                } else { 
                     echo "파일 업로드 실패입니다.\n"; 
                } 
          } 
     } 
 } 
 print_r($_FILES);
?>
```

---

## 임의의 문자 생성기 
* random.php

```php
<?php
function RandomString()
{
    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
    $randstring = '';
    for ($i = 0; $i < 15; $i++) {
        $randstring = $randstring.$characters[rand(0, strlen($characters)-1)];
    }
    return $randstring;
}
$result_string = RandomString();
echo $result_string;
?>
```

## 파일의 존재여부 확인 
* exist.php

```php<?php
	echo("*echo:");
	echo(file_exists("./files/test.txt"));
	echo("<br />");
	//echo : string형 변수만 표시 합니다.

	echo("*var_dump:");
	var_dump(file_exists("./files/test.txt"));
	echo("<br />");
	//var_dump : 괄호안의 값의 type과 value를 동시에 표시합니다.
?>
```

## 겹치지 않는 파일명 생성기 
* random_file_name.php

```php
<?php
	function RandomString()
	{
	    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
	    $randstring = '';
	    for ($i = 0; $i < 15; $i++) {
	        $randstring = $randstring.$characters[rand(0, strlen($characters)-1)];
	    }
	    return $randstring;
	}

	function random_file_name($original_file_name){
		$result_name; //결과 문자 - 리턴용
		$directory = "./files/";
		$File_ext = substr(strrchr($original_file_name, "."), 1); // 확장자 추출

		var_dump(strrchr("파일명.확장자", "."));
		//strrchr("파일명.확장자", ".");
		//.(마침표) 있는 부분부터 리턴
		echo "<br />";

		var_dump(substr("text", 1));
		//substr("text", 1)
		//1번주소 부터 리턴
		echo "<br />";

		$randstring = RandomString(); //임의의 문자 생성
		while(file_exists($directory.$randstring.".".$File_ext)){
			//만약 파일명이 존재 한다면
			$randstring = RandomString(); //임의의 문자 생성
		}//만약 파일명이 존재하지 않는다면
		$result_name = $directory.$randstring.".".$File_ext;
		return $result_name; //파일명을 리턴
	}
	$original_file_name = "./test/sub_folder/test.txt";
	echo random_file_name($original_file_name);
?>
```

---

## 최종결과 
* random_uploader.php

```php
<?php
 // uploads디렉토리에 파일을 업로드합니다. 
 $uploaddir = './files/'; 
 $uploadfile = $uploaddir . basename($_FILES['userfile']['name']); 

 echo '<pre>'; 
 if($_POST['MAX_FILE_SIZE'] < $_FILES['userfile']['size']){ 
      echo "업로드 파일이 지정된 파일크기보다 큽니다.\n"; 
 } else { 
     if(($_FILES['userfile']['error'] > 0) || ($_FILES['userfile']['size'] <= 0)){ 
          	echo "파일 업로드에 실패하였습니다.  <br />"; 
          	// 실패 내용을 출력
			switch ($_FILES['userfile']['error']) {
			case 1:
				echo 'php.ini 파일의 upload_max_filesize 설정값을 초과함(업로드 최대용량 초과)';
				break;
			case 2:
				echo 'Form에서 설정된 MAX_FILE_SIZE 설정값을 초과함(업로드 최대용량 초과)';
				break;
			case 3:
				echo '파일 일부만 업로드 됨';
				break;
			case 4:
				echo '업로드된 파일이 없음';
				break;
			case 6:
				echo '사용가능한 임시폴더가 없음';
				break;
			case 7:
				echo '디스크에 저장할수 없음';
				break;
			case 8:
				echo '파일 업로드가 중지됨';
				break;
			default:
				echo '시스템 오류가 발생';
				break;
		} // switch
		echo "<br />";
     } else { 
          // HTTP post로 전송된 것인지 체크합니다. 
          if(!is_uploaded_file($_FILES['userfile']['tmp_name'])) { 
                echo "HTTP로 전송된 파일이 아닙니다."; 
          } else { 
                // move_uploaded_file은 임시 저장되어 있는 파일을 ./uploads 디렉토리로 이동합니다. 
                //if (move_uploaded_file($_FILES['userfile']['tmp_name'], $uploadfile)) { 
          		if (move_uploaded_file($_FILES['userfile']['tmp_name'], random_file_name($uploadfile))) { 
                	//random_file_name($original_file_name)
                     echo "성공적으로 업로드 되었습니다.\n"; 
                } else { 
                     echo "파일 업로드 실패입니다.\n"; 
                } 
          } 
     } 
 } 
 print_r($_FILES);

 	function RandomString()
	{
	    $characters = '0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ';
	    $randstring = '';
	    for ($i = 0; $i < 15; $i++) {
	        $randstring = $randstring.$characters[rand(0, strlen($characters)-1)];
	    }
	    return $randstring;
	}

	function random_file_name($original_file_name){
		$result_name; //결과 문자 - 리턴용
		$directory = "./files/";
		$File_ext = substr(strrchr($original_file_name, "."), 1); // 확장자 추출

		var_dump(strrchr("파일명.확장자", "."));
		//strrchr("파일명.확장자", ".");
		//.(마침표) 있는 부분부터 리턴
		echo "<br />";

		var_dump(substr("text", 1));
		//substr("text", 1)
		//1번주소 부터 리턴
		echo "<br />";

		$randstring = RandomString(); //임의의 문자 생성
		while(file_exists($directory.$randstring.".".$File_ext)){
			//만약 파일명이 존재 한다면
			$randstring = RandomString(); //임의의 문자 생성
		}//만약 파일명이 존재하지 않는다면
		$result_name = $directory.$randstring.".".$File_ext;
		return $result_name; //파일명을 리턴
	}
	//$original_file_name = "./test/sub_folder/test.txt";
	//echo random_file_name($original_file_name);

	$prevPage = $_SERVER['HTTP_REFERER'];
	// 변수에 이전페이지 정보를 저장

	header('location:'.$prevPage);
	// 페이지 이동	
?>
```
