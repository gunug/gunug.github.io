---
layout: post
title: 프로그래머스 코딩기초 트레이닝 3일차
category: coding
tags: javascript coding
---

# 코딩 기초 트레이닝
* [링크](https://school.programmers.co.kr/learn/challenges/training?order=acceptance_desc&languages=javascript)

---

# [문자열 섞기](https://school.programmers.co.kr/learn/courses/30/lessons/181942)
```javascript
function solution(str1, str2) {
    var arr1 = [...str1];
    var arr2 = [...str2];
    var arr3 = [];
    for(i=0; i<=arr1.length*2; i++){
        if(i%2==0){
            arr3.push(arr1[i/2]);
        }else{
            arr3.push(arr2[(i-1)/2]);
        }
    }
    var answer = arr3.join("");
    return answer;
}
```

* 다른풀이 : for문을 한번만 돌고 한번씩 붙이면 되는것

```javascript
for(i=0; i<=arr1.length; i++){
    arr3.push(arr1[i]);
    arr3.push(arr2[i]);
}
```

---

# [문자 리스트를 문자열로 변환하기](https://school.programmers.co.kr/learn/courses/30/lessons/181941)
```javascript
function solution(arr) {
    var answer = arr.join("");
    return answer;
}
```

---

# [문자열 곱하기](https://school.programmers.co.kr/learn/courses/30/lessons/181940)
```javascript
function solution(my_string, k) {
    var answer = '';
    for(i=0; i<k; i++){
        answer += my_string;
    }
    return answer;
}
```

```javascript
function solution(my_string, k) {
    return my_string.repeat(k)
}
```

---

# [더 크게 합치기](https://school.programmers.co.kr/learn/courses/30/lessons/181939)
```javascript
function solution(a, b) {
    var answer = Math.max(""+a+b,""+b+a);
    return answer;
}
```

---

# [두 수의 연산값 비교하기](https://school.programmers.co.kr/learn/courses/30/lessons/181938)

```javascript
function solution(a, b) {
    var answer = Math.max(""+a+b, 2*a*b);
    return answer;
}
```

---

