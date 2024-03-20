---
layout: post
title: unity cinemachine 시네머신
category: unity
tags: 
---

# unity cinemachine 시네머신

# Cinemachine 설치
1. Window > Package Manager로 이동합니다. 오른쪽 상단 코너에 있는 검색창에서 “Cinemachine”을 검색합니다. 왼쪽에서 Cinemachine을 선택하여 Package 페이지에 액세스한 다음 Install 버튼을 클릭하여 Package를 설치합니다(그림 01). 

# Cinemachine brain
* 디렉터 역할

# Hierarchy > Cinemachine > virtual camera
* Focal length : 초점거리, 화각이 변경됨 '중립'프레이밍에 적절한 초점거리는 35mm
* Near Clipping Planes, Far Clipping Planes: 가장 가까운 클립핑 거리, 가장 먼 클리핑 거리
* Dutch : X축 방향으로 카메라를 기울여 극적인 각도 생성
* solo 버튼을 누르면 게임 뷰에서 가상 카메라 보기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710899079.jpg" />

# 타임라인에서 가상카메라 제어
* 타임라인 +버튼 > Cinemachine 추가
* Cinemachine brain 칸에 Main camera에 달려있는 Cinemachine brain 드래그 드롭
* Vriture Camera는 하단 이름부분에 드래그 드랍하여 Add Animation track 하여 제어할 수 있음
* Cinemathine brain 트랙에 virtual camera를 드래그 드랍하면 활성화 카메라를 정할 수 있음
* 카메라의 활성화 프레임을 교차하여 블렌딩