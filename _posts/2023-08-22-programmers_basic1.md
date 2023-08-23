---
layout: post
title: 프로그래머스 코딩기초 트레이닝 1일차
category: coding
tags: javascript coding
---

# 코딩 기초 트레이닝
* [링크](https://school.programmers.co.kr/learn/challenges/training?order=acceptance_desc&languages=javascript)

---

# [문자열 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/181952)
```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    console.log(str);
});
```
* 기본 내용에 console.log(str);만 추가함

---

# [A와 B 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/181951)
```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = line.split(' ');
}).on('close', function () {
    //console.log(Number(input[0]) + Number(input[1]));
    console.log("a = "+input[0]+"\n"+"b = "+input[1]);
});
```

---

# [문자열 반복해서 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/181950)
```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = line.split(' ');
}).on('close', function () {
    str = input[0];
    n = Number(input[1]);
    hap = "";
    for(i=0;i<n;i++){
        hap+=str;
    }
    console.log(hap);
});
```
* String.repeat(횟수)로 반복시킬 수 있는 것 같다.

---

# [대소문자 바꿔서 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/181949)
```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = [line];
}).on('close',function(){
    str = input[0];
    arr = [...str];
    for(i=0; i<arr.length; i++){
        if(arr[i] != arr[i].toUpperCase()){
            arr[i] = arr[i].toUpperCase();
        }else{
            arr[i] = arr[i].toLowerCase();
        }
    }
    str = arr.join("");
    console.log(str);
});
```

---

# [특수문자 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/181948)
```javascript
const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.on('close', function () {
    console.log("!@#$%^&*(\\'\"<>?:;");
});
```
* \역슬레시, "쌍따옴표는 문법에서 사용되는 글자라 이스케이프 문자(escape character)로 예외처리하여야 한다 (/)