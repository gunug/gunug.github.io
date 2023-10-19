---
layout: post
title: box model 박스모델
category: web
tags: css
---

# box model 박스모델
* 브라우저는 모든 태그를 작은 박스로 취급
* 그 안의 텍스트, 이미지등을 포함하는 여느 태그 처럼 무언가를 포함한 박스


## 블록 요소의 여백적용
```html
<div style="background-color:green; margin:20px; padding:20px;">
	container
	<div style="background-color:lime; margin:20px; padding:20px;">
		content
	</div>
</div></source>
<div style="background-color:green; margin:20px; padding:20px;">
	container
	<div style="background-color:lime; margin:20px; padding:20px;">
		content
	</div>
</div>
```
[[파일:Blockmodel sample.jpg]]

## 호환모드에서 박스모델
* DTD 설정에 따른 박스모델의 표현법이 다름
* XHTML 문서가 웹 브라우저에서 표준모드로 렌더링 될 경우와 호환모드로 렌더링 될 경우 CSS의 박스 모델이 다르게 적용됨

```html
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml/DTD/xhtml1-transitional.dtd">
<!-- 문서 첫 번째 줄에 DTD를 올바르게 선언하지 않으면 IE6이하 버전의 웹 브라우저에서 호환 모드로 렌더링함 -->
```

## 표준 모드에서 블록요소 넓이 계산
* 실제 가로 사이즈 = width + margin + border + padding
* 실제 세로 사이즈 = height + margin + border + padding

## width, height
```html
<div style="background-color:#bdf; width:100px;">
	width:100px;
</div>
<div style="background-color:#bdf; height:50px;">
	height:50px;
</div>
<div style="background-color:#bdf; width:150px; height:50px;">
	width:150px; height:50px;
</div>
```

## padding
```html
<div style="background-color:#bdf; padding:50px;">
	padding:50px;
</div>
<div style="background-color:#bdf; padding-left:50px;">
	padding-left:50px;
</div>
<div style="background-color:#bdf; 
	padding-left:10px; padding-top:20px; 
	padding-right:30px; padding-bottom:40px;">
	padding-left:10px; padding-top:20px;
	padding-right:30px; padding-bottom:40px;
</div>
```

## margin
```html
<div style="background-color:#bdf; margin:50px;">
	margin:50px;
</div>
<div style="background-color:#bdf; margin-left:50px;">
	margin-left:50px;
</div>
<div style="background-color:#bdf; 
	margin-left:10px; margin-top:20px; 
	margin-right:30px; margin-bottom:40px;">
	margin-left:10px; margin-top:20px;
	margin-right:30px; margin-bottom:40px;
</div>
```

### 마진 겹침 현상(margin collapsing)
* 세로 방향으로 마진이 만났을 경우 겹치는 현상
* 마진이 하나로 합쳐질 때 두개의 마진 값 중에서 큰 값으로 적용

```html
<div style="border:solid 1px #00ff00">
	<div style="margin:50px; border:solid 1px #ff0000;">margin 50px</div>
	<hr />
	<div style="margin:30px; border:solid 1px #ff0000;">margin 30px</div>
</div>
```
<div style="border:solid 1px #00ff00">
	<div style="margin:50px; border:solid 1px #ff0000;">margin 50px</div>
	<hr />
	<div style="margin:30px; border:solid 1px #ff0000;">margin 30px</div>
</div>

```html
<div style="border:solid 1px #00ff00">
	<div style="margin:50px; border:solid 1px #ff0000;">margin 50px</div>
	<div style="margin:30px; border:solid 1px #ff0000;">margin 30px</div>
</div>
```
<div style="border:solid 1px #00ff00">
	<div style="margin:50px; border:solid 1px #ff0000;">margin 50px</div>
	<div style="margin:30px; border:solid 1px #ff0000;">margin 30px</div>
</div>