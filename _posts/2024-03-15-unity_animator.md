---
layout: post
title: unity 2d animator 애니메이터
category: unity3d
tags:
---

# unity 2d animator 애니메이터
* animation을 연결하여 긴 애니메이션 모음을 만드는 기능

## animator 창 열기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710428800.jpg" />

* Main Menu > Window > Animation > Animator 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710428932.jpg" />

* Animator 창의 이름 부분을 드래그하여 Scene창 옆에 드롭

## animation 추가

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710999512.jpg" />
* Project창의 Animation(일반적으로 삼각형이 날아가고 있는 모양의 아이콘)을 Animator로 드래그 드랍하여 추가

## animation 삭제

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710999617.jpg" />
* Animator창에 등록된 Animation에 마우스 우클릭 ```Delete```선택하여 삭제

---

## transition 연결
* 트랜지션은 애니메이션과 애니메이션을 연결해주는 역할을 합니다

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710999995.jpg" />
* Animator창 Animation 마우스 우클릭 '''Make Transition``` 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1711000065.jpg" />
* 연결할 대상 Animation을 클릭하여 트랜지션 연결

## transition 삭제
* transition(이어진 선)을 마우스로 클릭
* 윈도우 : 키보드의 delete키
* 맥 : Shift + backspace(←)키

---

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1711022992.jpg" />
* 새롭게 Animation3를 만들고 내용은 비워둡니다 (아무것도 움직이지 않도록)
* Animation3를 마우스 우클릭 하여 ```Set as Layer Default State``` 선택, 기본으로 등록합니다
* Animation1,2,3 간에 Transition은 없도록 합니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1711023185.jpg" />
* Project 창에서 Animation(삼각형이 날아가는 아이콘)을 찾아서 선택
* Inspector창에서 Loop Time의 체크 해제