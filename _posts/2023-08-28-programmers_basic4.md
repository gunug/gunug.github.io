---
layout: post
title: 프로그래머스 코딩기초 트레이닝 4일차
category: coding
tags: javascript coding
---

# 코딩 기초 트레이닝
* [링크](https://school.programmers.co.kr/learn/challenges/training?order=acceptance_desc&languages=javascript)

---

# [n의 배수](https://school.programmers.co.kr/learn/courses/30/lessons/181937)
```javascript
function solution(num, n) {
    var answer = num%n==0?1:0;
    return answer;
}
```

---

# [공 배수](https://school.programmers.co.kr/learn/courses/30/lessons/181936)
```javascript
function solution(number, n, m) {
    var answer = number%n + number%m == 0 ? 1: 0;
    return answer;
}
```

---

# [홀짝에 따라 다른값 반환하기](https://school.programmers.co.kr/learn/courses/30/lessons/181935)
```javascript
function solution(n) {
    var answer = 0;
    if(n%2!=0){
        //홀수
        for(var i=1;i<=n;i+=2){
            answer += i;
        }
    }else{
        //짝수
        for(var i=2;i<=n;i+=2){
            answer += Math.pow(i,2);
        }
    }
    return answer;
}
```

---

# [조건 문자열](https://school.programmers.co.kr/learn/courses/30/lessons/181934)
```javascript
function solution(ineq, eq, n, m) {
    var ineq_ep = ineq+eq;
    var answer = 0;
    switch(ineq_ep){
        case "<=":
            answer = n<=m ? 1:0
            break;
        case ">=":
            answer = n>=m ? 1:0
            break;
        case "<!":
            answer = n<m ? 1:0
            break;
        case ">!":
            answer = n>m ? 1:0
            break;
    }
    return answer;
}
```

---

# [flag에 따라 다른 값 반환하기](https://school.programmers.co.kr/learn/courses/30/lessons/181933)
```javascript
function solution(a, b, flag) {
    var answer = flag?a+b:a-b;
    return answer;
}
```