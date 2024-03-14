---
layout: post
title: javascript 자바스크립트 기초
category: web
tags: javascript
---

# Javascript 개요
## 자바스크립트 기본
* 출처: https://developer.mozilla.org/ko/docs/Web/API/Document_Object_Model/Introduction
* DOM : 문서 객체 모델(The Document Object Model)
* HTML, XML 문서의 프로그래밍 interface 이다.
* DOM은 문서의 구조화된 표현(structured representation)을 제공하며 프로그래밍 언어가 DOM 구조에 접근할 수 있는 방법을 제공하여 그들이 문서 구조, 스타일, 내용 등을 변경할 수 있게 돕는다. 
* DOM 은 구조화된 nodes와 property 와 method 를 갖고 있는 objects로 문서를 표현한다.
* 웹 페이지를 스크립트 또는 프로그래밍 언어들에서 사용될 수 있게 연결시켜주는 역할을 담당한다.

## DOM에서의 객체 접근
* document.getElementById(id)
* document.getElementsByTagName (en-US)(name)
* document.createElement(name)
* parentNode.appendChild (en-US)(node)
* element.innerHTML (en-US)
* element.style (en-US).left
* element.setAttribute (en-US)
* element.getAttribute
* element.addEventListener (en-US)
* window.content (en-US)
* window.onload (en-US)
* window.dump (en-US)
* window.scrollTo (en-US)

## 자바스크립트, Node.js 자습 사이트
* 노마드코더 : https://www.youtube.com/channel/UCUpJs89fSBXNolQGOYKn0YQ
* 생활코딩 : https://opentutorials.org/course/3085
* w3cschool 레퍼런스 : https://www.w3schools.com/jsref/default.asp
* w3cschool : https://www.w3schools.com/js/default.asp
* Node js school : https://nodeschool.io/ko/#workshoppers
* http://tcpschool.com
* https://www.w3schools.com/
* 참고할만한 사이트 : https://www.codingfactory.net/

---

# 자바스크립트 버전에 관하여 
* 출처 : https://medium.com/sjk5766/ecma-script-es-%EC%A0%95%EB%A6%AC%EC%99%80-%EB%B2%84%EC%A0%84%EB%B3%84-%ED%8A%B9%EC%A7%95-77715f696dcb
  
## ES3 (1999)
* 우리가 흔히 말하는 자바스크립트.
  
## ES5 (2009)
* 배열에 forEach, map, filter, reduce, some, every와 같은 메소드 지원
* Object에 대한 getter / setter 지원
* 자바스크립트 strict 모드 지원 (더 깐깐한? 문법 검사를 한다.)
* JSON 지원 ( 과거에는 XML을 사용하다가, json이 뜨면서 지원하게 됨 )
  
## ES 2015 (ES 6)
* let, const 키워드 추가 : 기존의 변수는 함수 scope를 가진 var 키워드를 이용하여 선언하였다. 때문에 block scope 를 가진 let과 const 키워드를 추가하였다. 기존에는 상수형 키워드가 없어 CONST_TEST와 같이 대문자로 상수임을 표시했다면, ES 6부터 const 키워드가 추가되어 값의 변경을 통제한다.
*  arrow 문법 지원 : arror 문법은 두 가지의 장점을 제공한다. 첫 번째는 익숙하면 편하고 간결해진 코드를 작성할 수 있다. 두 번째는 this 를 바인딩하지 않는다. (다르게 말하면, this는 해당 scope의 this와 같다.)
* iterator / generator 추가 : 위 arrorw에서 샛길로 빠져서 더 새진 않겠습니다. 이 둘은 따로 공부해서 글을 쓸 정도로 내용이 깊고 많습니다.
* module import / export 추가 : 사실 저는 익숙하고 당연하게 import / export를 써 왔는데 도입된 시점이 그리 오래되지 않았다는 것에 잠깐 놀라네요.
* Promise 도입 : 자바스크립트의 비 동기 callback hell을 해결해 줄 기법이 추가 되었습니다.
  
## ECMA 2017 (ES 8)
* async — await : 위에서 ES6에서 callback hell을 해결하기 위해 Promise가 도입되었다고 했는데 async-await도 Promise처럼 callback 을 해결할 뿐만 아니라 좀 더 직관적이고 단순하게 코드를 만들 수 있습니다
  
# 브라우저별 자바스크립트 지원 여부
* 출처 : https://ko.wikipedia.org/wiki/%EC%9E%90%EB%B0%94%EC%8A%A4%ED%81%AC%EB%A6%BD%ED%8A%B8_%EC%97%94%EC%A7%84
![image](https://user-images.githubusercontent.com/52345276/192162066-eec566f0-f016-48b5-883b-2a15222a729c.png)

## 프로그램 언어 순위?
* TIOBE : https://www.tiobe.com/tiobe-index/
* TIOBE programming language index는 해당 프로그래밍 언어를 이용하는 엔지니어 및 업체의 수와 Google, Bing, Yahoo 등의 검색 엔진을 통해 검색되는 결과물의 수를 바탕으로 순위를 결정한다. 따라서 TIOBE index에서는 C/C++이나 Java와 같은 전통적인 프로그래밍 언어의 순위가 높게 산정되는 경향이 있다.

---

# Javascript의 작성위치
## external
* 외부에 js 파일을 두고 이를 불러서 사용
```  <script src="externalScriptFile.js"></script>```

## embeded
* script 태그 내에 스크립트를 작성
  
```html
  <script>
    alert("test");
  </script>
```
## inline
* html의 onclick등에 직접 작성
  
```html
<button onclick="alert('버튼 클릭')">버튼<button/>
```

---

# 자바스크립트의 구성요소
## 이벤트(트리거)
* DOM Events : https://www.w3schools.com/jsref/dom_obj_event.asp
  
```html
  <button onclick="alert('클릭됨')">클릭 해 주세요.</button >
  <button onmouseover="alert('마우스 올림')">마우스를 올려주세요.</button >
```
## 함수(function, method)
* 기능
* 여러가지 명령을 묶어 놓은 것
### 함수의 선언
* 함수를 사용하기 전, 함수의 형태나 내용등을 정의합니다. (사용 하기 위해 미리 설명을 해둡니다)
* ```function 함수 이름 (인자1, 인자2 ...) { 내용 }```

### 함수의 호출
* 함수를 불러서 정해진 대로 작동 하도록 해줍니다.
* 인자 값을 전달하여 함수가 그때그때 다른 동작을 할 수 있도록 할 수도 있습니다.
* ```함수 이름 (인자1, 인자2 ...); ```


## 예제
### 기본함수
```html
  <script>
  	function f1(){
  		alert("아주 기본적인 형태의 함수 입니다");
  	}
  </script>
  <button onclick="f1()">f1 실행</button>
```
### 인자값이 있는 함수
```html
  <script>
  	function f2(i){
  		alert(i+"라는 값을 전달 받았습니다");
  	}
  </script>
  <button onclick="f2(1)">f2 실행하면서 1을 전달</button>
  <button onclick="f2(2)">f2 실행하면서 2을 전달</button>
```
* 인자값 (변수 variable) 이 있는 경우는 호출하기에 따라 각각 다른 일을 할 수 있습니다.

### 리턴이 있는 함수
* 함수의 처리 결과를 의미하는 리턴(return)이 있는 함수는 스스로 무언가를 하기보다는 처리결과를 되돌려 줍니다.
  
```html
  <script>
  	function f3(i,j){
  		return i+j;
  	}
  	function f4(i,j){
  		var sum = f3(i,j);
  		alert(i+"더하기"+j+"는?"+sum);
  	}
  </script>
  <button onclick="f4(3,5)"> 3+5는? </button>
```

---

### 변수(variable)
* 변하는 수
* 똑같은 기능(function)을 가지고도 다양한 결과가 나올 수 있도록 함

# 출력장치
```javascript
  document.getElementById("demo").innerHTML="";
  document.write("");
  window.alert("");
  console.log("");
```
# 변수
## 이름규칙
* 이름에는 문자(영문),숫자,언더라인(_),달러기호($)이 사용될 수 있다.
* 이름은 반드시 문자(영문)으로 시작하여야 한다.
* 이름은 달러기호($)와 언더라인(_)으로 시작할 수도 있다.
* *라이브러리의 주기능에 대한 별칭으로 ($)가 사용되는 경우가 많음
* *비공개(숨겨진) 변수에 대한 별칭으로 (_)가 사용되는 경우가 많음
* 이름은 대소문자를 구분해야 한다. (y와 Y는 서로 다른 변수이름)
* 예약어(javascript에서 사용하기 위해 미리 지정된 이름)는 변수이름으로 사용될 수 없다.
  
## 선언방식

```javascript
 var carName;
 carName = "sport car"; //hoist라고 부르며 var만 이 방식으로 선언가능
 var carName = "sport car";
 var carName = "sport car", carColor = "red", carPrice = "10000";
```
## var
* 중복선언 시 값이 유실되지 않음
  
```html
  <p id="demo"></p>

  <script>
    var carName = "Volvo";
    var carName;
    document.getElementById("demo").innerHTML = carName;
  </script>
```
## let
* let은 ES6(2015)에 처음 소개되었다.
* let은 재정의 될 수 없다.
* let은 사용전 반드시 값이 할당되어야 한다.
* let은 블록변수(block scope)로 사용될 수 있다

### 재정의 될 수 없다
```javascript
  let x = "John Doe";
  let x = 0;
  // SyntaxError: 'x' has already been declared
```
### 블록변수(block scope)로 사용 될 수 있다
* {} 내에서 정의 된 let은 밖에서 접근할 수 없다.
  
```javascript
 {
   let x = 2;
 }
 // x can NOT be used here
 console.log(x);
```
* 지역변수로 사용할 수 있는 기초
* var같은 경우는 scope 밖에서 변수가 재정의 되거나 변경될 수 있다.
* 이미 선언된 let를 var로 재정의 하거나, var를 let으로 재정의 하는것이 불가능

## const 
* const는 ES6(2015)에 처음 소개되었다.
* const는 재정의 되지 않는다.
* const는 값이 재할당 되지 않는다.
* const는 블록변수(block scope)를 가지고 있다.
* Array(배열) Object(객체) Function(함수) RegExp(정규표현식)
* 변수가 아니기 때문에 고정된 값을 할당합니다.
* 위와같은 객체형 변수를 할당할 경우 객체참조(주소)를 고정값으로 가지고 있고. 객체 자체에 접근하여 변수를 수정할수 있습니다.

---

### 산술연산
* 사칙연산(+,-,*,/)으로 기본되는 숫자를 이용한 셈 연산

### 논리연산
* 예/아니오, 참/거짓 으로 표현될 수 있는 판단
* !=, ==, <=, >=, <, >

### 제어문
* 조건문, 반복문, 분기문
#### 조건문
* 조건식을 통하여 비교판단 하고 기능을 제어하는 구문
* if, if ~ else, if ~ else if ~ else, switch

#### 반복문
* 같은 작업(또는 약간의 차이가 있는 연속성작업)을 쉽게 처리하기 위한 구문
* while, do ~ while, for

#### 분기분
* 실행순서를 변경하여 다른명령을 실행할 수 있도록 하는 구문
* break, continue, return

---

# 자바스크립트의 특수성 
## DOM(문서 객체 모델 : The Document Object Model) 제어
```html
  <div>나의 이름은 <span id="my_name">홍길동</span>입니다. 반가워요</div>
  <script>
  	var name_span = document.getElementById("my_name");
  	name_span.innerHTML = "고길동";
  </script>
```
## CSS 제어
```html
  <style>
  	.red_back{
  		background-color: red;
  	}
  </style>
  <div id="div_red"> 붉은 배경 </div>
  <script>
  	var target_div = document.getElementById("div_red");
  	target_div.classList.add("red_back");
  </script>
```
## class제어, transition의 조합
```html
  <style>
  	#div_red2{
  		transition: background-color 1s;
  	}
  	.red_back2{
  		background-color: red;
  	}
  </style>
  <div id="div_red2" onmouseover="add_red()" onmouseout="remove_red()"> 붉은 배경 </div>
  <script>
  	var target_div = document.getElementById("div_red2");
  	function add_red(){
  		target_div.classList.add("red_back2");
  	}
  	function remove_red(){
  		target_div.classList.remove("red_back2");	
  	}
  </script>
```