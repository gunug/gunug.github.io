---
layout: post
title: php 일반변수 객체형변수 함수
category: web
tags: php basic
---

# php 일반변수 객체형변수 함수

```php
<?php
	$a = 10;
	echo $a;
	$a = 5;
	echo $a;
?>
<br />
<script type="text/javascript">
	var a = 10;
	document.write(a);
	a = 5;
	document.write(a);
	var e = 0;
	e = a; //값만 전달됨 (객체가 아닌 값을 갖은 변수라서)
	e = 8;
	document.write(e); //8
	document.write(a); //5

	var b = new Object();
	b.c = 10;
	b.d = 7;
	document.write(b.c);
	document.write(b.d);
	var f = new Object();
	f = b; //참조(주소)가 전달됨 (값이 아닌 객체를 갖은 변수라서)
	f.c = 8; // b.c = 8;
	f.d = 6; // b.d = 8;
	// f == b;
	document.write(f.c); //8
	document.write(f.d); //6
	document.write(b.c); //8
	document.write(b.d); //6
</script>

<script type="text/javascript">
	function g(j){
		//함수의 선언부
		document.write("hi"+j);
	}
	var h = 10;
	var i = new Object();
	i.a = 9;
	g(8); //함수의 호출부
	g(h); //함수의 호출부
	g(i.a); //함수의 호출부

	var a.height = 180;
	var b.height = 170;

	//class : 함수와 변수의 집합체
</script>
```
