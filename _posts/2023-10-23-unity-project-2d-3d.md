---
layout: post
title: unity 2d 3d 프로젝트 전환
category: unity3d
tags: c# simple-code 
---

* [참고자료](https://docs.unity3d.com/kr/2021.1/Manual/2DAnd3DModeSettings.html)

* Edit > Project Settings 를 선택하고 Editor 메뉴를 통해 에디터 설정 창을 엽니다.
* Default Behavior Mode 를 2D 또는 3D 로 설정합니다.
* 기존 Scene이 있다면 새로 생성합니다.

* 3D 프로젝트로 생성되었을 경우 필수 2D 패키지들이 설치되지 않은 상태이므로 Package manager에서 2d관련 패키지 추가설치가 필요
* 이미 import된 그래픽 객체의 경우 texture type을 sprite로 변경필요