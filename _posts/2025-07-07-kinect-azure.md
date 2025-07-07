---
layout: post
title: Kinect Azure 스펙정리
category: unity
tags: 
---

# Kinect Azure 스펙정리
* <https://learn.microsoft.com/en-us/previous-versions/azure/kinect-dk/hardware-specification> 참고링크

| 모드         | 특징       | 장점                                                         | 단점                                                     |
|--------------|------------------------------------------------------|------------------------------------------------------------|------------------------------------------------------|
| **Wide mode**  | - 화각(FOV): 120° x 120°<br>- 측정거리: 0.25–2.21 m      | - 넓은 시야 확보<br>- 가까운 거리도 측정 가능<br>- 여러 사물 감지에 유리 | - 최대 측정거리가 짧음<br>- 넓은 화각으로 객체당 해상도 저하 가능성  |
| **Narrow mode**| - 화각(FOV): 75° x 65°<br>- 측정거리: 0.5–5.46 m        | - 먼 거리까지 측정 가능<br>- 동일 거리 대비 더 높은 해상도<br>- 좁은 장면에 적합 | - 시야가 좁음<br>- 가까운 거리(0.5m 미만) 측정 불가           |
| **Near mode**  | - 일부 적용(Depth Camera Only)<br>- 측정거리: 0.25–2.88 m | - 아주 가까운 거리도 정확하게 측정<br>- 가까운 물체 관찰 및 제스처 인식 등 적합 | - 적용 화각 제한적<br>- 최대 거리 짧음                  |


<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1751862975.jpg" />


---

# 촬영범위 계산기
* <https://image.onethelab.com/util/kinect_azure_spec.html>
  
---

# 촬영범위 확정
* 시작거리 1m, 종료거리 2m, 촬영위치 1.5m
* 가로 최소 점뷔 3.46m, 세로 최소 범위 3.46m

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1751870860.jpg" />