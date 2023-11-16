---
layout: post
title: 흑백 컬러 판별
category: c#
tags: simple-code
---

# 흑백 컬러 판별

```c#
var color1:uint = 0xff0000;
var color2:uint = 0xffff00;
var color3:uint = 0x333333;

function monotype(color:uint):Boolean{
 var r :uint = (color << 8) >>> 24;
 var g :uint = (color << 16) >>> 24;
 var b :uint = (color << 24) >>> 24;
 //trace("[r:"+r.toString(16),"][g:"+g.toString(16),"][b:"+b.toString(16)+"]");
 
 var boolean1:Boolean = false;
 var boolean2:Boolean = false;
 var boolean3:Boolean = false;
 
 boolean1 =  (Math.abs(r-g) < 10);
 boolean2 =  (Math.abs(g-b) < 10);
 boolean3 =  (Math.abs(b-r) < 10);
 
 return boolean1 && boolean2 && boolean3;
}

trace(monotype(color1));
trace(monotype(color2));
trace(monotype(color3));
```
* 비트 연산자를 이용하면 쉽게 RGB값을 나눌 수 있습니다.