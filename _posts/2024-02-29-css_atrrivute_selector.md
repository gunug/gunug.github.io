---
layout: post
title: atrribute selector 특성 선택자
category: web
tags: css
---

# atrribute selector 특성 선택자

* https://developer.mozilla.org/ko/docs/Web/CSS/Attribute_selectors

```css
  /* <a> elements with a title attribute */
  /* <a> 요소 중 title 속성을 가지고 있는*/
  a[title] {
    color: purple;
  }
  
  /* <a> elements with an href matching "https://example.org" */
  /* <a> 요소 중 href 속성값이 "https://example.org"로 일치할 시 */
  a[href="https://example.org"] {
    color: green;
  }
  
  /* <a> elements with an href containing "example" */
  /* <a> 요소 중 href 속성값에 "example"이 포함되어 있을 시*/
  a[href*="example"] {
    font-size: 2em;
  }
  
  /* <a> elements with an href ending ".org" */
  /* <a> 요소 중 마지막이 ".org"로 끝날 시 */
  a[href$=".org"] {
    font-style: italic;
  }
  
  /* <a> elements whose class attribute contains the word "logo" */
  /* <a> 요소 중 class의 속성값에 "logo"라는 단어가 있을시
  a[class~="logo"] {
    padding: 2px;
  }
```