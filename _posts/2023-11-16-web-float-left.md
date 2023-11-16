---
layout: post
title: float left 왼쪽 배열 특징
category: web
tags: css
---

# float:left의 특징
* 출처 : http://naradesign.net/wp/2008/05/27/144/
* 부모 엘리먼트 A와 자식 엘리먼트 B가 있을시에 자식 엘리먼트 B에 float:left 속성을 부여하면 부모 엘리먼트가 자식 엘리먼트를 놓치는 상황이 발생합니다

```html
<div id="A">
    <div id="B" style="float:left">
    </div>
</div>
```

## 부모객체에도 똑같이 float:left를 부여한다
* 한번 시작한 float:left가 모두에게 전이 됨으로 '''권장하지 않는다.'''

## 부모객체에 overflow:auto 또는 overflow:hidden을 부여한다
* 컨텐츠의 분량에 따라 auto는 스크롤바 생김, hidden은 컨텐츠의 잘림이 발생할 수 있다.
* Chrome 69버전에서 동작함, 70버전에서 동작하지 않는 상황 발견 (2018.10)

## 자식객체의 맨 마지막에 빈 객체를 추가하여 clear:both로 처리한다
* 가장 권장되는 방법

```css
.clear {clear:both; height:0; overflow:hidden;}
```
* 빈 객체가 높이를 갖지 않도록 하고 보이지 않도록 처리

## 부모객체의 :after 가상 선택자를 이용하여 clear:both를 부여한다
* InternetExplorer는 :before, :after 가상 선택자를 지원하지 않는다.

```css
#container {*zoom:1;} /* IE5.5~7 브라우저 대응 Hack */
#container:after {content:" "; display:block; clear:both;} 
/* 표준계열 브라우저에 대응하는 float 해제용 가상 엘리먼트의 생성 */
```
* IE 5~7 브라우저는 hasLayout이라는 고유한 성질을 갖게 되면 float을 해제하는 트리거로 작용하는 성질이 있고 zoom:1 속성이 hayLayout 이라는 성질을 갖도록 하기 때문에 IE 5~7 브라우저 고유의 특징을 이용한 해결방법

## 부모객체에 display:inline-block을 부여한다
* 표준계열 브라우저는 부모객체의 넓이가 자식의 넓이 만큼 줄어들지만, IE6~7 브라우저는 100%의 넓이를 갖게됨
* inline-block 속성을 갖게되는 요소는 인라은 요소와 마찬가지로 박스가 끝나는 지점에 약 4px 정도의 공백이 생성됨

---

# clearfix
* 현재까지 가장 권장되는 float:left 해제 방식

```css
.clearfix::after{
    content: "";
    clear: both;
    display: table;
}
```