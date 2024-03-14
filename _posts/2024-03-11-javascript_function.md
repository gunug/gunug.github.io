---
layout: post
title: javascript 자바스크립트 응용
category: web
tags: javascript
---

# 토글(toggle) - if, boolean
클릭에 따라 두가지 상태를 번갈아 변하는 버튼을 말합니다. 
"Num Lock" , "Caps Lock" , "Scroll Lock"

# 기본
on/off 형식의 기본적인 토글입니다.
```html
 <input id="toggle_button" onclick="toggle()" type="button" value="off">
 <!--input onclick = oncick 을 할때마다 toggle이라는 함수를 실행 합니다.-->
 <script type="text/javascript">
     var toggle_value = false;
     //toggle_value는 false 입니다.
     function toggle(){
         var element = document.getElementById("toggle_button");
         //변수 element에 = 문서에서.element가져오기 아이디는("toggle_button");
         if(toggle_value){
             //1. toggle_value가 참(true)일때
             element.value = "off"; //input button의 value 값을 "off"로 바꾼다.
             toggle_value = false; // toggle_value의 값을 false로 바꾼다.
         }else{
             //2. toggle_value가 거짓(false)일때
             element.value = "on"; //input button 의 value 값을 "on"으로 바꾼다
             toggle_value = true; //toggle_value의 값을 ture로 바꾼다.
         }
     }
 </script>
```
# 심화
3번클릭 후 다시 첫번째로 넘어가는 심화-토글 입니다.
```html
 <input id="toggle_button2" onclick="toggle2()" type="button" value="1단">
 <!--input onclick2= 를 실행할 떄 마다 toggle2이라는 함수를 실행 합니다. -->
 <script type="text/javascript">
     var toggle_value2 = 0;
     //toggle_value2의 기본 값은 0 입니다.
     function toggle2(){
         var element = document.getElementById("toggle_button2");
         //변수 element에 = 문서에서.element가져오기 아이디는("toggle_button2");
         if(toggle_value2 == 0){
             //toggle_value2가 0일때
             element.value = "2단"; //input button의 value 값을 "2단"으로 바꾼다.
             toggle_value2 = 1; // toggle_value의 값
         }else if(toggle_value2 == 1){
             //toggle_value2가 0은 아니고 1일때
             element.value = "3단";
             toggle_value2 = 2;
         }else{
             //toggle_value2가 0도아니고 1도 아닐때
             element.value = "1단";
             toggle_value2 = 0;
         }
     }
 </script>
```
# 키보드(keyboard) - switch case
키보드의 1~6까지의 숫자값을 받아 사이트를 이동시키는 스위치문 입니다.
```html
 <div id="print_text">default text</div>
 <script type="text/javascript">
     var print_target = document.getElementById("print_text"); //element(요소)
     //print_target 객체형 변수 = element;
     function setKeyboardEvent(){
         document.onkeydown = keyDown;
     } // 선언부
  
     function keyDown(event) {
     var key = event.which || event.keyCode; // "||" or (또는)
         //event.witch 또는 event.keyCod라는 변수에 받아둡니다.
  
         //0~9key : 48~57
         switch(key){
         //만약 키코드가...
             case 49: // ; 땀표시 아님 : 땡땡이임
                 // 49라면 (키보드의 1번키가 눌렸다면)
                 //if(key == 49); 만약 (키가 49와 같다면)
                 print_target.innerHTML = "1번 키가 눌렸습니다. - 네이버"
                 //"default text" 글자 바꾸기
                 window.open("http://www.naver.com","_blank");
                 //창을.새로 오픈("주소(url)","새창");
             break;
             case 50:
                 print_target.innerHTML = "2번 키가 눌렸습니다. - 구글"
                 window.open("http://www.google.com","_blank");
             break;
             case 51:
                 print_target.innerHTML = "3번 키가 눌렸습니다. - 유투브"
                 window.open("http://www.youtube.com","_blank");
             break;
             case 52:
                 print_target.innerHTML = "4번 키가 눌렸습니다."
             break;
             case 53:
                 print_target.innerHTML = "5번 키가 눌렸습니다."
             break;
             case 54:
                 print_target.innerHTML = "6번 키가 눌렸습니다. - 롤인벤"
                 window.open("http://lol.inven.co.kr","_blank");
             break;
  
  
         }
     }
     setKeyboardEvent();
 </script>
```
![image](https://user-images.githubusercontent.com/52345276/200197288-f5ec478c-5f8e-4e11-8a59-985edf25c2a5.png)


# 랜덤(random) - Math.random(),Math.floor(),array
그때 그때 다른 결과값을 무작위(random)으로 출력할수 있습니다. 재미요소나 게임요소로 사용됩니다.
주사위, 룰셋, 슬롯머신 http://kr.vonvon.me/ - 랜덤 결과 사이트

## 기본
```html
 <input onclick="random()" type="button" value="복불복" id="random_button">
 <div id="result_div" style="width:300px;">default text</div>
 <script type="text/javascript">
     var items = new Array(
                     "곰",
                     "까마귀",
                     "야생화",
                     "개미",
                     "사자",
                     "강아지",
                     "사람"
                 );
     function random(){
         var result_div = document.getElementById("result_div");
         var num = Math.floor(Math.random()*items.length);
         result_div.innerHTML = "당신은 전생에 " + items[num] + " 였습니다.";
     }
 </script>
```
## 심화
![image](https://user-images.githubusercontent.com/52345276/200197318-90fdec99-667b-48a2-9600-6fcf0b220233.png)
![image](https://user-images.githubusercontent.com/52345276/200197322-92b4a219-605a-4518-8498-74b2e2fed212.png)
![image](https://user-images.githubusercontent.com/52345276/200197327-e5b69868-0b96-4227-842e-06b6b848d274.png)
![image](https://user-images.githubusercontent.com/52345276/200197331-6df6c132-cafd-414c-8350-f661c2559112.png)
![image](https://user-images.githubusercontent.com/52345276/200197340-070beaac-7438-4600-a037-673664194c39.png)
![image](https://user-images.githubusercontent.com/52345276/200197341-96073f2c-fa62-4d4a-9630-f97429c3f207.png)
```html
 <input onclick="random3()" type="button" value="주사위" id="random_button3">
 <div id="result_div3" style="width:300px;">default text</div>
 <script type="text/javascript">
     var items3 = new Array(
                     "dice_1.jpg",
                     "dice_2.jpg",
                     "dice_3.jpg",
                     "dice_4.jpg",
                     "dice_5.jpg",
                     "dice_6.jpg"
                 );
     function random3(){
         var result_div3 = document.getElementById("result_div3");
         var num1 = Math.floor(Math.random()*items3.length);
         result_div3.innerHTML = "<img style=\"width:150px;\" src=\""+items3[num1]+"\">";
         //document.getElementById("imgId").src
     }
 </script>
```
## 더 심플한 버전
```html
 <input onclick="random3()" type="button" value="주사위" id="random_button3">
 <div id="result_div3" style="width:300px;">
     <img id="dice_image" />
 </div>
 <script type="text/javascript">
    var items3 = new Array(
                    "dice_1.jpg",
                    "dice_2.jpg",
                    "dice_3.jpg",
                    "dice_4.jpg",
                    "dice_5.jpg",
                    "dice_6.jpg"
                );
    function random3(){
        var dice_target = document.getElementById("dice_image");
        var num = Math.floor(Math.random()*items3.length);
        dice_target.src = items3[num];
    }
 </script>
```
# 반복(loop) - while, do while
~하는 동안(while)을 뜻합니다. 특정 조건이 만족하는 기간동안 반복하는 구문을 만들어 봅시다.
* while문과 do while문은 아주 사소한 차이가 있지만 프로그램상에서 크게 다른결과를 가져옵니다.
* while : 배부를때까지 먹습니다.
* do while : 먹다가 배부르면 그만둡니다.

## 기본
* while
  
```html
 <input type="button" onclick="make_div_function()" value="make div">
 <div id="div_target" style="width:300px; height:400px; overflow:auto;"></div>
 <script type="text/javascript">
     function make_div_function(){
         var num = prompt("div을 몇개나 생성 할까요?","3");
         var target_div = document.getElementById("div_target");
         var counter = 0;
         target_div.innerHTML = "";
         while(counter < num){
             //counter가 num보다 작은 수라면 다음을 진행합니다.
             target_div.innerHTML += "<div style='border: solid 1px #000000'>"+counter+"번째 div 입니다.</div>";
             //div_target에 새 div를 생성
             counter ++;
             //counter를 하나 증가시킵니다. (counter = counter + 1과 동일기능)
         }//반복합니다.
     }
 </script>
```

 * do while

```html
 <input type="button" onclick="make_div_function3()" value="make div">
 <div id="div_target3" style="width:300px; height:400px; overflow:auto;"></div>
 <script type="text/javascript">
     function make_div_function3(){
         var num = prompt("div을 몇개나 생성 할까요?","3");
         var target_div = document.getElementById("div_target3");
         var counter = 0;
         target_div.innerHTML = "";
         do{
             target_div.innerHTML += "<div style='border: solid 1px #000000'>"+counter+"번째 div 입니다.</div>";
             //div_target에 새 div를 생성
             counter ++;
             //counter를 하나 증가시킵니다. (counter = counter + 1과 동일기능)
         }while(counter < num) //counter가 num보다 작은 수라면 반복합니다.
     }
 </script>
```

## 심화

```html
 <input onclick="loop_function()" type="button" value="start" id="toggle_button2">
 <script type="text/javascript">
     var count = 0;
     function loop_function(){
         do{
             count ++;
             var boo = confirm(count+"번째 시도 입니다. 계속 할까요?");
         }while(boo)
         alert("총"+count+"회 시도하셨습니다. 종료합니다.");
     }
 </script>
```

```html
 <input onclick="loop_function2()" type="button" value="start" id="toggle_button2">
 <div id="div_target6" style="width:300px; height:400px; overflow:auto;"></div>
 <script type="text/javascript">
     function loop_function2(){
         var target_div = document.getElementById("div_target6");
         target_div.innerHTML = "";
         var counter = 0;
         do{
             var value = prompt("값을 입력해 주세요 (0입력시 종료)","0");
             target_div.innerHTML += "<div style='border: solid 1px #000000'>"+counter+"번째 : "+value+"</div>";
             counter ++;
         }while(value != 0)
     }
 </script>
```

# 반복2(loop) - for

## 기본

```html
<input type="button" onclick="make_div_function()" value="make div">
    <div id="div_target" style="width:300px; height:400px; overflow:auto;"></div>
    <script type="text/javascript">
        function make_div_function(){
            var num = prompt("div을 몇개나 생성 할까요?","3");
            var target_div = document.getElementById("div_target");
            target_div.innerHTML = "";
            for(var i=0; i<num; i++){
                //i는 0입니다. i는 num보다 작습니다. i는 한개씩 커집니다.
                target_div.innerHTML += "<div style='border: solid 1px #000000'>"+i+"번째 div 입니다.</div>";
                //div_target에 새 div를 생성
            }//반복합니다.
        }
</script>
```

## 심화
```html
 <div id="for_1" style="position:relative; width:150px; height:150px;"></div>
 <script type="text/javascript">
     var ins_for1 = document.getElementById("for_1");
     ins_for1.innerHTML = "";
     window.addEventListener("load", readyFunc);
     function readyFunc(){
         for(var i=0; i<5; i++){
             for(var j=0; j<5; j++){
                 ins_for1.innerHTML += "<div style='position:absolute; border: solid 1px #000000; left:"+(j*30)+"px; top:"+(i*30)+"px; width:30px; height:30px;'>"+j+","+i+"</div>";
             }
         }
     }
 </script>

 <div id="for_3" style="position:relative; width:150px; height:150px;"></div>
 <script type="text/javascript">
     var ins_for = document.getElementById("for_3");
     ins_for.innerHTML = "";
     window.addEventListener("load", readyFunc3);
     function readyFunc3(){
         for(var i=0; i<5; i++){
             for(var j=0; j<i; j++){
                 ins_for.innerHTML += "<div style='position:absolute; border: solid 1px #000000; left:"+(j*30)+"px; top:"+(i*30)+"px; width:30px; height:30px;'>"+j+","+i+"</div>";
             }
         }
     }
 </script>
```

# 분기 - break, continue, return

* break

```html
 <input onclick="result()" type="button" value="결과 보기" id="result_button">
 <div id="result_target_1"></div>
 <script type="text/javascript">
     function result(){
         var element = document.getElementById("result_target_1");
         element.innerHTML = "";
         for(var i=0; i<30; i++){
             if(i == 15){
                 //만약 i 가 15라면
                 break;
                 //중단한다.
             }
             element.innerHTML += i+",";
         }
     }
 </script>
```

* continue

```html
 <input onclick="result3()" type="button" value="결과 보기" id="result_button3">
 <div id="result_target_3"></div>
 <script type="text/javascript">
     function result3(){
         var element = document.getElementById("result_target_3");
         element.innerHTML = "";
         for(var i=0; i<30; i++){
             if(i == 15){
                 //만약 i 가 15라면
                 continue;
                 //다음루프를 진행한다
             }
             element.innerHTML += i+",";
         }
     }
 </script>
```
* return
  
```html
 <input onclick="result6(0)" type="button" value="결과1" id="result_button6">
 <input onclick="result6(1)" type="button" value="결과2" id="result_button6">
 <script type="text/javascript">
     function result6(value){
         alert("alert 1");
         if(value == 0){
             //만약 넘겨받은 값(value)이 0이라면
             return;
             //함수(function)를 종료한다
         }
         alert("alert 2");
     }
 </script>
```