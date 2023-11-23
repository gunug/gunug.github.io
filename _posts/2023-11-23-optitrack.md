---
layout: post
title: optitrack 옵티트랙
category: etc
tags:
---

# 옵티트랙
* optitrack : [https://optitrack.com/](https://optitrack.com/)

---

# 시스템 제반사항
* Facial iPhone
* Pose optitrack 2.0
* Hand optitrack 3.0 -> 마뉴스 manus

* 필더세임회사에서 장갑만 판매 100만
* 버튜버 사업
* 립모션 울트라, 메타퀘스트 프로

---

# 딜레이 문제
* OSC통신, 유선통신 딜레이, 케이블 문제
* optitrack -> motive -> unity 0.2초
* optitrack 3.0 -> motive3.0 -> unity
* X scence plug-in 거쳐서 유니티로 간다

---

* IPhone Arkit
* InterM / load preset -> input1 메인 -> input3 옵티트랙 컴퓨터

## 창2
* Makers etc
* Skeleton 074 끄기
* 가운데 티포즈 드래그
* 크리에이트 스켈레톤

## 창3
* Take name 이름넣기
* 자동저장

## 창4
* Data에서 파일 선택
* labeling 숫자가 빨간 부분 튄부분을 100으로
* 튄부분 드래그 한뒤 C입력, X를 누르면 스무스

* Export tracking data -> fbx binary로 저장

---

# 시스템 이용
* 투꺼비집 '트러스'라고 적힌거 올림
* 모티브 2.0이라서 핸드 캡쳐는 실시간으로 안됨.

* 켈리브레이션 데이터 불러오기

## 1탭
* device mode 물러보면 실화면 확인가능
* 환경에 따른 반사광 제외. 반사광 막는 메트
* Mask visible
* StartWanding

## 2탭
* rigidbody. skeleton
* 상의 하의 신발 장갑 머리
* 37개, 41개 (우리꺼)
* 핑크색 마커는 움직여도 됨

* Maker detected 숫자가 변하는게 required 수량이랑 맞아야함 15분~20분, 모션캡쳐 40~50분 걸림

## 3탭
* 파일명 우클릭 export tracking data
* FBX binary. Frame rate 30프레임
* 블렌더에서 fbx임포트 하고 익스포트하면 유니티에서 쓸 수 있음

bass take 004

---

* 모티브에서 실시간 움직임
* 유니티에서 데이터 불러서 연동
* OBS 화면 송출

* 원캠퍼트 원향. Voss라는 일본사이트
* 외부협력 업체 대표님이 관리함
* 유니티에서 기본적인 플러그인 사용함

* 버츄얼 캐릭터 메이킹 렌더링 플러그인

* Vital facecam. 아이폰 전용 어플

---

* 마누스 핸드 트래킹
* Manus core.
* FBX로 뽑힘

---

169.254.191.202

* 순차전원기 하단의 Power. EPS실에서 전원이 공급됨 하단부터 1234. 좌부터 1234.
* 4096 * 1344 해상도