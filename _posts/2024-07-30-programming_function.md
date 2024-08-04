---
layout: post
title: programming function 함수
category: coding
tags: 
---


함수 Function

---

* Function : 독립된 기능을 수행하는 단위
* Method : 클래스, 구조체, 열거형에 포함되어 있는 함수(Function)

---

함수의 선언
기본 함수
```c#
public void func1(){
	Console.WriteLine("C");
}
```
* void 비어 있음

```javascript
function func1(){
    console.log("C");
}
```

---

함수의 호출
```
func1();
```

---

인자값이 있는 함수
```c#
public void func1(string str1){
	Console.WriteLine(str1);
}
```
* void 비어 있음

```javascript
function func1(str1){
    console.log(str1);
}
```

```c#
func1("D");
func1("C");
```

---

리턴이 있는 함수
```c#
public int func1(){
	return 10;
}
```
* void 비어 있음

```javascript
function func1(){
    return 10;
}
```

```c#
int num1 = func1();
Console.WriteLine(num1);
```

---

인자값 리턴 있는 함수
```c#
public int func1(int num1){
    return num1 + 1;
}
```
* void 비어 있음

```javascript
function func1(num1){
    return num1 + 1;
}
```

```c#
int num1 = func1(10);
Console.WriteLine(num1);
//11
```