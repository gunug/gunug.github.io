---
layout: post
title: javascript 고급
category: web
tags: javascript
---

# javascript 고급

@ 2022년 01월 22일

# 자바스크립트 Promise 
* pythontutor.com/javascript.html
* setTimeout - 비동기통신에서 중요한?
* typescript를 해석하기위한 swc
* add -D types - 로 설치
* 리액트는 따로 설치할 필요없음

* 프로미스 객체를 본다. 프로미스 동작보기, 
* Async, Away가 promise와 연동되어 어떻게 동작하는지
* Promise() 

* developer.mozilla.org/ko/docs/web/javascript/reference/global_object
* 대기, 이행, 거부

---

# 동기 비동기 
* 비동기 Asynchtonous
  * 산발적으로 수행되기 때문에 특점 지점을 알수가 없다.
* 동기 synchronous : 같이 동시적으로 실행된다 : run-to-completion
  * 모든 내용을 순차적으로 시작하기 때문에 어떤 시점에 대한 이벤트를 잡기가 쉬워짐

* 작업의 시작은 알 수 있으나 작업의 끝은 알 수 없다.
* 코어(물리적 연산 분리), 스레드(논리적 연산 분리)
* Task(프론트엔드 단에서의 스레드같은 개념)

* 프론트 엔드에서의 무거운작업 수행시 UI가 굳는 현상을 방지하기 뒤한 방법. Ajax(화면을 새로고침하지 않고 부분적으로 처리)
* worker를 이용하여 스레드를 사용할수 있지만 사용하고 있지 않다.

* setTimeout이나 promise 같은 비동기 코드들


* macrotask(중요한), microtack(덜 중요한)
* callback - 이전까지 비동기를 처리하던 방식?

```javascript
  const asuncFunc = async () -> {
    await delay(100);
    return "hello";
  }
  
  const delay = ( t = 0 ) -> {
    return new Promise(resolve -> {
      setTimeout(() -> {
        resolve(t);
      }, t);
    });
  };
```
* async가 붙으면 무조건 promise 리턴 타입이 된다.

```javascript
  async function hello() { return "Hello" };
  hello();
```
# 제너레이터 
```javascript
  function* f(){
    let i = 0;
    while(true){
      yield i++;
    }
  }
```
* f.next();로 수행요청을 할수 있나봄
  
```javascript
 고차함수 
  function f2(){
    let i =0;
    return i;
  }
```

* 고차함수(컨티뉴에이션 모나드) <- 제너레이터 <- async-await
* 이렇게 의존성이 있어요

---

# Javascript macrotask 
* setTimeout(); setInterval();

# Javascript microtask 
* promise();
* Event Loop가 받아서 순차로 처리함

* 옵셔널 체이닝 : func?. (); : 없을 경우에는 함수를 수행하지 않음

# 콜백체인 
* new Promise((resolve, reject) --> { })
* then, finally, catch
  
```javascript
  print("hello")
  .then(() -> print("world"))
  .then(() -> print("foo"))
  .catch()
  .finally();

  try{
  }catch(e){
  }finally{
  }
```

# Trailing comma 
* https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Trailing_commas
* Trailing comma라고 해서 기능입니다 문제 안 되어용
* Trailing comma 시 공란이라면 for문이 하나 덜 돌거나 length가 하나 적게 표시되거나 그러는건가? 신기하네

# Promise 
* Promise.all : 배열로 promise를 받아서 모든 promise를 수행했다가 .then 체인을 수행함
  * 리턴값 배열
* Promise.race : 선착순
  * 리턴값 단독
* Promise 체인닝의 리턴값은 Promise로 돌아온다.
await으로 Promise 리턴을 받아서 이어나간다.

* https://developer.mozilla.org/ko/docs/Learn/JavaScript/Asynchronous/Async_await
* async를 사용하면 아무거나 return해도 promise로 감싸져서 되돌아간다.

# 새로운 기능 
* console.time("test");
* console.timelog("time","say test");
* console.timeEnd("test");

* process.exit(); 프로세스 종료

---

# 람다식 
* 람다식 예제
 
* 기존 자바 문법
  
```javascript
  new Thread(new Runnable() {
     @Override
     public void run() { 
        System.out.println("Welcome Heejin blog"); 
     }
  }).start();
```

* 람다식 문법

```javascript
  new Thread(()->{
        System.out.println("Welcome Heejin blog");
  }).start();
```