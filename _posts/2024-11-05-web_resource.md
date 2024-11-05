---
layout: post
title: 웹관련 수업자료
category: web
tags: 
---

# 웹관련 수업자료
```html
<!DOCTYPE html>
<html>
	<head>
		<title>html 기본형태</title>
		<meta charset="utf-8" />
		<style></style>
		<script></script>
	</head>
	<body>
		<!-- html5 태그 header, footer, nav, section, article, aside -->
		<header></header>
		<nav></nav>
		<section>
			<article></article>
			<article></article>
			<article></article>
		</section>
		<aside></aside>
 		<footer></footer>
	</body>
</html>
```

---

# 반응형 웹
```html
<!DOCTYPE html>
<html>
    <head>
        <title>반응형</title>
        <meta charset="utf-8" />
        <meta name="viewport" 
        content="width=device-width,initial-scale=1.0" />
        <style>
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
            div{border: solid black 1px;}
            body{background-color: lightblue;}
            /* 최대 넓이가 700px 이상이라면*/
            /* 최대 넓이가 : 700px (이하라면)*/
            /*2K이상 대화면 (1920~)*/
            @media (max-width:1920px){
                /* FHD(1920*1080) PC, 노트북 */
                body{background-color: blue;}
            }
            @media (max-width:1024px){
                /* HD(1024*768) 타블렛 */
                body{background-color: olive;}
            }
            @media (max-width:768px){
                /* 스마트폰 */
                body{background-color: red;}
            }
            div[class^="col"]{
                background-color: aqua;
            }
            div[class*="-"]{
                color: red;
            }
            /* ^ 시작단어, $ 끝단어, * 포함 */
            #image_frame{
                background-image: url("dog_big.png");
                width: 100%;
                height: 300px;
                background-size: cover;
                background-position: 50% 100%;
            }
            @media (max-width:1000px){
                #image_frame{
                    background-image: url("dog_small.png");
                }
            }
        </style>
    </head>
    <body>
        내용
        <div class="col-12">col-12</div>
        <div class="col-6">col-6</div>
        <div class="col-3">col-3</div>
        <div id="image_frame"></div>

        <style>
            #min_max{
                min-width: 200px; /* 최소넓이 */
                max-width: 800px; /* 최대넓이 */
                background-color: beige;
                border-radius: 5px 10px 15px 20px;
            }
        </style>
        <div id="min_max">min_max</div>
        <style>
            #text_shadow{
                text-shadow: 1px 1px 1px red;
                background-color: white;
            }
        </style>
        <div id="text_shadow">text_shadow</div>

        <style>
            #text_color1{color:red;}
            #text_color2{color:#f100b1;}
            #text_color3{color:rgb(30%,80%,10%);}
            #text_color4{color:hsl(27,88%,58%);}
        </style>
        <div id="text_color1">text_color1</div>
        <div id="text_color2">text_color2</div>
        <div id="text_color3">text_color3</div>
        <div id="text_color4">text_color4</div>
        <style>
            #transition_div{
                color:gray;
                width: 100px;
                background-color: white;
                transition: color 1s, width 1s, 
                background-color 1s;
            }
            #transition_div:hover{
                color:orange;
                width: 500px;
                background-color:burlywood;
            }
        </style>
        <div id="transition_div">transition_div</div>
    </body>
</html>
```

---

# javascript scroll
```html
<!DOCTYPE html>
<html>
  <head>
      <title></title>
      <style>
          #scroll_metter{
              position: fixed;
              right: 0px;
              background-color: white;
              border: solid 1px black;
              z-index: 10;
          }
          #sample_div{
              height: 1800px;
          }
          .block{
              position: absolute;
              background-color: red;
              width: 100px;
              height: 100px;
              transition: background-color 1s, width 1s, height 1s, border-radius 1s;
          }
          .blue{
              background-color: blue;
              width: 300px;
              height: 300px;
              border-radius: 50px;
          }
      </style>
  </head>
  <body onscroll="change_scroll()">
      <div id="scroll_metter">0</div>
      <div id="sample_div">
          <div class="block" style="top:500px;">block</div>
          <div class="block" style="top:1000px;">block</div>
          <div class="block" style="top:1500px;">block</div>
          <div class="block" style="top:2000px;">block</div>
          <div class="block" style="top:2500px;">block</div>
          <div class="block" style="top:3000px;">block</div>
      </div>
      <script>
          var sample_div = document.getElementById("sample_div");
          //alert(sample_div.scrollTop);
          //alert(sample_div.offsetTop);
          var blocks = document.getElementsByClassName("block");
          for(var i=0; i<blocks.length; i++){
              var this_block = blocks[i];
              this_block.innerHTML = this_block.offsetTop;
          }

          var scroll_metter = document.getElementById("scroll_metter");
          var intFrameHeight = window.innerHeight;
          var range = 200;
          function change_scroll(){
              //scroll_metter.innerHTML = document.body.scrollTop;
              scroll_metter.innerHTML = document.documentElement.scrollTop;
              var screen_center = document.documentElement.scrollTop+window.innerHeight/2;
              for(var i=0; i<blocks.length; i++){
                  var this_block = blocks[i];
                  if(this_block.offsetTop <= screen_center+range && this_block.offsetTop >= screen_center-range){
                      this_block.classList.add("blue");
                  }else{
                      this_block.classList.remove("blue");
                  }
              }
          }
      </script>
  </body>
</html>
```

---

#variable
```html
<style>
    div{border:solid;}
</style>
<div id="test_div">test</div>
<script>
    var bbb = "test_div";
    var a1 = document.getElementById(bbb);
    var a2 = document.getElementById("test_div");
    a2.style.backgroundColor  = "red";
    var color_name = "yellow";
    color_name = "red";
    document.getElementById("test_div").style.backgroundColor  = color_name;

    function change_color(c_name){
        document.getElementById("test_div").style.backgroundColor  = c_name;
    }
</script>

<button onclick="change_color('blue')">change color blue</button>
<button onclick="change_color('yellow')">change color yellow</button>
```

---

# 기말평가 베이스 소스
```html
<!DOCTYPE html>
<html>
    <head>
        <title>기말평가</title>
        <meta charset="utf-8" />
        <meta name="viewport" content="width=device-width, initial-scale=1.0"/>
        <style>
            body{
                /*767px 이하 = 기본환경 = 스마트폰*/
                background-color: lightpink;
                margin: 0px;
            }
            #title{
                background-color: darkblue;
                color:white;
                font-size: 40px;
                text-align: center;
            }
            #respon1 div{
                float:left;
                width: 100%;
            }
            #respon2{
                display: flex; /* 화면출력: 유연하게 */
                flex-flow: row wrap; /* 유연한-흐름: 행 줄내림 */
            }
            #respon2 div{
                width: 100%;
            }
            #respon3{
                display: flex;
                flex-flow: row wrap;
            }
            #respon3 div{
                width: 100%;
            }
            #respon3 #content_left{
                background-color: hotpink;
            }
            #respon3 #content_right{
                background-color: lightsalmon;
            }
            #respon3 #content1{
                background-color: lightslategrey;
            }
            #respon3 #content2{
                background-color:lightgreen;
            }
            #respon1 #content1{
                background-color:darksalmon;
            }
            #respon1 #content2{
                background-color:floralwhite;
            }
            #respon1 #content3{
                background-color:khaki;
            }
            #respon2 #content1{
                background-color:darksalmon;
            }
            #respon2 #content2{
                background-color:floralwhite;
            }
            #respon2 #content3{
                background-color:khaki;
            }
            .clearfix::after{
                content:"";
                clear:both; /*float 해제: 양쪽*/
                display:table;
            }
            #respon1 div, #respon2 div, #respon3 div{
                min-height: 150px;
            }
            @media only screen and (min-width:767px){
                /*적어도 767픽셀은 되어야 한다 = 767픽셀 이상 = 타블렛*/
                body{
                    background-color: lightskyblue;
                }
                #title{
                }
                #respon1 #content1{ width: 40%; }
                #respon1 #content2{ width: 60%; }
                #respon1 #content3{ width: 100%; }

                #respon2 #content1{ width: 40%; }
                #respon2 #content2{ width: 60%; }
                #respon2 #content3{ width: 100%; }

                #respon3 #content_left{ width: 20% }
                #respon3 #content_right{ width: 80% }
            }
            @media only screen and (min-width:1024px){ /*컴퓨터*/
                body{
                    background-color:lightyellow;
                }
                #title{
                    font-size: 80px;
                    letter-spacing: 40px;
                }
                #respon1 #content1{ width: 30%; }
                #respon1 #content2{ width: 40%; }
                #respon1 #content3{ width: 30%; }

                #respon2 #content1{ width: 30%; }
                #respon2 #content2{ width: 40%; }
                #respon2 #content3{ width: 30%; }
            }
            @media only screen and (min-width:1920px){ /*FHD이상 = 2k, 4k*/
                body{
                    background-color: lightseagreen;
                }
                #title{
                    width: 1920px;
                    margin-left: auto;
                    margin-right: auto;
                }
            }
        </style>
    </head>
    <body>

        <div id="visual">
            <div id="title">MY MIDDLE TEST</div>
        </div>
        
        <!-- navigation -->
        <style>
            #nav_content ul{
                display: flex;
                /* flex-wrap: nowrap = 줄내림 없음 = 부모의 크기에 맞추어 자동 축소 */
                flex-wrap: wrap; /* 줄내림 있음 = 자신의 크기에 따라 줄내림 */
            }
            #nav_content li{
                list-style: none;
                width: 100%;
            }
            #nav_content ul{
                height: 0px;
                transition: height 0.5s;
                margin: 0px;
                overflow: hidden;
            }
            #nav_content .nav_open{
                height: 150px;
            }
            /*스마트폰*/
            @media only screen and (min-width:767px){ /*타블렛*/
                #nav_content li{
                    width: auto;
                }
                #nav_content ul{
                    height: auto;
                }
                #nav_content .nav_open{
                    height: auto;
                }
                #opan_button{
                    display: none;
                }
            }
            @media only screen and (min-width:1024px){ /*컴퓨터*/
            }
            @media only screen and (min-width:1920px){ /*FHD이상 = 2k, 4k*/
            }
        </style>
        <nav id="nav_content">
            <span id="opan_button" onclick="open_nav()">menu open</span>
            <ul id="open_target">
                <li>menu 1</li>
                <li>menu 2</li>
                <li>menu 3</li>
                <li>menu 4</li>
                <li>menu 5</li>
            </ul>
        </nav>
        <script>
            var nav_target = document.getElementById("open_target");
            function open_nav(){
                nav_target.classList.toggle("nav_open");
            }
            
        </script>
        <!-- navigation -->

        <!-- image gallery -->
        <style>
            #image_gallery{
                width: 100%;
                height:50vh;
                position: relative;
                overflow: hidden;
            }
            #image_container{
                width: 400%;
                display: flex;
                position: absolute;
                transition: left 0.5s;
            }
            .image_content{
                width: 25%;
                height:50vh;
            }
            .m_0{ left: 0% }
            .m_1{ left: -100% }
            .m_2{ left: -200% }
            .m_3{ left: -300% }
            .image_content:nth-child(1){ 
                background-color: red; 
                background-image: url("johannes-plenio.jpg");
                background-size: cover;
                background-position: 50% 50%;
            }
            .image_content:nth-child(2){ background-color: blue; }
            .image_content:nth-child(3){ background-color: green; }
            .image_content:nth-child(4){ background-color: yellow; }
            .bt{
                cursor:pointer;
                background-color: black;
                color: white;
            }
            #buttons{
                position:absolute;
                display: inline-block;
                margin: 0px auto;
                bottom: 0px;
                left: 50%;
                transform: translate(-50%, 0);
            }
        </style>
        <div id="image_gallery">
            <div id="image_container" class="m_0">
                <div class="image_content">content1</div>
                <div class="image_content">content2</div>
                <div class="image_content">content3</div>
                <div class="image_content">content4</div>
            </div>
            <div id="buttons">
                <span class="bt" onclick="change_con(0)">bt0</span>
                <span class="bt" onclick="change_con(1)">bt1</span>
                <span class="bt" onclick="change_con(2)">bt2</span>
                <span class="bt" onclick="change_con(3)">bt3</span>
            </div>
        </div>
        <script>
            function change_con(idx){
                var target = document.getElementById("image_container");
                target.classList = ""
                target.classList.add("m_"+idx);
            }
        </script>
        <!-- image gallery -->

        <div id="respon1" class="clearfix">
            <div id="content1">content1</div>
            <div id="content2">content2</div>
            <div id="content3">content3</div>
        </div>
        
        <div id="respon2" class="clearfix">
            <div id="content1">content1</div>
            <div id="content2">content2</div>
            <div id="content3">content3</div>
        </div>

        <div id="respon3">
            <div id="content_left">left</div>
            <div id="content_right">
                <div id="content1">content1</div>
                <div id="content2">content2</div>
            </div>
        </div>
    </body>
</html>
```

# 중간평가 베이스 소스
```html
<!DOCTYPE html>
<html>
    <head>
        <title> 000의 중간평가 - 주제명</title>
        <meta charset="utf-8" />
        <meta name="viewport" content=
        "width=device-width, initial-scale=1.0"/>
        <!-- 뷰포트 설정, 넓이=장치-넓이, 기준-크기=배율 -->
        <style>
            h1{ 
                background-color: navy; 
                color: white;
                margin: 0px;
                padding: 20px;
            }
            #respon_float div{
                float: left; /*왼쪽부터 둥둥 떠다니게*/
                /* width: calc(100%/3); */
                width: 100%;
            }
            #respon_flex{
                display: flex; /* 표시방식: 유연함 */
                flex-flow: row wrap; /* 유연한-흐름: 행방향 줄바꿈 */
            }
            #respon_flex2{
                display: flex; /* 표시방식: 유연함 */
                flex-flow: row wrap; /* 유연한-흐름: 행방향 줄바꿈 */
            }
            #respon_flex2 div{ width: 100%; }
            #respon_flex div{ width: 100%; }
            #respon_flex div:nth-child(1){
                background-color: aquamarine;
            }
            #respon_flex div:nth-child(2){
                background-color:blanchedalmond;
            }
            #respon_flex div:nth-child(3){
                background-color:darkkhaki;
            }
            #respon_float div:nth-child(1){
                background-color: aquamarine;
            }
            #respon_float div:nth-child(2){
                background-color:blanchedalmond;
            }
            #respon_float div:nth-child(3){
                background-color:darkkhaki;
            }
            #respon_flex2 div:first-child{background-color:blue;}
            #respon_flex2 div:last-child{background-color:brown;}
            #flex_right>div:first-child{
                background-color: beige;
            }
            #flex_right>div:last-child{
                background-color:greenyellow;
            }
            .clearfix::after{
                content:"";
                clear:both; /*float 해제: 양쪽*/
                display:table;
            }
            /*0~767스마트폰, 768~1023타블렛, 
            1024~1919컴퓨터(FHD), 1920~ 2k, 4k */
            @media only screen and (min-width:768px){
                /*타블렛*/
                h1{ font-size: 40px; }
                #respon_float div{ width: 50% }
                #respon_float div:last-child{ width: 100% }
                #respon_flex div{ width: 50% }
                #respon_flex div:last-child{ width: 100% }
                #respon_flex2>div{ width: 30% }
                #respon_flex2>div:last-child{ width: 70% }
            }
            #respon_float div, #respon_flex div, #respon_flex2 div{
                min-height: 150px;
            }
            @media only screen and (min-width:1024px){
                /*FHD 컴퓨터*/
                h1{ text-align: center; color:bisque; }
                #respon_float div{ width: calc(100%/3); }
                #respon_float div:last-child{ width: calc(100%/3); }
                #respon_flex div{ width: calc(100%/3); }
                #respon_flex div:last-child{ width: calc(100%/3); }
            }
            @media only screen and (min-width:1920px){
                /*2K,4K모니터 */
                h1{ text-shadow: 5px 5px 5px red;}
            }
        </style>
    </head>
    <body>
        <div id="wrap">
            <header>
                <h1> My Middle Test </h1>
            </header>
            <div id="content">
                <div id="respon_float" class="clearfix">
                    <div>content1</div>
                    <div>content2</div>
                    <div>content3</div>
                </div>
                <div id="respon_flex">
                    <div>content1</div>
                    <div>content2</div>
                    <div>content3</div>
                </div>
                <div id="respon_flex2">
                    <div>left</div>
                    <div id="flex_right">
                        <div>content1</div>
                        <div>content2</div>
                    </div>
                </div>
            </div>
        </div>
    </body>
</html>
```

---

# grid 그리드
```html
<!DOCTYPE html>
<html>
    <head>
        <title>grid</title>
        <meta charset="utf-8" />
        <style>
            #grid{
                display: grid;
                grid-template-columns: repeat(auto-fill, 200px); /* 줄맞추기-유형-행: 반복(자동채움, 넓이);*/
                align-items: stretch; /* 잡아늘임 */
                align-items: start; /* 내용에 맞춤 */
            }
            #grid div{
                background-color: aquamarine;
                border: solid 1px black;
                width: 200px;
            }
            #flex{
                display: flex;
                flex-flow: row wrap;
                align-items: start; /* 내용에 맞춤 */
            }
            #flex div{
                background-color: burlywood;
                border: solid 1px black;
                width: 200px;
            }
        </style>
    </head>
    <body>
        <div id="grid">
            <div>content1 content1 content1 content1content1content1</div>
            <div>content2</div>
            <div>content3 content3 content3content3</div>
            <div>content4</div>
            <div>content5 content5 content5 content5 content5 content5 content5 content5 content5 content5 content5 content5</div>
            <div>content6</div>
            <div>content1</div>
            <div>content2</div>
            <div>content3</div>
            <div>content4</div>
            <div>content5</div>
            <div>content6</div>
        </div>

        <div id="flex">
            <div>content1 content1 content1 content1content1content1</div>
            <div>content2</div>
            <div>content3 content3 content3content3</div>
            <div>content4</div>
            <div>content5 content5 content5 content5 content5 content5 content5 content5 content5 content5 content5 content5</div>
            <div>content6</div>
            <div>content1</div>
            <div>content2</div>
            <div>content3</div>
            <div>content4</div>
            <div>content5</div>
            <div>content6</div>
        </div>
    </body>
</html>
```

---

# 기말평가
```html
<!DOCTYPE html>
<html>
    <head>
        <title>기말평가</title>
        <meta charset="utf-8" />
        <meta name="viewport" content=
        "width=device-width, initial-scale=1.0"/>
        <style>
            header{
                display: flex;
                justify-content: space-between;
            }
            header>h1{
                margin: 10px 0px;
                color: green;
            }
            header>ul{
                display: flex;
                margin: 18px 0px;
            }
            header>ul>li{
                list-style: none;
                padding: 0px 15px;
            }
            #main_visual{
                background-image: url("background_image.jpg");
                background-repeat: no-repeat;
                background-color: black;
                background-position: 50% 50%; /*가로x, 세로y */
                background-size: 300px 400px;
                background-size: 100% 100%;
                background-size: cover;
                height: 50vw;
                /* vw, viewport-width 화면 넓이 */
                padding: 100px;
            }
            #main_visual>h2{
                font-size: 40px;
                text-align: center;
                font-weight: bold;
                letter-spacing: 10px;
                background-color: rgba(255,255,255,40%);
            }
            #main_visual>p{
                text-align: center;
                background-color: rgba(255,255,255,40%);
            }
            #image_frame{
                width: 100%;
                position: relative;
                /* absolute 자식의 기준이 되도록 함*/
                height: 50vw;
                overflow: hidden;
            }
            #image_container{
                width: 500%;
                display: flex;
                position: absolute; /*절대적인 위치*/
                /* left right top bottom으로 위치지정 가능*/
                height: 50vw;
                transition: left 1s;
            }
            #image_container>div{
                width: 20%;
                background-repeat: no-repeat;
                background-position: 50% 50%;
                background-size: cover; 
            }
            #image_container>div:nth-child(1){
                background-image: url("dog1.jpg");
            }
            #image_container>div:nth-child(2){
                background-image: url("dog2.jpg");
            }
            #image_container>div:nth-child(3){
                background-image: url("dog3.jpg");
            }
            #image_container>div:nth-child(4){
                background-image: url("dog4.jpg");
            }
            #image_container>div:nth-child(5){
                background-image: url("dog5.jpg");
            }
            .content1{ left: 0%; }
            .content2{ left: -100%; }
            .content3{ left: -200%; }
            .content4{ left: -300%; }
            .content5{ left: -400%; }

            #image_button{
                position:absolute;
                bottom: 0px;
                left: 50%;
            }
            #image_button>span{
                background-color: rgba(255,255,255,80%);
                border-radius: 20px;
            }
            #pc_nav{
                display: flex;
                display: none; /* 표시: 안함 */
                justify-content: space-between;
            }
            #pc_nav>ul{
                display: flex;
                margin: 26px 0px;
            }
            #pc_nav>ul>li{
                list-style: none;
                padding: 0px 10px;
            }
            #phone_nav>ul>li{
                list-style: none;
            }
            /* 기본값 : 스마트폰 -------------------------- */

            @media only screen and (min-width : 1024px){
                header>h1{
                    color: red;
                    font-weight: normal;
                }
                #main_visual>h2{
                    text-align: left;
                }
                #main_visual>p{
                    text-align: left;
                }
                #pc_nav{
                    display: flex;
                }
                #phone_nav{
                    display: none;
                }
            }
            /* 타블렛 (1024 ~ 1919) ---------------------- */

            @media only screen and (min-width : 1920px){

            }
            /* 컴퓨터 (1920 ~ ) ---------------------- */
        </style>
    </head>
    <body>
        <div id="wrap">
            <header>
                <h1>Title</h1>
                <ul>
                    <li>menu1</li>
                    <li>menu2</li>
                    <li>menu3</li>
                </ul>
            </header>
            <nav id="pc_nav">
                <h2>navigation</h2>
                <ul>
                    <li>menu1</li>
                    <li>menu2</li>
                    <li>menu3</li>
                    <li>menu4</li>
                </ul>
            </nav>
            <style>
                #phone_ul{
                    overflow: hidden;
                    transition: height 1s;
                }
            </style>
            <script>
                var isOpen = false;
                function open_close(){
                    console.log("열림 닫힘");
                    var target_ul = document.getElementById("phone_ul");
                    if(isOpen == true){ //열려있음==진실, 열려있다면
                        target_ul.style.height = "0px";
                        isOpen = false; //열려있음이 거짓이라고 기록
                    }else{ //아니라면, 닫혀있다면
                        target_ul.style.height = "160px";
                        isOpen = true; //열려있음이 진실이라고 기록
                    }
                }
            </script>
            <nav id="phone_nav" onclick="open_close();">
                <h2>navigation</h2>
                <ul id="phone_ul" style="height:0px;">
                    <li>menu1</li>
                    <li>menu2</li>
                    <li>menu3</li>
                    <li>menu4</li>
                </ul>
            </nav>
            <div id="main_visual">
                <h2>title1</h2>
                <p>
                    Lorem ipsum dolor sit amet, 
                    consectetur adipisicing elit, 
                    sed do eiusmod tempor incididunt
                </p>
            </div>
            <div id="image_frame">
                <div id="image_container" class="content1">
                    <div>content1</div>
                    <div>content2</div>
                    <div>content3</div>
                    <div>content4</div>
                    <div>content5</div>
                </div>
                <div id="image_button">
                    <span onclick="move_page(1);">1</span>
                    <span onclick="move_page(2);">2</span>
                    <span onclick="move_page(3);">3</span>
                    <span onclick="move_page(4);">4</span>
                    <span onclick="move_page(5);">5</span>
                </div>
            </div>
            <script>
                function move_page(index){
                    console.log(index);
                    var image_frame = document.getElementById("image_container");
                    /*대상 찾기*/
                    image_frame.className = ""; //클래스 비우기
                    image_frame.classList.add("content"+index); //클래스 추가하기
                }
            </script>
            <div id="content"> </div>
            <footer></footer>
        </div>
    </body>
</html>
```