---
layout: post
title: javascript cropper.js 이미지 크롭
category: web
tags: javascript
---

# javascript cropper.js 이미지 크롭
* <https://fengyuanchen.github.io/cropperjs/>
* <https://github.com/fengyuanchen/cropperjs/blob/main/README.md>

```html
<script src="https://code.jquery.com/jquery-3.4.1.min.js"></script>
<!-- <script src="https://fengyuanchen.github.io/cropper/js/cropper.js"></script> -->
<link href="node_modules/cropperjs/dist/cropper.css" rel="stylesheet">
<script src="node_modules/cropperjs/dist/cropper.js"></script>

<!-- Wrap the image or canvas element with a block element (container) -->
<style>
/* Make sure the size of the image fits perfectly into the container */
img {
  display: block;

  /* This rule is very important, please don't ignore this */
  max-width: 100%;
  min-height: 600px;
}
</style>
<div>
  <img id="image" src="picture.jpg" />
</div>
<div id="preview" style="overflow: hidden;">
    <img src="picture.jpg" />
</div>

<script>
//import 'cropperjs/dist/cropper.css';
//import Cropper from 'cropperjs';

const image = document.getElementById('image');
const preview = document.getElementById('preview');
const cropper = new Cropper(image, {
  aspectRatio: 16 / 9,
  preview: preview,
  crop(event) {
    console.log(event.detail.x);
    console.log(event.detail.y);
    console.log(event.detail.width);
    console.log(event.detail.height);
    console.log(event.detail.rotate);
    console.log(event.detail.scaleX);
    console.log(event.detail.scaleY);
  },
});
</script>
```


---

# 에러
* Cannot use import statement outside a module
* type="module"를 추가해야 모듈로 사용함
* 경로중 src가 아닌 dist에서 js와 css를 따서 써야 했음
* -------------- 안되길레 다음의 방법을 사용
* ```import Cropper from 'cropperjs';``` 주석처리
* type="module" 삭제

---

# formdata send까지 붙어있는 소스코드

```html
<script src="https://code.jquery.com/jquery-3.4.1.min.js"></script>
<!-- <script src="https://fengyuanchen.github.io/cropper/js/cropper.js"></script> -->
<link href="node_modules/cropperjs/dist/cropper.css" rel="stylesheet">
<script src="node_modules/cropperjs/dist/cropper.js"></script>

<!-- Wrap the image or canvas element with a block element (container) -->
<style>
/* Make sure the size of the image fits perfectly into the container */
img {
  display: block;

  /* This rule is very important, please don't ignore this */
  max-width: 100%;
}
</style>
<div>
  <img id="image" src="picture.jpg" />
</div>
<div id="preview" style="overflow: hidden;">
    <img src="picture.jpg" />
</div>
<input type="button" onclick="setImage();" value="set image" />
<img id="test" />

<script>
//import 'cropperjs/dist/cropper.css';
//import Cropper from 'cropperjs';

const image = document.getElementById('image');
const preview = document.getElementById('preview');
const cropper = new Cropper(image, {
  aspectRatio: 16 / 9,
  preview: preview,
  crop(event) {
    console.log(event.detail.x);
    console.log(event.detail.y);
    console.log(event.detail.width);
    console.log(event.detail.height);
    console.log(event.detail.rotate);
    console.log(event.detail.scaleX);
    console.log(event.detail.scaleY);
  },
});
let img_target = document.querySelector("#image_file");
let form_target = document.querySelector("#form_target");
let test_target = document.querySelector("#test");
let formdata = new FormData();
let canvas_;

function setImage(){
    //cropper.getCroppedCanvas({ maxWidth: 4096, maxHeight: 4096 })
    //img_target.crossOrigin = "anonymous";
    //img_target.file = cropper.getCroppedCanvas({ maxWidth: 4096, maxHeight: 4096 }).toDataURL("image/jpg");
    canvas_ = cropper.getCroppedCanvas({ maxWidth: 2048, maxHeight: 2048 })
    let blob_ = canvas_.toBlob((blob)=>{
        file = new File([blob], 'cropped.jpg', { type: 'image/jpeg' }); //blob을 가지고 파일을 생성
        let url = window.URL.createObjectURL(blob);
        test_target.src = url;
        //여기까진 성공

        submit();
    }, "image/jpeg", 1.0);
}

async function submit() {
    let imageBlob = await new Promise(resolve => 
    cropper.getCroppedCanvas({ maxWidth: 2048, maxHeight: 2048 }).toBlob(resolve, 'image/jpeg')
    );
    console.log("step1");
    let formData = new FormData();
    formData.append("firstName", "Bora");
    formData.append("image", imageBlob, "cropped.jpg");
    console.log("step2");
    let response = await fetch('이미지업로드 대상주소', {
    method: 'POST',
    body: formData
    });
    let result = await response;
    console.log(result);
}
</script>
```