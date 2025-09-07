---
layout: post
title: react 리액트 router 라우터
category: web
tags: simple-code
---

# 라우터 기본형
```jsx
// App4.jsx
import React from 'react';
import { BrowserRouter, Routes, Route, Link } from 'react-router-dom';
import Page1 from './pages/Page1';
import Page2 from './pages/Page2';

function App4() {
  return (
    <>
    <BrowserRouter>
      <nav>
        <Link to="/page1">페이지 1</Link> | {" "}
        <Link to="/page2">페이지 2</Link>
      </nav>
      <Routes>
        <Route path="/page1" element={<Page1 />} />
        <Route path="/page2" element={<Page2 />} />
      </Routes>
    </BrowserRouter>
    </>
  );
}

export default App4;
```

* React Router v6 이후부터 ```element={<Page1 />} ``` 형태가 표준화 되어. 이외의 다른 방법으로 컴포넌트 렌더링이 불가
* <> </> Fragment (여러 개의 자식(child) 컴포넌트나 엘리먼트를 그룹화하면서, 불필요한 DOM 노드(예: <div> 태그)를 생성하지 않는 것)
* React 컴포넌트는 항상 하나의 부모 엘리먼트만 반환할 수 있다는 규칙때문에 결과적으로 하나의 태크로 마무리 되어야한다.
* Fragment는 **"그룹화"**라는 목적은 달성하면서, **"추가적인 래퍼(Wrapper) 엘리먼트"**는 생성하지 않도록 돕는 역할. 이는 특히 테이블(table)이나 CSS Flexbox/Grid를 사용할 때 유용