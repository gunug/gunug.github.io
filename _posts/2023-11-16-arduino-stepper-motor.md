---
layout: post
title: arduino stepper motor 스테퍼 모터
category: arduino
tags:
---

# 개요

* stepping motor 스테핑 모터 라고도 하는데. 정식명칭은 스테퍼 모터 인듯
* 2상,4상,5상 등이 있는듯하다. 코일의 갯수? 정밀도와 영향이 있을듯
* 유니폴라 : 트랜지스터가 코일마다 한개씩, 저속에서 약한토크와 진동문제
* 바이폴라 : 트랜지스터가 코일마다 두개씩, 많은 전류를 소모하는 문제

---

# arduino 코드
```c++
#include <Stepper.h>

define STEPS 100
Stepper stepper(STEPS, 8, 9, 10, 11); //stepper motor control pin = 8,9,10,11;

stepper.step(val - previous);
```