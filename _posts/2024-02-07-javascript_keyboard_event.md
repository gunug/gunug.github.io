---
layout: post
title: javascript keyboard event 키보드 이벤트
category: web
tags: javascript simple-code
---


# 자바스크립트 키보드 이벤트 2012/12/5

```javascript
function myKeyPressHandler(){
    var x;
    if (  event.which ) // IE9 / Firefox / Chrome / Opera / Safari
    {
     x = event.which;
    }
    else if ( window.event ) // IE8 and earlier
    {
     x = event.keyCode;
    }
    var keychar = String.fromCharCode(x);
    if(x== 27)
     mp3_stop();
   }
   if( navigator.userAgent.indexOf('Firefox') >= 0 ) {
     var eventNames = ["mousedown", "mouseover", "mouseout", 
       "mousemove", "mousedrag", "click", "dblclick",
       "keydown", "keypress", "keyup" ]; 
     for( var i = 0 ; i < eventNames.length; i++ ) {
      window.addEventListener( eventNames[i], function(e) {
       window.event = e;
      }, true );
     }
   }
   document.onkeypress=myKeyPressHandler;
//onkeypress는 크롬에서 안먹음
//onkeydown으로 바꾸세요
```