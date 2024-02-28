---
layout: post
title: blob, multipart form-data
category: web
tags: 
---

# blob, multipart form-data
* 참고: https://velog.io/@aptakqmf12/%EC%84%9C%EB%B2%84%EC%97%90-%EC%9D%B4%EB%AF%B8%EC%A7%80-%EB%B3%B4%EB%82%B4%EA%B8%B0-multi-formdata-blob
* Blob(Binary Large Object)란 바이너리 형태중에서도 큰 객체를 뜻하는데, 주로 이미지, 비디오, 사운드 같은 멀티미디어 객체를 나타낸다.
* Blob은 4GB의 이진데이터의 위치포인터를 DB에 저장한다.

```javascript
var blob = new Blob([typedArray], {type: "application/octet-binary"})
var audioBlovb = new Blob([dataView], {type:type})

var reader = new FileReader();
reader.readAsArrayBuffer(blob);
//FileReader를 통해서 blob을 읽을 수 있다.
```

---

# Multi-FormData
1. 서버에 이미지를 보내기위해서는 브라우저에서 form을 통해서 파일을 전송한다.
1. 브라우저에서 보내는 HTTP메시지는 ```Content-Type```속성이 ```multipart/form-data```로 지정되며 정해진 형식에 따라 메시지를 인코딩한다
1. 서버에서는 해당 메시지에 대해 각 파트별로 분리하여 개별 파일의 정보를 얻는다

## 구성요소
* name, action, method, autocomplete, enctype

## enctype
* application/x-www-form-urlencoded
    * default값으로 모든 문자들을 서버로 보내기전에 인코딩됨을 명시함

* text/plain
    * 공백문자는 "+"로 변환, 나머지 문자는 인코딩하지않음을 명시

* multipart/form-data
    * 모든 문자들을 인코딩하지않음을 명시함. 이 방식은 <form>요소가 파일이나 이미지를 서버로 전송할때 주로 사용한다. 또한 요청시 POST로 보내야한다.

```html
<form action="/home/uploadfiles" method="post" enctype="multipart/form-data">
   파일명 : <input type="file" name="myfile">
   <button type="submit">제출하기</button>
</form>
```