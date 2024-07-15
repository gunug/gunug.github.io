---
layout: post
title: esp32 intterupt 인터럽트
category: arduino
tags:
---

# esp32에서 인터럽트가 작동하지 않습니다.
* 링크 : https://forum.seeedstudio.com/t/interrupts-on-xiao-esp32c3-not-working/267237

## 작동하지 않는코드
```c++
void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(0), Handler, CHANGE);
}

void Handler() {
  Serial.println("Pushed!");
}

void loop() {
}
```
## 작동하는 코드

```c++
void setup() {
  Serial.begin(9600);
  pinMode(D0, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(D0), Handler, FALLING);
}

void Handler() {  
  Serial.println("Pushed!");
}

void loop() {
}
```
* 작동하는 코드 그대로 라면 채터링으로 인해 인터럽트가 여러 번 트리거 됨