---
layout: post
title: 변수
category: coding
tags:
---

# 변수(Variable)
* 변하는 수

```c#
private int a = 10; //변수의 선언
//접근제한자 변수타입 변수이름 = 초기값;

a = 30; //변수에 값 할당
Debug.Log(a); //변수 사용
```

## 기본형 변수, 참조형 변수
* 기본형(primitive type) : 리터럴, 즉 실제 값이 들어가는 변수
  * int, string, char, double, float, bool
* 참조형(reference type) : 참조(reference)가 들어가는 변수, 참조란 값이 있는 주소(위치)를 의미
  * Object, GameObject, Vector3

### 참조형 변수 예시
```c#
    int[] a = {1,2,3,4,5};
    Console.WriteLine(a[0]); //1
    a[0] = 10; //10이라는 리터럴을  a의 0번 주소에 기록
    Console.WriteLine(a[0]); //10

    int[] b = a;  //a의 참조를 b변수에 기록
    b[0] = 30; //b를 변경하였지만 b는 a의 참조 이므로, b와 a가 동일대상

    Console.WriteLine(b[0]); //30
    Console.WriteLine(a[0]); //30
```

### 기본형 변수의 참조
* ref 키워드를 이용하여 기본형 변수라도 참조를 넘길 수 있다.
  
```c#
    void Start()
    {
        int a = 10;
        b(ref a);
        Debug.Log(a); //30
        //참조를 전달받아 내용을 수정하였음으로 원본 변수의 내용이 변경됨

        int c = 10;
        d(c);
        Debug.Log(c); //10
        //값(리터럴)을 전달받아 값을 수정하였음으로 원본 변수의 내용은 변경되지 않음
    }
    private void b(ref int c)
    {
        c = 30;
    }
    private void d(int c)
    {
        c = 30;
    }
```

```c#
    int d = 20;
    ref int e = ref d;
    e = 30;
    Debug.Log(d);
```
---

## 변수이름 표기법
* 표기법은 일종의 약속 같은 것, 프로그램을 작성하는 사람마다 다를 수 있음
* 카멜🐫 : camelCase : 변수명, 함수명
* 파스칼 : PascalCase: 클래스명, 함수명
* 스네이크🐍 : snake_case : 변수명
* 헝가리안: usValue : 접두사가 있는, 정적 타입 언어

## 변수의 범위
* 정수 숫자 형식

```c#
using System;		
public class Program
{	
	public static void Main()
	{
		int a = 2147483647;
		Console.WriteLine(a);
        //2147483647
		a++;
		Console.WriteLine(a);
        //-2147483648
	}
}
```
* [참고링크](https://learn.microsoft.com/ko-kr/dotnet/csharp/language-reference/builtin-types/integral-numeric-types)
* int : -2,147,483,648 ~ 2,147,483,647

---

## 정리
### 왜 변수가 필요한가?
* 바뀌어야 하니까
* 값이 바뀌면 결과가 바뀜 = 프로그램의 목적
  
### 왜 참조가 필요한가?
* 코드가 간결해짐
* 반복작업 방지 = 생산성 증대, 컴퓨터 리소스 확보
* 변수에 참조를 기록하면 참조를 변경하여 다른 결과를 만들수 있음

---

## 변수 유형 variable type
* 변수에는 유형(type)이 있음
* 유형에 맞는 값을 넣어야 함 (유형에 맞지 않는 값은 넣을 수 없음)
* 유형에 맞지 않는 변수는 형변환(type cast) 해서 넣음
* 형변환 방법에는 대표적으로 (int)
* 자동으로 캐스팅 되는 경우 : 묵시적 형변환(implicitly type cast)
* 안되는 경우 : 명시적 형변환(Explicit Type Conversion)
* 명시적 형변환이 불가능한경우 : 값 자체를 재 가공

## 묵시적 형변환 Implicitly Type Casting
* 하위객체를 상위객체로 변환
* 상위객체를 하위객체로 묵시적 형변환 시도하면 에러

## 명시적 형변환 Explicit Type Casting
* 직접 데이터 타입을 변환

## 캐스팅(castring) 형변환
```c#
int m = 10;
int n = 3;
Console.WriteLine( (double)m / n );
Console.WriteLine( m / n );
```

---

# 기타
* typescript : MS에서 만든 JavaScript의 슈퍼셋(Superset) 프로그래밍 언어.
* 호이스팅(hoisting) : 변수 선언이 어디에 있든 상관없이 다른 코드보다 먼저 실행되는 특징

```c#
int a  = 10;
char b = 'B';
a = System.Convert.ToInt32(b);
Console.WriteLine(a);
```