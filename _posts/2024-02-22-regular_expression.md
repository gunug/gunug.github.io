---
layout: post
title: regular expression 정규표현식
category: etc
tags: php javascript
---


# 정규표현식
* 특정한 규칙을 가진 문자열의 집합을 표현하는데 사용하는 형식 언어입니다.
* 정규표현식 시각화 사이트 : https://regexper.com/

---

## 정규 표현식(Regular Expression) php 
* validation.php

```php
<form action="validation.php" mathod="GET">
	<input type="text" name="input_value" value=""/>
	<input type="submit" value="test"/>
</form>
									
<?php

	//int preg_match ( string $pattern , string $subject [, array &$matches [, int $flags [, int $offset ]]] )
	$subject = $_GET['input_value'];
	// 패턴 구분자 뒤의 "i"는 대소문자를 구별하지 않게 합니다.
	echo $subject."<br />";
	$pattern = '/(\w+\.)*\w+@(\w+\.)+[A-Za-z]+/i';
	if (preg_match($pattern, $subject)) {
	    echo "유효 합니다.";
	} else {
	    echo "유효하지 않습니다.";
	}

	/*
	- IP : (((\d{1,2})|(1\d{2})|(2[0-4]\d)|(25[0-5]))\.){3}((\d{1,2})|(1\d{2})|(2[0-4]\d)|(25[0-5]))
	- URL : https?://(\w*:\w*@)?[-\w.]+(:\d+)?(/([\w/_.]*(\?\S+)?)?)?
	- Email : (\w+\.)*\w+@(\w+\.)+[A-Za-z]+
	- HTML 주석 : <!-{2,}.*?-{2,}>
	- 주민등록번호 : \d{2}(0[1-9]|1[0-2])(0[1-9]|[12][0-9]|3[01])-[1-4]\d{6}
	- 한글 : [가-힣]
	- 유니코드 : \ucodenumber
	*/
?>
```
---

## 정규 표현식(Regular Expression) javascript 
* validation_javascript.html

```javascript
<meta charset="utf-8" />
<input type="text" name="input_" id="input_" value="" onChange="changeFunc()">
<div id="result_div"></div>
<script type="text/javascript">
 var re = new RegExp(/(\w+\.)*\w+@(\w+\.)+[A-Za-z]+/);
 function changeFunc(){
  var data = document.getElementById('input_').value
  var result = data.match(re);
  if(result){
   document.getElementById('result_div').innerHTML = "유효합니다";
  }else{
   document.getElementById('result_div').innerHTML = "유효하지 않습니다.";
  }
 }
</script>
```
