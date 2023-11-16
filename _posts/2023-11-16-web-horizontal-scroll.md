---
layout: post
title: 가로 스크롤
category: web
tags: 
---


# 그림 가로 스크롤
```html
<!DOCTYPE html>
<html>
    <head>
        <title></title>
        <style type="text/css">
        </style>
        <style type="text/css">
            #image_container{
                width: 500px;
                height: 400px;
                overflow-x: scroll;
                overflow-y: hidden;
            }
            #image_container::-webkit-scrollbar {
                width: 5px;
                height: 5px;
                color: white;
                -webkit-box-shadow: inset 0 0 9px rgba(0,0,0,0.3);
                background-color: #000;
            }
            #image_container::-webkit-scrollbar-thumb {
                background-color: #aaa; 
            }
        </style>
    </head>
    <body>
        <div id="image_container">
            <img id="panomara"src="panorama.jpg"/>
        </div>
    </body>
</html>
```

# div가로 스크롤
```html
<!DOCTYPE html>
<html>
    <head>
        <title></title>
        <style type="text/css">
        </style>
        <style type="text/css">
            #image_container{
                width: 500px;
                height: 400px;
                overflow-x: scroll;
                overflow-y: hidden;
                position: relative;
            }
            #image_content{
                width: 1500px;
            }
            .con_card{
                width: 280px;
                height: 400px;
                background-color: red;
                margin:10px;
                float:left;
            }
            #image_container::-webkit-scrollbar {
                width: 7px;
                height: 7px;
                background-color: #555;
            }
            #image_container::-webkit-scrollbar-thumb {
                background-color: #aaa; 
            }
        </style>
    </head>
    <body>
        <div id="image_container">
            <div id="image_content">
                <div class="con_card">1</div>
                <div class="con_card">2</div>
                <div class="con_card">3</div>
                <div class="con_card">4</div>
                <div class="con_card">5</div>
            </div>
        </div>
    </body>
</html>
```
