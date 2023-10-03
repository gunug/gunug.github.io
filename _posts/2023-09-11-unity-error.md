---
layout: post
title: Unity Error 유니티 에러
category: unity3d
tags: error
---

# 문제해결
* 안드로이드 SDK 설치 후 빌드 문제
* 해당 버전의 SDK만 Unity와 호환됩니다.

---

# 유니티 오디오 관련문제

---

# 점검사항
* Game창의 Mute Audio 토글 확인
* AudioClip선택 후 inspector창 하단의 클립 재생 직접 시켜보기
* oculus앱이 켜진 상태에서 VR이 연결되어 있으면 오디오가 출력되지 않음

---

# 오디오 코덱확인
* 오디오 재생 프로그램 (팟플레이어)등을 이용하여 오디오 코덱 확인
* 타입캐스트 무료버전의 경우 MPEG Audio Layer 3(0x55) 16000Hz

---
Audio preview in Inspector does not work

---

# 전/반각 문자, 2byte 문자 관련
* ExecutionEngineException: String conversion error: Illegal byte sequence encounted in the input.
* 오디오장치 이름을 불러오는 과정에서 한글표기된 오디오 장치 이름이 있었는듯하다.
* 이에 따라 2바이트 문자를 1바이트 문자처럼 표현하려다가 에러가 나는듯