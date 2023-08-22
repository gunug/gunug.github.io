---
layout: post
title: 프로그래머스 문자열밀기
category: coding
tags: javascript coding
---

* [문자열 밀기](https://school.programmers.co.kr/learn/courses/30/lessons/120921)

```javascript
function solution(A, B) {
    var a_arr = [...A]; //문자열을 배열로
    var answer = -1;
    for(var i=0; i<a_arr.length; i++){
        a_arr.unshift(a_arr.pop()); //하나씩 밀기
        var _A = a_arr.join('');
        if(B===_A){
            answer = (i+1)%a_arr.length; //숫자가 넘치면 나머지값을 사용
            break;
        }
    }
    return answer;
};
```