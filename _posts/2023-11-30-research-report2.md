---
layout: post
title: research report 연구보고서
category: work
tags:
---

# “모션 캡쳐 장비를 활용한 실사 모델링 실시간 합성 연구”
# Real-time synthesis of realistic modeling using motion capture device

* 연구기간 2023.05.18 ~ 2023.11.24

---

## 연구 개요 및 목표 (2페이지) 



1. 모션 캡쳐 장비 (Motion Capture Device)
![image](https://github.com/gunug/gunug.github.io/assets/52345276/603ddced-ce40-4ec6-9cce-019f55d67785)
![image](https://github.com/gunug/gunug.github.io/assets/52345276/c9054dee-2750-4d9d-aa7b-bc898003643f)
* 이미지 출처 : 옵티트랙 (https://optitrack.com/)

    * 정의
        * 사용자의 특정 자세 또는 연속 동작을 보이는 그대로 인식하여 대응 소프트웨어에 입력값으로 전달하는 장비
    * 특징
        * 옵티트랙 모션 캡쳐 장비를 이용하여 사람의 움직임을 캡쳐할 수 있다.
        * 움직임은 실시간으로 가상캐릭터에 적용 가능하다
        * 녹화, 반복 재생이 가능하다.

3. 실사 모델링 (Photorealistic Modeling)
![image](https://github.com/gunug/gunug.github.io/assets/52345276/a39c5fd1-c5bf-4ba5-aa2b-5b91d4d04fba)
* 이미지 출처 : 3D Art (www.3dart.it)
    * 정의
        * 다중 카메라로 대상물의 삼차원 기하구조를 얻고, 실사와 CG를 합성하여 모델을 생성하는 방식
    * 특징
        * 3D Scan된 실사 모델을 통하여 실제 사람과 같은 가상의 주인공을 만들수 있다.
        * 복제 및 대역이 가능한 디지털 미디어 특성을 이용할 수 있다.

5. 실시간 합성 (Real-Time synthesis)
![image](https://github.com/gunug/gunug.github.io/assets/52345276/c28ea064-22d5-48b9-a1b7-af9b74348283)
* 이미지 출처 : iabm (https://theiabm.org/)

    * 정의
        * 사전 시각화, 게임 엔진, 모션 캡처, 가상 카메라, LED 월 등의 기술을 활용하여 가상 이미지와 실사 이미지를 실시간으로 합성하는 것
        * 버추얼 프로덕션(virtual production)에서 자주 사용 하는 방식
    * 특징
        * 사전 렌더링(Pre-rendering)이 아닌 실시간 렌더링 (Real-Time Rendering)의 특징을 갖는다
        * 라이브 방송 및 관람객와의 상호작용을 연출 할 수 있다.

- 모션캡쳐 장비를 활용한 실사 모델링 실시간 합성이란 무엇인가?
실제 사람을 가상의 모델로 제작하고 모션캡쳐 장비를 이용하여 움직임을 구현하다. 이를 실시간 합성을 하여 버추얼 프로덕션을 가능하게 한다.

- 왜 모션 캡쳐 장비를 활용하여 실사 모델링을 실시간 합성해야 하는가?

4. XR Studio
    * 정의
        * LED월과 AI 기술을 활용해 기존 스튜디오 세트의 물리적 한계에서 벗어나 고화질의 가상환경을 구현하는 스튜디오
        * 다양한 몰입형 및 인터랙티브 기술 영역을 아우르는 확장현실(XR)은 증강현실(AR, Augmented Reality), 혼합현실(MR, Mixed Reality), 가상현실(VR, Virtual Reality)을 망라한다.
    * 특징
        * 기존 크로마키(chroma key) 촬영 등의 영상 합성 콘텐츠보다 시간과 비용을 획기적으로 줄일 수 있다.
        * XR 영상은 위치트래커 기술과 스튜디오에 마커 세팅을 통해 실시간으로 Unreal Engine 내의 위치와 동기화되어 카메라 구도와 화각에 따른 가상환경 배경을 미디어 서버를 통해 LED로 즉각 송출한다. 이와 동시에 LED 영상정보와 위치정보를 분석하여 또 다른 미디어 서버를 통해 가상공간을 더 확장해(AR 기술을 활용) 송출함으로써 만들어진다.
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
* XR Studio 실사용 사례, 업체 포트폴리오, 자료 사진, 동영상 등
* 업무를 직접 수행하거나, 업무관련 인재양성에 활용될수 있다.


---

## 참고문헌
* 사전 렌더링, 실시간 렌더링 : [https://garagefarm.net/ko-blog/pre-rendering-versus-real-time-rendering-whats-the-difference](https://garagefarm.net/ko-blog/pre-rendering-versus-real-time-rendering-whats-the-difference)
* obj, mtl 파일 : [https://mvje.tistory.com/83](https://mvje.tistory.com/83)
* 모션 캡쳐 장비 : [https://www.kci.go.kr/kciportal/ci/sereArticleSearch/ciSereArtiView.kci?sereArticleSearchBean.artiId=ART002845433]
* 실사 모델링 : [https://www.kci.go.kr/kciportal/ci/sereArticleSearch/ciSereArtiView.kci?sereArticleSearchBean.artiId=ART001122098]
* 실시간 합성 : [http://journal.dcs.or.kr/xml/33684/33684.pdf / https://www.riss.kr/search/detail/DetailView.do?p_mat_type=be54d9b8bc7cdb09&control_no=2724b55da005c8ddffe0bdc3ef48d419]
* XR 스튜디오 : [https://www.chosun.com/special/special_section/2022/12/26/SGVPXCSNNBGM3CTN5JR7VGKW7Q/ / https://www.autodesk.com/kr/design-make/articles/what-is-xr-kr#1 / http://tech.kobeta.com/%EB%B0%A9%EC%86%A1%EC%9D%98-xr%EA%B3%BC-%EC%A1%B0%EB%AA%85/]