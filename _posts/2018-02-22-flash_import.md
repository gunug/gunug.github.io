---
layout: post
title: flash import 플래시 임포트
category: etc
tags: flash
---

* 이전 플래시를 브라우저에 임폴트할때 연동오류를 일으키지 않도록 임포트 하는 방법. 이제는 별로 의미 없는 내용일지도

```javascript
function flashMenu(url,id,width,height,trans,flashvars){
 var strFlashTag = new String();  
 if (navigator.appName.indexOf("Microsoft") != -1)    {
  strFlashTag += '<object classid="clsid:D27CDB6E-AE6D-11cf-96B8-444553540000" ';
  strFlashTag += 'codebase="http://download.macromedia.com/pub/shockwave/cabs/flash/swflash.cab#version=9,0,0,0" width="' + width + '" id="' + id + '" name="' + id + '" height="' + height + '">';
  strFlashTag += '<param name="movie" value="' + url + '"/>';      
  strFlashTag += '<param name="FlashVars" value="' + flashvars + '"/>';
  strFlashTag += '<param name="quality" value="best"/>';
  //strFlashTag += '<param name="bgcolor" value="' + bgcolor + '"/>';
  strFlashTag += '<param name="menu" value="false"/>';
  //strFlashTag += '<param name="salign" value="LT"/>';
  //strFlashTag += '<param name="scale" value="noscale"/>';
  if(trans==true){
   strFlashTag += '<param name="wmode" value="transparent"/>';
  }
  else{
   strFlashTag += '<param name="wmode" value="window"/>';
  }
  strFlashTag += '<param name="allowScriptAccess" value="always"/>';
  strFlashTag += '</object>';
 }
 else{
  strFlashTag += '<embed src="' + url + '"';
  strFlashTag += 'pluginspage="http://www.macromedia.com/go/getflashplayer"';
  strFlashTag += 'type="application/x-shockwave-flash"';
  strFlashTag += 'flashvars="' + flashvars + '" ';
  strFlashTag += 'quality="best" ';
  //strFlashTag += 'bgcolor="' + bgcolor + '" ';
  strFlashTag += 'width="' + width + '" ';
  strFlashTag += 'height="' + height + '" ';
  strFlashTag += 'menu="false" ';
  strFlashTag += 'id="'+id+'" ';
  strFlashTag += 'name="'+id+'" ';
  //strFlashTag += 'scale="noscale" ';
  //strFlashTag += 'salign="LT" ';
  if(trans==true){
   strFlashTag += 'wmode="transparent" ';     
  }else{
   strFlashTag += 'wmode="opaque" ';
  }
  strFlashTag += 'allowScriptAccess="always" ';
  //strFlashTag += '<param name="FlashVars" value="' + flashvars + '"/>';
  strFlashTag += '</embed>';
 }
 document.write(strFlashTag);
}
function resizeFlash(width,height){
 var targetFlash = document.getElementById("gnb");
 //targetFlash.style.width = width;
 targetFlash.style.height = height;
}
``````