---
layout: post
title: javascript fullscreen 자바스크립트 풀스크린
category: web
tags: javascript
---

# javascript fullscreen 자바스크립트 풀스크린

## 전체화면(full screen), 해상도(resolution) 
* display (html) 부분
  
```html
<div id="full_content" style="width:500px; height:500px; border: solid 5px #ff0000; display:none"> content </div>
<input type="button" id="fullscreen_bt" value="start fullscreen application">
```
* fullscreen function (javascript) 부분

```javascript
function requestFullscreen(ele) {
    if (ele.requestFullscreen) {
        ele.requestFullscreen();
    } else if (ele.webkitRequestFullscreen) {
        ele.webkitRequestFullscreen();
    } else if (ele.mozRequestFullScreen) {
        ele.mozRequestFullScreen();
    } else if (ele.msRequestFullscreen) {
        ele.msRequestFullscreen();
     } else {
         // Fallback
         console.log('Fullscreen API is not supported.');
     }
 };
 
 
function exitFullscreen() {
     if (document.exitFullscreen) {
         document.exitFullscreen();
     } else if (document.webkitExitFullscreen) {
         document.webkitExitFullscreen();
     } else if (document.mozCancelFullScreen) {
         document.mozCancelFullScreen();
     } else if (document.msExitFullscreen) {
         document.msExitFullscreen();
     } else {
         // Fallback
         console.log('Fullscreen API is not supported.');
     }
};
```
---

## 풀 스크린 진입/해제 화면처리 
```javascript
var full_bt = document.getElementById("fullscreen_bt");
var full_con = document.getElementById("full_content");
full_bt.addEventListener("click",fullscreenFunc)
function fullscreenFunc(e){
    requestFullscreen(full_con);
}
if (document.addEventListener)
{
    document.addEventListener('webkitfullscreenchange', exitHandler, false);
    document.addEventListener('mozfullscreenchange', exitHandler, false);
    document.addEventListener('fullscreenchange', exitHandler, false);
    document.addEventListener('MSFullscreenChange', exitHandler, false);
}
function exitHandler()
{
    if (document.webkitIsFullScreen || document.mozFullScreen || document.msFullscreenElement){
        //풀 스크린 진입시
        full_con.style.width = screen.width+"px";
        full_con.style.height = screen.height+"px";
        full_con.style.display = "block";
    }else{
        //풀 스크린 해제시
        full_con.style.display = "none";
    }
}
```
