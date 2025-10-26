---
layout: post
title: syntax highlighting 구문 강조
category: coding
tags:
---

# 구문 강조(syntax highlighting)

## Prism.js
* 매우 가볍고 빠름
* CSS 테마 다양 (GitHub, Dark, Solarized 등)
* React, Vue, Markdown 등과 잘 통합됨
* C#, JS, JSX, HTML, CSS 등 모두 지원
* 플러그인 시스템으로 줄번호, 코드 복사 버튼 등 쉽게 확장 가능

```html
<link href="https://cdn.jsdelivr.net/npm/prismjs/themes/prism-tomorrow.css" rel="stylesheet" />
<script src="https://cdn.jsdelivr.net/npm/prismjs/prism.js"></script>
<script src="https://cdn.jsdelivr.net/npm/prismjs/components/prism-csharp.min.js"></script>
<pre><code class="language-csharp">Console.WriteLine("Hello World");</code></pre>
```

## React용 Wrapper
* react-syntax-highlighter (Prism 기반 테마 지원)
* prism-react-renderer (깔끔하고 커스터마이즈 쉬움)

## react-syntax-highlihter

```
npm install react-syntax-highlighter@^15.5.0
```
* react-syntax-highlighter 설치 (안정적인 15.5.0 버전)
* 15 버전은 refractor(의존성 라이브러리) v3를 자동으로 설치함
* ***install 명령어는 프로젝트의 루트 폴더에서 실행해야 합니다***

## 코드 예시

```jsx
import React from "react";
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import { atomOneDark } from "react-syntax-highlighter/dist/esm/styles/prism";


export default function CodeBlock() {
  const codeString = 
  `
  using System;
  class Hello {
    static void Main() {
      Console.WriteLine("Hello World");
    }
  }
  `;

  return (
    <SyntaxHighlighter language="csharp" style={atomOneDark} showLineNumbers>
      {codeString}
    </SyntaxHighlighter>
  );
}
```
## 코드 설명
* Prism as SyntaxHighlighter → Prism.js 엔진 기반으로 사용
* style={atomOneDark} → Prism 테마 적용
* language="csharp" → 코드 언어 지정
* showLineNumbers → 줄 번호 표시 옵션

## 사용 가능한 Prism 테마 목록

| 테마 이름 | 비고 |
|------------|------|
| `atomDark` | GitHub Dark 스타일 (v15에서 `atomOneDark` -> `atomDark`로 변경) |
| `vscDarkPlus` | VSCode Dark+ 스타일 |
| `dracula` | 어두운 보라톤 테마 |
| `solarizedlight` | 밝은 톤 테마 |
| `okaidia` | 기본 Prism 테마 중 하나 |
| `tomorrow` | 깔끔하고 중립적인 다크 테마 |
| `coy` | 밝고 대비가 강한 테마 |
| `twilight` | 부드러운 다크 모드 테마 |
| `funky` | 색감이 화려한 실험적 테마 |
| `a11yDark` | 접근성(A11Y)을 고려한 다크 테마 |

### 사용 예시

```jsx
import { Prism as SyntaxHighlighter } from "react-syntax-highlighter";
import { atomDark } from "react-syntax-highlighter/dist/esm/styles/prism";
import { vscDarkPlus } from "react-syntax-highlighter/dist/esm/styles/prism"; //VSCode 스타일
import { solarizedlight } from "react-syntax-highlighter/dist/esm/styles/prism"; //밝은 테마
import { dracula } from "react-syntax-highlighter/dist/esm/styles/prism"; //드라큘라 테마

// 언어별 import
import { javascript } from "react-syntax-highlighter/dist/esm/languages/prism";
import { jsx } from "react-syntax-highlighter/dist/esm/languages/prism";
import { html } from "react-syntax-highlighter/dist/esm/languages/prism";
import { css } from "react-syntax-highlighter/dist/esm/languages/prism";

// 언어 등록
SyntaxHighlighter.registerLanguage("javascript", javascript);
SyntaxHighlighter.registerLanguage("jsx", jsx);
SyntaxHighlighter.registerLanguage("html", html);
SyntaxHighlighter.registerLanguage("css", css);


<SyntaxHighlighter language="javascript" style={atomOneDark}>
{`const hello = "world";`}
</SyntaxHighlighter>
```


---

# 적용된 최종 소스 코드 (참고용)

```jsx
import { useState } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'
//import { Routes, Route, Link } from 'react-router-dom'; // 라우터 관련 컴포넌트 임포트
import { Routes, Route, Link } from 'react-router-dom';
import Resume from './Resume.jsx';
import Portfolio from './Portfolio.jsx';
import About from './About.jsx';
import DdayCounter from './DdayCounter.jsx';

import { PrismLight as SyntaxHighlighter } from "react-syntax-highlighter";
import { csharp } from "react-syntax-highlighter/dist/esm/languages/prism";
import { atomDark } from "react-syntax-highlighter/dist/esm/styles/prism";

SyntaxHighlighter.registerLanguage("csharp", csharp);

function App() {
  const [count, setCount] = useState(0)
  const codeString = 
  `
  using System;
  class Hello {
    static void Main() {
      Console.WriteLine("Hello World");
    }
  }
  `;

  return (
    <>
      <header>
        <DdayCounter />
      </header>
      <nav>
        <Link to="/resume">이력</Link> | {" "}
        <Link to="/portfolio">포트폴리오</Link> | {" "}
        <Link to="/about">자기소개</Link>
      </nav>
      <div className="main-content">
        <Routes>
          <Route path="/resume" element={<Resume />} />
          <Route path="/portfolio" element={<Portfolio />} />
          <Route path="/about" element={<About />} />
        </Routes>
      </div>
      <SyntaxHighlighter language="csharp" style={atomDark} showLineNumbers>
        {codeString}
      </SyntaxHighlighter>
    </>
  )
}

export default App
```
* 전체 복붙 하여 사용하지 마세요. 어떤 부분이 달랐는지 비교용 입니다.