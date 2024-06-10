---
layout: post
title: project arduino 9axis 아두이노 9축센서 연동
category: project
tags: 
---


# 문제사항

>
## 값 누락 문제
* BLE bluetooth의 경우 패킷당 최대 20바이트 전송을 하기 때문에 값이 누락됩니다.
* 20바이트 이상의 데이터를 전송하려면 디바이스 및 유니티가 전송 방식을 합의 하여 같이 수정해야합니다.

# 값이 상이한 문제
* 필요한 값과 실제 전달되고 있는 값이 상이하여 결과가 원하는 대로 나오지 않습니다.
* 값을 일방적으로 반영하여 드릴 수는 있으나 의미있는 결과가 나오지 않습니다.
* 실제 전달되고 있는 값을 연산하여 필요한 값으로 만들어서 전달해 주셔야합니다.

>
## 필요한 값
* 디바이스의 x,y,z 회전 각도 값 : 오일러 각 또는 쿼터니언
* 디바이스의 x,y,z 이동량 : 회전 각도 값이 반영된 이동량

>
## 실제 전달되고 있는 값
* 자이로센서 : x,y,z 회전 가속도 값
* 가속도센서 : x,y,z 직선 가속도 값
* 지자기센서 : x,y,z 자기장의 방향 성분

---

# 전달주신 참고자료
* <https://youtu.be/zN89M_MjVKo>
* <https://youtu.be/L4WfHT_58Dg>

# MPU9250 9축센서 라이브러리 참고자료
* <https://github.com/hideakitai/MPU9250>

```c++
//센서 로우 데이터를 통해 만들어진 회전량 : 센싱된 값을 연산을 통해 사용할수 있는 값으로 변환한 결과 입니다.
float getRoll() const;
float getPitch() const;
float getYaw() const;

float getEulerX() const;
float getEulerY() const;
float getEulerZ() const;

//쿼터니언 (짐벌락 방지)
float getQuaternionX() const;
float getQuaternionY() const;
float getQuaternionZ() const;
float getQuaternionW() const;

//센서 로우 데이터 : 센서의 연산을 거치지 않은 날(生)값입니다. 여러가지 문제가 동반 될 수 있습니다.
float getAccX() const;
float getAccY() const;
float getAccZ() const;
float getGyroX() const;
float getGyroY() const;
float getGyroZ() const;
float getMagX() const;
float getMagY() const;
float getMagZ() const;

//중력 성분을 제거한 선형 가속도
float getLinearAccX() const;
float getLinearAccY() const;
float getLinearAccZ() const;
```

* 현재 자이로센서의 x,y,z값을 roll,pitch,yaw로 사용하고 있는데 이는 서로 다른 종류의 값입니다.

---

# 현재 상황

```
Byte Size: 58
 1, 1,0.05,-0.04,-0.04,0.64,-0.90,0.20,-1620,-70,-773,4.13
Byte Size: 58
 1, 1,0.05,-0.04,-0.02,0.64,-0.90,0.20,-1635,-65,-788,4.14
Byte Size: 58
 1, 1,0.04,-0.04,-0.01,0.63,-0.91,0.20,-1613,-80,-757,4.14
Byte Size: 58
 1, 1,0.04,-0.03,-0.01,0.63,-0.91,0.20,-1632,-57,-770,4.13
Byte Size: 58
 1, 1,0.04,-0.04,-0.02,0.64,-0.91,0.20,-1603,-90,-786,4.14
Byte Size: 58
 1, 1,0.04,-0.04,-0.03,0.62,-0.91,0.19,-1632,-72,-767,4.14
Byte Size: 58
 1, 1,0.04,-0.04,-0.02,0.63,-0.89,0.19,-1635,-95,-757,4.14
Byte Size: 58
 1, 1,0.04,-0.03,-0.02,0.63,-0.91,0.19,-1613,-82,-757,4.13
Byte Size: 58
 1, 1,0.04,-0.03,-0.03,0.63,-0.91,0.20,-1645,-75,-755,4.12
Byte Size: 58
```

* 스위치(1, 1),자이로센서(0.04,-0.04,-0.03),가속도센서(0.64,-0.90,0.20),지자계센서(-1627,-75,-747),4.11
* 자이로센서에서는 회전가속도 값을 전달 받습니다. 이 값을 그대로 사용하면 큐브가 다음과 같이 작동합니다.
  
---

<iframe width="560" height="315" src="https://www.youtube.com/embed/DLRi4vR4rm0?si=Q6S6aHH1oPkPSq6F" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
※위 영상은 '일부공개' 영상으로 직접적인 링크를 열지 않으면 유튜브내에서 검색하여 볼수 없는 영상으로 등록되어 있습니다.

## 영상에서 확인 가능한 문제점
* 회전값 드리프트 : 센서가 캘리브레이션 (오차를 계산하여 offset값 설정) 되어있지 않아서 회전가속도 값에 누적 오차가 생깁니다. 센서를 바닥에 내려놓은 상태(고정 상태)에서도 3D객체가 천천히 회전하는것을 볼 수 있습니다.
* 직선운동 가속도 : 자이로센서 값에 가속도센서값이 반영되어 있지 않아서 직선운동을 할때에도 회전운동을 한것 같은 오차가 생깁니다.

---

## 필요 요청사항
* 센서의 캘리브레이션 후 옵셋값이 eeprom등을 통해 유지되어야합니다. (드리프트 방지)
* 센서의 로우값이 아닌 가공된 각도값이 필요합니다.
* 센서의 가속도값이 회전량이 반영된 가속도량(실 공간에서의 위아래 좌우에 해당하는 방향으로의 가속도량)이 필요합니다.