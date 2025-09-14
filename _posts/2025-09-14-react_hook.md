---
layout: post
title: react hook
category: web
tags: 
teaser: 
---

# react hook
* 리액트 훅은 함수형 컴포넌트에서 상태(state)와 생명주기 기능(lifecycle features)을 사용할 수 있게 해주는 특별한 함수입니다. 훅이 등장하기 전에는 이러한 기능들을 사용하기 위해 클래스형 컴포넌트를 사용해야 했습니다.

## 훅이 필요한 이유
* 리액트에서 클래스형 컴포넌트를 사용하다 보면 다음과 같은 문제들이 발생했습니다.
* 재사용성 문제: 여러 컴포넌트에서 동일한 로직(예: 데이터 불러오기, 구독 설정)을 공유하기가 어려웠습니다. HOC(High-Order Components)나 렌더 프롭스(Render Props)와 같은 패턴을 사용해야 했는데, 이는 코드의 복잡성을 높였습니다.
* 복잡한 컴포넌트: componentDidMount, componentDidUpdate 등 여러 생명주기 메서드에 흩어져 있는 관련 로직을 한눈에 파악하기가 어려웠습니다. 예를 들어, 데이터 구독과 구독 해제 로직이 다른 메서드에 분리되어 있어 코드가 직관적이지 않았습니다.
* 클래스 문법의 어려움: 자바스크립트의 this 키워드 바인딩이나 클래스의 동작 방식에 익숙하지 않은 개발자에게는 클래스형 컴포넌트가 배우고 사용하기 어려웠습니다.

---

## useState
* 변수 대신 쓸 수 있는 데이터 저장 공간
* useState() 함수를 이용하여 생성
* state가 변경되면 HTML이 자동으로 재렌더링 됨
* 자주 바뀌는, 중요한 데이터는 변수대신 state로 저장하여 사용하기

* useState는 함수형 컴포넌트에서 상태를 관리할 수 있게 해주는 훅입니다.
* 사용법: const [state, setState] = useState(initialState);
* 설명: 첫 번째 인자인 state는 현재 상태 값, 두 번째 인자인 setState는 상태를 업데이트하는 함수입니다. useState의 인자로 초기 상태 값을 넣어줍니다.

```jsx
import React, { useState } from 'react';

function Counter() {
  const [count, setCount] = useState(0);

  return (
    <div>
      <p>현재 카운트: {count}</p>
      <button onClick={() => setCount(count + 1)}>증가</button>
    </div>
  );
}
```

## useEffect
* useEffect는 함수형 컴포넌트에서 **부수 효과(side effects)**를 처리할 수 있게 해주는 훅입니다. 부수 효과란 데이터 불러오기, DOM 직접 조작, 타이머 설정, 구독 설정/해제와 같은 것들을 의미합니다.
* 사용법: useEffect(() => { ... });
* 설명: 컴포넌트가 렌더링될 때마다 특정 코드를 실행하도록 합니다. 두 번째 인자인 **의존성 배열(dependency array)**을 통해 실행 시점을 제어할 수 있습니다.
* 의존성 배열이 없을 때: 매 렌더링마다 실행
* 빈 배열([])일 때: 컴포넌트가 처음 마운트(화면에 나타날 때)될 때만 한 번 실행
* 값들이 포함된 배열일 때: 배열 내의 값이 변경될 때마다 실행

```jsx
import React, { useState, useEffect } from 'react';

function TitleUpdater() {
  const [count, setCount] = useState(0);

  useEffect(() => {
    document.title = `카운트: ${count}`;
  }, [count]); // count가 변경될 때만 실행

  return (
    <div>
      <p>현재 카운트: {count}</p>
      <button onClick={() => setCount(count + 1)}>증가</button>
    </div>
  );
}
```

---

## 훅의 규칙
* 훅을 사용할 때는 다음과 같은 두 가지 중요한 규칙을 반드시 지켜야 합니다.
* 최상위에서만 호출: 반복문, 조건문, 중첩된 함수 내에서 훅을 호출하면 안 됩니다. 리액트는 훅의 호출 순서를 통해 상태를 추적하므로, 항상 컴포넌트의 최상위 레벨에서 호출해야 합니다.
* 리액트 함수 컴포넌트에서만 호출: 일반 '자바스크립트 함수'에서는 훅을 호출할 수 없습니다. 오직 '리액트 함수 컴포넌트'나 '커스텀 훅' 내에서만 호출해야 합니다.
* 훅은 리액트 개발을 더 간결하고, 직관적이며, 재사용하기 쉽게 만들어 줍니다. 이를 통해 함수형 컴포넌트만으로도 대부분의 기능을 구현할 수 있게 되었습니다.

## 자바스크립트 함수
* 자바스크립트 함수: 특정 작업을 수행하고 값을 반환하는 범용적인 코드 블록입니다.

```jsx
function add(a, b) {
  return a + b;
}
```
## 리액트 함수 컴포넌트
* 리액트 함수 컴포넌트: JSX를 반환하여 UI를 렌더링하는 함수입니다.
* jsx 반환: 항상 jsx를 반환해야 합니다.
* props를 인자로 받음: 부모 컴포넌트로 부터 전달받은 props를 인자로 받습니다.
* 훅(hook)사용 : useState, useEffect 같은 리액트 훅을 컴포넌트의 최상위 레벨에서 사용할 수 있습니다.

```jsx
import React from 'react';

function MyButton({ text }) {
  const [isClicked, setIsClicked] = React.useState(false);
  
  return <button onClick={() => setIsClicked(true)}>{text}</button>;
}
```
## 커스텀 훅
* 커스텀 훅: 리액트 훅을 사용하여 상태 로직을 재사용 가능하도록 만든 함수입니다.
* use 접두사: 함수 이름이 use로 시작해야 합니다.
* 훅 호출: useState나 useEffect와 같은 다른 훅을 내부에서 호출합니다.
* 값을 반환: 상태값, 상태를 변경하는 함후등 원하는 값을 반환할 수 있습니다.

```jsx
import { useState, useEffect } from 'react';

// 커스텀 훅은 리액트 함수 컴포넌트와 동일한 훅 규칙을 따릅니다.
function useFetch(url) {
  const [data, setData] = useState(null);
  
  useEffect(() => {
    fetch(url).then(response => response.json()).then(setData);
  }, [url]);

  return data;
}

// 이 커스텀 훅을 다른 함수 컴포넌트에서 사용합니다.
function UserList() {
  const users = useFetch('https://api.example.com/users');
  
  // ... JSX 렌더링
}
```