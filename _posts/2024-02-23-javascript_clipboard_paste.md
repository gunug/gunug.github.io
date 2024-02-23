---
layout: post
title: javascript clipboard paste 클립보드 붙여넣기
category: coding
tags: javascript simple-code
---

# javascript clipboard paste 클립보드 붙여넣기
* 스크린샷된 이미지를 클립보드에서 form에 밀어넣는 구문

```html
<form enctype="multipart/form-data" action="제출대상주소" method="post">
    <input type="hidden" name="name" value="default" />
    <input id="image_file" name="image" class="btn-file d-none" type="file" /> <!--파일 input box 형태-->
    <input type="submit" value="제출" />
</form>
```

```javascript
addEventListener("paste", onPaste);
function onPaste(event) {
    alert("붙여넣기");
    if (event.clipboardData.files.length) {
        let files = event.clipboardData.files;
        document.querySelector('#image_file').files = files;
        document.querySelector('#image_target').src = URL.createObjectURL(files[0]);
    }
}
```