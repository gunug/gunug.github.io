---
layout: post
title: arduino 심박센서
category: arduino
tags:
---

# arduino 심박센서

* 심박수 테이블 : https://ko.wikipedia.org/wiki/%EC%8B%AC%EB%B0%95%EC%88%98

# 기본소스

```c++
int PulseSensorPurplePin = A5;
int Signal;
boolean beep_on = false;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(PulseSensorPurplePin);
  Serial.println(Signal);
  if(Signal > 550 && beep_on==false){
    beep_on = true;
  }
  if(Signal < 500){
    beep_on = false;
  }
  delay(10);
}
```