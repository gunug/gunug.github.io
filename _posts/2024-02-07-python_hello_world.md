---
layout: post
title: python hello world
category: coding
tags: python
---

# 파이썬 확인 
* python 또는 python3를 입력하여 파이썬에 진입합니다.
* Ctrl+D를 누르면 REPL에서 빠져나올 수 있습니다.
  
# 새 파일 만들기 
* sudo nano hello_world.py 입력하여 에티터에 진입합니다.
* Ctrl+X 그리고 Y를 눌러 세이브하고 빠져나올 수 있습니다.
 코드입력 

```python
#!/usr/bin/python
print "Hello, World!";
```

# 프로그램 구동하기 
* python hello_world.py

# 실행가능(EXECUTABLE) 프로그램 만들기 
* sudo chmod +x hello_world.py

# 만들어진 프로그램 실행하기 
* ./hello_world.py

---

# 배열 
리스트, 튜플, 세트, 딕셔너리
## 리스트 
* 합 : sum(list)
* 평균 : sum(list)/len(list)
* 최대값 : max(list)
* 최소값 : min(list)
* 정렬 : list.sort();

## 세트 
* a = set() #set
* 중복 허용이 되지않는다.
* 순서가 없다.
* 집합처럼 활용이 된다.
* 교집합 : &, intercection()
* 합집합 : ```|```, union()
* 차집합 : -
* 대칭차집합 : ^

## 딕셔너리 
* a = {} #dic
* dict = {"kor":10, "eng":20}
* list(dict.keys())
* list(dict.values())

## map 
* li = list(map(int,string_value.split))

---

# 추후 확인해볼 내용
* <https://wikidocs.net/77>

---

```python
#1. Boolean: 참, 거짓
#2. int: 정수
#3. float: 실수
#4. complex: 복소수
#5. strings: 문자열
#6. bytes: 바이트

#7. lists
#8. Tuples
#9. Sets:
#10. Dictionaries

x = 1
y = 2
x = 3

print(x)
print(y)
```

```python
init python:
    class SampleClass:
        a: int = None
        b: int = None
        c: int = None

    p = SampleClass()
    p.a = 1
    p.b = 2
    p.c = 3

    r = SampleClass()
    r.a = 5
    r.b = 6
    r.c = 7
```