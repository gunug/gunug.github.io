---
layout: post
title: CSS selector 선택자
category: web
tags: css
---

# CSS selector 선택자

## 전체 선택자
* 모든 요소를 선택하는 방법으로 "*"를 선택자로 선언한다
* 유니버설 선택자

```css
{ margin:0; padding:0; }
```

## 요소(element) 선택자
* HTML요소를 선택하는 방법
* type선택자, 태그 선택자
* h1, p, div등

```css
div {margin:0;padding:0;}
p {color:#333:front-weight:bold;text-decoration:underline;}
```

---

## 클래스(class), 아이디(id) 선택자
* XHTML요소에 class나 id속성을 부여한 경우 해당 class명이나 id명으로 접근하여 선택
* class명은 여러 번 사용할 수 있기 때문에 여러가지 요소들을 한꺼번에 선택하여 스타일을 지정할때 사용
* 특정 id값을 가지고 있는 유일한 요소에 접근하여 스타일을 지정할 때는 id선택자 형식을 사용

### 클래스(class)선택자

```css
.box {font-size:14px;color:#fff;background-color:#000;} 
.ti {font-size:20px;font-weight:normal;letter-spacing:10px;}
```

## 아이디(id)선택자
```css
#box {font-size:14px;color:#fff;background-color:#000;} 
#ti {font-size:20px;font-weight:normal;letter-spacing:10px;}
```

---

# 선택자 연습 - 소스코드
```html
<style type="text/css"> 
    /* css 주석 */
    /* *{ color: red; } */ 
</style>

<div>div 요소</div>

<style type="text/css">
    /*요소 선택자*/ 
    p{ color: blue; } 
     strong{ color: yellow; } 
</style>

<p>문단<p>
<strong>강조글</strong>
<p>문단2</p>


<style type="text/css">
    /*class, id 선택자*/ 
    #b1{ color:pink; } 
    .a2{ color:green; } 
</style>

<div id="b1"> div1 </div>
<div class="a2"> div2 </div>
<div class="a2"> div3 </div>
<div class="a2"> div4 </div>

<style type="text/css"> 
    #div1{ border: solid 1px #000; } 
</style> 
<div id="div1"> class는 중복가능, id는 불가능 </div>
```

# 가상요소(element) 선택자
* 실제로 존재하지 않는 요소를 마치 존재하는 것처럼(가상) 이용하는 방법
* 콘텐츠 영역의 앞, 뒤에 가상 콘텐츠 추가
* :before, :after, :first-line, :first-letter, 

## :first-line
* 요소의 첫번째 줄에 있는 콘텐츠만 선택하여 스타일을 지정
* 크기에 따라 유동적

## :first-letter
* 요소의 첫 글자만 선택하여 스타일을 지정

```html
<style type="text/css"> 
    #p_con1:first-line {color:red;} 
    #p_con1:first-letter {color:blue;font-size:30px;} 
</style>
<p id="p_con1">문단은 전체 문장에서 의미별로 단락을 나눌때 사용됩니다. 문단에서 가상선택자를 사용하여, 첫글자를 선택하거나 첫줄을 선택하여 스타일시트를 지정할 수 있습니다.</p>
```

* inline형 태그에서 first-line과 first-letter가 적용되지 않음
* block형 태그에서만 적용됨.

## :before, :after
* 가상의 콘탠츠를 이전이나 이후에 추가할 수 있는 선택자
* content속성에 원하는 문자열을 지정
* 스타일을 위해서 사용. 문서에 내용을 추가하는 요소로 사용하지 않도록 주의

```html
<style type="text/css"> 
    #p_con2:before {content:"시작";color:#ff00ff;display:inline;} 
    #p_con2:after {content:"끝";color:#ff00ff;display:inline;} 
</style>
<p id="p_con2"> 시작과 끝에 특정 콘텐츠를 추가합니다. 문서에 내용을 추가하는 요소로 사용하지 마세요. </p>
```

# 가상클래스 선택자
* 실제로 존재하지 않는 요소(클래스)를 마치 존재하는 것처럼(가상) 이용하는 방법
* 상황에 따라 구분
* :first-child, :link, :visited, :hover, :active, :focus
## :first-child , :last-child, :nth-child(n)
* 첫번째 자식(child)요소에만 스타일을 적용할 수 있는 선택자
* 두번째 자식요소부터는 스타일이 적용되지 않음

```html
<style type="text/css"> 
    .con:first-child{ color:red; }
    .con:last-child{color:olive; } 
</style>
<div>
    <div class="con">content1</div>
    <div class="con">content2</div>
    <div class="con">content3</div>
</div>
```

## :link, :visited, :hover, :active, :focus
* :link 방문하지 않은 링크
* :visited 방문한 링크
* :hover 마우스 오버
* :active 활성화
* :focus 포커스가 생긴 경우

```html
<style type="text/css"> 
    .anchor1:link{color:#ff0000;} 
    .anchor1:visited{color:#ffff00;} 
    .anchor1:hover{color:#ff00ff;} 
    .anchor1:active{color:#00ffff;} 
    .anchor1:focus{color:#000000;} 
</style> 
<a class="anchor1" href="http://www.google.com">구글링크</a>
```
* chrome 60.0.3112.113~61버전에서 마우스 active시 focus되어 검은색으로 글씨 표시
* 60.0.3112.113 (2017.09.25 최신버전) 하늘색으로 active가 잘 나오는 경우도 있음
* 몇몇 브라우저, 버전에서 active 대신 focus로 적용되는 경우가 있음
* safari 에서 active로 표시됨
* 최신 크롬, 익스, 엣지 focus로 표시됨

# 선택자 조합
## 하위 선택자
* 상위 요소가 포함하고 있는 모든 하위 요소에 스타일을 지정할때
* 선택자와 선택자를 공백( )으로 구분하여 선언

```html
<style type="text/css">
	.con1 span{color:red;}
</style>
<div class="con1">
	<span>content1</span><br />
	<span>content2</span><br />
	<div>content3<br />
		<span>content3_1</span><br />
		<span>content3_2</span><br />
	</div>
</div>
<span>content0_1</span><br />
<span>content0_2</span><br />
```

## 자식 선택자
* 부모 요소의 바로 다음에 있는 자식 요소에 스타일을 적용
* 선택자와 선택자를 왼쪽 부등호(>)로 구분하여 선언

```html
<style type="text/css">
	.con2 > span{color:blue;}
</style>
<div class="con2">
	<span>content1</span><br />
	<span>content2</span><br />
	<div>content3<br />
		<span>content3_1</span><br />
		<span>content3_2</span><br />
	</div>
</div>
```

## 선택자 그룹화
* 다수의 요소에 똑같은 선언을 지정할 경우
* 반복해서 작성하는 대신 선택자를 그룹화 하여 표현
* 콤마(,)사용하여 구분

```html
<style type="text/css">
	.class1,#id1{color:red;}
</style>
<div class="class1">class1 div</div>
<div id="id1">id1 div</div>
```