---
layout: post
title: 프로그래머스 코딩기초 트레이닝 2일차
category: coding
tags: javascript coding
---

# 코딩 기초 트레이닝
* [링크](https://school.programmers.co.kr/learn/challenges/training?order=acceptance_desc&languages=javascript)

---

# [덧셈식 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/181947)
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
    console.log(input[0]+" + "+input[1]+" = "+ (Number(input[0]) + Number(input[1])));
});
```

---

#[문자열 붙여서 출력하기](https://school.programmers.co.kr/learn/courses/30/lessons/181946)
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
    str1 = input[0];
    str2 = input[1];
    console.log(str1+str2);
});
```

---

#[문자열 돌리기](https://school.programmers.co.kr/learn/courses/30/lessons/181945)
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
        console.log(arr[i]);
    }
});
```
* 다른 방법들

```javascript
[...str].forEach(c => console.log(c))
for(let i of str){console.log(i)}
[...str].map(x=>console.log(x))
```

---

#[홀짝 구분하기](https://school.programmers.co.kr/learn/courses/30/lessons/181944)
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
    n = Number(input[0]);
    if(n%2==0){
        console.log(n+" is even");
    }else{
        console.log(n+" is odd");
    }
});
```
* 다른 방법들

```javascript
const result = Number(line) % 2 ? 'odd' : 'even'
console.log(line, 'is', result)

console.log(n%2===0? `${n} is even`:`${n} is odd`)
//문자열 사이에 변수 끼워넣기
console.log(`${input} is ${input % 2 ? 'odd' : 'even'}`);
//문자열 내에서 약식 비교판단
```

---

#[문자열 겹쳐쓰기](https://school.programmers.co.kr/learn/courses/30/lessons/181943)
```javascript
function solution(my_string, overwrite_string, s) {
    var answer = my_string.substr(0,s)+overwrite_string+my_string.substr(s+overwrite_string.length);
    return answer;
}
```
* substr의 두번째 인자값을 입력하지 않으면 최대치