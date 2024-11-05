---
layout: post
title: arduino simple FOC kalman noise
category: arduino
tags: simple-code
---

# FOC
```c++
// https://docs.simplefoc.com/library_download
// Tools > Manage Libraries....
// Search for “Simple FOC” library and install the latest version .

#include <SimpleFOC.h> //SimpleFOC import
void setup() {
  Serial.begin(9600);
}

LowPassFilter filter = LowPassFilter(0.001); // Tf = 1ms 로우패스필터 생성
float value = 0;
float radian = 0;

// the loop function runs over and over again forever
void loop() {
  radian += 0.1;
  value = sin(radian)* 100 + random(-100, 100)/5;
  Serial.print(value);
  Serial.print(",");
  
  filter.Tf = 0.01; // changed to 10ms 필터링 정도 변경
  float signal_filtered = filter(value); // 원본 데이터 입력후 필터링된 값 리턴
  Serial.println(signal_filtered);
  
  delay(10);
}
```

# Kalman
```c++
#include <SimpleKalmanFilter.h>
void setup() {
  Serial.begin(9600);
}

float value = 0;
float radian = 0;

float e_mea = 1; //측정값 달라지는 양
float e_est = 1; //kalman필터가 값을 조정함으로 e_mea와 동일값 입력
float q = 0.01; // 0.001 ~ 1 : 측정이 얼마나 빨리 움직이는지 (권장: 0.01) 필요에 따라 조정
SimpleKalmanFilter kf = SimpleKalmanFilter(e_mea, e_est, q);

// the loop function runs over and over again forever
void loop() {
  radian += 0.1;
  value = sin(radian)* 100 + random(-100, 100)/5;
  Serial.print(value);
  Serial.print(",");
  
  float estimated_x = kf.updateEstimate(value);
  Serial.print(estimated_x);
  Serial.print(",");
  
  Serial.println("");
  
  delay(10);
}
```

# noise
```c++
void setup() {
  Serial.begin(9600);
}

float value = 0;
float radian = 0;
// the loop function runs over and over again forever
void loop() {
  radian += 0.1;
  value = sin(radian)* 100 + random(-100, 100)/5;
  Serial.println(value);
  delay(10);
}
```