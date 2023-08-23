---
layout: post
title: 유니티 오디오 관련문제 해결방법
category: unity3d
tags: unity3d audio c#
---
# 유니티 오디오 관련문제 해결방법

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
