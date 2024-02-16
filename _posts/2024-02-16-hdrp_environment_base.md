---
layout: post
title: hdrp environment base
category: unity3d
tags: 
---

# hdrp environment base
* HDRP core 프로젝트 생성
* [Book Of The Dead: Environment HDRP](https://assetstore.unity.com/packages/essentials/tutorial-projects/book-of-the-dead-environment-hdrp-121175)
* import 한 후 switch project말고 그냥 import 누름
* Hapki.EnumExtensions.cs에서 타입에러뜸
* 잠시 기다렸더니 리소스 다시 불러 오고 문제 해결됨 - 그래픽도 개선됨
* [map magic2](https://assetstore.unity.com/packages/p/mapmagic-2-165180)
* [map magic2 bundle](https://assetstore.unity.com/packages/tools/terrain/mapmagic-2-bundle-178682)

---

# map magic 생성

* Hierarchy 우클릭 3D object > map magic
* Create Empty
* Graph 더블클릭하여 창 열기
* Noise -> Height
* inspector > terrain properties > base map resolution에서 해상도 변경가능
* Noise 노드의 intensity로 강도 변경가능
* linear한 noise값에 Curve노드를 이용하여 곡선을 줄 수 있음
* Erosion(부식) : 뽀족한 부분을 갈아내는 역할
* Contrast : 대비
* Slope : 경사면
* cavity : 공동, 정상의 움푹 패인곳
  * convex : 볼록한
  * concave : 오목한

---

* Scatter : 흩어지게하다