---
layout: post
title: javascript varibale 자바스크립트 변수
category: web
tags: javascript
---

# 변수 출력
```c#
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
* 라이브러리의 주기능에 대한 별칭으로 ($)가 사용되는 경우가 많음
* 비공개(숨겨진) 변수에 대한 별칭으로 (_)가 사용되는 경우가 많음
* 이름은 대소문자를 구분해야 한다. (y와 Y는 서로 다른 변수이름)
* 예약어(javascript에서 사용하기 위해 미리 지정된 이름)는 변수이름으로 사용될 수 없다.

## 선언방식
```c#
var carName;
carName = "sport car"; //hoist라고 부르며 var만 이 방식으로 선언가능
var carName = "sport car";
var carName = "sport car", carColor = "red", carPrice = "10000";
```

## var
중복선언 시 값이 유실되지 않음
```c#
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
* 재정의 될 수 없다

```c#
 let x = "John Doe";
 let x = 0;
 // SyntaxError: 'x' has already been declared
```

## 블록변수(block scope)로 사용 될 수 있다
* {} 내에서 정의 된 let은 밖에서 접근할 수 없다.

```c#
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