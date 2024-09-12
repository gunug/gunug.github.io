---
layout: post
title: 2024년 2학기 피지컬 컴퓨팅 스튜디오
category: education
tags: kaywon
teaser: 
---

# 1주차 - 오리엔테이션
* [introduction 교수소개](/education/2024/03/02/introduction.html){:target="_blank"}
* 16년차 프로그래머 (action script, c++, c#, html, css, java script, php)
  * AR, VR, 피지컬 컴퓨팅, 메타버스
* 9년차 전문대학교 강사 (디자인 대학생 대상 프로그래밍 교육)
  * Unity3D, Arduino, 프론트엔드(html,css,javascript), 백엔드(php,mysql)
* [2024년 학과 수칙 및 수업 진행 방식](/subpage/2024/03/03/education-rule.html){:target="_blank"}
* [생성형 AI를 활용한 교수/학습 운영방법 가이드라인](/subpage/2024/09/01/sub_ai.html){:target="_blank"}

# 실습
* [Meta quest 설치 및 사용](/vr/2024/09/04/meta_quest_start.html){:target="_blank"}
* [Meta XR Project Setting](/vr/2024/09/05/meta_xr_start.html){:target="_blank"}

# 1주차 과제
* 개인별로 제출합니다.
* 2~3인 1조로 팀 만들기. (1인 불가), 팀이름, 팀원 명시
* 생성형 AI 사용내역 공유 링크 - ([생성형 AI를 활용한 교수/학습 운영방법 가이드라인](/subpage/2024/09/01/sub_ai.html){:target="_blank"} 참고)
* VR에서 가상의 스마트폰을 만든다면 스마트폰에 표시할 글씨 크기는 몇으로 해야할까? 
* VR에서 폰트의 크기의 단위는 무엇이 적절할까? (cm, inch, pixel, pica, point)
* 정보가 없는 상태에서 정보를 수집하고 자신이 할 수 있는 가장 합리적인 이유를 찾아서 글씨 크기를 정해봅시다
* 자료조사를 하면서 찾은 모든 자료는 링크를 첨부합니다.
* PDF 파일로 제작 합니다. 문서 양식, 디자인 등은 신경쓰지 않아도 됩니다. (내용이 중요)

---

# 2주차
* [vr smart phone 가상현실 스마트폰](/vr/2024/09/11/vr_smart_phone.html){:target="_blank"}

# 2주차 수업진행
* 개인정보 보호 목적으로 기기를 공장초기화 합니다. 이후 내용은 1주차와 동일 합니다.
* [meta quest factory reset 메타 퀘스트 공장 초기화](/vr/2024/09/11/meta_quest_factory_reset.html){:target="_blank"}
* [Meta quest 설치 및 사용](/vr/2024/09/04/meta_quest_start.html){:target="_blank"}
* [Meta XR Project Setting](/vr/2024/09/05/meta_xr_start.html){:target="_blank"}
* [vr empty room 빈 가상공간 만들기](/vr/2024/09/12/unity_empty_vr_room.html){:target="_blank"}

# 2주차 실습
## 실제 폰에 글꼴 크기 맞추기
* 각자 자신의 폰에 30pt 크기로 "Hello World!" 글자를 출력해 봅시다.
* Arial 글꼴을 사용합니다. (윈도우, 맥 모두 기본으로 설치되어 있는 글꼴)
* 지난 시간에 pt 단위가 어떤 의미를 가지고 있는지 조사 하였다면 대략 추측되는 방법이 있을 것입니다.
* 이론상 1inch는 72pt 입니다. 계산이 맞다면 모든 학생들의 폰에는 같은 크기의 글자가 떠있어야 합니다.
* 친구들과 글자 크기를 비교해 봅시다. 이론과 실제가 맞는지도 확인해 봅시다.

<div style="font-size:30pt; font-family:arial;">Hello World</div> css로 입력한 30pt의 글자
  
## VR 폰에 글꼴 크기 맞추기
* VR환경에 Cube를 만들고 자신의 폰의 화면과 크기를 맞춥니다(x,y,z 값 입력)
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726085214.jpg" />
* 기본 생성된 큐브는 scale(크기 배율)이 1,1,1이며 1m * 1m * 1m에 해당합니다.
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726091948.jpg" />
* 유니티 특성상 이미지 텍스쳐는 큐브의 크기에 맞추어 늘어지게 되어있습니다. (비율 무시)
* VR 폰에 30pt 크기로 "Hello World!" 글자를 출력해 봅시다.
* Arial 글꼴을 사용합니다. (윈도우, 맥 모두 기본으로 설치되어 있는 글꼴)

# 2주차 과제
* 실험은 같이(이미지 전달 등) 상의 하는것도 좋습니다, 실험 결과는 개인별로 제출합니다.
* 내가 선정한 폰트 크기를 유니티에서 어떻게 구현할것인가? 각자 고민해보고 기술합니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726090569.jpg" />

* 선정한 폰트 크기의 "Hello World!"글자를 메타 퀘스트 3에서 출력한 스크린샷 (meta horizon의 미러링 기능을 이용하여 촬영) 합니다.
* VR기기를 쓰고 보았을때의 가독성 확인합니다.
* 스크린샷 첨부하고 VR기기를 쓰고 보았을때의 결과(글자를 알아볼 수 없음, 읽을 수 있음, 깨끗하게 읽힘 등)를 기록합니다.
* 폰트 크기를 조절 하며 Meta Quest 3 의 스마트폰에 적합한 폰트 크기를 찾아갑니다.
* 최적이라고 생각하는 폰트 크기를 적용한 스크린샷 하나를 추가로 첨부합니다.

# PDF 파일 포함내용
* 내가 선정한 폰트 크기를 유니티에서 어떻게 구현할 것인가? 설명글
* 선정한 폰트 크기를 가상의 큐브에 얹어서 VR에 띄운 스크린샷
* 선정한 폰트 크기를 Meta Quest 3에서 보았을때의 결과. 설명글
* 최적이라고 생각하는 폰트 크기를 적용한 스크린샷
* 최종결과 00pt

---

# 정리중 (수업에 참고할 내용)
* <b style="color:red"> 이 이후의 내용은 이대로 진행되지 않습니다. 수업 진행상황에 따라 변경됩니다. 미리 진행하지 않도록 합니다. </b>

---

## 메타 퀘스트 스크린샷, 동영상 촬영
* 스크린샷 : 메타 버튼 + 트리거
* 동영상 시작 : 메타 버튼 + 트리거 (노란색 점이 빨간색이 될때까지 유지)
* 동영상 종료 : 메타 버튼 + 트리거 (빨간색 점이 노란색이 될때까지 유지)
* 촬영된 동영상, 스크린샷은 '카메라' 앱에서 확인할 수 있습니다.

## USB로 옮기기
* 참고링크 : <https://just-hobby.tistory.com/36>
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726083393.jpg" />
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726083431.jpg" />
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726083458.jpg" />

---

## 단위
### 포인트, 파이카
* 참고자료 : <https://ko.wikipedia.org/wiki/%ED%8C%8C%EC%9D%B4%EC%B9%B4>
* 파이카(Pica)는 활자 크기를 재는 단위로 1/72피트(feet) 또는 1/6인치(inch)이다. 1파이카는 12포인트이다.
* 현대 컴퓨터용 활자에서 1파이카는 1959년 결정된 국제 표준 피트의 1/72로서 4.233mm 또는 0.166inch이다.

### 인치, 픽셀
* 참고자료 : <https://spoqa.github.io/2012/07/06/pixel-and-point.html>
* 1inch = 6pica
* 1pica = 12pt
* 1inch = 6pica = 72pt
* 1pixel, 1point, 1pica

### dpi(dot per inch), ppi(pixel per inch)
* 1인치에 들어가는 픽셀의 개수
* "72dpi 환경에서" 1inch = 72pixel = 72pt
* 1pixel = 1pt

## 참고자료
* 오큘러스 개발자 문서 : https://developer.oculus.com/documentation/

---

* VR 폰트 해상도
* VR 색상
* VR 버튼의 크기, 거리
* VR의 조작방식

---

* Meta XR 참고 영상 : <https://youtu.be/es9d1y1hYfM?si=-TefESt1oDAZC5wL>

* 메타 퀘스트3 화각(viewing angle, field of view)
* 110 degrees horizontal and 96 degrees vertical

## 개요
* [XR Simulator](https://developer.oculus.com/documentation/unity/xrsim-heroscenes)
* [Mixed Reality](https://developer.oculus.com/documentation/unity/unity-learn-mixed-reality-through-discover/)
* [Passthrough](https://developer.oculus.com/documentation/unity/unity-passthrough/)

- 강의소개, 강의 진행방식, 교재준비, 학사일정안내, VR, XR 소개
- 환경 및 헤드셋 설정, SDK다운로드, Core Blocks
* [Meta XR Core SDK(UPM)](https://developer.oculus.com/downloads/package/meta-xr-core-sdk/)
- 컨트롤러(Controller)[OVR Input](https://developer.oculus.com/documentation/unity/unity-ovrinput/)
* 핸드 트래킹
* 음성입력 [voice input](https://developer.oculus.com/documentation/unity/unity-tutorial-basic-voice-input/)
* 바디 트래킹 [Body Tracking](https://developer.oculus.com/documentation/unity/xrsim-body-tracking/)
* 페이스 트래킹 [Face Tracking](https://developer.oculus.com/documentation/unity/move-face-tracking/)
* 아이 트래킹 [Eye Tracking](https://developer.oculus.com/documentation/unity/move-eye-tracking/)
* Intraction SDK [unity isdk example scenes](https://developer.oculus.com/documentation/unity/unity-isdk-example-scenes/)
* 직무수행능력평가1
* VR, MR, XR 프로젝트 기획
* 연출 방법, 입력 상호작용 방법 결정
* 프로모션 비디오 만들기
* 프로모션 비디오 연출법 리서치, 레퍼런스 수집
* 직무수행능력평가2

---

* AR, VR 디자인 원칙, 플랫폼 및 기능, 어플리케이션 개발, 문제 해결 기술, 개발 프로세스, 어플리케이션 출시

---

# Meta XR Package
* 상호작용 SDK OVR 샘플(UPM) : <https://developer.oculus.com/downloads/package/meta-xr-interaction-sdk-ovr-samples/> <b style="color:red">Deprecated 더 이상 사용되지 않음</b>
* Meta XR Simulator Samples : <https://developer.oculus.com/downloads/package/meta-xr-simulator-samples/>