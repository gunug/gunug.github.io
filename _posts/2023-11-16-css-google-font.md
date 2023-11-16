---
layout: post
title: css google font 구글폰트
category: web
tags: 
---

# css google font 구글폰트

# 나눔고딕
```html
<!DOCTYPE html>
<html>

	<head>
		<meta charset="utf-8">
		<style type="text/css">
			@import url(http://fonts.googleapis.com/earlyaccess/nanumpenscript.css);
			body{
				font-family: 'Nanum Pen Script', cursive;
			}
		</style>
	</head>
	<body>
		폰트를 테스트 합니다.
	</body>
</html>
```

# 폰트 종류 다르게
* 폰트 링크 확인 : http://fonts.google.com
* 2018.10 유건욱 학생이 찾아준 내용

## 폰트에 띄어쓰기가 없을 때 ex)Roboto
```html
<link href='https://fonts.googleapis.com/css?family=Roboto' rel="stylesheet" type="text/css">
<style>
    div{font-family:"Roboto", cursive;}
</style>
<div>폰트가 적용될 텍스트 font text</div>
폰트가 적용 안된 텍스트 font text
```

## 폰트에 띄어쓰기가 있을 때 ex)Chakra Petch
```html
<link href='https://fonts.googleapis.com/css?family=Chakra+Petch' rel="stylesheet" type="text/css">
<style>
    div{font-family:"Chakra Petch", cursive;}
</style>
<div>폰트가 적용될 텍스트 font text</div>
폰트가 적용 안된 텍스트 font text
```

## 한영폰트 복합으로 사용하기
```html
<!DOCTYPE html>
<!-- Noto Sans KR -->
<!-- https://fonts.googleapis.com/css?family= -->
<link href='https://fonts.googleapis.com/css?family=Nanum+Gothic' rel="stylesheet" type="text/css">
<link href='https://fonts.googleapis.com/css?family=Niramit' rel="stylesheet" type="text/css">
<!-- 폰트 로드 -->

<style type="text/css">
	div{
		font-family:"Niramit", "Nanum Gothic", cursive;
		font-size: 300px;
	} /*폰트 적용*/
</style>
<div>폰트가 적용될 텍스트 font text</div>
폰트가 적용 안된 텍스트 font text
```
