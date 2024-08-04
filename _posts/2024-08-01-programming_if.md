---
layout: post
title: programming if 비교 판단문
category: coding
tags: 
---

# programming if 비교 판단문
if

---

```c#
int a = 10;
if(a == 10){

}
//if(조건식){수행구문}
// a = 1 + 1; //2
// b = 1 == 1; //true
// c = 1 == 3; //false
bool b = false;
b = 1 == 3;
b = false;
if(b){
    
}

int a = 10;
a = 1 + 1;
a = 30;

string c = "a";
c = "a" + "b";
c = "dd";
```

---

```c#
int a = 10;
if(a == 10){

}

if(A == 사람){
    말을건다
}else if(A == 동물){
    밥을준다
}else if(A == 생명체){

}else{

}
```

---

```c#
if(A == 사람){
    말을건다
}
if(A == 동물){
    밥을준다
}
if(A == 생명체){

}
```

---

```c#
if(A == 사람){
    말을건다
}
if(A != 사람 && A == 동물){
    밥을준다
}
if(A != 사람 && A != 동물 && A == 생명체){

}
```
# 관계연산자
* ==, >=, <=, >, <, !=

# 논리연산자
* and: ```&&```
* or: ```||```
* not: ```!```

(1==3) && (2==3)

---

```c#
// A가 짝수면 (2,4,6,8,10)
// A를 2로 나눈다음 나머지가 0이면
// A가 3의 배수면 (3,6,9,12)
// A를 3로 나눈다음 나머지가 0이면

몫 = A/2;
나머지 = A%2;
나머지 == 0;
if(A%2 == 0){
    //A를 2로나눈 나머지가 0이면
    //A가 짝수면
}

//화면이 밝아지면
//가림막 불투명도가 0이되면

```

---

```c#
		bool[] box_win = {true,true,false,false,false};
		Console.WriteLine(box_win[3]);
		Random rand = new Random();
		
		int result_number = rand.Next(0,5);
		Console.WriteLine(result_number);
		Console.WriteLine(box_win[result_number]);
		
		if(box_win[result_number]){
			Console.WriteLine("당첨되었습니다. 축하합니다");
		}else{
			Console.WriteLine("꽝 다음기회에");
		}
```