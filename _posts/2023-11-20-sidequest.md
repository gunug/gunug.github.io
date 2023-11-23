---
layout: post
title: sidequest 사이드퀘스트
category: vr
tags: 
---

* 출처 [https://www.reddit.com/r/OculusQuest/comments/13zbiiw/how_can_i_disable_sidequest_app_audio_streaming/](https://www.reddit.com/r/OculusQuest/comments/13zbiiw/how_can_i_disable_sidequest_app_audio_streaming/)
* sidequetst의 stream 기능을 이용하면 헤드셋에서 소리가 들리지 않는 문제
* 기존 8000000 부분을 다음과 같이 입력하면 사운드 문제 해결
```markdown
8000000 --no-audio
```