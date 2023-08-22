---
layout: post
title: 프로그래머스 다음에 올 숫자
category: coding
tags: javascript coding
---

* [다음에 올 숫자](https://school.programmers.co.kr/learn/courses/30/lessons/120924)

```javascript
function solution(common) {
    var cha1 = common[1]-common[0];
    var cha2 = common[2]-common[1];
    var cha3 = cha2-cha1;
    var bi = cha2/cha1;
    console.log(bi);
    var answer = 0;
    if(cha3==0){
        answer = common[common.length-1]+cha1;
    }else{
        answer = common[common.length-1]*bi;
    }
    return answer;
}
```