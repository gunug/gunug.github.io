---
layout: post
title: viewport 뷰포트
category: web
tags: 
---
# Meta Viewport
* 출처: https://www.w3schools.com/css/css_rwd_viewport.asp

## 뷰포트란?
* 뷰포트는 웹 페이지에서 사용자가 볼 수 있는 영역이다.
* 뷰포트는 장치마다 다르며 보통 컴퓨터 화면보다 모바일에서 더 작다.
* 태블릿이나 스마트폰이 있기 이전, 웹 페이지는 컴퓨터 화면 전용으로 디자인 되었고 고정 된 디자인과 고정된 크기를 갖는 것이 일반적이었다.
* 이런 환경에서 태블릿이나 스마트폰을 사용할경우 고정 크기 웹 페이지가 너무 커서 뷰포트에 맞지 않았다.
* 뷰포트가 없던 환경에서 브라우저를 단지 사이즈를 줄여서 디바이스 화면 크기에 맞추는 것은 효과적이지 못하였다. (글씨크기가 너무 작아 읽지 못하거나 링크를 클릭하지 못하는등)

## 뷰포트 주의사항
* 뷰포트에 맞도록 콘텐츠 크기 조정 : 사용자는 데스크톱과 모바일장치 모두에서 웹사이트를 세로로 스크롤하지만 가로로는 스크롤하지 않는다.
* 따라서 사용자가 전체 웹 페이지를 보기위해 가로로 스크롤해야 하거나 축소, 확대 해야 한다면 사용자 경험(UX)이 저하된다.
* 큰 고정 너비 요소를 사용하지 않는다
    * 이미지가 뷰포트보다 넓은 너비로 표시되면 뷰포트가 수평으로 스크롤 될 수 있다.
    * 콘텐츠를 뷰포트의 너비에 맞도록 조정해야한다.
* 콘텐츠가 잘 렌더링 되도록 특정 뷰포트 너비에 의존하지 않는다
    * CSS 픽셀의 화면 크기와 너비는 장치마다 크게 다르므로 콘텐츠가 잘 렌더링 되기 위해 특정 뷰포트 너비에 의존하면 안된다.
* CSS 미디어 쿼리를 사용하여 작은 화면과 큰화면에 다른 스타일을 적용 한다.
    * 페이지 요소에 대하여 큰 절대 CSS 너비를 설정하면 더 작은 뷰포트에서 요소가 너무 크게 적용된다.
    * 따라서 절대 너비 보다는 100%와 같은 상대적 너비를 사용하는것이 좋다.
    * 절대위치 값이 큰 경우는 뷰포트가 작은 장치에서 뷰포트 외부로 벗어날 수 있다.

## 문법 및 속성값
```html
<meta name="viewport" content="width=device-width,initial-scale=1.0" />
```
* meta tag에 Viewport에 대한 별 내용이 없으면 기본적으로 웹 페이지는 980px을 기준으로 렌더링 한다. 
* 하지만 글자의 가독성이 떨어지므로 장비별로 가독성이 가장 좋은 device-width를 Viewport에 세팅할 수 있는 옵션이 존재한다. 
* 위의 옵션 정의 후, 장비별 device-width로 페이지가 렌더링 된다.

## 속성값
* user-scaleable=no : 유저가 핀치 투 줌으로 스케일링을 할 수 있는지의 여부
* width : viewport의 가로 크기를 조정한다. 일반적인 숫자값이 들어갈 수도 있고, device-width와 같은 특정한 값을 사용할 수도 있다. device-width는 100% 스케일에서 CSS 픽셀들로 계산된 화면의 폭을 의미한다.
* height : viewport의 세로 크기를 조정한다.
* initial-scale : 페이지가 처음 로딩될 때 줌 레벨을 조정한다. 값이 1일때는 CSS 픽셀과 기기 종속적인 픽셀 간의 1:1 관계를 형성한다.
* minimum-scale : viewport의 최소 배율값, 기본값은 0.25이다.
* maximum-scale : viewport의 최대 배율값, 기본값은 1.6이다.
* user-scalable : 사용자의 확대/축소 기능을 설정, 기본값은 yes이다.

## 받아올 수 있는 값
* device-width : 기기의 가로 넓이 픽셀 값 (웹페이지의 가로(width) 값은 기기가 사용하는 가로 넓이 값(device-width) 만큼 적용하여 사용하라는 의미)
* device-height : 기기의 세로 높이 픽셀 값

## 주의사항
* contents보다 작은 viewport width/height를 설정하면 무시된다.
* viewport에서 initial-scale을 설정하지 않고 width/height를 설정하면 전체화면이 표시된다.
* viewport에서 initial-scale도 width/height도 설정하지 않으면 width=980px/height=1091px이 된다.
* 표시영역과 contents의 크기가 일치하지 않을때 initial-scale를 설정하면, 의도하지 않은 layout이 발생한다.

*참고 : https://jongmin92.github.io/2017/02/09/HTML/viewport/