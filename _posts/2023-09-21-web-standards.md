---
layout: post
title: web standards 웹 표준
category: web
tags: kaywon
---

# web standards 웹 표준
## 표준의 개요

* cm, inch
* kg, pound
* km, mile
* 제곱미터, 평

* 명확한 기준이 없거나 서로 다른 기준을 사용한다면 혼동을 야기할 수있다.
* 기준이 있더라도 서로 다르다면 소통이 어려울 수 있다.
* 무엇인가 한가지로 통일해야 한다면 명확한 정의를 내릴 수 있는 기관이 필요하다.

---

## 웹 표준 개요
* 웹 접근성 수준을 향상시킬 수 있는 다양한 방법론의 중심
* 웹에서 표준적으로 사용되는 기술이나 규칙을 정의한 것
* W3C(World Wide Web Consortium)의 토론을 통해 나온 권고안 (recommentdation) : [https://www.w3.org/](https://www.w3.org/)
* HTML(XHTML), HTML5 / CSS, CSS3 / DOM & ECMA Script

## 웹 표준 준수의 기대효과
* 웹 접근성 수준의 향상
* 크로스 브라우징을 통한 웹 접근성 향상
* 검색 친화적인 웹 사이트 구현
* 구조와 표현의 분리
* 손쉬운 유지 보수 및 비용 절감 효과
* 호환성 확보

## 표준의 예시

* 이전에는 컴퓨터 주변기기들이 각가의 포트에 사용되었다. (표준화 되지 못함)
* 장치별로 다른 port를 사용하기 때문에. 컴퓨터에 해당 port가 없을 경우 사용이 불가능 하였다. - 호환성 문제 = 접근성 문제
* USB가 보급되면서 거의 모든 컴퓨터 주변장치들이 USB를 사용한다
* 표준화가 잘되어 있기 때문에(USB 규격을 모두 잘 지키기 때문에) 우리는 USB장치를 구입할때 호환 문제를 신경쓰지 않고서도 이용할 수 있다.

## 단계적 향상(progressive enhancement)
* 모든 사용자에게 반드시 제공해야 할 <b>정보와 기능은 기본으로 제공</b>한다.
* 좋은 성능을 가진 브라우저를 사용하는 사용자에게는 좀더 멋진 화면과 추가적인 기능을 제공한다
* 결과적으로 성능이 떨어지거나 오래된 버전의 브라우저 사용자는 어떤 기능이 생략 되었는지 조차 모른다
* 웹사이트가 모든 브라우저에서 똑같이 보여야 한다는 믿음이 단계적 향상의 걸림돌
* 웹사이트는 브라우저에 따라 다르게 보일 수도 있다 라고 인정하는것이 단계적 향상
* 각 플랫폼(PC, 타블렛, 스마트폰)이 가지고 있는 한계를 인지하고 장점을 살려서 정보전달을 더 극대화 할 수도 있다.


## 내용(content), 형태(design), 동작(function)의 분리
* 웹 사이트의 내용은 HTML로 작성
* 웹 사이트의 형태는 CSS로 작성
* 웹 사이트의 동작은 JavaScript로 작성

### HTML
```html
<html>
<head>
	<title>HTML 홈페이지</title>
</head>
<body>
	본문
</body>
</html>
```
### CSS
```css
table{
    width: 100px;
    height: 100px;
    margin: 100px;
}
#id{
    font-size: 10px;
}
.class{
    background-color: #f00;
}
```

### Javascript
```javascript
function index_page(){
    document.location.href = "index.html";
}
index_page();
```
										
* 실제로도 셋은 서로 다른 문법으로 구성되어 있고 들여오기(import) 방식으로 불러오고 제거할 수 있다.

## 웹표준에 관한 이해하기 쉬운 만화
* [웹 표준 만화](http://www.thisisgame.com/webzine/nboard/213/?n=56672)
