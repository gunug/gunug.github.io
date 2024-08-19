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

---

---
marp: true
theme: a4
class:
  - lead
  - invert
paginate: true
header: 정규표현식
footer: 2023-03-10
---

# 정규표현식 (Regexp, Regular expression)
* 특정 규칙을 가진 문자열의 집합을 표현하는데 사용하는 형식언어
* 정규표현식 테스트 사이트 : https://regex101.com/
* 정규식 체크 : https://velog.io/@rimo09/%EC%A0%95%EA%B7%9C%EC%8B%9D-%EC%B2%B4%ED%81%AC

---

* ```/A\d+/``` A로 시작하고 그 뒤에 하나 이상의 숫자가 순차적으로 나오는 문자열
* ```/ABC/``` ABC가 차례대로 나오는 문자열
* 일반표현식 리터럴은 슬래시(/) 문자로 나타냄
* ```/([0-9a-zA-Z])+[-._+&])*[0-9a-zA-Z]+@([-0-9a-zA-Z]+[.])+a-zA-Z]{2,6}``` 전자메일주소 확인

---

# 정규표현식의 사용
* String 클래스의 Match(), Replace(), Search(), split() 메서드는 정규표현식을 매개변수로 사용함
* RegExp 클래스에는 test(), exec() 메서드가 포함되어 있음

---

# 정규표현식 패턴 만들기
* 여러문자의 시퀀스 식별 (2자리 숫자, 7개 문자와 10개 문자사이)
* 문자, 숫자 범위내 식별 (a부터 m사이의 임의의 문자)
* 가능한 문자 세트에서 문자식별
* 하위 시쿼스 식별 (패턴 내 세그먼트)
* 패턴을 사용한 텍스트의 비교 및 바꾸기

---

* 이스케이프문자 : 다으멩 오는 문자가 리터럴 문자가 아닌 메타문자로 처리되어야 함을 나타내는 문자
* 정규표현식 구문에서 백슬래시 문자(\)는 이스케이프 문자로, 백슬래시 뒤에 오는 문자는 리터럴이 아닌 특수 코드로 처리됨
* 플래그 : 패턴 사용방법에 대한 옵션을 지정 (대소문자 구분 여부)
* 메타문자 : 패턴에서 특별한 의미를 갖는 문자, 문자를 글자 그대로 나타내는 리터럴과 대비되는 개념.
* 한정기호 : 패턴을 구성하는 한 부분의 반복 횟수를 나타내는 문자(또는 여러문자)
* 정규 표현식 : 문자 패턴을 정의하는 프로그램 명령, 해당 패턴의 일치하는 패턴을 찾거나 문자열의 일부를 바꿀때 사용

---

# 플래그 및 속성
* g: global 둘 이상의 일치항목을 찾음 (없으면 하나의 항목만 찾음)
* i: ignore case 대소문자를 구분하지 않음 A-Z, a-z등에는 적용되지만 확장문자에는 적용되지 않음
* m: multiline ^는 시작부분을 $는 끝부분을 찾는데. m플래그가 설정되어 있으면 전체 문자열에서가 아닌 각 행에서 찾음
* s: dot all 도트(.)는 개행문자(\n)와 일치시킬 수 있음 (본래는 토드문자가 개행문자를 문자로 취급하지 않음)
* x: extended 확장 정규 표현식을 사용할 수 있음. 패턴의 일부로 무시되는 공백을 패턴에 추가하여 가독성을 높일 수 있음, x플래그를 설정한 이후 공백문자를 리터럴로서 사용하려면 백슬래시(\)를 붙여서 써야함
* ```/abc/gimsx``` 처럼 정규표현식 뒤에 작성하여 플래스를 설정할 수 있음 (기본값은 false, 설정시 true)

---

# Character literals
```
* `/a/` : M`a`ry had `a` little l`a`mb. And everywhere th`a`t M`a`ry went, the l`a`mb w`a`s sure to go.
* `/Mary/` : `Mary` had a little lamb.And everywhere that `Mary` went, the lamb was sure to go.
```

# "Escaped" characters literals
```
* 역슬래시(`\`)는 기능이 있는 문자를 리터럴 그 자체로 사용할수 있게 해준다
* `/.*/` : `Special characters must be escaped.*`
* `/\.\*/` : Special characters must be escaped`.*`
```

---

# Positional special characters
```
* `/^Mary/`: `Mary` had a little lamb.And everywhere that Mary went, the lamb was sure to go.
* `/Mary$/`: Mary had a little lamb.And everywhere that `Mary` went, the lamb was sure to go.
```

# The "wildcard" character
```
* `/.a/`: `Ma`ry `ha`d `a` little `la`mb.And everywhere t`ha`t `Ma`ry went, the `la`mb `wa`s sure to go.
```

---

# Grouping regular expressions
```
* `/(Mary)( )(had)/` : `Mary had` a little lamb.And everywhere that Mary went, the lamb was sure to go.
```

# Chracter class
```
* `/[a-z]a/` : Mary `ha`d `a` little `la`mb.And everywhere t`ha`t Mary went, the `la`mb `wa`s sure to go.
* 대소문자 구별로 `Ma`가 검사에서 제외됨
```

---

# Complement operator
```
* `/[^a-z]a/` : `Ma`ry had `a` little lamb.And everywhere that `Ma`ry went, the lamb was sure to go.
* 소문자 알파벳으로 시작하는 a를 제외한 모든 a(대문자, 공백) 검사됨
* ^는 시작을 나타낸다고 알고 있었는데 부정으로도 쓰임?
```

# Alternation of patterns
```
* `/cat|dog|bird/` : The pet store sold `cat`s, `dog`s, and `bird`s
```

---

```
* =first first= # =second second= # =first= # =second=
* `/=first|second=/` : `=first` first= # =second `second=` # `=first`= # =`second=`
* `/(=)(first)|(second)(=)/` : =first first= # =second second= # =first= # =second=
* `/=(first|second)=/`: =first first= # =second second= # `=first=` # `=second=`
```

---

# The basic abstract quantifier
```
* `/@(=+=)*@/` : `@@`, @=+=ABC@ 매칭값이 다 존재 하지만 비매칭이 끼어 있어서 탈락, `@=+==+==+=@`, @=+=+=+=@ 패턴이 맞지 않아 탈락
```

# More abstract quantifiers

```
* `/A+B*C?D/`
* +1개이상, *0개이상, ?1개이하
* AAAD : true
* ABBBBCD : true
* BBBCD : false
* ABCCD : false
* AAABBBC : false
```

---

# Numeric quantifiers
```
* `/a{5} b{,6} c{4,8}/` a 5개, b 6개이하, c 4개이상 8개이하
```

# Back references
```
* `/(abc|xyz) \1/`
* jkl abc xyz
* jkl xyz abc
* jkl `abc abc`
* jkl `xyz xyz`
```

---

# Don't match more then you want to
```
* -- I want to match the words that start
* -- with 'th' and end width 's'.
* this, thus, thistle, this line matches too much
```

## ``` `/th.*s/` ```
```
* -- I want to match `the words that s`tart
* -- wi`th 'th' and end width 's'`'
* `this`, `thus`, `this`tle, `this line matches` too much
```

---

# Tricks for restraining matches
```
* `/th[^s]*./`
* -- I want to match `the words that s`tart
* -- wi`th 'th' and end width 's`'.
* `this`, `thus`, `this`tle, `this` line matches too much
```

---

# A literal-string modification example 리터럴 문자열 수정예제

```
* 원문 The zoo had wild dogs, bobcats, lions, and other wild cats.
* `s/cat/dog/g`
* 수정 후 The zoo had wild dogs, bab`dog`s, lions, and other wild `dog`s.
* `s/cat|dog/snake/g`
* 수정 후 The zoo had wild `snake`s, bob`snake`s, lions, and other wild `snake`s.
* `s/[a-z]+i[a-z]*/nice/g`
* 수정 후 The zoo had `nice` dogs, bobcats, `nice`, and other `nice` cats.
```

---

# Modification using backreferences 역참조를 사용한 수정
* 원문 A37 B4 C107 D54112 E1103 XXX
```
* `s/([A-Z])([0-9]{2,4}) /\2:\1 /g` 괄호()로 레퍼런스 등록 후. \2, \1로 레퍼런스(참조) 번호를 매길수 있음
* 수정후 `37:A` B4 `107:C` D54112 `1103:E` XXX
```

---

# Non-greedy quantifiers
```
* `/th.*s/`
* -- I want to match `the words` that start
* -- with '`th' and end width 's`'.
* `this`, `thus`, `this`tle, `this` line matches too much

* `/th.*?s/`
* -- I want to match `the words that s`tart
* -- with '`th' and end width 's`'.
* `this`, `thus`, `this`tle, `this` line matches too much

* `/th.*?s /`
* -- I want to match `the words` that start
* -- with 'th' and end width 's'.
* `this`, `thus`, thistle, `this` line matches too much
```

---

# Pattern-match modifiers
```
* MAINE # Massachusetts # Colorade #
* sississippi # Missouri # Minnesota #

* `/M.*[ise] /`
* `MAINE # Massachusetts` # Colorade #
* sississippi # `Missouri` # Minnesota #

* `/M.*[ise] /gis`
* `MAINE # Massachusetts # Colorade #`
* `sississippi # Missouri` # Minnesota #
```
* A-xyz-37 # B:abcd:42 # C-wxy-66 # D-qrs-93
  
# Changing backreference behavior
```
* `s/([A-Z])(?:-[a-z]{3}-)([0-9]*)/\1\2/g`
* `A37` # B:abcd:42 # `C66` # `D93`
```

# Naming backreferences
```
import re
txt = "A-xyz-37 # B:abcd:142 # C-wxy-66 # D-qrs-93"
print re.sub("(?P<prefix>[A-Z])(-[a-z]{3}-)(?P<id>[0-9]*)","\g<prefix>\g<id>",txt)
```
* ``` `A37` # B:abcd:42 # `C66` # `D93` ```

---

# Lookahead assertions
```
`s/([A-Z]-)(?=[a-z]{3})([a-z0-9]*)/\2\1/g`
A-xyz37 # B-ab6142 # C-Wxy66 # D-qrs93
`xyz37A-` # B-ab6142 # C-Wxy66 # `qrs93D-`

`s/([A-Z]-)(?![a-z]{3})([a-z0-9]*)/\2\1/g`
A-xyz37 # B-ab6142 # C-Wxy66 # D-qrs93
A-xyz-37 # `ab6142B-` # `Wxy66C-` # D-qrs-93
```

---

# Making regular expressions more readable
```
/               # identify URLs within a text file
[^="]           # do not match URLs in IMG tags like: <img src="http//mysite.com/mypic/png">
http|ftp|gopher # make sure we find a resource type
:\/\/           # ...needs to be followed by colon-slash-slash
[^\n\r]+        # stuff other than space newline, tab is in URL
(?=[\s\.,])     # assert: follow by whitespace/period/comma
/
```
---

## 식
```
\s         공백문자(스페이스,탭등)
\*          *
\D        숫자가 아닌 문자
^           문자의 시작부분  ex)/^The/i
$           문자열 끝부분                     ex)/end$/ 
\w       알파벳,숫자,밑줄기호(_)
[^0-9]    숫자를 제외한
[0-9]     숫자만
[A-Za-z]알파벳 대소문자
|           or
s{2}      s의 두번 반복  {반복 횟수}
```

## 속성
```
g            전역 매칭
m           여러 줄 매칭
i             대소문자 구분 않음
```

## 문자 매칭

```
*           0회 이상 반복
+           1회 이상 반복
?           0 or 1개의 문자 매칭
.           1개의 문자 매칭
```

---
