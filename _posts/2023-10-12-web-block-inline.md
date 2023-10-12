---
layout: post
title: block element 블록요소, inline element 인라인요소
category: web
tags: html
---

# block element 블록요소, inline element 인라인요소

## 블록 요소 (Block element)
* 독립적인 형태의 상자
* h1~h6, p, div
* 인라인 요소, 텍스트, 또다른 블록 레벨 요소를 포함할 수 있다
* 블록요소와 블록요소의 사이에는 기본적으로 여백이 있는데. 브라우저마다 다를 수 있음

## 블록 요소의 기본적인 여백
* position : 실제 위치 (left, right, top, bottom)
* margin : 바깥 여백 (margin, margin-left, margin-right, margin-top, margin-bottom)
* border : 외곽선 (border)
* padding : 내부 여백 (padding, padding-left, padding-right, padding-top, padding-bottom)

## 인라인 요소 (inline element)
* 블록 상자 안의 일부
* a, img, em, strong, span
* 텍스트 그 자체도 inline요소에 해당
* 인라인 요소는 텍스트나 인라인 요소를 포함할 수 있다.
* 블록 요소를 포함할 수 없다
* 반드시 블록 레벨 요소에 포함시켜 표현
* 즉, body 요소의 바로 하위에는 블록레벨요소만 자식요소로 올수 있다

```html
인라인 요소들은 글 내에서 자유롭게 줄내림 가능한 특징을 가지고 있습니다.
<a style="border: solid 1px #000000" href="www.google.com" target="_blank">클릭하면 구글로 이동할 수 있습니다.</a>
<img style="border: solid 1px #000000; width:30px; height:30px;" src="/kaywon/img/chrome_logo.png" />
<em style="border: solid 1px #000000">기울임체를 이용하여 특정 내용을 도드라지게 보이게 할 수 있습니다.</em>
<strong style="border: solid 1px #000000">강조는 볼드체(bold)를 이용하여 특정 내용을 강조하여 보여줍니다.</strong>
<span style="border: solid 1px #000000">묶음은 겉으로 보기에는 큰 차이가 없으나 특정 내용을 한데 모을 수 있습니다. (표현방식을 바꾸지 않아도 글내용 묶음이 가능함)</span>
```

## 인라인 요소(inline element)와 블록 요소(block element)의 활용
```html
<div style="border: solid 1px #000000; width:480px; height:120px; position:relative;">
	<div style="border: solid 1px #000000; width:100px; height:100px; left:10px; top:10px; position:absolute;">
		블록요소 안쪽에 바로 텍스트 요소가 들어가는 경우
	</div>
	<div style="border: solid 1px #000000; width:100px; height:100px; left:130px; top:10px; position:absolute;">
		<em>블록요소 안쪽에 인라인 요소 가 들어가는 경우</em>
	</div>
	<div style="border: solid 1px #000000; width:100px; height:100px; left:250px; top:10px; position:absolute;">
		<div style="border: solid 1px #000000; width:90; height:90; left:0; top:0; position:absolute;">
			블록요소 안에 블록요소가 들어가는 경우
		</div>
	</div>
	<div style="border: solid 1px #000000; width:100px; height:100px; left:370px; top:10px; position:absolute;">
	</div>
</div>
```
