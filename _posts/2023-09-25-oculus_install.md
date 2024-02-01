---
layout: post
title: Oculus Install 오큘러스 설치 및 사용가이드
category: work
tags: tutorial

marp: true
theme: a4
class:
  - lead
  - invert
paginate: true
---

# 1. 최초 설치
* 최초 1회 새 컴퓨터 및 새 오큘러스 프로 기기에 설정해야 할 사항입니다.
* 이미 설치되어 있는 경우에는 수행할 필요가 없습니다.

## 오큘러스 프로 최초 실행 후 설정
* 해드셋을 끼고 안내에 따라 최초 실행 및 설정과정을 진행 하시면 됩니다.

---

## 스마트폰에 오큘러스 앱 설치
* 개발자 모드는 1:1로 연결된 스마트폰에서 가능합니다.
* 앱 설치 후 기기를 등록하고 다음의 절차로 개발자 모드를 활성화 합니다.

![image width:800px](https://github.com/gunug/gunug.github.io/assets/52345276/5d81a317-27d1-4e25-9fce-9c900af4a052)

* [개발자 모드 단체등록 관련 에러](https://playvr.co.kr/bbs/board.php?bo_table=TIP&wr_id=13)

* https://dashboard.oculus.com/organizations/create/

* 새 단체 만들기 -> 원하는 명칭 적기 -> i understand 체크박스 클릭 후 제출

---

## 베타 기능 활성화
* oculus PC용 프로그램 실행하고 다음 순서대로 베타 기능을 활성화 합니다.

![image width:800px](https://github.com/gunug/gunug.github.io/assets/52345276/b7a92dd1-b7a1-44ae-b869-32b66f4785e3)

---

## PC에 오큘러스 앱 설치
* [오큘러스 퀘스트2 사이트](https://www.meta.com/kr/ko/quest/setup/?utm_source=www.tomsguide.com&utm_medium=oculusredirect)
* https://www.meta.com/kr/ko/quest/setup/?utm_source=www.tomsguide.com&utm_medium=oculusredirect
* 오큘러스 퀘스트2와 프로는 같은 소프트웨어를 사용합니다.
* 오큘러스 퀘스트2의 소프트웨어를 다운로드 하여 설치합니다.

---

![image width:800px](https://github.com/gunug/gunug.github.io/assets/52345276/1e80b1bb-83d4-410f-a86e-d76a955443b8)

* 소프트웨어 다운로드 선택하여 설치과정 진행

---

# 2. Mitech VR 소프트웨어 실행
* 시연을 하기 위해 해드셋 및 소프트웨어 실행 절차 입니다.
* 매 시연때 다음의 방법으로 실행하시면 됩니다.

---

## PC와 VR기기 연결
* USB-C 케이블을 이용하여 해드셋과 컴퓨터를 연결 합니다.
* 해드셋을 쓰고 'USB디버깅 허용' 또는 '파일 접근 허용' 팝업이 나온다면 '허용' 선택합니다.
* 실수로 '거부'를 눌렀다면 케이블을 뺐다가 다시 꽂으면 됩니다.

---

![image width:800px](https://github.com/gunug/gunug.github.io/assets/52345276/9f3406ea-d0cc-4254-9ed4-dc41afefee93)

* 빠른설정 > Quest Link 선택

---

![image width:800px](https://github.com/gunug/gunug.github.io/assets/52345276/f95f900a-8cc5-4311-851e-4754fa111a74)

* Quest Link 초기화면이 나오면 VR해드셋 준비 완료입니다.

---

## 소프트웨어 실행

![image width:800px](https://github.com/gunug/gunug.github.io/assets/52345276/21447573-5eb5-4da5-bd7f-f2bd122d5a28)

* Project_MITech_VR 소프트웨어를 실행 합니다.

---

# 3. 히든키
* 시연 도중 콘텐츠 제어를 위한 히든키 입니다
* 키보드 최상단 좌측부터 순서대로 배치되어 있습니다.

---

## 첫줄 - 위치이동
* Q : 시작지점으로 이동
* W : 제품존으로 이동
* E : 영상존으로 이동
* T : 수술대 앞으로 이동
* ※LocationManager.cs에 명시

---

## 둘째줄 - 옵션
* A : 옵션창 표시
* S : 옵션창 숨기기
* D : 그래픽 - 상
* F : 그래픽 - 중
* G : 그래픽 - 하
* H : 음량 - 줄이기
* J : 음량 - 늘리기
* ※OptionChanger.cs에 명시