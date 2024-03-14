---
layout: post
title: javascript 자바스크립트 기본기능
category: web
tags: javascript
---

# 참고가 되는 웹 사이트
* https://www.awwwards.com

# 배경색 변화
```html
<style>
    #with_css{
        background-color: red;
        transition: background-color 2s;
    }
    #with_css:hover{
        background-color: green;
    }
    #with_javascript{
        transition: background-color 2s;
    }
    .color_red{
        background-color: red;
    }
    .color_green{
        background-color: green;
    }
</style>
<script>
    function over_func(){
        var element = document.getElementById( 'with_javascript' );
        element.classList.add('color_green');
        element.classList.remove('color_red');
    }
    function out_func(){
        var element = document.getElementById( 'with_javascript' );
        element.classList.add('color_red');
        element.classList.remove('color_green');
    }
</script>
<div id="with_css">with css</div>
<div id="with_javascript" class="color_red" 
onmouseover="over_func()" onmouseout="out_func()">
    with javascript
</div>
```
# 가로 슬라이드 이미지 갤러리 
```html
<style>
    #b_red{
        background-color: red;
    }
    #b_blue{
        background-color: blue;
    }
    #b_yellow{
        background-color: yellow;
    }
    #b_green{
        background-color: green;
    }
    [id*="b_"]{
        width: 25%;
        height: 200px;
        float: left;
    }
    #container{
        width: 400%;
        position: absolute;
        transition: left 0.5s;
    }
    .m_0{ left: 0% }
    .m_1{ left: -100% }
    .m_2{ left: -200% }
    .m_3{ left: -300% }
    #frame{
        height: 200px;
        overflow: hidden;
        position: relative;
    }
    .clear{
        clear: both;
        height: 0px;
        overflow: hidden;
    }
</style>
<script>
    function change_con(idx){
        var target = document.getElementById("container");
        target.classList = ""
        target.classList.add("m_"+idx);
    }
</script>
<div id="frame">
    <div id="container" class="m_0">
        <div id="b_red">content1</div>
        <div id="b_blue">content2</div>
        <div id="b_yellow">content3</div>
        <div id="b_green">content4</div>
        <div class="clear"></div>
    </div>
</div>
<button onclick="change_con(0)">content1</button>
<button onclick="change_con(1)">content2</button>
<button onclick="change_con(2)">content3</button>
<button onclick="change_con(3)">content4</button>
```
# 좌우 기능 추가
```html
<style>
    #b_red{
        background-color: red;
    }
    #b_blue{
        background-color: blue;
    }
    #b_yellow{
        background-color: yellow;
    }
    #b_green{
        background-color: green;
    }
    [id*="b_"]{
        width: 25%;
        height: 200px;
        float: left;
    }
    #container{
        width: 400%;
        position: absolute;
        transition: left 0.5s;
    }
    .m_0{ left: 0% }
    .m_1{ left: -100% }
    .m_2{ left: -200% }
    .m_3{ left: -300% }
    #frame{
        height: 200px;
        overflow: hidden;
        position: relative;
    }
    .clear{
        clear: both;
        height: 0px;
        overflow: hidden;
    }
</style>
<script>
	var save_idx = 0;
    function change_con(idx){
    	save_idx = idx;
        var target = document.getElementById("container");
        target.classList = ""
        target.classList.add("m_"+idx);
    }
</script>
<div id="frame">
    <div id="container" class="m_0">
        <div id="b_red">content1</div>
        <div id="b_blue">content2</div>
        <div id="b_yellow">content3</div>
        <div id="b_green">content4</div>
        <div class="clear"></div>
    </div>
</div>
<button onclick="change_con(0)">content1</button>
<button onclick="change_con(1)">content2</button>
<button onclick="change_con(2)">content3</button>
<button onclick="change_con(3)">content4</button>
<script>
	function left_con(){
		if(save_idx > 0){
			save_idx --;
			change_con(save_idx);
		}
	}
	function right_con(){
		if(save_idx < 3){
			save_idx ++;
			change_con(save_idx);
		}
	}
</script>
<button onclick="left_con()">go left</button>
<button onclick="right_con()">go right</button>
```
# 롤 기능 추가
```html
<style>
            #div_frame{
                width: 200px;
                position: relative;
                height: 200px;
                overflow: hidden; /* 넘쳐흐를때 : 숨김*/
            }
            #div_contain{
                width: 400%;
                display: flex;
                position: absolute;
                height: 200px;
                transition: left 1s; /* 점진적으로(서서히) 변함: left 1초동안 */
            }
            .m_0{left: 0%;}
            .m_1{left: -100%;}
            .m_2{left: -200%;}
            .m_3{left: -300%;}
            #div_contain div{
                width: 25%;
                height: 200px;
            }
            #div_contain div:nth-child(1){background-color:red;}
            #div_contain div:nth-child(2){background-color:blue;}
            #div_contain div:nth-child(3){background-color:green;}
            #div_contain div:nth-child(4){background-color:purple;}
        </style>
        <div id="div_frame">
            <div id="div_contain" class="m_0">
                <div>content1</div>
                <div>content2</div>
                <div>content3</div>
                <div>content4</div>
            </div>
        </div>
        <script>
            var now_page = 0; //변수의 선언
            function change_page(index){
                console.log("change_page");
                var target_container = document.getElementById("div_contain"); 
                //객체를 찾기(가져오기)
                target_container.classList.remove("m_0"); 
                //클래스 목록에서 m_0을 제거(remove)한다
                target_container.classList.remove("m_1"); //클래스 목록에서 m_1을 제거(remove)한다
                target_container.classList.remove("m_2"); //클래스 목록에서 m_2을 제거(remove)한다
                target_container.classList.remove("m_3"); //클래스 목록에서 m_3을 제거(remove)한다
                /* 클래스 목록을 모두 제거 한다 */
                
                target_container.classList.add("m_"+index); 
                //클래스 목록에 "m_"+index을 추가한다
                now_page = index; // 현재페이지 = 변한 페이지의 번호
            } //함수의 선언
            function move_left(){
                console.log("move left");
                if(now_page+1 <= 3){ 
                    // 현재페이지+1 3이거나 작으면 = 끝까지 가지 않았으면
                    change_page(now_page+1);  // 현재페이지(??) +1
                }else{
                    // 현재페이지+1 3보다 크다면 = 끝까지 다 갔으면
                    console.log("더이상 이동할 수 없습니다.");
                }
            }
            function move_right(){
                console.log("move right");
                if(now_page-1 >= 0){ //끝까지 가지 않았으면
                    change_page(now_page-1);
                }else{
                    console.log("더이상 이동할 수 없습니다.");
                }
            }
            function roll_left(){
                console.log("move left");
                if(now_page+1 <= 3){ 
                    // 현재페이지+1 3이거나 작으면 = 끝까지 가지 않았으면
                    change_page(now_page+1);  // 현재페이지(??) +1
                }else{
                    // 현재페이지+1 3보다 크다면 = 끝까지 다 갔으면
                    change_page(0); //페이지0으로 이동 = 반대편 끝에서 다시 시작
                }
            }
            function roll_right(){
                console.log("move right");
                if(now_page-1 >= 0){ //끝까지 가지 않았으면
                    change_page(now_page-1);
                }else{
                    change_page(3); //반대편 끝에서 다시 시작
                }
            }
        </script>
        <button onclick="roll_right()">◀◀</button>
        <button onclick="move_right()">◀</button>
        <button onclick="change_page(0);//함수의호출">content1</button>
        <button onclick="change_page(1);//함수의호출">content2</button>
        <button onclick="change_page(2);//함수의호출">content3</button>
        <button onclick="change_page(3);//함수의호출">content4</button>
        <button onclick="move_left()">▶</button>
        <button onclick="roll_left()">▶▶</button>
```
# 롤링배너
```html
  <!DOCTYPE html>
  <html>
    <head>
        <style>
            #frame_div{
                width:100px;
                height: 100px;
                overflow: show;
                position: relative;
            }
            #inner_div{
                position: absolute;
                width: 500px;
                height: 100px;
                left:0px;
                transition: left 1s;
            }
            .block_div{
                width: 100px;
                height: 100px;
                float:left;
            }
            .block_div:nth-child(1){
                background-color: red;
            }
            .block_div:nth-child(2){
                background-color: blue;
            }
            .block_div:nth-child(3){
                background-color: yellow;
            }
            .block_div:nth-child(4){
                background-color: green;
            }
            .block_div:nth-child(5){
                background-color: yellowgreen;
            }
            .clear{
                clear:both;
            }
        </style>
        <script>
            var left_value = 0;
            function left(){
                left_value -= 100;
                var inner_div = document.getElementById("inner_div");
                inner_div.style.left = left_value+"px";
            }
            function right(){
                alert("right");
            }
        </script>
    </head>
    <body>
        <div id="frame_div">
            <div id="inner_div">
                <div class="block_div">1</div>
                <div class="block_div">2</div>
                <div class="block_div">3</div>
                <div class="block_div">4</div>
                <div class="block_div">5</div>
                <div class="clear"></div>
            </div>
        </div>
        <button onclick="left();">left</button>
        <button onclick="right();">right</button>
    </body>
  </html>
```
# 자동 롤링 
```html
<script>
  setInterval(myMethod, 5000);
  
  function myMethod( )
  {
    //this will repeat every 5 seconds
    //you can reset counter here
  }


  var roll = setInterval(roll_left, 1000); //반복설정(함수명, 간격 밀리초=1/1000초)
  function setRoll(){ //인터벌을 추가한다
    clearInterval(roll); //인터벌 추가전 삭제
    roll = setInterval(roll_left, 1000);
  }
  function clearRoll(){ //인터벌을 제거한다
    clearInterval(roll);
  }
</script>
```
# 스크롤링
* 소스코드 : https://github.com/gunug/Code/blob/main/Web/Javascript/Scrolling.html
* 결과 : https://gunug.github.io/Code/Web/Javascript/Scrolling.html
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
* object.offsetTop
* object.offsetHeight/2
* document.documentElement.scrollTop
* window.innerHeight/2
# 스프라이트 시트 애니메이션
* https://itnext.io/creating-css-animations-using-sprite-sheet-47e2b7a3793c
![image](https://user-images.githubusercontent.com/52345276/192162477-e8035850-7d6e-459f-a7e8-534d2acebd0a.png)

```html
 <style>
    #container{
        width: 85px;
        height: 85px;
        overflow: hidden;
    }
            #animation_target{
                background-image: url("Sample_image.png");
                background-repeat: no-repeat;
                width: 600px;
                height: 340px;
                animation : playX 0.5s steps(7) infinite,
                            playY 2s steps(4) infinite;
            }
            @keyframes playX {
                from {background-position-x: 0px;}
                to {background-position-x: -600px;}
            }
            @keyframes playY {
                from {background-position-y: -0px;}
                to {background-position-y: -340px;}
            }
 </style>
 <div id="container">
     <div id="animation_target"></div>
 </div>
```
# position 변경시 깜빡임 해결방법

```javascript
  try {
      document.execCommand('BackgroundImageCache', false, true);
  } catch(e) {}
```
* 출처: https://duellist.tistory.com/113 [Return]

# 애니메이션 제어 
```html
 <div id="container">
    <div onmouseover="stop_animation()" onmouseout="play_animation()" id="animation_target"></div>
 </div>
 <script>
    function play_animation(){
        var target_div = document.getElementById("animation_target");
        target_div.style.animationPlayState = "running";
    }
    function stop_animation(){
        var target_div = document.getElementById("animation_target");
        target_div.style.animationPlayState = "paused";
    }
 </script>
```