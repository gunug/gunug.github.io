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

---

# 네이티브 클래스 관련
* 'HttpListenerExample.HttpServer' is missing the class attribute 'ExtensionOfNativeClass'!
* MonoBehaviour를 상속받지 않은 class를 컴퍼넌트로 사용하려 할때 발생

---

# ```System.InvalidOperationException: \\.\pipe\unity-ilpp```
* https://forum.unity.com/threads/unhandled-exception-system-invalidoperationexception-cant-find-file-pipe-unity-ilpp.1394605/
* 프로젝트가 세이프 보드로 구동할것을 권장됨
* 무시하고 실행하면 에러를 동반하여 빌드가 안됨
* 세이프모드로 구동하고 timeline를 업데이트 해보라는 이야기가 있음

---

# Library/PackageCache/  error
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710899204.jpg" />

# 패키지 리셋 후 input system 찾을수 없음
 'InputSystem' does not exist in the namespace 'UnityEngine'
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710899227.jpg" />

# 패키지 리셋 후 cinemachine 찾을수 없음
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710899245.jpg" />

# 우클릭 WASD 먹히지 않음
* all layout reset
# Project setting > player > other settings > input both
* 새로운 입력 시스템이 나오면서 구 시스템과 동시 사용 설정을 해주어야함