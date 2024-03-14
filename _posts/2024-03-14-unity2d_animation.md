---
layout: post
title: unity 2d animation 애니메이션
category: unity3d
tags:
---

# unity 2d animation 애니메이션

## Empty Game Object 만들기
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710426746.jpg" />

* Hieraechy창에 마우스 우클릭 ```Create Empty``` 선택하여 빈 게임오브젝트 만들기
* 빈 게임오브젝트의 이름을 'animation root'로 변경

<img style='border:solid 1px black;' width="50%" src="https://image.onethelab.com/resized/1710426917.jpg" />
<img style='border:solid 1px black;' width="50%" src="https://image.onethelab.com/resized/1710427011.jpg" />

* Hierarchy창에서 밖에 있는 그림을 드래그 드롭하여 Animation Root에 옮기면 폴더에 파일을 집어 넣듯 상하관계를 만들수가 있습니다.

---

## Animation창 열기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710427143.jpg" />

* Main Menu > Window > Animation > Animation 을 선택하여 애니메이션 창 열기
* Animation과 Animator를 해깔리지 않도록 합니다. 서로 기능이 다릅니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710427295.jpg" />

* 열린 animation 창의 이름을 드래그 드랍하여 game창의 옆에 두기

## Animation 만들기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710427393.jpg" />

* <b style="color:red; font-weight:bold">Hierarchy창에서 Animation Root 선택</b>
* Animation창의 Create 버튼 클릭

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710427534.jpg" />

* 이름을 'Animation1'이라고 입력
* 저장위치 변경하지 말고 그자리에 저장

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710427623.jpg" />

* 새 애니메이션을 등록하고 나면 Animation창에 타임라인이 생김
* 좌상단의 빨간 동그라미(녹화버튼)을 누를때마다 녹화 on/off로 상태가 바뀜

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710427813.jpg" />
1. 녹화 시작
2. 시간 선택
3. 이동 도구(tool) 선택
4. 대상을 이동

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710427919.jpg" />
* 녹화중일 때 객체의 상태가 변화할때 마다 key frame이라고 하는것이 생성됩니다.

---

## 새 애니메이션 추가하기
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1710428074.jpg" />

* Animation창의 애니메이션 이름 (Animation 1)을 클릭
* ```Create New Clip...``` 을 선택하여 새 애니메이션 추가 가능
* 'Animation 2'라는 이름으로 새 애니메이션을 만듭니다.