---
layout: post
title: 프로그래머스 연속된 수의 합
category: coding
tags: javascript coding
---

* [연속된 수의 합](https://school.programmers.co.kr/learn/courses/30/lessons/120923?language=javascript)

```javascript
function solution(num, total) {
    var answer = [];
    var start = Math.ceil(total/num) - Math.floor(num/2);
    //수의 중앙에서 횟수의 반만큼 앞으로 나가면 그곳이 시작점
    for(var i=0; i<num; i++){
        answer.push(start+i);
    }
    return answer;
}
```