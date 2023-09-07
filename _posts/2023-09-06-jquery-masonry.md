---
layout: post
title: jquery masonry
category: web
tags: javascript jquery
---

# jquery masonry.md
* 웹사이트 : https://masonry.desandro.com/
* [자료파일](/file/zip/Masonry.zip)

```html
<!DOCTYPE html>
<html>
    <head>
        <title></title>
        <meta charset="utf-8">
        <script src="jquery-3.2.1.min.js"></script>
        <script src="masonry.pkgd.min.js"></script>
        <style type="text/css"> 
            .grid{width: 100%;} .grid-item { width: 200px; } .grid-item--width2 { width: 400px; } 
            img{ width:100%; display: block; } 
        </style> 
        <script type="text/javascript"> 
            $( document ).ready(function() { $('.grid').masonry({ // options 
            itemSelector: '.grid-item', columnWidth: 200 }); }); 
        </script> 
    </head>
    <body>
    </body>
</html>
```