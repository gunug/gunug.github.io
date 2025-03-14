---
layout: post
title: 2024년 2학기 피지컬 컴퓨팅 스튜디오
category: education
tags: kaywon
teaser: https://image.onethelab.com/thumbnail/1726639605.jpg
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
* Unity3d 설치 (2022년 이후 LTS 버전, 이전년도 버전 문제 발생)
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
* --- 수업 진행 상황에 따라 위 과정까지 밖에 진행하지 못한 팀에서는 위 내용만 첨부합니다. (하단 내용은 첨부되지 않아도 과제 점수에 영향이 없습니다.)
* 선정한 폰트 크기를 Meta Quest 3에서 보았을때의 결과. 설명글
* 최적이라고 생각하는 폰트 크기를 적용한 스크린샷
* 최종결과 00pt

---

# 3주차

# 3주차 수업진행
* 내가 만든 폰트 00pt 가 과연 정확한 사이즈 일까?
* 잘못 조정된 사이즈로 폰트를 큐브에 얹었다면 폰트 사이즈에 대한 고찰도 같이 잘못 되었을 것
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726663878.jpg" />

# 3주차 실습
## 가이드에 따라 다시 한번 폰트 크기를 맞추어 봅시다
* 핸드폰 화면 사이즈 실측 (베젤이 포함되면 베젤 사이즈 만큼 오차가 나기 때문에 베젤은 제외)
* 핸드폰 화면 사이즈에 맞추어 큐브 생성 (x 7.5cm 라면 0.075) *0.01 한 값을 쓰면 됨 (미터 > 센티미터 변환)
* 핸드폰 해상도에 맞추어 포토샵에서 이미지 생성 ppi(dpi)설정은 핸드폰 ppi를 인터넷에 검색하여 입력
* 아래 예시는 갤럭시 울트라 s22 (1440 * 3080 : 500ppi)
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726663767.jpg" />

* 포인트(pt) 기준으로 텍스트 생성

## 표준과 비교하여 봅시다
* 큐브를 생성하고 x,y,z 값을 각각 0.1,0.1,0.1 로 설정하여 한번이 10센티미터인 큐브 생성
* 포토샵에서 이미지 생성 ppi설정은 72, 가로 10cm, 세로 10cm
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726664642.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726665036.jpg" />

* 화면에 큐브 배치시 카메라와의 거리에 따라서도 글씨 크기가 다르게 보일 수 있음

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726665374.jpg" />

# Sample 체험
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726668160.jpg" />
* Samples 폴더 안에 다양한 Scene에 샘플들이 있습니다.
* 하나씩 열어보고 사용해보세요. (아직은 체험으로 이에 따른 과제 등은 없습니다)

# 3주차 과제
## 지난주에 진행하지 못했던 내용을 이번주에 시도합니다.
* 선정한 폰트 크기를 Meta Quest 3에서 보았을때의 결과.
  * 실제 스마트폰과의 글씨크기 체감차이, VR 환경이 가지고 있는 특성에 따른 가독성의 변화 등을 작성합니다.
  * 실제 육안으로 확인하고 팀원과 상의하여 자신의 의견과 팀원의 의견을 모두 작성합니다.
* 최적이라고 생각하는 폰트 크기를 적용한 스크린샷 (제목, 본)
* 최종결과 00pt

## 새로운 내용을 포함합니다
* 내가 생성한 이미지가 제대로된 크기였는지 큐브를 통하여 검증하기 (위 예시 참고)
* 한 화면에 10, 15, 20, 25, 30, 35, 40, 45, 50 pt의 텍스트를 포함하는(hello world가 아니여도 좋습니다. 글씨 크기를 알아볼 수 있도록 글자로 입력하세요) 이미지를 생성하여 스마트 폰에 올리기
* 추후 이 스크린샷은 VR 콘텐츠 제작 가이드(중간평가)에 사용됩니다.

---

# 4주차
* 거리에 따른 폰트 가독성 확인
* 거리 = \|시작위치(카메라) - 도착위치(큐브)\|(절대값)
* 거리를 2배로 늘리면 크기도 2배로 해야 같은 크기로 보임 (정비례관계)
* 1미터 거리에서 30pt로 보이는 글씨가 3미터 거리에서 몇pt여야 동일한 크기로 보일까?
  * 1m : 30pt = 3m : Xpt
  * X = 30/1*3 = 90pt

# 4주차 실습
* 이론적으로 스마트폰에서 적당하다고 생각한 폰트 크기를 새로 계산하고 그대로 키워서 모니터와 전광판에 띄우면 같은 크기의 글자를 얻을 수 있습니다.
* 스마트폰 거리 30cm, 모니터 거리 70cm, 전광판 거리 10m 로 설정하고 거리에 따라 몇pt의 폰트가 필요한지 계산합니다.
* 모니터용, 전광판용 이미지를 별도로 제작하지 말고, 큐브의 크기를 조절하여 각 거리에 적합한 크기로 변경합니다.
* VR에서 보았을때 스마트폰에서 설정한 폰트크기를 그대로 사용할 수 있을지 확인합니다. 아니라면 이유를 작성합니다. (시력 등의 영향 확인)


## Sample 사용
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726668160.jpg" />
* Samples 폴더 안에 다양한 Scene에 샘플들이 있습니다.
* 하나씩 열어보고 사용해보세요.

## 기능의 파악
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1727301572.jpg" />
* Unity는 component방식으로 기능이 추가 됩니다. 해당 객체(object)를 선택하고 inspector창에서 확인 가능합니다.
* Grabbable(잡을수 있는), Water Spray(물 분사), RespawnOnDrop(떨어트렸을때 재생성) 기능이 붙어 있습니다.

## 기능의 이식
* Scene에 있는 객체(Object)를 복사(Ctrl+C)하여 내 Scene으로 붙여넣기(Ctrl+V) 할 수 있습니다.
* 기능이 망가지지 않는다면 그대로 사용할 수 있습니다. 기능이 망가지면 사용할 수 없습니다.

## 구조의 변경
* component를 삭제하여 기능을 삭제할 수 있습니다.
* component를 추가하여 기능을 추가할 수 있습니다.
* 자식 객체(child object)를 추가하여 그래픽 객체를 교체할 수 있습니다.

# 4주차 과제
* 스마트폰 거리 30cm, 모니터 거리 70cm, 전광판 거리 10m 로 설정하고 거리에 따라 몇pt의 폰트가 필요한지 계산한 결과를 기록합니다.
* 거리에 맞게 큐브의 크기를 변경하여 설치하고 VR통해 글씨 가독성을 확인하고 결과를 기록합니다.
* 질문 : 거리에 따른 배치된 VR 객체가 실제와 같이 시력에 영향을 받을까요? 예상과 결과를 모두 기록합니다.
* 기능의 이식과 구조의 변경을 시도합니다. (이 내용은 과제로 기록하지 않아도 됩니다. 다음주 까지 sample을 이어서 테스트하고 프로젝트 기획을 시작할 예정입니다.)

---

# 5주차 - 개천절로 인한 휴강

---

# 6주차

|환경|거리|큐브크기|배율|
|:---|:---|:---|:---|
|스마트폰|30cm|0.1|1|
|모니터|70cm|0.23|2.3|
|전광판|10m(1000cm)|3.3|33|

* 큐브 크기에 따라 폰트의 배율계산이 필요 (전광판은 일반적으로 500pt가 넘어갑니다.)

## 가상현실의 사물의 거리와 시력
* VR에서 초점을 맞춰야하는 대상은 VR 헤드셋 스크린
* [스크린 - 렌즈 - 눈] 사이에 초점이 맞는다면 거리에 상관없이 잘 보임

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1728516290.jpg" />

## VR 멀미
* [VR 회전체 유니티 패키지](https://onethelab-my.sharepoint.com/:u:/p/gh_cho/EdCafbtWQZFLpdp1r6VEPDQB22kjgTisTq2KrdAIxRb2GA?e=E9MfIg){:target="_blank"}
* unitypackage를 다운로드
* 파일을 더블클릭 하거나 unity3d의 project창에 드래그 드랍하여 import
* Scenes/MovingRoom 씬을 열어서 재생, 확인
* BuildingBlock Camera Rig 선택 후 inspector창에 맨 하단, speed_rpm, distance로 회전 속도 및 회전 반경 조절 가능

## 탐구 사항
* 사람은 어느정도 속도에서 멀미를 느끼는가?
* 느린 속도부터 시도합시다. 30초 정도 유지하였을때의 상태를 확인합시다.
* 멀미가 느껴지면 바로 중단합니다. (이후에도 영향이 오래 갈 수 있음)

## 분당 회전수

* rpm(revolutions per minute, 분당 회전수)
* 1회전 = 360도
* 1분당 1회전 = 1분당 360도

## 원의 둘레
* 원둘레 = 2 * π * 반지름
* 초당 1회 회전하는 중심으로 부터 5m떨어진 물체의 회전 속도
* 속도(m/s) = 2 * π * 5 = 31.4m/s
* 속도(km/h) = 2 * π * 5 * 60(분) * 60(시) / 1000(km) = 113.04km/h

# 6주차 과제
## VR 멀미에 관한 레포트
* m/s, km/h, 체험시간(30초) 등으로 멀미에 대한 테스트를 해봅시다.
  
## Sample 사용, 기능의 파악, 기능의 이식, 구조의 변경
* Sample 사용, 기능의 파악, 기능의 이식, 구조의 변경등을 수행하고 기록
* 최소 3가지의 기능의 이식을 시도 하고 기록 합니다.
* 7주차, 8주차는 사용 가능한 기능으로 프로젝트 기획서 작성을 진행할 예정입니다.

---

# 7주차, 8주차 - 중간평가 준비, 제출

## 속도의 단위
* rpm, m/s, km/h
* 초당 1회 회전하는(1rps = 60rpm) 중심으로 부터 5m떨어진 물체의 회전 속도
* 속도(m/s) = 1회 * 2 * π * 5m = 31.4m/s
* 속도(m/m) = 60회 * 2 * π * 5m = 1884m/m
* 속도(km/h) = 1회 * 2 * π * 5m * 60(분) * 60(시) / 1000(km) = 113.04km/h
* 기존 멀미 보고서에 거리3(m), 속도5(rpm) 등으로 표현했던 부분은 (m/s)단위로 재 계산되어야 합니다.

## bezier path creator
* [Bezier Path Creator](/unity-asset/2024/10/16/bezier_path_creator.html){:target="_blank"}

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1729050592.jpg" />
* Camera Rig를 드래그 드랍하여 Fallower에 내려놓기 = 부모(parent) 자식(child)관계 만들기
* 자식객체는 부모객체를 따라가는 특성이 있습니다. 이 방법으로 롤러코스터 같은 이동식 장치를 만들 수 있습니다.

## Sample 사용
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1726668160.jpg" />
* Samples 폴더 안에 다양한 Scene에 샘플들이 있습니다.
* 하나씩 열어보고 사용해보세요.

## 기능의 파악
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1727301572.jpg" />
* Unity는 component방식으로 기능이 추가 됩니다. 해당 객체(object)를 선택하고 inspector창에서 확인 가능합니다.
* Grabbable(잡을수 있는), Water Spray(물 분사), RespawnOnDrop(떨어트렸을때 재생성) 기능이 붙어 있습니다.

## 기능의 이식
* Scene에 있는 객체(Object)를 복사(Ctrl+C)하여 내 Scene으로 붙여넣기(Ctrl+V) 할 수 있습니다.
* 기능이 망가지지 않는다면 그대로 사용할 수 있습니다. 기능이 망가지면 사용할 수 없습니다.

## 구조의 변경
* component를 삭제하여 기능을 삭제할 수 있습니다.
* component를 추가하여 기능을 추가할 수 있습니다.
* 자식 객체(child object)를 추가하여 그래픽 객체를 교체할 수 있습니다.

## 중간평가 - VR 콘텐츠 제작 가이드, 프로젝트 기획서
>### VR 콘텐츠 제작 가이드 (개별)
* 메타퀘스트3 하드웨어 스펙 기록 (해상도, 시야각 등)
* 디지털 콘텐츠 이미지 해상도, 폰트크기, 가독성
* VR 멀미
* sample의 사용, 기능의 파악, 기능의 이식, 구조의 변경
* 그동안 제출하였던 주차별 과제에서 주요내용만 요약하여 문서를 작성합니다. (VR 가이드로 활용할 수 있도록 합니다)

>### 프로젝트 기획서 (공통, 팀당 1개, 같은 파일을 복사하여 개인당 각각 업로드 합니다)
* 사용할수 있는 기능을 추려보고 해당 기능을 이용한 프로젝트 기획
* Bezier path creator의 사용을 고려해 보세요. (사용이 필수는 아님, 사용할 경우 기능 구현이 쉽고 sample과 함께 완성품을 만들기 용이)
* 후반기는 실제로 제작을 할 예정이니 구현 가능성에 중점을 두고 기획합니다.
* 이미지를 직접 제작하고 폰트 크기 가이드에 맞춰 내용을 입력, 정보를 제공하고 사용자가 읽을 수 있도록 하는 것이 필수 입니다.

>### 프로젝트 기획서 내용
* 주제
* 디자인 컨셉, 레퍼런스 (인터넷 이미지, 에셋 등)
* 이미지, 폰트 활용 방안 (어떤 정보를 어떻게 보여줄 것인가)
* 기능 활용 방안 (bezier를 이용한 이동기능, 물건집기, 구슬 쏘기 등)
* VR에서 기능을 나열하는 것이 아닌 기능들을 조합하여 어떤 체험을 하도록 할 것인가
* 위 사항은 필수 내용은 기록한 것이니, 이외에 프로젝트 기획서가 갖추어야 할 내용은 자유롭게 추가 가능

* 7주차, 8주차 중간평가 준비
* 제출 마감 9주차 수업 전 까지 (10월 30일 수요일 23:59:59)
* 후반기 목표 : VR 콘텐츠 가이드를 실체 프로젝트에 적용하고 보완

---

# 9주차
## 낭만고양이의 하루
* 생선 가져오기, 박스 무너트리기, 장난감 가져오기, 낭만 즐기기
* Bazer path, Snap, Transformer, DistanceGrab, ConcurrentHandController
  
## SF 공간체험
* 우주선 타고 이동, 물건을 집기, 자유롭게 이동
* Bazer path, Hand grap, Locomotion
  
## 캐릭캐릭 체인지
* 움직임, 양손 인식 물건집기, 제스텨 모션 이펙트, 물건 쏘기, 물건 당기기
* Bazier path creator, Snap, Pose, Concurrent Hand and Controllers, Distance Grab
  
## 달리는 레일 코스를 완주하자!
* 기차 출발하기, 기차 멈추기, 스와이프 주사위 색 변경, 폭탄 던저 저금통 무너트리기, 가위바위보 이기기
* Bazier path, color changer, Grabbable, Respawn On Drop, Hand Ref
* 미션을 클리어했다는걸 판단할 수 있는 판정 부분의 구현이 중요합니다.
  
## 스타레일 익스프레스
* 열차 출발, 무기 사용, 공격막기 크기변경, 무기사용, 공간이동
* Bazier path creator, BodyPose, HandGrab, Panel, ConcurrentHand, Locomotion
  
## 산타의 벼락치기 선물 배달 프로젝트
* 썰매 움직이기, 선물박스 들기, 집과 선물 부딪히기, 폭죽(파티클) 아이의 웃음소리, 미션클리어, 실패
* Bazier path creator, grabable, onTriggerEnter, 인앤아웃(?), ray
* 파티클 시스템 (Particle System), 오디오 시스템 (Audio System) : Audio Source, Audio Clip
  
## Zombie in office
* 좀비 이동, 좀비 무기 맞추기, 총 집기, 무기 크기 변경, 상자에서 무기 꺼내기, 사무용품
* Bazier Path, Rigidbody, Collider, Grabbable, Transformer, One Grab Rotate Tranformer

# 기능구현
* 복합기능(Bazier path를 이용하여 움직이다가 locomotion을 이용하여 워프하기, Bazier path를 이용하여 움직이다가 충돌하여 넘어지기)은 원하는 대로 작동하지 않을 수 있습니다.
  
># 누가? 언제? 무엇을?
## 누가 : Object 사물, 대상
* 기차가, 좀비가, 총이, 선물이, 집이
>
## 언제 : Event 상황(Trigger 방아쇠)
* 선물이 집에 닿았을때, 좀비가 무기에 맞았을때, 총을 집었을때, 목적지에 도착했을때, 기차가 특정 지역에 도착했을때
>
## 무엇을 : Function 기능, 함수
* 폭죽이 터진다, 기차가 멈춘다, 웃음소리가 재생된다

* 누가(Object), 언제(Event, trigger)와 무엇을(function)을 분리하여 생각합시다.

# Follower trigger 기능 만들기
* [follower trigger 기능 만들기](/vr/2024/10/31/follower_trigger.html){:target="_blank"}

# 9주차 과제
* bazier path를 이용하여 코스를 제작합니다.
* player가 직접 이동하지 않는 팀은 이동하는 대상(좀비 등)을 제작합니다.
* 이동지역에 큐브 또는 assets store의 obejct를 배치 합니다.
* VR로 보여지는 모습을 동영상 촬영 (핸드폰 미러링의 녹화기능 활용)하여 업로드합니다.
* 팀별로 한명이 대표로 제출, 전체 팀원의 이름을 게시물 제목에 명시
* VR기기가 없으면 촬영이 불가능 하기 때문에 수업시간내에 일단 녹화를 우선 테스트 하고, 녹화가 가능하면 이후에 코스만들기, 주변 꾸미기를 합시다

---

# 10주차
* 공간 오디오 구성이 끝나고 나면 분업과정을 진행할 예정입니다. 서브컴퓨터(VR을 연결하지 않을)에 유니티를 미리 실행하도록 합니다.
* 프로젝트가 생성되어 있지 않다면 3D built-in으로 프로젝트를 생성합니다. 

## 공간 오디오 구성
* [unity audio clip 오디오 클립](/unity/2024/11/06/unity_audio_source.html){:target="_blank"}
* 여러개의 입체 오디오를 구성하여 각 지역마다 다른 배경음악이 나오거나 효과음을 사물에 부여하여 시선을 집중할 수 있도록 할 수 있습니다.
* 시선이 더욱 분산 될 수 있는 VR환경에서 효과음은 중요합니다.

## 분업
* Export Package, Import Packge를 이용하여 작업물을 친구의 컴퓨터로 전달 할 수 있습니다.
* [unity export package 패키지 내보내기](/unity/2024/11/07/unity_export_package.html){:target="_blank"}

# 10주차 과제
## 공간 오디오 구성
* 공간에 오디오를 구성 (배경음악, 효과음 등)
* 직접 레일을 타고 움직이거나, 소리를 가지고 있는 객체를 움직이는 모습을 동영상으로 촬영 (소리가 이동하는 것을 동영상에서 확인 할 수 있어야 합니다)
* 팀중 한명이 전체 팀원 이름 명시하여 카페에 업로드

## 분업 과정 진행
* 개별적으로 유니티 프로젝트를 생성하여 일을 분담하고 제작합니다.
* VR과 연결된 노트북을 가지고 있는 학생에게 파일을 전달하고 한 공간에 합치기
* 스크린샷을 하고 팀중 한명이 전체 팀원 이름 명시하여 카페에 업로드
* 팀원 이름과 역할을 카페에 작성

---

# 11주차
* [unity sound trigger 특정 위치에서 소리 출력하기](/unity3d/2024/11/13/unity_sound_trigger.html){:target="_blank"}
* [unity random sound 무작위 소리출력](/unity3d/2024/11/13/unity_random_sound.html){:target="_blank"}
* [moving object 상하로 움직이는 오브젝트](/unity3d/2024/11/13/moving_object.html){:target="_blank"}
* [trigger parent null 특정위치에서 부모연결 끊기](/unity3d/2024/11/14/trigger_drop.html){:target="_blank"}

# 11주차 과제
* 코스완성 : 코스를 명확히 하고 각 구획을 완성합니다.
* 수업시간내에 제작된 내용을 스크린샷, 동영상 등으로 업로드 합니다
* 이후 과정은 프로젝트를 완성하고 프로모션 비디오를 제작하기위한 선행작업입니다.
* 15주차에 기말평가 발표를 할 수 있도록 시간 안배를 하여 완성할 수 있도록 합니다.

---

# 12주차

# 12주차 과제
* 수업시간내에 제작된 내용을 스크린샷, 동영상 등으로 업로드 합니다
* 이후 과정은 프로젝트를 완성하고 프로모션 비디오를 제작하기위한 선행작업입니다.
* 15주차에 기말평가 발표를 할 수 있도록 시간 안배를 하여 완성할 수 있도록 합니다.

---

# 10,11주차 - 코스완성
# 12,13주차 - 기능완성
# 14주차 - 프로모션 비디오 완성
* 동영상 총 2편 (프로젝트 동영상, 요약 동영상), 스크린샷 다수
* 프로젝트 동영상 : 프로젝트를 잘 볼 수 있는 동영상(길이는 자유)
* 프로젝트 제목, 간단한 소개글을 (100자 이하) 동영상 내에 자막으로 표시 (동영상 재생중 항시 띄워놓도록 합니다)
* 요약 동영상 : 자유길이 동영상 요약한 동영상(15초)
* 스크린샷 : 프로젝트를 볼 수 있는 스크린샷(이미지 장수 자유)

# 15주차 - 기말평가 발표
* 프로젝트 동영상을 재생시키고 프로젝트를 설명
* 프로젝트 완성도, 동영상으로 프로젝트를 충분히 알 수 있는지를 위주로 평가
* 프로젝트 내에 글씨, 이미지 등으로 정보를 전달하는 내용 필수 (VR 콘텐츠 가이드 중 폰트의 내용 반영)

# 기말평가 - 프로젝트 제작, 프로모션 비디오

---

# 기말평가
* 카페에 '파일'로 제출하는 경우 용량문제 발생
* '동영상'으로 제출하시면 자체적으로 동영상을 재 인코딩 하여 용량문제 없이 바로 재생시켜 볼 수 있습니다.

---

# 연합PT
* 2024년 2학기 연합PT 공지 : <https://cafe.naver.com/kwdmd/227542>
* 15초 영상 6개 = 1분 30초
* 우수작 발표시간 1분 30초
* 15초 영상은 쭉 틀어서 볼 수 있도록 하나로 편집합니다.
* 소리 크기가 들쑥 날쑥 하지 않도록 조정 하세요.

---

# 정리중 (수업에 참고할 내용)
* <b style="color:red"> 이 이후의 내용은 이대로 진행되지 않습니다. 수업 진행상황에 따라 변경됩니다. 미리 진행하지 않도록 합니다. </b>

* 갤럭시 s22 울트라 : 1440 * 3080 : 500ppi : 77.9mm * 163.3mm * 8.9mm

---

## LOD(Level of Detail)
* 컴퓨터 리소스를 절약하기 위한 수단으로 거리와 시점에 따라 텍스처의 해상도를 동적으로 조절하는 방식

## Mipmap
* <https://docs.unity3d.com/kr/2022.3/Manual/texture-mipmaps-introduction.html>

1. **근거리(0-2미터):** 고해상도 텍스처 (예: 2048x2048 또는 그 이상)
   - 플레이어가 객체를 가까이서 자세히 볼 수 있을 때 필요한 수준입니다.

2. **중간 거리(2-5미터):** 중해상도 텍스처 (예: 1024x1024)
   - 객체가 플레이어의 관심 영역 내에 있지만 세부사항을 너무 자세히 보지 않아도 될 때 사용합니다.

3. **원거리(5미터 이상):** 저해상도 텍스처 (예: 512x512 또는 그 이하)
   - 객체가 멀리 있어 자세한 디테일 묘사가 필요 없을 때 사용합니다.

---

## 스마트폰 에셋
* <https://assetstore.unity.com/packages/3d/props/free-phone-181455>

## VR 최적화
* <https://medium.com/@xavidevsama/optimizing-vr-performance-in-unity-techniques-and-best-practices-b9c6a5d539f3>

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

# 메타 퀘스트3 스펙
## 메타 퀘스트3 화각(viewing angle, field of view)
* 110 degrees horizontal and 96 degrees vertical

## 해상도
* 한쪽당 2064 * 2208px

---

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