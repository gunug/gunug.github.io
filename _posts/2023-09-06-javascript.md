---
layout: post
title: Javascript 자바스크립트
category: web
tags: javascript coding
---

```javascript
10.toString(2); //decimal to binary;
parseInt("100"); //String to int
```

---

## javascript event
* [참고](https://www.w3schools.com/js/js_events.asp)

```javascript
 function function_name() {내용;}
 window.onload = function_name();
//onLoad,onUnload,onResize
```

---

## javascript object
* [참고](https://developer.mozilla.org/ko/docs/Learn/JavaScript/Objects/Basics)

```html
<html>
   <head>
       <script>
           var obj2 = {c:'d'};
           function b(){
               console.log(this);
           }
           b(); //window
           b.bind(obj2).call(); //obj2
           b.call(obj2); //obj2
           b.apply(obj2); // obj2
           function Person(name, age){
               this.name = name;
               this.age = age;
           }
           Person.prototype.hello = function(){
               console.log(this.name, this.age);
           }
           Person('test',25);
           console.log(window.name, window.age);
           var sample2 = new Person('test2',30);
           sample2.hello();
           var sample3 = new Person('test3',35);
           sample3.hello();
           sample2.hello();
           function Pet(name,age){
               this.name = name;
               this.age = age;
           }
           Pet.prototype.name = "none";
           Pet.prototype.age = 99;
           Pet.prototype.hello = function(){
               console.log("pet is:"+this.name+":"+this.age);
           }
           var dog = new Pet("dog", 10);
           dog.hello();
           var cat = new Pet("cat", 7);
           cat.hello();
           dog.hello();
       </script>
   </head>
   <body>
   </body>
</html>
```

---

## get 변수 받아오기

* [https://css-tricks.com/snippets/javascript/get-url-variables/](https://css-tricks.com/snippets/javascript/get-url-variables/)

```javascript
function getQueryVariable(variable) {
      var query = window.location.search.substring(1);
      var vars = query.split("&");
      for (var i=0;i<vars.length;i++) {
              var pair = vars[i].split("=");
              if(pair[0] == variable){return pair[1];}
      }
      return(false);
}
```

---

## div 레이어사이즈 변환
```javascript
/**
 * lnb 레이어사이즈 변환
 */
function setGnbSize(h){
        var container = document.getElementById("gnb");
        container.style.height = h+"px";
}

function getFlashMovieObject(movieName){
    if (window.document[movieName]) 
    {
        return window.document[movieName];
    }
    if (navigator.appName.indexOf("Microsoft Internet")==-1)
    {
        if (document.embeds && document.embeds[movieName])
        return document.embeds[movieName]; 
    }
    else // if (navigator.appName.indexOf("Microsoft Internet")!=-1)
    {
        return document.getElementById(movieName);
    }
}
```

---

## 구둣점

```javascript
function comma(oriData:String){
 var resultData:String = "";
 for(var i:int=-3; i>=-oriData.length; i-=3){
  var dan:String = oriData.substr(i,3);
  resultData = dan+resultData;
  if(-oriData.length != i)resultData = ","+resultData;
 }
 resultData = oriData.substr(0,oriData.length%3)+resultData;
 return resultData;
} 
//+
```
