---
layout: post
title: 이미지 업로드 종합
category: web
tags: html javascript
---

# 이미지 업로드 종합
* form에서 파일선택
* 이미지파일 드래그 드랍
* 스크린샷 후 ctrl+v

```html
<html>
    <head>
        <title>one the lab image</title>
        <style>
            .upload-box{
                min-width: 200px;
                min-height: 200px;
                border: solid 1px black;
            }
        </style>
    </head>
    <body>
        <h1>one the lab image</h1>
        <h1>Image gallery</h1>
        <div class="upload-box">
            <img id="image_target" src="" />
            <form id="form_target" enctype="multipart/form-data" action="http://image.onethelab.com/image_upload.php" method="post">
                <label>select file, drag&drop, ctrl+v</label>
                <input type="hidden" name="name" value="default" />
                <input id="image_file" name="image" class="btn-file d-none" type="file" /> <!--파일 input box 형태-->
                <input type="submit" value="submit" />
            </form>
        </div>

        <script>
            var uploadBox = document.querySelector('.upload-box');

            /* 박스 안에서 Drag를 Drop했을 때 */
            uploadBox.addEventListener('drop', function(e) {
                e.preventDefault();

                const data = e.dataTransfer;
                if(!isValid(data)) return; //유효성 Check

                document.querySelector('#image_file').files = data.files;
                document.querySelector('#image_target').src = URL.createObjectURL(data.files[0]);
            });

            let image_target = document.querySelector('#image_file');
            image_target.addEventListener("change", dataUpdate);
            function dataUpdate(e){

                const data = e.dataTransfer;
                if(!isValid(image_target)) return; //유효성 Check
                document.querySelector('#image_target').src = URL.createObjectURL(image_target.files[0]);
            }

            ////
            function isValid(data){
                //파일인지 유효성 검사
                if(!isNull(data.types) && data.types.indexOf('Files') < 0) {alert("exit1"); return false;}
                
                //이미지인지 유효성 검사
                if(data.files[0].type.indexOf('image') < 0){
                    alert('이미지 파일만 업로드 가능합니다.'+data.files[0].type);
                    return false;
                }
                //파일의 개수는 1개씩만 가능하도록 유효성 검사
                if(data.files.length > 1){
                    alert('파일은 하나씩 전송이 가능합니다.');
                    return false;
                }
                //파일의 사이즈는 50MB 미만
                if(data.files[0].size >= 1024 * 1024 * 50){
                    alert('50MB 이상인 파일은 업로드할 수 없습니다.');
                    return false;
                }
                return true;
            }
            addEventListener("paste", onPaste);
            function onPaste(event) {
                if (event.clipboardData.files.length) {
                    let files = event.clipboardData.files;

                    document.querySelector('#image_file').files = files;
                    document.querySelector('#image_target').src = URL.createObjectURL(files[0]);
                }
            }
            function isNull(v) {
                return (v === undefined || v === null) ? true : false;
            }
        </script>
</html>
```