---
layout: post
title: unity audio clip 오디오 클립
category: unity
tags: 
---

# AudioClip

* (오디오 클립 다운 받는곳)<https://file-examples.com/index.php/sample-audio-files/sample-mp3-download/>
* 700kb mp3 오른쪽 'download sample mp3 file' 클릭
* 광고는 우상단 닫기 버튼 눌러서 끄기
* downloading.. 기다려면 재생장치에서 mp3를 직접 들어볼 수 있음
* 더보기(...)에서 download 클릭하여 mp3 파일을 다운로드

---

# AudioClip import
* 다운로드 받은 mp3 파일을 project 창에 드래그 드랍하여 import

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730878697.jpg" />
* project창 마우스 우클릭, import new asset 선택하여 import하는 방법도 있음

---

# Scene에 배치
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730878906.jpg" />
* Hirarchy창 빈공간 마우스 우클릭, create empty 선택하여 빈 game object 생성
* 이름을 Audio1 등으로 변경하여 다른 객체와 혼동하지 않도록 합니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730879062.jpg" />
* 새로만든 game object를 선택
* Project창에 있는 mp3파일을 드래그 하여 inspector창의 빈공간에 드랍
* AudioSource라는 Component 생성 확인

---

# 공간 소리

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730879530.jpg" />
* AudioSource > Spatial Blend를 1로 변경하여 거리와 방향에 따라 소리를 출력 하도록 변경