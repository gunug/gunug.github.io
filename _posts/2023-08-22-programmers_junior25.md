---
layout: post
title: 프로그래머스 입문 25일차
category: coding
tags: javascript coding
---

# [문자열 밀기](https://school.programmers.co.kr/learn/courses/30/lessons/120921)

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

---

# [연속된 수의 합](https://school.programmers.co.kr/learn/courses/30/lessons/120923?language=javascript)

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

---

# [다음에 올 숫자](https://school.programmers.co.kr/learn/courses/30/lessons/120924)

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