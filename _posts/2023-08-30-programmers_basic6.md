---
layout: post
title: 프로그래머스 코딩기초 트레이닝 6일차
category: coding
tags: javascript coding
---

# 코딩 기초 트레이닝
* [링크](https://school.programmers.co.kr/learn/challenges/training?order=acceptance_desc&languages=javascript)

---

# [마지막 두 원소](https://school.programmers.co.kr/learn/courses/30/lessons/181927)
```javascript
function solution(num_list) {
    var answer = num_list;
    var value1 = num_list[num_list.length-2];
    var value2 = num_list[num_list.length-1];
    if(value1 < value2){
        answer.push(value2-value1);
    }else{
        answer.push(value2*2);
    }
    return answer;
}
```

---

# [수 조작하기 1](https://school.programmers.co.kr/learn/courses/30/lessons/181926)
```javascript
function solution(n, control) {
    var arr_control = [...control];
    var answer = n;
    for(var i=0; i<arr_control.length; i++){
        switch(arr_control[i]){
            case "w":
                answer++;
                break;
            case "s":
                answer--;
                break;
            case "d":
                answer+=10;
                break;
            case "a":
                answer-=10;
                break;
        }
    }
    return answer;
}
```

---

# [수 조작하기 2](https://school.programmers.co.kr/learn/courses/30/lessons/181925)
```javascript
function solution(numLog) {
    var answer = '';
    for(var i=1; i<numLog.length; i++){
        if(numLog[i] - numLog[i-1] == 1)answer += "w";
        if(numLog[i] - numLog[i-1] == -1)answer += "s";
        if(numLog[i] - numLog[i-1] == 10)answer += "d";
        if(numLog[i] - numLog[i-1] == -10)answer += "a";
    }
    return answer;
}
```

---

# [수열과 구간 쿼리 3](https://school.programmers.co.kr/learn/courses/30/lessons/181924)
```javascript
function solution(arr, queries) {
    var answer = arr;
    for(var i=0; i<queries.length; i++){
        var val1 = answer[queries[i][0]];
        var val2 = answer[queries[i][1]];
        answer[queries[i][0]] = val2;
        answer[queries[i][1]] = val1;
    }
    return answer;
}
```

---

# [수열과 구간 쿼리 2](https://school.programmers.co.kr/learn/courses/30/lessons/181923)
```javascript
function solution(arr, queries) {
    var answer = [];
    console.log(arr,queries);
    for(var j=0; j<queries.length; j++){
        var min = 1000001;
        var s = queries[j][0];
        var e = queries[j][1];
        var k = queries[j][2];
        for(var i=s; i<=e; i++){
            if(arr[i]>k && arr[i]<min)min=arr[i];
        }
        if(min==1000001)min=-1;
        answer.push(min);
    }
    return answer;
}
```

```javascript
var min = Infinity; //무한값
```