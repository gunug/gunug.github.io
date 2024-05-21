---
layout: post
title: AI Character 인공지능 캐릭터 만들기
category: AI
tags:
---

# AI Character 인공지능 캐릭터 만들기
* 참고 영상 : https://youtu.be/oB8C4FcZDD0?
si=cQ28bI7DnhdZr2b8

---

# 음성 -> 텍스트 (STT)
* OpenAI Wispher model

---

# 특성 성격 만들기
* ChatGPT Assistants API
* 나무위키에서 설정등을 PDF파일로 준비
* 실제 대사를 택스트로 준비
* 질문 답변을 텍스트로 준비

---

# 텍스트 -> 음성 (TTS)
* 파이썬 XTTS 라이브러리
* 파인튜닝
* 음원 품질이 좋고 잡음이 존재하지 않는 사운드 파일
* UVR5 : 음원에서 음성과 배경음 등을 분리해주는 프로그램
* 학습된 모델을 사용하여 TTS를 구현