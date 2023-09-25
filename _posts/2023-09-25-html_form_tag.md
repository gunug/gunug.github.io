---
layout: post
title: HTML form tag 폼(양식) 태그
category: web
tags: html
---

# HTML form tag 폼(양식) 태그

## form
* 입력양식의 시작
* 하나의 양식지는 하나의 form으로 이루어진다

## input 입력
* form에서의 입력은 모두 input으로 처리한다. 
* 속성(attribute)에 따라 text, password, radio, checkbox등으로 변환 가능하다
* name: 각 input값에 따른 이름으로. 양식을 전송할때 필요로 한다 (필수)
### text
* 글씨를 입력하는 창 

```html
<input name="text_value1" placeholder="영문,숫자를 입력해주세요" type="text" value="기본값"/>
```
### password
* 패스워드를 입력하는 창 

```html
<input type="password" />
```

### radio
* 라디오버튼 (단일값만 선택가능한 버튼)
* name이 같아야 동일 radio로 취급되어 단일선택이 적용된다.

```html
<input name="radio_one" value="1" type="radio" checked />
<input name="radio_one" value="2" type="radio" />
<input name="radio_one" value="3" type="radio" />
```

### checkbox
* 체크박스 (복수선택이 가능한 버튼)

```html
<input type="checkbox" checked />
<input type="checkbox" />
```

### select
* 여러가지 선택지를 만들어 놓고 선택하도록 함
* combo box 콤보박스 라고도 부름

```html
<select>
    <option>선택</option>
    <option>www.naver.com</option>
    <option>www.google.com</option>
</select>
```
### textarea
* 여러줄의 글을 입력할수 있는 입력창
* rows 줄수, cols 글자수 기준으로 초기 크기를 정할 수 있다.

```html
<textarea rows="5" cols="60"></textarea>
```
### button
* 여러가지 기능을 연결할 수 있는 버튼

```html
<input type="button" value="버튼이름" />
<!-- 기본형 -->

<source lang="javascript" line>
<button onclick="alert('테스트완료')"  value="테스트 버튼" />
<!-- 간단한 기능을 붙여봅시다 -->
```

### label 레이블

```html
<label for="check_box_1">check label</label>
<input id="check_box_1" type="checkbox" />
```

### submit 제출
* form 양식을 모두 작성한 후 발송할 수 있는 제출 버튼
* 버튼과 동일하게 생겼으나 오로지 양식의 제출만을 위해서 사용한다.

```html
<input type="submit" value="제출" />
```

## form 추가사항
* https://gunug.github.io/html_sample/form_test.html
* https://www.w3schools.com/tags/tag_input.asp

```html

<!DOCTYPE html>
<html>
<head>
</head>
<body>

			<form>
				fieldset
				<fieldset>
					legend
					<!-- fieldset 폼을 그룹화 할때 사용합니다. -->
					<!-- legend 필드셋의 이름을 작성합니다. -->
					<legend>필드셋의 이름</legend>
					필드셋의 내용
				</fieldset>
				<label for="button">button</label>
				<input type="button" value="button"/>
				<br/>
				<label for="checkbox">checkbox</label>
				<input type="checkbox" checked />
				<input type="checkbox" />
				<br/>
				<label for="color">color</label>
				<input type="color" />
				<br/>
				<label for="date">date</label>
				<input type="date" />
				<br/>
				<label for="datetime-local">datetime-local</label>
				<input type="datetime-local" />
				<br/>
				<label for="email">email</label>
				<input type="email" />
				<br/>
				<label for="hidden">hidden</label>
				<input type="hidden" />
				<br/>
				<label for="image">image</label>
				<input type="image" src="" value="test" width="50px"/>
				<br/>
				<label for="month">month</label>
				<input type="month" />
				<br/>
				<label for="number">number</label>
				<input type="number" />
				<br/>
				<label for="password">password</label>
				<input type="password" />
				<br/>
				<label for="radio">radio</label>
				<input name="radio_one" value="1" type="radio" checked />
				<input name="radio_one" value="2" type="radio" />
				<input name="radio_one" value="3" type="radio" />
				<!-- input radio의 경우는 name이 같아야 같은 종류로 판단되어 제대로 작동합니다. -->
				<br/>
				<label for="range">range</label>
				<input type="range" />
				<br/>
				<label for="reset">reset</label>
				<input type="reset" />
				<br/>
				<label for="search">search</label>
				<input type="search" />
				<br/>
				<label for="submit">submit</label>
				<input type="submit" />
				<br/>
				<label for="tel">tel</label>
				<input type="tel" />
				<br/>
				<label for="text">text</label>
				<input type="text" placeholder="영문,숫자를 입력해주세요"/>
				<br/>
				<label for="time">time</label>
				<input type="time" />
				<br/>
				<label for="url">url</label>
				<input type="url" />
				<br/>
				<label for="week">week</label>
				<input type="week" />
				<br/>
				<label for="select">select</label>
				<select>
					<option>선택</option>
					<option>www.naver.com</option>
					<option>www.google.com</option>
				</select>
				<br/>
				<label for="textarea">textarea</label>
				<textarea rows="5" cols="60"></textarea>
			</form>


</body>
</html>
```