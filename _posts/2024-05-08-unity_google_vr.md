---
layout: post
title: Unity Google Vr 구글 카드보드
category: unity3d
tags:
---

* 2020버전이후 부터는 다음의 설치방법을 권장
* https://developers.google.com/cardboard/develop/unity/quickstart?hl=ko
* package manager > + > add from git url > 링크주소에 있는 git 주소 입력하여 등록
* https://github.com/googlevr/cardboard-xr-plugin.git
* sample을 import하여 scene 확인

---

## switch platform
* Build Settings > Android
* Switch Platform

## Scene 등록
* Assets\Samples\Google Cardboard XR Plugin for Unity\1.24.0\Hello Cardboard\Scenes
* HelloCardboard.unity

* 다음의 내용은 (https://developers.google.com/cardboard/develop/unity/quickstart?hl=ko)다시 기입한 내용입니다.

## 해상도 설정
* Project Setting > Player > Resolution and Presentation
* Default Prientation : Landscape Left
* Optimized Frame Pacing 체크 해제

## 기타 설정
* Project Setting > Player > Other Settings
* Auto Graphics API 체크 해제
* Vulkan 선택후 - 로 제거
* OpenGLES3만 남도록 합니다.
* Minimum API Level : Android 8.0 'Oreo' (API level 26)
* Target API Level : API lavel 33 이상 선택
* Scripting Backend : IL2CPP 선택
* Target Architectures : ARMv7, ARM64 모두 체크
* Internet Access : Require 선택

## 게시 설정
* Project Setting > Player > Publishing Settings
* Build > Custom Main Gradle Template 체크
* Assets\Plugins\Android\mainTemplate.gradle에 다음내용 추가

## XR플러그인 관리 설정
* Project Setting > XR Plug-in Management
* Plug-in Providers > Cardboard XR Plugin 체크

## 빌드
* Build, Build and Run 선택
  
```
  implementation 'androidx.appcompat:appcompat:1.6.1'
  implementation 'com.google.android.gms:play-services-vision:20.1.3'
  implementation 'com.google.android.material:material:1.6.1'
  implementation 'com.google.protobuf:protobuf-javalite:3.19.4'
```

* Build > Custom Gradle Properties Template 체크
* Assets\Plugins\Android\gradleTemplate.properties에 다음내용 추가
  
```
  android.enableJetifier=true
  android.useAndroidX=true
```

---

## 각종 에러
* Manifest merger failed with multiple errors, see logs See the Console for details.
* 빌드에러
* 튜토리얼 : https://www.youtube.com/watch?v=we-sgSmy5p0
* 결론 : SDK 중복등록으로 인한 Manifest 겹침문제, 차라리 프로젝트를 다시 시작하는 것이 낫다

* Manifest merger failed : uses-sdk:minSdkVersion 22 cannot be smaller than version 26 declared in library [:GfxPluginCardboard:] C:\Users\One The Lab\.gradle\caches\transforms-3\3df939d206deefe776eb9a648d0c485a\transformed\GfxPluginCardboard\AndroidManifest.xml as the library might be using APIs not available in 22 See the Console for details.