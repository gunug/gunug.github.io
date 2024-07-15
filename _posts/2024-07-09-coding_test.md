---
layout: post
title: coding test 코딩 테스트
category: coding
tags: 
---


* 알고리즘 프로그래밍 훈련에 도움되는 웹사이트 몇 곳을 공유드립니다.
* 백준 온라인 저지 (Baekjoon Online Judge) : https://www.acmicpc.net/
* 백준 온라인 저지는 대한민국 최초의 알고리즘 문제 풀이 사이트입니다. 다양한 난이도와 주제의 문제들을 제공하며, C++, Java, Python 등 다양한 언어를 지원합니다.

* 프로그래머스(Programmers) : https://programmers.co.kr/
* 프로그래머스는 코딩테스트를 준비하는 개발자들을 위한 온라인 교육 사이트입니다. 프로그래머스에서는 다양한 주제의 문제들을 제공하며, 알고리즘 뿐만 아니라 SQL, 데이터 분석, 인공지능 등 다양한 분야의 문제를 풀어볼 수 있습니다.

* 리트코드(LeetCode) : https://leetcode.com/
* 리트코드는 알고리즘 문제를 제공하는 미국의 온라인 교육 플랫폼입니다. 대부분의 문제가 영어로 제공되지만, 다양한 주제와 난이도의 문제들을 제공하며, 다양한 언어를 지원합니다.

* 해커랭크(HackerRank) : https://www.hackerrank.com/
* 해커랭크는 알고리즘과 데이터 구조, 수학 등 다양한 분야의 문제를 제공하는 온라인 교육 사이트입니다. 문제의 난이도와 유형이 다양하며, 다양한 언어를 지원합니다.

* 코드포스(Codeforces) : https://codeforces.com/
* 코드포스는 알고리즘 대회를 주최하며, 대회 이외에도 다양한 주제와 난이도의 문제를 제공하는 온라인 교육 사이트입니다. 대회에서는 랭킹이 제공되며, 문제의 난이도와 유형이 다양합니다.

---

# 분수의 덧샘
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120808)
# 분수의 덧셈
분자 = 분자1*분모2 + 분자2*분모1;
분모 = 분모1*분모2;
# 기약분수
* 기약분수 = 분자와 분모를 최소공배수로 나누면 얻을수 있음

---

# 최대공약수 gcd(greatest common divisor)
* 두 숫자를 나누어 떨어지게 할수 있는 가장큰수 = 두 숫자를 나눈 나머지가 0이 될때의 값
* 항상 큰수에서 작은수를 나누어야 한다. 
  
```javascript
//javascript
function gcd(a,b){
  var min = Math.min(a,b);
  var max = Math.max(a,b);
  var _gcd = min;
  while(true){
      if(max % min == 0)break;
      _gcd = max % min;
      max = min;
      min = _gcd;
  }
  console.log("gcd:"+_gcd);
  return _gcd;
}
```

# 최소공배수 lcm(least common multiple)
* 두 수에 서로 공통으로 존재하는 배수 중 가장 작은 수
* 두 수를 곱한 후 최대공약수로 나눈수
  
```javascript
//javascript
function lcm(a,b){
  var _gcd = gcd(a,b);
  var _lcm = a*b/_gcd;
  console.log("lcm:"+_gcd);
  return _lcm;
}
```

---

# 중앙값 구하기
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120811)
* javascript sort를 이용하여 정렬 가능
* var answer = array[Math.round(array.length/2)-1];
* 정렬 후 전체길이의 반절 -1 (0 주소 부터 시작하기 때문)하여 문제해결

* 값의 크기가 비교되는게 아니라 앞글자부터 비교되어 에러가 난 경우
* sort()는 문자열의 유니코드 순서를 따르므로
* sort((a,b) => a-b)로 해주어야 한다.

---

# 최빈값 구하기
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120812)
  
```javascript
//javascript
function solution(array) {
    var counters = [];
    counters[0] = 0;
    for(var i=0; i<array.length; i++){
        if(Number.isInteger(counters[array[i]])){ //주소에 들은 값이 정수인지 확인
            counters[array[i]]++;
        }else{ //아니라면 초기값 입력
            counters[array[i]] = 1;    
        }
        
    }
    var appear_time = 0;
    var max_appear = -1;
    for(var i=0; i<counters.length; i++){
        if(counters[i] == appear_time){
            max_appear = -1;//최빈값 중복시 최빈값 -1로 변경
        }
        if(counters[i] > appear_time){
            appear_time = counters[i]; //최빈값 등장시 최빈량 저장 
            max_appear = i; //최빈값 저장
        }
    }
    console.log(counters);
    var answer = max_appear;
    return answer;
}
```

---
# 짝수는 싫어요
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120813)
  
```javascript
function solution(n) {
    var answer = [];
    for(i=1; i<=n; i+=2){
        answer.push(i);
    }
    console.log(answer);
    return answer;
}
```
---

# Javascript Reduce를 이용한 배열의 모든 숫자 더하기
```javascript
var numbers = {1,2,3,4,5};
var sum = numbers.reduce((a,b) => (a+b));
```

---

# 배열 뒤집기
```javascript
num_list.sort((a, b) => -1);
return num_list.reverse();
```

---

# 문자열 뒤집기
```javascript
function solution(my_string) {
    var strings = my_string.split('').reverse();
    var answer = strings.reduce((a,b) => (a+b));
    return answer;
}
```

```javascript
var answer = [...my_string].reverse().join(""); //스프레드문법
```

---

# 문자 반복하기
```javascript
function solution(my_string, n) {
    var answer = [...my_string].map(v => v.repeat(n)).join("");
    console.log(answer);
    return answer;
}
```

---

# 문자열 치환하기
```javascript
function solution(my_string, letter) {
    const re = new RegExp(`${letter}`, 'g'); 
    var answer = my_string.replace(re,"");
    return answer;
}
```
```my_string.replaceAll(letter, "");```

---
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120833)
  
```javascript
function solution(numbers, num1, num2) {
    var str = numbers.join(''); //하나의 문자열로 합시기
    var new_str = str.substr(num1,num2-num1+1); //시작인덱스와 끝인덱스 문자만 자르기
    var answer = new_str.split(''); //각문자를 배열로 변환
    answer = answer.map(Number); //배열에 들어간 각각의 문자열을 숫자로 치환
    answer = answer.map(x => Number(x)); //상동
    return answer;
    //2가지 케이스에 대한 테스트 실패가 나옴
}
```
```
function solution(numbers, num1, num2) {
    var answer = numbers.slice(num1,num2+1);
    return answer;
}
```
---

# .slice, .splice
* splice(start, deleteCount)
* slice(begin, end)
* splice 메소드는 기존 배열에 영향을 주지만 slice 메소드는 기존 배열에 영향을 주지않습니다

---

* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120835)

```javascript
    var rank = [...emergency];
    rank.sort((a,b) => b-a);
    answer = emergency.map((x) => rank.indexOf(x)+1);
    return answer;
```

---

# 어떠한 숫자를 이루는 약수의 개수 == 순서쌍
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120836)
  
```javascript
function solution(n) {
    var answer = 1;
    for(var i=0; i<n; i++){
        if(n%i == 0)answer++;
    }
    return answer;
}
```
---

# 모스부호 치환
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120838)
  
```javascript
function solution(letter) {
    morse = { 
    '.-':'a','-...':'b','-.-.':'c','-..':'d','.':'e','..-.':'f',
    '--.':'g','....':'h','..':'i','.---':'j','-.-':'k','.-..':'l',
    '--':'m','-.':'n','---':'o','.--.':'p','--.-':'q','.-.':'r',
    '...':'s','-':'t','..-':'u','...-':'v','.--':'w','-..-':'x',
    '-.--':'y','--..':'z'
    }
    var arr = letter.split(" ");
    for(var i=0; i<arr.length; i++){
        arr[i] = morse[arr[i]];
    }
    var answer = arr.join("");
    return answer;
}
```
* ```letter.split(' ').map(v=>morse[v]).join('');```
* ```return letter.split(' ').reduce((prev, curr) => prev + morse[curr], '')```

---
# 가위바위보 - 글자 치환
* 삼항연산자 : https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Operators/Conditional_Operator
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120839)
  
```javascript
function solution(rsp) {
    var arr = rsp.split("");
    arr = arr.map((x) => x==2 ? 0 : x==0 ? 5 : 2);
    var answer = arr.join("");
    return answer;
}
```

---

# 경우의 수 계산 - 팩토리얼
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120840)
  
```javascript
function solution(balls, share) {
    //balls!/(balls-share)!*share!
    console.log(fectorial(2));
    var answer = Math.round(fectorial(balls)/(fectorial(balls-share)*fectorial(share)));
    return answer;
}
function fectorial(num){
    if (num < 0){
        return -1;
    }else if(num==0){
        return 1;  
    } else {
        return num*fectorial(num-1);    
    }
}
```
* Math.round는 왜? 부동소숫점 오류 - https://joooing.tistory.com/entry/Javascript-%EC%86%8C%EC%88%98%EC%A0%90floating-point-%EA%B3%84%EC%82%B0-%EC%98%A4%EB%A5%98

---

# 구조 분해

```javascript
function solution(dot) {
    const [num,num2] = dot;
    const check = num * num2 > 0;
    return num > 0 ? (check ? 1 : 4) : (check ? 3 : 2);
}
```

---

# 배열에 갑추가, 빼기
* .push() : 배열의 맨 끝에 값을 추가한다.
* .unshift() : 배열의 맨 앞에 값을 추가한다.

##배열에 값을 제거하는 함수
* .pop() : 배열의 맨 끝에 값을 제거한다.
* .shift() : 배열의 맨 앞에 값을 제거한다.

---

# 정규표현식
* [^0-9] : 숫자가 아니면
* [0-9] : 숫자면
* [\d] : desimal 이면
* [^\d] : desimal 아니면
* [a-zA-Z] : 영문이면
* [^a-zA-Z] : 영문이 아니면

---

# 소인수 분해 하기
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120852)
  
```javascript
function solution(n) {
    var arr = [];
    for(var i=2; i<=n; i++){
        if(n%i==0){
            arr.push(i); //소인수 입력
            n=n/i; //소인수값으로 나눔
            i--; //값이 나누어 떨어지면 재시도
        }
    }
    arr = arr.filter((v, i) => arr.indexOf(v) === i) //중복제거
    var answer = arr;
    return answer;
}
```

```javascript
function prime_factor(n){
    var arr = [];
    for(var i=2; i<=n; i++){
        if(n%i==0){
            arr.push(i); //소인수 입력
            n=n/i; //소인수값으로 나눔
            i--; //값이 나누어 떨어지면 재시도
        }
    }
    arr = arr.filter((v, i) => arr.indexOf(v) === i)
    //중복제거
    return arr;
}

```

* 컨트럴 제트
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120853)
  
```javascript
function solution(s) {
    var ss = s.split(" ");
    var keep = ss[0];
    var answer = ss.reduce((a,b) => {
        if(b!="Z"){
            a = Number(a);
            b = Number(b);
            keep = b;
            return (a+b);
        }else{
            a = Number(a);
            return (a-keep);
        }
    });
    return answer;
}
```

* 테스트케이스 678번 실패
  
```javascript
function solution(s) {
    var ss = s.split(" ").map(Number);
    var answer = ss.reduce((acc,current,index,arr) => !isNaN(current)?acc+current:acc-arr[index-1]);
    return answer;
}
```
* keep이라고 해서 숫자를 저장하는 방식이 문제였나 본데
  
---

# reduce
* https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Array/reduce
* 매개변수
  
```javascript 
arr.rebuce((accumulator,currentValue,currentIndex,array)=>{return 연산후값},initialValue); 
```

```javascript 
arr.rebuce((acc,current,index,arr)=>{return 연산후값},init); 
```
* callbackFn : 배열의 각 요소에 실행할 함수
* accumulator : 이전 호출의 결과값
* currentValue : 현재 요소의 값
* currentIndex : 배열에서 인덱스 위치
* array : 배열
* initialValue : 콜백이 처음 호출될 때 초기화되는 값

---

# 369
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120891)
  
```javascript
function solution(order) {
    var arr = order.toString().split('');
    console.log(arr);
    var answer = arr.reduce((a,b) => a+(b==3)+(b==6)+(b==9), 0);
    return answer;
}
```
* 숫자에 블린을 덧셈해서 카운트에 사용하기도 하네


---

# 아스키코드
* 참고 링크 : https://developer-talk.tistory.com/880
  
```javascript
문자열.charCodeAt(0); //0번째 글자의 아스키코드 반환
String.fromCharCode(); //UTF-16코드를 문자로 반환
문자열.codePointAt(); //charCodeAt과 유사하나 표현할수 있는 정수의 범위가 더 크다
String.fromCodePoint(code1,code2 ... codeN); //지정된 코드 포인트 시퀀스를 문자열로 변환
```
---

# 필터
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120905)

```javascript
function solution(n, numlist) {
    var answer = numlist.filter(x => x%n==0);
    return answer;
}
```
---

# 자릿수 더하기
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120906)
  
```javascript
function solution(n) {
    var arr = [...n.toString()];
    var answer = arr.reduce((a,b)=>Number(a)+Number(b));
    return answer;
}
```
* 에러 : reduce에 초기값이 없음으로 초기값이 string으로 시작됨
* ```arr.reduce((a,b)=>Number(a)+Number(b),0);```으로 초기값을 잡고 시작하거나 arr을 map(Number)하여 숫자로 변환 후 사용

---

# 문자열 검사
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120908)
  
```javascript
function solution(str1, str2) {
    var regex = new RegExp(`${str2}`, 'g');
    var answer = regex.test(str1)?1:2;
    return answer;
}
```

---

# 제곱근 정수 판별
```javascript
function solution(n) {
    var sqrt = Math.sqrt(n);
    var answer = sqrt==Math.floor(sqrt)?1:2;
    return answer;
}
```

---

# 문자열 치환
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/12951)
  
```javascript
function solution(s) {
    var answer = s.toLowerCase();
    var regex = /^\w| \w/g; //문자로 시작하거나(|)스페이스가 앞에 붙은 문자
    answer = answer.replaceAll(regex,function(v){
        return v.toUpperCase();
    });
    return answer;
}
```

---


# 괄호
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/12909)
  
```javascript
function solution(s){
    var regex = /\(\)/gm;
    while(regex.test(s)){
        s = s.replaceAll(regex,"");
    }
    return s.length == 0;
}
```
* 리플레이스로 해결하려하니 효율성 테스트에서 실패

```javascript
function solution(s){
    var arr = [...s];
    var counter = arr.reduce((a,b)=>b==")"?a-1:a+1,0);
    return counter==0 && arr[0]=="(";
}
```
* 플러스마이너스 0이고 (로 시작한다면. 통과
* 갯수만 가지고는 안되나? ())(() 반례

```javascript
function solution(s){
    var arr = [...s];
    var counter = arr.reduce((a,b)=>b=="("?a+1:a>0?a-1:a-100,0);
    console.log(counter);
    return counter == 0;
}
```
* 시간초과
* 테스트 17 〉	통과 (2.21ms, 33.5MB)
* 테스트 18 〉	통과 (3.40ms, 33.5MB)
  
```javascript
function solution(s){
    var arr = [...s];
    var counter = 0;
    for(var i=0; i<arr.length; i++){
        counter = arr[i]=="("?counter+1:counter>0?counter-1:counter-100
    }
    console.log(counter);
    return counter == 0;
}
```
* 같은내용을 reduce가 아닌 for로 돌려서 해결
* 테스트 17 〉	통과 (2.25ms, 33.6MB)
* 테스트 18 〉	통과 (3.30ms, 33.5MB)
* 테스트 케이스에서는 차이가 별로 안나는데.

---

# 문자의 사용 만족
```javascript
function solution(spell, dic) {
    var answer = 0;
    var exist = true;
    for(var i=0;i<dic.length; i++){
        if(dic[i].length != spell.length) continue; //글자수가 안맞으면 넘어가
        console.log(dic[i]);
        exist = true;
        for(var j=0; j<spell.length; j++){
            dic[i] = dic[i].replace(spell[j],"");
            if(dic[i].length != spell.length-1-j){ //두개이상 지워지면 넘어가
                exist = false;
                break;
            }
        }
        if(exist)return 1;
    }
    return 2;
}
```


```javascript
function solution(p, d) {
    return d.some(s => p.sort().toString() == [...s].sort().toString()) ? 1 : 2;
}
```

---

# fill
* arr3.fill('A', 1, 3);
* 인덱스 1부터 3 까지 'A'로 채움

---

# 등수매기기
* [문제링크](https://school.programmers.co.kr/learn/courses/30/lessons/120882)
  
```javascript
function solution(score) {
    var i=0;
    score = score.map(function(v){return (v[0]+v[1])/2;}); //평균내기
    var arr = [...score];
    arr.sort((a,b)=>b-a); //등수내기
    console.log(arr);
    var answer = score.map(v => arr.indexOf(v)+1); //현점수가 몇순위인지 확인하여 배열에 넣기
    return answer;
}
```

---

# 십진수 이진수
```javascript
function solution(bin1, bin2) {
    var de1 = parseInt(bin1, 2); //2진수를 10진수로
    var de2 = parseInt(bin2, 2);
    console.log(de1);
    console.log(de2);
    var answer = (de1+de2).toString(2); //10진수를 2진수로
    return answer;
}
```

---

# 배열의 비교
```javascript
const equals = (a, b) => a.length === b.length && a.every((v, i) => v === b[i]);
function solution(before, after) {
    var arr1 = [...before];
    var arr2 = [...after];
    arr1 = arr1.sort();
    arr2 = arr2.sort();
    console.log(arr1);
    console.log(arr2);
    var answer = equals(arr1, arr2);
    return answer;
}
```

---

# 문자열내 포함여부
1. String.indexOf(): 문자열에 어떤 문자열이 포함되어있는지 확인
2. String.includes(): 문자열에 어떤 문자열이 포함되어 있는지 확인
3. String.startsWith(), String.endsWith(): 문자열이 어떤 문자열로 시작하거나 끝나는지 확인