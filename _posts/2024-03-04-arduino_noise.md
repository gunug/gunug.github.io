---
layout: post
title: Arduino Noise 아두이노 노이즈 잡음
category: arduino
tags: arduino
---

# Arduino Noise 아두이노 노이즈 잡음

# 기본적인 노이즈 환경
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
![image](https://github.com/gunug/gunug.github.io/assets/52345276/621a9896-fc8a-4757-aa4d-4bdd1e04a0d5)


# SimpleFOC
* 출처 : https://docs.simplefoc.com/library_download
* ```Tools > Manage Libraries....```
* Search for “Simple FOC” library and install the [latest version .](https://github.com/simplefoc/Arduino-FOC/releases)

```c++
#include <SimpleFOC.h>
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
```c++
![image](https://github.com/gunug/gunug.github.io/assets/52345276/f7c5e542-b694-49f3-89f8-062f6da19155)

* Tf = 0.01;
![image](https://github.com/gunug/gunug.github.io/assets/52345276/a9df399e-b4f0-4a0c-aff3-7d0da4504e7d)

* Tf = 0.03;

# Kalman Filter Library
* https://github.com/TKJElectronics/KalmanFilter
* * ```Tools > Manage Libraries....```
* Search for “Kalman Filter Library” library and install the [latest version .]
* "SimpleKalmanFilter" : https://github.com/denyssene/SimpleKalmanFilter
```c++
  double dt = (double)(micros() - timer) / 1000000; // Calculate delta time
  timer = micros();
```

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
* 녹색이 칼만필터

![image](https://github.com/gunug/gunug.github.io/assets/52345276/960146dd-e960-4c8d-b530-b83ca8a7ee9b)

* q = 0.01;
![image](https://github.com/gunug/gunug.github.io/assets/52345276/c75a882e-37c1-4d82-a33c-754e7c54789e)

* q = 0.1;
# 실적용 예시
* 파랑 로우데이터, 빨강 로우패스필터, 녹색 칼만필터

![image](https://github.com/gunug/gunug.github.io/assets/52345276/41597684-aab7-4649-91b7-7868be1e696f)
![image](https://github.com/gunug/gunug.github.io/assets/52345276/e7143160-ce48-4b30-a3d8-38c2d624ead3)
![image](https://github.com/gunug/gunug.github.io/assets/52345276/1107a11d-d072-4b40-85cf-928e0752601c)

* filter.Tf = 0.1;
* float q = 0.01;
* 확실히 칼만필터쪽이 반응이 빠르고 노이즈 제거 효과가 좋다
