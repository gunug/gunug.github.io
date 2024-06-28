---
layout: post
title: Responsive Web 반응형 웹
category: web
tags: 
---

# Responsive Web 반응형 웹
# 반응형 웹 개요

* 출처 : https://ko.wikipedia.org/wiki/%EB%B0%98%EC%9D%91%ED%98%95_%EC%9B%B9_%EB%94%94%EC%9E%90%EC%9D%B8
* 출처 : https://www.samsungsds.com/global/ko/support/insights/Responsive_web_1.html
* 출처 : https://www.samsungsds.com/global/ko/support/insights/Responsive-Web-2.html
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719547613.jpg" />

* 하나의 웹사이트에서 PC, 스마트폰, 태블릿 PC 등 접속하는 디스플레이의 종류에 따라 화면의 크기가 자동으로 변하도록 만든 웹페이지 접근 기법
* 웹사이트를 PC용과 모바일용으로 각각 별개로 제작하지 않고, 하나의 공용 웹사이트를 만들어 다양한 디바이스에 대응
* PC용 URL과 모바일용 URL이 동일하기 때문에 검색 포털 등 광고를 통한 사용자 접속을 효율적으로 관리
* 웹 페이지 내용을 수정할 경우, 하나의 페이지만 수정하면 PC와 모바일 등 다양한 디바이스에서 동일하게 반영
* 반응형 웹의 핵심 기술은 가변 그리드(fluid grid), 유연한 이미지(flexible images), 미디어 쿼리(media query)
* 반대말은 디바이스별로 별도의 웹사이트를 제작하는 적응형 웹(adaptive web)이다.
## 예시 사이트
* http://mediaqueri.es (모음)
* http://rwdb.kr/(모음)
* http://mediaqueri.es/san/ 
* https://www.squarespace.com 
* http://foodsense.is 
* http://colly.com

## 참고사이트
* w3schools : https://www.w3schools.com/css/css_rwd_intro.asp
* google 반응형 웹 디자인 기본사항 : https://developers.google.com/web/fundamentals/design-and-ux/responsive?hl=ko - 링크 복구 예정

## 반응형 웹의 형태
* 반응형 웹 템플릿 : https://www.w3schools.com/css/css_rwd_templates.asp

## 반응형 웹 디자인 패턴
* 출처: https://developers.google.com/web/fundamentals/design-and-ux/responsive/patterns?hl=ko
* 유동형(Mostly Fluid) : 각각의 화면해상도에 맞는 레이아웃 형태를 계획하여 그 모양에 맞추어 나가는방식
* 열 끌어놓기(Column Drop)
* 레이아웃 시프터(Layout shifter)
* flexbox : https://developer.mozilla.org/ko/docs/Web/CSS/CSS_Flexible_Box_Layout/Basic_Concepts_of_Flexbox
* 미세 조정(Tiny tweaks)
* 오프 캔버스(Off canvas)

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
``` <meta name="viewport" content="width=device-width,initial-scale=1.0" /> ```
* meta tag에 Viewport에 대한 별 내용이 없으면 기본적으로 웹 페이지는 980px을 기준으로 렌더링 한다. 
* 하지만 글자의 가독성이 떨어지므로 장비별로 가독성이 가장 좋은 device-width를 Viewport에 세팅할 수 있는 옵션이 존재한다. 
* 위의 옵션 정의 후, 장비별 device-width로 페이지가 렌더링 된다.
### 속성값
* user-scaleable=no : 유저가 핀치 투 줌으로 스케일링을 할 수 있는지의 여부
* width : viewport의 가로 크기를 조정한다. 일반적인 숫자값이 들어갈 수도 있고, device-width와 같은 특정한 값을 사용할 수도 있다. device-width는 100% 스케일에서 CSS 픽셀들로 계산된 화면의 폭을 의미한다.
* height : viewport의 세로 크기를 조정한다.
* initial-scale : 페이지가 처음 로딩될 때 줌 레벨을 조정한다. 값이 1일때는 CSS 픽셀과 기기 종속적인 픽셀 간의 1:1 관계를 형성한다.
* minimum-scale : viewport의 최소 배율값, 기본값은 0.25이다.
* maximum-scale : viewport의 최대 배율값, 기본값은 1.6이다.
* user-scalable : 사용자의 확대/축소 기능을 설정, 기본값은 yes이다.

### 받아올 수 있는 값
* device-width : 기기의 가로 넓이 픽셀 값 (웹페이지의 가로(width) 값은 기기가 사용하는 가로 넓이 값(device-width) 만큼 적용하여 사용하라는 의미)
* device-height : 기기의 세로 높이 픽셀 값

#### 주의사항
* contents보다 작은 viewport width/height를 설정하면 무시된다.
* viewport에서 initial-scale을 설정하지 않고 width/height를 설정하면 전체화면이 표시된다.
* viewport에서 initial-scale도 width/height도 설정하지 않으면 width=980px/height=1091px이 된다.
* 표시영역과 contents의 크기가 일치하지 않을때 initial-scale를 설정하면, 의도하지 않은 layout이 발생한다.

* 참고 : https://jongmin92.github.io/2017/02/09/HTML/viewport/

# Grid View : 12단 그리드 방식
* 출처 : https://www.w3schools.com/css/css_rwd_grid.asp
```
 .col-1 {width: 8.33%;}
 .col-2 {width: 16.66%;}
 .col-3 {width: 25%;}
 .col-4 {width: 33.33%;}
 .col-5 {width: 41.66%;}
 .col-6 {width: 50%;}
 .col-7 {width: 58.33%;}
 .col-8 {width: 66.66%;}
 .col-9 {width: 75%;}
 .col-10 {width: 83.33%;}
 .col-11 {width: 91.66%;}
 .col-12 {width: 100%;}
 [class*="col-"] {
  float: left;
  padding: 15px;
  border: 1px solid red;
 }
* [class^="status-"] — starts with "status-"
* [class*=" status-"] — contains the substring "status-"
* class^ : 해당이름으로 시작하는 클래스명
* class* : 해당이름이 들어가 있는 클래스명

 <div class="row">
  <div class="col-3">...</div> <!-- 25% -->
  <div class="col-9">...</div> <!-- 75% -->
 </div>
 .clearfix::after {
  content: "";
  clear: both;
  display: table;
 }
```
# CSS3, Media Query
* 하나의 웹페이지에 CSS를 분기하여 각각 다른 스타일을 갖도록 하는것
* 참고 : https://www.w3.org/TR/mediaqueries-4/

## 기기별 사이즈 내역
* 모바일 320px ~ 767px
* 타블렛 768px ~ 1023px or 1199px
* PC 1200px 이상 or 1024px 이상
* http://styleguide.co.kr/index.php : 디자인 스타일 가이드

## 지원 브라우저
* 지원 브라우저 확인 : https://caniuse.com/?search=%40media
* ie9+,chrome21+,firefox3.5+,safari4.0+,opera9+
## 사용방법
#### 내부
```
 @media (max-width:700px){
   .container{
     margin:0px;
   }
 }
```
### 외부
```
 <link rel="stylesheet" media="(max-width:700px)" href="target.css" />
```
## 미디어쿼리 문법
* 미디어쿼리는 대소문자를 구분하지 않음
```
 @media​ [미디어쿼리지원여부​] ​[대상미디어]​ [​논리적연산]​ ​(​조건문 Media Features)​ {실행문 CSS구문}
 @media [not,only] [all,print,screen,speech] [and,or] (width,height,aspect-ratio,orientation,color) {css}
 <link rel="stylesheet" media="(max-width: 400px)" href="mobile.css" />
```
* ```@media​ only​ ​all​ ​and​ ​(​min-width: 800px​)​ { … }```

* @media : 미디어 쿼리가 시작됨 (선언)
* only : 미디어 쿼리를 지원하는 웹 브라우저만 이 구문을 해석하라는 명령. 기본값이 only 이므로 생략 가능. 이 자리에 not 을 사용할 수도 있다.
* all : 미디어 쿼리를 해석해야 할 대상 미디어.  all(모든장치), print(인쇄장치), screen(스크린장치), speech(화면 낭독기) 가 현재 적용 가능. 생략 가능
* 추가로 aural, braille(점자), embossed, handheld(휴대용), projection, tty, tv. 등이 있으나 기기의 모호함이나 퇴화 등으로 점차 사용되지 않을전망
* and : 논리적 연산. and 연산은 앞과 뒤의 조건을 모두 만족해야 한다는 의미. or 연산은 앞뒤 조건 중 하나의 조건만 만족해도 된다는 의미.
* (min-width: 800px) : 조건문. 최소 크기 800 픽셀부터 (즉, 800픽셀 이상 부터) 조건이 참(true) 이 된다.
* { … } : 실행문. 조건문이 참이면 실행문 부분이 실행된다. 실행문 내부는 CSS의 일반적인 작성 방법과 같다.

* 참고: https://www.w3schools.com/css/css3_mediaqueries_ex.asp

### 미디어쿼리 주의사항
* #link 태그에 미디어 쿼리를 설정할 수 있으나 성능면에서 권장하진 않는다.
* ```<link rel=”stylesheet” media=”all and (조건A)” href=”A.css”>```
* ```<link rel=”stylesheet” media=”all and (조건B)” href=”B.css”>```
* 미디어 쿼리를 지원하지 않는 구형 모바일 브라우저를 위해 "모바일 퍼스트" 전략을 사용하는 것을 고려해 볼 수 있다.
* 구형 IE 브라우저(6~8)를 사용자를 위한 처리
* https://github.com/scottjehl/Respond 를 다운로드한 후 경로를 수정하여 아래와 같이 설정한다.
```
 <!--[if lt IE 9]>
 <script type="text/javascript" src="../js/respond.min.js"></script>
 <![endif]-->
```
*또는 아래와 같이 CDN 방식으로…
```
 <!--[if lt IE 9]>
 <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
 <![endif]-->
```
* 이 respond.js 는 로컬 웹브라우저에서는 동작하지 않음

### CSS2에서 CSS3로의 변화 Point
* 가장 큰 변화는 selector의 변화
* div[id^="bar"]처럼 id가 bar로 시작하는 div 엘리먼트 또는, 
* div[id$="end"]처럼 id가 end로 끝나는 div 엘리먼트를 찾을 수 있는 selector 가능
* 백그라운드 이미지 여러 개 사용 가능
* 박스 모델 적용
* 미디어 쿼리 적용
* 이 외에도 많은 사람들이 “모던 브라우저의 시작은 CSS3”라고 할 정도로 다양한 변화들이 있었습니다.

### 미디어 쿼리 예제

```html
 <!DOCTYPE html>
 <html>
     <head>
        <title>media query</title>
        <meta name="viewport" content="width=device-width,initial-scale=1.0" />
        <style>
            /*
                 모바일 320px ~ 767px
                 타블렛 768px ~ 1023px or 1199px
                 PC 1200px 이상 or 1024px 이상
            */
            body{background-color: green;}
            @media screen and (max-width: 1920px) {
                body{background-color: blue;}
            }
            @media screen and (max-width: 1023px){
                body{background-color: red;}
            }
            @media screen and (max-width: 767px){
                body{background-color: yellow;}
            }
        </style>
     </head>
     <body>
 	
     </body>
 </html>
```

* 참고 : http://www.nextree.co.kr/p8622/

```html
 /* 스마트폰 가로+세로 */
 @media only screen and (min-device-width : 320px) and (max-device-width : 480px){
 }
 
 /* 스마트폰 가로 */
 @media only screen and (min-width : 321px) {
 }
 
 /* 스마트폰 세로 */
 @media only screen and (max-width : 320px) {
 }
 
 /* iPhone4와 같은 높은 크기 세로 */
 @media
 only screen and (-webkit-min-device-pixel-ratio : 1.5),  
 only screen and (min-device-pixel-ratio : 1.5) {  
 }
 
 /* iPhone4와 같은 높은 해상도 가로 */
 @media only screen and (min-width : 640px) {
 }
 
 /* iPad 가로+세로 */
 @media only screen and (min-device-width : 768px) and (max-device-width : 1024px) {
 }
 
 /* iPad 가로 */
 @media only screen and (min-device-width : 768px) and (max-device-width : 1024px) and (orientation : landscape) {
 }
 
 /* iPad 세로 */
 @media only screen and (min-device-width : 768px) and (max-device-width : 1024px) and (orientation : portrait) {
 }
 
 /* 데스크탑 브라우저 가로 */
 @media only screen and (min-width : 1224px) {
 }
 
 /* 큰 모니터 */
 @media only screen and (min-width : 1824px) {
 }
```

# Image

* 참고 : https://www.w3schools.com/css/css_rwd_images.asp

```html
 /* For width smaller than 400px: */
 body {
  background-image: url('img_smallflower.jpg');
 }

 /* For width 400px and larger: */
 @media only screen and (min-width: 400px) {
  body {
    background-image: url('img_flowers.jpg');
  }
 }
```

# 반응형웹 프레임워크
* Bootstrap : https://getbootstrap.com/
* Foundation : https://foundation.zurb.com/
* Bulma : https://bulma.io/
* UI Kit : https://getuikit.com/
* Semantic UI : https://semantic-ui.com/

## 부트스트랩 (boot strap)

* 출처 : https://masterdomon.tistory.com/121

* 반응형, 모바일, HTML, CSS, Javascript 프레임워크 
* 공식 웹사이트 ​http://getbootstrap.com  
* 한글 웹사이트 ​http://bootstrapk.com  
 
* 트위터에서 제작하고 공개. 특정 서비스의 랜딩 페이지(landing page), 또는 컨텐츠 분량이 적은 웹사이트 제작에 많이 사용됨. 
* 사용법에 익숙해지면 굉장히 빠른 속도로 웹 사이트를 제작할 수 있음. 웹 사이트 전체를 만들 수 있는 프레임워크이다 보니 부트스트랩 기반으로 하나의 웹 사이트 전체가 만들어져 무료로 공개 또는 판매되는 템플릿도 상당히 많이 존재함 (예: ​http://startbootstrap.com​ ) 
 
* 2017년 11월 현재 버전 4가 정식 런칭 "한번도 안써본 퍼블리셔는 있을 수 있어도 한번만 써본 퍼블리셔는 없다" 
 
* 부트스트랩 테마 ​https://themes.getbootstrap.com/  
  
### 부트스트랩으로 제작된 웹사이트 ​

* https://expo.getbootstrap.com/  
* https://overv.io  
* http://www.vogue.com  
* http://indicius.com 
* 부트스트랩으로 만든 관리자 프레임웍 ​https://adminlte.io

# 반응형 웹 레이아웃 예제
* 참고사이트 : * http://www.nextree.co.kr/p8622/
* 구조 예시 스크린샷 포함된 PTT : https://www.slideshare.net/theresaneil/mobile-design-strategic-solutions/55-Responsive_Design_Layout_Patterns_Mostly

# 저장된 자료
* http://www.onethelab.com/sample_html/responsive_web_sample.html
