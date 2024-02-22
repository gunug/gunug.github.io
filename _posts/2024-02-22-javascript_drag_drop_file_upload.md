---
layout: post
title: javascript drag & drop file upload 드래그 드롭 파일 업로드
category: web
tags: javascript
---

# javascript drag & drop file upload 드래그 드롭 파일 업로드
* 참고링크 : <https://dev-gorany.tistory.com/254>

```html
<section id="ex9">
    <style>
        #ex9 .upload-box{
            width:500px;
            height: 300px;
            border:1px solid gray;
            box-shadow: 2px 3px 9px hsl(0, 0%, 47%);
            padding:10px;
        }
    </style>
    <h1>파일업로드 : DND & Trigger</h1>
    <div class="upload-box">
        <form enctype="multipart/form-data" action="이미지파일 처리서버 주소" method="post">
            <input type="hidden" name="name" value="default" />
            <input id="image_file" name="image" class="btn-file d-none" type="file" /> <!--파일 input box 형태-->
            <input type="submit" value="제출" />
        </form>
    </div>
</section>
```

```javascript
var sec9 = document.querySelector('#ex9');
var btnUpload = sec9.querySelector('.btn-upload');
var inputFile = sec9.querySelector('input[type="file"]');
var uploadBox = sec9.querySelector('.upload-box');

/* 박스 안에 Drag 들어왔을 때 */
uploadBox.addEventListener('dragenter', function(e) {
    console.log('dragenter');
});

/* 박스 안에 Drag를 하고 있을 때 */
uploadBox.addEventListener('dragover', function(e) {
    e.preventDefault();

    var vaild = e.dataTransfer.types.indexOf('Files') >= 0;

    if(!vaild){
        this.style.backgroundColor = 'red';
    }
    else{
        this.style.backgroundColor = 'green';
    }
    
});

/* 박스 밖으로 Drag가 나갈 때 */
uploadBox.addEventListener('dragleave', function(e) {
    console.log('dragleave');

    this.style.backgroundColor = 'white';
});

/* 박스 안에서 Drag를 Drop했을 때 */
uploadBox.addEventListener('drop', function(e) {

    e.preventDefault();
    
    const data = e.dataTransfer;
    
    //유효성 Check
    if(!isValid(data)) return;
    alert('파일유형 통과');
    
    document.querySelector('#image_file').files = data.files;
});
```

---

* 유효성 검사
  
```javascript
	function isValid(data){
		
		//파일인지 유효성 검사
		if(data.types.indexOf('Files') < 0)
			return false;
		
		//이미지인지 유효성 검사
		if(data.files[0].type.indexOf('image') < 0){
			alert('이미지 파일만 업로드 가능합니다.');
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
```

---

```javascript

```

* /mypage/upload 주소로 받는 서버사이드는 별도로 구성해야함