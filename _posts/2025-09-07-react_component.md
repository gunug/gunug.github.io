---
layout: post
title: react 리액트 component 컴포넌트
category: web
tags: simple-code
---

# 컴포넌트 예제

```jsx
//App2.jsx
import React from 'react';

// Greet 컴포넌트를 정의합니다.
function Greet(props) {
  return <h1>Hello, {props.name}!</h1>;
}

// App 컴포넌트를 정의하고 Greet 컴포넌트를 포함시킵니다.
function App2() {
  return (
    <div>
      <Greet name="Alice" />
      <Greet name="Bob" />
    </div>
  );
}

export default App2;
```

```jsx
//App3.jsx
import React from 'react';

// Greet 컴포넌트를 정의합니다.
function Greet(props) {
  return (
    <div>
      <h1>Hello, {props.name}!</h1>
      <p>Your age is {props.age}.</p>
    </div>
  );
}

// App 컴포넌트를 정의하고 Greet 컴포넌트를 포함시킵니다.
function App3() {
  return (
    <div>
      <Greet name="Alice" age={30} />
      <Greet name="Bob" age={25} />
    </div>
  );
}

export default App3;
```

* React에서 props 값을 전달할 때, 숫자를 포함한 JavaScript 값(변수, 배열, 객체, 함수 등)을 전달하려면 **JSX 중괄호 {}**를 사용
* 만약 숫자를 "30"처럼 큰따옴표로 감싸서 전달하면, React는 그 값을 숫자가 아닌 **"30"이라는 문자열(String)**로 인식