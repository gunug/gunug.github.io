---
layout: post
title: cinemachine 시네머신 Dolly Track with Cart 돌리 트랙 카트
category: unity3d
tags: 
---

# cinemachine 시네머신  Dolly Track with Cart 돌리 트랙 카트
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759172724.jpg" />
* Menu > Windows > Package Manager
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759172455.jpg" />
* Packages:Unity Registry > 검색창에 Cinemachine 검색 > install 버튼 클릭하여 설치

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759175900.jpg" />
* Hierarchy창 빈공간 마우스 우클릭 > Cinemachine > Dolly Track with Cart

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759176081.jpg" />
* Hierarchy창 Dolly Track 선택 > CinemachineSmoothPath > Looped를 선택하여 왕복 설정
* CinimachineSmoothPath > + 플러스 버튼을 선택하여 지점을 추가

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759176275.jpg" />
* Scene창에 move tool을 선택하고 각 지점을 드래그하여 Dolly Track의 지점을 이동

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759177390.jpg" />
* Hierarchy창 Dolly Cart 선택 후 Cinemchine Dolly Cart > Speed 값을 조정하여 이동속도 설정
* Position Units가 Distance로 되어 있을때 10을 입력하면 10m/s (1초에 10미터를 이동)속도

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759177584.jpg" />
* 다른 물체를 드래그 드랍하여 부모(parent), 자식(child) 관계를 형성
* 자식 객체의 변형(transform)은 부모객체의 변형을 따르는 특성이 있습니다.