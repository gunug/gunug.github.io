---
layout: post
title: web accessibility 웹접근성 적용방법
category: web
tags: html css
---

# web accessibility 웹접근성 적용방법
* 참고: https://www.w3schools.com/html/html_accessibility.asp

## 시멘틱 HTML (Semantic HTML) 
``` html
<button>Click Me</button>
<!-- 시멘틱한, 의미가 있는 -->

<div>Click Me</div>
<!-- 시멘틱하지 못한, 의미가 없는 -->
```
* 기본적으로 버튼의 스타일이 더 적합합니다
* 스크린 리더가 버튼으로 식별할 수 있습니다.
* focusable(집중할 수있는), 입력수단(input)수단으로 판단되어 조작 가능한
* 클릭 가능
 대표사례 
* Examples of non-semantic elements: ```<div><span>``` - Tells nothing about its content.
* Examples of semantic elements: ```<form><table><article>``` - Clearly defines its content.
* div나 span은 내용에 관한 어떠한 정보도 주지 않습니다.
* form(양식지), table(도표), article(기사, 블로그 글)등은 내용에 관하여 분명하게(확실히 알 수 있도록) 정의 합니다.

## 제목 (headings Are Important) 
* ```<h1> ~ <h6>``` 까지의 제목을 정의하기 위한 태그들
* 몇몇 엔진들은 이 헤딩(heading)을 상징의 웹사이트 컨텐츠 구조와 목차로 활용합니다.
* 이런 해딩은 문서의 구조를 보여주고 각각의 색션의 관계를 표현하는데 있어서 중요합니다.
* 각각의 해딩 번호 따러 점점덜 중요한 제목을 포함합니다.
* 헤딩을 크고, 굵은 글씨를 표현하기 위해 사용하지 마세요.

## 대체 텍스트 (Alternative text) 
* 만약 당신이 몇몇 이유로 이 그림을 볼수 없게 되면 (예를 들어 느린 인터넷 환경이나, src 주소가 틀렸을경우, 또는 사용자가 스크린리더기를 통하여 페이지를 볼때) <source inline>alt``` 속성은 image를 위한 대체 텍스트를 제공합니다.
  
```html
<img src="img_chania.jpg" alt="Flowers in Chania">
```

 언어를 명확히 (Declare the Language) 
* 언어를 명시하는 것은 스크린리더기나 검색엔진을 위해서 중요합니다. 이것은 <source inline>lang```이라는 속성명으로 정의할 수 있습니다.
  
```html
<!DOCTYPE html>
<html lang="en">
<body>

...

</body>
</html>
```
* 이해하기 쉬운 명확한 언어를 사용하고 스크린 리더로 명확하게 읽을 수없는 문자는 사용하지 마십시오. 예를 들면 다음과 같습니다.
* 문장을 가능한 한 짧게 유지하십시오.
* 대시를 피하십시오. 1-3을 쓰지 말고 1 ~ 3을 쓰십시오
* 약어를 피하십시오. Feb을 쓰는 대신 February을 쓰는
* 속어를 피하십시오

 링크를 명확하게 (Write Good Links) 
* 링크는 누르게되면 어디로 이동하게 될지를 명확하게 설명해야 합니다.
* 좋은예: HTML대한 더 많은정보, 미국 패키지여행 구매하기, 건강한 식습관 상세정보
* 버튼, 클릭하세요, 더보기, 여기를 누르세요, 정보


## 링크타이틀 지정하기 (Link Titles) 
* 기존 anchor ```<a>``` 태그에 ```title```을 지정하여 추가 정보를 명시 할 수 있습니다.
* 이렇게 입력한 정보는 링크를 클릭하기 전 마우스를 올리면 화면에 표시됩니다.
  
```html
<a href="https://www.w3schools.com/html/" title="Go to W3Schools HTML section">Visit our HTML Tutorial</a>
```
