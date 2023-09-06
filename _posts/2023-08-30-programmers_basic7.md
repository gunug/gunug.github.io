---
layout: post
title: 프로그래머스 코딩기초 트레이닝 7일차
category: coding
tags: javascript coding
---

# 코딩 기초 트레이닝
* [링크](https://school.programmers.co.kr/learn/challenges/training?order=acceptance_desc&languages=javascript)

---

# [수열과 구간 쿼리 4](https://school.programmers.co.kr/learn/courses/30/lessons/181922)
```javascript
function solution(arr, queries) {
    var answer = arr;
    for(var q=0; q<queries.length; q++){
        var s = queries[q][0];
        var e = queries[q][1];
        var k = queries[q][2];
        for(var i=s; i<=e; i++){
            if(i%k==0) arr[i]++;
        }
    }
    return answer;
}
```

---

# [배열 만들기 2](https://school.programmers.co.kr/learn/courses/30/lessons/181921)
```javascript
function solution(l, r) {
    var number_set = [];
    var int_5 = 5;
    var count = 1;
    var answer = [];
    while(int_5 <= 1000000){
        var binary = count.toString(2); //2진수를 만든다
        int_5 = parseInt(binary)*5; // 5를 곱하여 5,50,55,500 형태를 만든다
        if(int_5 >= l && int_5 <= r){
            answer.push(int_5);
        }else if(int_5 > r)break;
        count++;
    }
    if(answer.length == 0)answer.push(-1);
    return answer;
}
```

---

# [카운트 업](https://school.programmers.co.kr/learn/courses/30/lessons/181920)
```javascript
function solution(start_num, end_num) {
    var answer = [];
    for(var i=start_num; i<=end_num; i++){
        answer.push(i);
    }
    return answer;
}
```

---

# [콜라츠 수열 만들기](https://school.programmers.co.kr/learn/courses/30/lessons/181919)
```javascript
function solution(n) {
    var answer = [n];
    while(n != 1){
        n = n%2==0?n/2:3*n+1;
        answer.push(n);
    }
    return answer;
}
```

---

# [배열 만들기 4](https://school.programmers.co.kr/learn/courses/30/lessons/181918)
```javascript
function solution(arr) {
    var stk = [];
    var i = 0;
    while(i<arr.length){
        if(stk.length <=0){
            stk.push(arr[i]);
            i++;
        }else if(stk[stk.length-1]<arr[i]){
            stk.push(arr[i]);
            i++;
        }else{
            stk.pop();
        }
    }
    return stk;
}
```