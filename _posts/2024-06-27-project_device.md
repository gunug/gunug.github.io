---
layout: post
title: 디바이스 협조 요청
category: project
tags: 
---

---

# 2024-06-24 중간보고

<iframe width="560" height="315" src="https://www.youtube.com/embed/FIjxhge5Lq4?si=iPf4x_g5tdGG0sKc" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
* 센서에서 전달되는 로우값 자체가 틀어져있습니다.
* 회전 방향에 따른 짐벌락도 발생하는것 같습니다.

<iframe width="560" height="315" src="https://www.youtube.com/embed/RECcc1bKkm8?si=-Sx7saoJhmkp31tt" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
* 틀어진 회전축을 재계산하여 소프트웨어로 맞추어도 조금만 움직이면 (움직이지 않고 기다려도) 축이 틀어집니다.
* 짐벌락 현상으로 추청되는 원인으로 인하여 회전시 축이 맞지 않고 돌아가 버립니다.

---

# 2024-06-27 협조요청

## 센서 오차값에 따른 offset값 반영요청

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719453838.jpg" />

* 시작시 - 디바이스로 부터 받은 센서값이 기울어져 있습니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719453870.jpg" />

* 디바이스를 조금 움직이고 4초 뒤 시작했을 때와 축이 다릅니다.
* 센서 자체에 오차를 측정하고 offset 값을 설정하여 측정값 drift(밀림)현상을 최소화 해야합니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719454199.jpg" />
* 원문 : <https://forum.arduino.cc/t/mpu6050-drift/683146/4>

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719454365.jpg" />
* 전달해 주신 소스코드내에 offset값이 기록되어 있기는 하지만 drift가 계속 발생하는 것으로 보아 올바른 값이 입력되어 있다고 생각하기 어렵습니다.
* 다음은 제가 가진 소스코드로 제가 측정한 offset 값입니다.

```c++
Sensor readings with offsets:	-16	-6	16391	1	0	0
Your offsets:	-408	1472	1822	-80	57	45

Sensor readings with offsets:	3	0	16384	0	-2	0
Your offsets:	-400	1474	1822	-78	59	42

Sensor readings with offsets:	0	0	16387	1	3	1
Your offsets:	-385	1478	1830	-73	58	45

Data is printed as: acelX acelY acelZ giroX giroY giroZ
Check that your sensor readings are close to 0 0 16384 0 0 0
```
* 이를 반영하여 offset값을 다음과 같이 변경 하였으나 소스코드 자체가 달라서 문제가 해결되지 않았습니다.

```c++
#define MPU6050_AXOFFSET -400
#define MPU6050_AYOFFSET 1474
#define MPU6050_AZOFFSET 1822

#define MPU6050_GXOFFSET -78
#define MPU6050_GYOFFSET 59
#define MPU6050_GZOFFSET 42
```

# 짐벌락 문제로 인한 쿼터니언값 요청

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719454757.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719454793.jpg" />

* 디바이스를 든 손을 시계방향으로 한바퀴 회전한 뒤의 결과 입니다.
* 각 축을 색깔로 표시한 막대를 보시면 축이 완전히 틀어집니다.
* 이는 오일러 앵글의 짐벌락에 의해 발생하는 것으로 짐벌락에 관한 설명은 다음의 영상에서 보실 수 있습니다.

<iframe width="560" height="315" src="https://www.youtube.com/embed/zc8b2Jo7mno?si=OwgWL3mxkG--oyy3" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

* x,y,z축을 순서대로 반영하는 오일러각 계산법으로 축계산을 하면 측정 축이 겹치는 환경에서 축값이 잘못 계산되는 현상이 있습니다.
* 따라서 쿼터니언으로 만들어진 값을 전달받아야 합니다.

# 왜 센서 기본값으로 직접 쿼터니언 계산을 하지 않는가?

* 센서 RAW값은 -1~+1의 '이전 위치에서 얼마나 각회전을 하였는가' 값으로 이루어져 있습니다. - 변화량을 전달합니다.
* Bluetooth 통신상 통신이 정확한 시간으로 동일한게 데이터를 전달하지 않고. 때에 따라서는 누락되거나 디바이스부하로 인한 지연, 컴퓨터쪽 소프트웨어로 인한 지연이 발생할 수 있습니다 - 시간이 어긋납니다.
* 시간이 어긋난 상태에서 변화량만 전달하면 계산을 제대로 할 수가 없습니다. (현재 각도 = 시간 * 변화량 이기 때문입니다, 시간 없이 각회전량만 가지고는 각도를 계산할 수 없습니다)
* 따라서 센서 RAW값으로 PC쪽에서 계산하기 위해서는 timestamp 까지 같이 전달해야 "이전시간, 다음시간, 각변화량"을 가지고 계산이 가능해 집니다.
* 하지만 이 계산도 쉬운 것을 너무 복잡하게 하는 경우라 디바이스 자체에서 계산해서 넘기는 것 보다 너무 비효율 적이고 오차를 발생 시킬 수 있습니다.
* 그래서 최종적으로 디바이스 프로그램의 지원이 불가능하다면 제가 직접 디바이스 프로그램을 수정하는 것이 더 나은 상황이 되었습니다.