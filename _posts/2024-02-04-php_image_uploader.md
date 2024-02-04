---
layout: post
title: php image uploader 이미지 업로더
category: web
tags: php simple-code
---

# php image uploader 이미지 업로더

## 폼태그 구성 
* image_index.php

```html
<form action="image_uploader.php" method="post" enctype="multipart/form-data">
	<!--action: 전송타겟/method: 전송방식/enctype: 엔코딩 타입 (multipart/form-data 멀티파일 전송방식)-->
	<input type="file" name="file1" id="file1"/><br />
	<input type="submit" value="업로드"/>
</form>
```

---

## 전송용 PHP 
* image_uploader.php
  
```php
<?php
$GLOBALS['img_width'] = 1920; //3840
$GLOBALS['img_height'] = 1080; //2160
$GLOBALS['thumb_width'] = $GLOBALS['img_width']/10;
$GLOBALS['thumb_height'] = $GLOBALS['img_height']/10;
function file_upload($id){
	if(isset($_FILES[$id])){
		if($_FILES[$id]["error"] > 0) {
			//에러가 있는지 검사하는 구문
			echo "Error:".$_FILES[$id]["error"]."<br />";
		}else{
			echo "upload:".$_FILES[$id]["name"]."<br />";
			echo "type:".$_FILES[$id]["type"]."<br />";
			echo "size:".$_FILES[$id]["size"]."<br />";
			echo "stored in:".$_FILES[$id]["tmp_name"]."<br />";
			//에러가 없다면 파일 정보 출력
			if(file_exists("./file_folder/".$id.".jpg")){//동일한 파일이 있음
				unlink("./file_folder/".$id.".jpg");
				
			}
			if(file_exists("./file_folder/".$id."_thumb.jpg")){//동일한 파일이 있음
				unlink("./file_folder/".$id."_thumb.jpg");
			}
			//move_uploaded_file($_FILES[$id]["tmp_name"], "./file_folder/".$_FILES[$id]["name"]);
			//4k (3840*2160);
			cropImage($GLOBALS['img_width'],$GLOBALS['img_height'],$_FILES[$id]["tmp_name"],$_FILES[$id]["type"],"./file_folder/".$id);
		}
	}
}
for($i=1; $i<=5; $i++){
	file_upload("file".$i);
}

function cropImage($nw, $nh, $source, $stype, $dest) {
    $size = getimagesize($source);
    $w = $size[0];
    $h = $size[1];
    echo $w.":".$h;
    switch($stype) {
		case "image/gif":
			$simg = imagecreatefromgif($source);
			$background = imagecolorallocate($simg, 255, 255, 255);
	        imagecolortransparent($simg, $background);
		break;
		case "image/jpeg":
			$simg = imagecreatefromjpeg($source);
		break;
		case "image/png":
			$simg = imagecreatefrompng($source);
			$background = imagecolorallocate($simg, 255, 255, 255);
	        imagecolortransparent($simg, $background);
	        imagealphablending($simg, false);
	        imagesavealpha($simg, true);
    	break;
    	default:
    		echo "지원하지 않는 확장자 입니다. (jpg, gif, png만 가능)"."<br />";
    		echo "파일 업로드를 종료합니다"."<br />";
    		return;
    	break;
    }
	$dimg = imagecreatetruecolor($nw, $nh);
	$wm = $w/$nw;
	$hm = $h/$nh;
	$h_height = $nh/2;
	$w_height = $nw/2;

	$type = 0;
	if($wm < $hm) {
		$adjusted_width = $w / $hm;
		$half_width = $adjusted_width / 2;
		$int_width = $half_width - $w_height;
		imagecopyresampled($dimg,$simg,-$int_width,0,0,0,$adjusted_width,$nh,$w,$h);
	} else if($wm > $hm) {
		$adjusted_height = $h / $wm;
		$half_height = $adjusted_height / 2;
		$int_height = $half_height - $h_height;
		imagecopyresampled($dimg,$simg,0,-$int_height,0,0,$nw,$adjusted_height,$w,$h);
	} else {
		imagecopyresampled($dimg,$simg,0,0,0,0,$nw,$nh,$w,$h);
	}
    imagejpeg($dimg,$dest.".jpg",100);
    $thumb = imagecreatetruecolor($GLOBALS['thumb_width'], $GLOBALS['thumb_height']);
    imagecopyresized($thumb, $dimg, 0, 0, 0, 0, $GLOBALS['thumb_width'], $GLOBALS['thumb_height'], $nw, $nh );
    imagejpeg($thumb,$dest."_thumb.jpg",100);
    echo "업로드가 완료되었습니다."."<br />";
}
$prevPage = $_SERVER['HTTP_REFERER'];
// 변수에 이전페이지 정보를 저장
header('location:'.$prevPage);
// 페이지 이동
?>
```

---

# 문제해결 
## Call to undefined function imagecreatefromjpeg()
* 원본출처: https://www.fun25.co.kr/blog/php-imagecreatefromjpeg-undefined-function/
* PHP 썸네일 생성등을 위해서 ImageCreateFromJPEG 함수 사용시
* PHP Fatal error:  Call to undefined function imagecreatefromjpeg()
* 에러가 날 경우는 gd 라이브러리가 설치가 안 된 경우입니다.

```terminal
# apt-get install php5-gd //옛날방식
# apt-get install php7.0-gd
```

* 우분투일 경우 위와 같이 php의 gd 라이브러리를 설치해 주면 됩니다.

## failed to open stream: No such file or directory
* 원본출처: http://iam777.tistory.com/301
* php.ini 에 extension=php_gd2.dll 구문이 막혀 있으면 안된다.
* 확장 dir  정의 확인 필요. extension_dir = "개인 pc dir 정보" 경로 설정이 주석으로 안되어 있고 정상 설정되어 있으면 된다.
* 이런 경우 phpinfo() 로 확인하면 내용중에 gd 에서 지원하는 내용이 보이게 된다.
* <b>위 내용은 도움 안됨</b>

* 서버라고 하는 컴퓨터 기준으로 root를 잡아야하는데, 서비스하는 웹서버 루트에서 부터 폴더명을 입력하여. 폴더 경로가 잘못되어 나오는 오류
