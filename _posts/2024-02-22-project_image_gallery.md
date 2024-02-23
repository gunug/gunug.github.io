---
layout: post
title: image gallery 이미지 저장소 만들기
category: project
tags: php html css javascript mysql
---

# image gallery 이미지 저장소 만들기

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
* 이미지 크기변경

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