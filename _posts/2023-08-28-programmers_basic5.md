---
layout: post
title: 프로그래머스 코딩기초 트레이닝 5일차
category: coding
tags: javascript coding
---

# 코딩 기초 트레이닝
* [링크](https://school.programmers.co.kr/learn/challenges/training?order=acceptance_desc&languages=javascript)

---

# [코드 처리하기](https://school.programmers.co.kr/learn/courses/30/lessons/181932)
```javascript
function solution(code) {
    var code_arr = [...code];
    var mode = true;
    var answer = '';
    for(var i=0; i<code_arr.length; i++){
        if(code_arr[i]=="1"){
            mode = !mode;
            continue;
        }
        if(mode && i%2==0){
            answer += code_arr[i];
        }
        if(!mode && i%2!=0){
            answer += code_arr[i];
        }
    }
    if(answer.length == 0)answer = "EMPTY";
    return answer;
}
```

---

# [등차수열의 특정한 항만 더하기](https://school.programmers.co.kr/learn/courses/30/lessons/181931)
```javascript
function solution(a, d, included) {
    var count = a;
    var answer = 0;
    for(var i=0; i<included.length; i++){
        if(included[i])answer+=count;
        count += d;
    }
    return answer;
}
```

---

# [주사위 게임 2](https://school.programmers.co.kr/learn/courses/30/lessons/181930)

```javascript
function solution(a, b, c) {
    var answer = 0;
    if(a==b&&b==c){
        answer = (a+b+c)*(Math.pow(a,2)+Math.pow(b,2)+Math.pow(c,2))*(Math.pow(a,3)+Math.pow(b,3)+Math.pow(c,3));
    }else if(a==b||a==c||b==c){
        answer = (a+b+c)*(Math.pow(a,2)+Math.pow(b,2)+Math.pow(c,2));
    }else{
        answer = a+b+c;
    }
    return answer;
}
```

```javascript
    let sum1 = a + b + c;
    let sum2 = a * a + b * b + c * c;
    let sum3 = a ** 3 + b**3 + c**3;
```
* 제곱과 세제곱을 표현하는 방법

---

# [원소들의 곱과 합](https://school.programmers.co.kr/learn/courses/30/lessons/181929)
```javascript
function solution(num_list) {
    var gop = num_list.reduce(function multiple(mul, value){return mul*value})
    var hap = Math.pow(num_list.reduce(function multiple(mul, value){return mul+value}),2);
    var answer = gop<hap?1:0;
    return answer;
}
```

```javascript
    let mul = num_list.reduce((a, c) => {return a*c;}, 1); //곱셈의 항등원(1)으로 시작
    let sum = num_list.reduce((a, c) => {return a+c;}, 0); //덧셈의 항등원(0)으로 시작

    num_list.reduce((a,b) => a+b);
    num_list.reduce((a,b) => a*b);
```

---

# [이어 붙인 수](https://school.programmers.co.kr/learn/courses/30/lessons/181928)
```javascript
function solution(num_list) {
    var single = "";
    var double = "";
    for(var i=0; i<num_list.length; i++){
        if(num_list[i]%2==0){
            double += num_list[i];
        }else{
            single += num_list[i];
        }
    }
    var answer = parseInt(double)+parseInt(single);
    return answer;
}
```
* odd홀수, even짝수 변수명을 설정하는 것도 좋은듯