---
layout: post
title: research report 연구보고서
category: work
tags:
---

# “모션 캡쳐 장비를 활용한 실사 모델링 실시간 합성 연구”
# Real-time synthesis of realistic modeling using motion capture device

* 3차년도 연구과제
* 연구기간 2023.05.18 ~ 2023.11.24

---

## 연구 개요 및 목표 (2페이지) 
- 왜 모션 캡쳐 장비를 활용하여 실사 모델링을 실시간 합성해야 하는가?

1. 모션 캡쳐 장비 (Motion Capture Device)
    * 정의
        * 
    * 특징
        * 옵티트랙 모션 캡쳐 장비를 이용하여 사람의 움직임을 캡쳐할 수 있다.
        * 녹화, 반복 재생이 가능하다.

2. 실사 모델링 (Photorealistic Modeling)
    * 정의
        * 
    * 특징
        * 3D Scan된 실사 모델을 통하여 실제 사람과 같은 가상의 주인공을 만들수 있다.
        * 복제 및 대역이 가능한 디지털미디어 특성을 이용할 수 있다.

3. 실시간 합성 (Real-Time synthesis)
    * 정의
        *  
    * 특징
        * 사전 렌더링(Pre-rendering)
        * 실시간 렌더링 (Real-Time Rendering)
        * 크로마키 (Chroma Key) [크로마키 에셋](https://assetstore.unity.com/packages/tools/video/chroma-key-kit-71684)

4. XR Studio
    * 정의
        * 
    * 특징
        * 

- 특징들을 나열하면 모션 캡쳐를 사용했을때, 실사 모델링을 사용했을때, 실시간 합성을 했을때의 특장점을 나열할 수 있다.
- XR Studio는 000 한 장점과 특징들이 있다
- 이 연구는 Real-Time XR Studio를 구축하기 위한 선행 절차

---

## 연구 내용 및 결과 (10페이지)
* 배경, 사물, 사람, 이펙트로 나누어 실사(사진, 동영상, 실시간 영상) 
* 미디어 및 가상미디어(3D 모델, 파티클 시스템)를 실시간 합성하여 영상매체(전광판, 빔프로젝터, 모니터)에 투사

1. 구성요소
    1. 배경
        * 실사(리얼타임)
        * 실사(녹화된)
        * 가상(3D model)
    2. 사물
        * 실사(리얼타임)
        * 실사(녹화된)
        * 가상(3D Model)
    3. 사람
        * 실사
    4. 이펙트
        * 파티클(particle)

1. 모션 캡쳐 장비 (Motion Capture Device)
    1. 캡쳐 장비 - Optitrack
    3. 처리 프로그램 - Unity 3D
2. 실사 모델링 (Photorealistic Modeling)
    1. 캡쳐 장비 - Smart shooter 3
    2. 합성 프로그램 - Agi soft meta shape
        * files, psx
        * Obj, Mtl(Material Library File 로 obj 에서 사용되는 재질 속성들의 정보를 담고 있음), Jpg
    3. 리깅 프로그램 - Mixamo
3. 실시간 합성 (Real-Time synthesis)
    1. 실시간 합성 프로그램 - Unity 3D
    2. 실시간 모션 캡쳐 API - 

---

## 기대 성과 및 활용 계획 (2페이지)

* Real-Time XR Studio를 구축하기 위한 선행 절차를 통하여 Real-Time XR Studio의 구성요소 중 일부를 직접 개발하고 적용 및 개선을 할 있는 여지가 생긴다.

---

## 참고문헌
* 사전 렌더링, 실시간 렌더링 : [https://garagefarm.net/ko-blog/pre-rendering-versus-real-time-rendering-whats-the-difference](https://garagefarm.net/ko-blog/pre-rendering-versus-real-time-rendering-whats-the-difference)
* obj, mtl 파일 : [https://mvje.tistory.com/83](https://mvje.tistory.com/83)