---
layout: post
title: javascript image load 자바스크립트 이미지 로드
category: web
tags: javascript
---

# javascript image load 자바스크립트 이미지 로드
* 이미지 로드 후 표시되도록 하기

```javascript
$(".title_image").each(function(index,item){
    if(this.complete){
        this.classList.add('loaded');
    }
    this.onload = function(){
        this.classList.add('loaded');
    }
});
```
* .onload는 이미지가 다운로드 완료 되면 호출됩니다.
* 이미 다운로드되어 캐시로부터 불러지는 이미지는 .onload를 호출하지 않습니다
* .complete를 이용하여 로드 완료 여부를 확인 할 수 있습니다.