---
layout: post
title: image gallery 이미지 저장소 만들기
category: research
tags: php html css javascript
teaser: https://image.onethelab.com/thumbnail/1709720179.jpg
---

# image gallery 이미지 저장소 만들기
<img src="https://image.onethelab.com/resized/1709720179.jpg" />

## 작업 기간
* 2024-02-22 ~ 2024-03-06 (총13일)
* 중간에 kernel panic으로 인한 서버 재설치로 시간이 좀 더 지체됨

## 작업 목록
### 업로드폼
* 파일선택
  * 선택 후 이미지 표시
* 드래그 드랍
  * 드래그 드랍 이벤트
  * 파일을 form data로 연결
* 복사 붙여넣기
  * Ctrl+V 키보드 이벤트
  * 클립보드를 form data로 연결
* 파일검사 : 이미지, 용량, 확장자 등
  
### 이미지 파일
* 이미지를 업로드 받고 폴더에 정리
  * 파일명 규칙
* 이미지 크롭
  * 원하는 위치 크기 크롭을 넣으면 구글포토를 한번 거치지 않아도 될것 같은데..
  * cropper.js 사용
* 이미지 크기변경
  
### 보안
* 이미지 업로드, 삭제 제한
  * 구글로그인 같은거 사용하면 좋을텐데
  * 패스워드 암호화
  * 동일 도메인의 form 데이터만 받기 - 세션으로 해결 가능할것 같다.
* HTTPS용 인증서 발급
  * Let's Encrypt
  * 인증서 자동갱신

---

## 해상도 규칙
* 해상도 참고 : https://namu.wiki/w/%ED%95%B4%EC%83%81%EB%8F%84/%EB%AA%A9%EB%A1%9D
* 320*180 : 16:9
* qVGA, 240*160, 3:2
* VGA, 640*480, 4:3
* WSVGA, 1024*576, 16:9
* HD, 1280*720, 16:9
* FHD, 1920*1080, 16:9
* QHD, 2560*1440, 16:9
* UHD, 3840*2160, 16:9

## 해상도 목표
* 취급 비율은 16:9
* 취급해상도는 320*180, WSVGA(1024*576), HD(1280*720),
* 목표는 FHD(1920*1080)에서 사용될 사진 자료 

## 폴더명 규칙
* original,1080p,720p,180p

## 파일명 규칙
* YYYYMMDDHHmmss
* date("YmdHis");
* time();

---

* uploader_test.html

```html
<h1>Image gallery</h1>
<style>
    .upload-box{
        min-width: 200px;
        min-height: 200px;
        border: solid 1px black;
    }
</style>
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
    uploadBox.addEventListener('dragover', function(e) {
        e.preventDefault();
    });
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
```

---

* cropper_test.html

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
    let response = await fetch('http://image.onethelab.com/image_upload.php', {
    method: 'POST',
    body: formData
    });
    let result = await response;
    console.log(result);
}
</script>
```

---

# complex.html
* 위 두버전을 합친 형태 cropper를 이미지가 교체될때 마다 destroy 하고 새로 생성해야(new) 했다

```javascript
<!-- ■ uploader start -->

<h1>Image gallery</h1>
<style>
    .upload-box{
        min-width: 200px;
        min-height: 200px;
        border: solid 1px black;
    }
</style>
<div class="upload-box">
    <img id="image_target" src="" />
    <form id="form_target" enctype="multipart/form-data" action="http://image.onethelab.com/image_upload.php" method="post">
        <label>select file, drag&drop, ctrl+v</label>
        <input type="hidden" name="name" value="default" />
        <input id="image_file" name="image" class="btn-file d-none" type="file" /> <!--파일 input box 형태-->
        <!-- <input type="submit" value="submit" /> -->
    </form>
</div>

<div>
    test
<img id="image" src="picture.jpg" />
</div>
<div id="preview" style="overflow: hidden;">
    <img id="crop_target" src="picture.jpg" />
</div>
<input type="button" onclick="setImage();" value="set image" />


<script>
    let crop_target = document.querySelector("#image");
    var uploadBox = document.querySelector('.upload-box');
    uploadBox.addEventListener('dragover', function(e) {
        e.preventDefault();
    });
    /* 박스 안에서 Drag를 Drop했을 때 */
    uploadBox.addEventListener('drop', function(e) {
        e.preventDefault();

        const data = e.dataTransfer;
        if(!isValid(data)) return; //유효성 Check

        document.querySelector('#image_file').files = data.files;
        //document.querySelector('#image_target').src = URL.createObjectURL(data.files[0]);
        del_cropper();
        crop_target.src = "";
        crop_target.src = URL.createObjectURL(data.files[0]);
        set_cropper();
    });

    let image_target = document.querySelector('#image_file');
    image_target.addEventListener("change", dataUpdate);
    function dataUpdate(e){

        const data = e.dataTransfer;
        if(!isValid(image_target)) return; //유효성 Check
        //document.querySelector('#image_target').src = URL.createObjectURL(image_target.files[0]);
        del_cropper();
        crop_target.src = "";
        crop_target.src = URL.createObjectURL(image_target.files[0]);
        set_cropper();
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
            //document.querySelector('#image_target').src = URL.createObjectURL(files[0]);
            del_cropper();
            crop_target.src = "";
            crop_target.src = URL.createObjectURL(files[0]);
            set_cropper();
        }
    }
    function isNull(v) {
        return (v === undefined || v === null) ? true : false;
    }
</script>

<!-- ■ cropper start -->

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

<script>
//import 'cropperjs/dist/cropper.css';
//import Cropper from 'cropperjs';

const image = document.getElementById('image');
const preview = document.getElementById('preview');
let cropper;
function del_cropper(){
    //alert(cropper);
    if(cropper != null){
        //alert("destroy!");
        cropper.destroy();
    } 
}
function set_cropper(){
    cropper = new Cropper(image, {
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
}
let img_target = document.querySelector("#image_file");
let form_target = document.querySelector("#form_target");
let formdata = new FormData();
let canvas_;

function setImage(){
    //cropper.getCroppedCanvas({ maxWidth: 4096, maxHeight: 4096 })
    //img_target.crossOrigin = "anonymous";
    //img_target.file = cropper.getCroppedCanvas({ maxWidth: 4096, maxHeight: 4096 }).toDataURL("image/jpg");
    alert(cropper);
    canvas_ = cropper.getCroppedCanvas({ maxWidth: 2048, maxHeight: 2048 })
    let blob_ = canvas_.toBlob((blob)=>{
        file = new File([blob], 'cropped.jpg', { type: 'image/jpeg' }); //blob을 가지고 파일을 생성
        let url = window.URL.createObjectURL(blob);
        //test_target.src = url;
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
    let response = await fetch('http://image.onethelab.com/image_upload.php', {
    method: 'POST',
    body: formData
    });
    let result = await response;
    console.log(result);
}
</script>
```