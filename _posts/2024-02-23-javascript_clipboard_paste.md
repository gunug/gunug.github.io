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

---

* 출처: https://min9nim.github.io/2019/10/access-clipboard/
  
# 클립보드에 데이터 쓰기(execCommand 이용)
```javascript
function copyToClipboard(val) {
  let t = document.createElement('textarea');
  document.body.appendChild(t);
  t.value = val;
  t.select();
  document.execCommand('copy');
  document.body.removeChild(t);
}
```

# 클립보드 데이터 읽기(execCommand 이용)
```javascript
<textarea id="output"></textarea>
<button id="paste">Paste</button>
function paste() {
  var pasteText = document.querySelector("#output");
  pasteText.focus();
  document.execCommand("paste");
  console.log(pasteText.textContent);
}

document.querySelector("#paste").addEventListener("click", paste);
```