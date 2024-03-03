---
layout: post
title: php cookie session 쿠키 세션
category: web
tags: php
---

# php cookie session 쿠키 세션

# 쿠키(Cookie)
* 쿠키는 개별 사용자의 컴퓨터(local)에 변수를 저장
* 개별 사용자에게 다른 서비스를 제공하기 위함
  
## 쿠키의 생성

```php
<?php
setcookie("counter", "1", 30*24*60*60+time(), "/");
//쿠키의 이름은 counter, 쿠키의 값은 1, 쿠키는 현재시간부터 30일동안 보관됨, 
//루트(/) 이하 모든 디렉토리에서 읽기 가능
?>
```		
## 쿠키의 이용
```php
<?php
//echo $_COOKIE["counter"];
if(!is_null($_COOKIE)){
	//NOT 빈값 이다 (쿠키가)
	if(!is_null($_COOKIE["counter"])){
		//NOT 빈값 이다 (쿠키 counet)
		echo "counter 쿠키값은".$_COOKIE["counter"]."입니다.";
		//$_COOKIE["counter"] ++;
		setcookie("counter", $_COOKIE["counter"]+1, 30*24*60*60+time(), "/");
	}else{
		echo "counter 쿠키가 없습니다.";
	}
}else{
	echo "쿠키가 없습니다.";
}	
?>
```

## 쿠키의 폐기
```php
<?php
setcookie("counter", "", time(), "/");
?>
```

---
		                				
# 세션(Session)
* 쿠키와 마찬가지로 개별 사용자를 구별하기 위한 용도로 사용
* 쿠키와 달리 페이지를 닫을때 세션이 자동으로 닫힘

```php
<?php
$cnt;
session_start(); //세션을 시작하는 함수
if($_SESSION){
	if(!is_null($_SESSION["cnt"])){
		$cnt = $_SESSION["cnt"] + 1; 
		//세션변수 "cnt"이 있다면 본래의 숫자에 1을 더함
		$_SESSION["cnt"] = $cnt;
		//세션에 변수 "cnt"를 저장함
	}else{
		$_SESSION["cnt"] = 0;
	}
}else{
	$_SESSION["cnt"] = 0;
}

echo "귀하는 이 페이지를 ".$_SESSION["cnt"]."번째 새로고침 하였습니다."
?>
```

## 세션의 폐기
```php
<?php 
unset($_SESSION['id']); //특정 변수의 폐기
session_destroy(); //세션변수 전체의 폐기
?>
```

## 세션의 특이 사항
```php
<?php
session_start(); // 세션변수 사용하기 시작
session_register('passtype'); // 세션변수 등록
$_SESSION['passtype']; //세션변수 접근
$_SESSION['passtype']=10; //세션변수 입력
echo $_SESSION['passtype']; //세션변수 출력
?>
```

```php
    if(!isset($_SESSION)) 
    { 
        session_start(); // 세션변수 사용하기 시작
    }
	// 세션시작 중복 방지
```

* 세션변수란 동일 브라우저내에서 계속 이어쓰는 변수이다.
* 세션변수 사용선언 > 세션변수등록 > 세션변수접근,사용 으로 이어진다.

* 세션변수는 http://로 시작하는 링크의 경우 같은 도메인이더라도 세션이 초기화된다.(상대주소나 /로 시작하는 절대주소를 사용하는것을 권장)
* 같은 도메인의 타 브라우져 사이에서는 세션이 유효하지 않다 (쿠키로 해결하는 것으로 생각됨)