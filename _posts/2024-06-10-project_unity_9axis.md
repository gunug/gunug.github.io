---
layout: post
title: project arduino 9axis 아두이노 9축센서 연동
category: project
tags: 
---

# project arduino 9axis 아두이노 9축센서 연동

## 프로젝트 관련링크

### 프로젝트 기록
* [arduino esp32](/arduino/2024/06/02/arduino_esp32.html){:target=_blank} : 기존 디바이스 프로그램 라이브러리 버전 기록
* [디바이스 협조 요청](/etc/2024/06/27/project_device.html){:target=_blank} : 기존 디바이스 개선 요청사항
* [arduino esp32 기존소스 분석](/arduino/2024/07/08/esp32_source.html){:target=_blank} : 디바이스 재개발로 인한 기록
* [unity version 유니티 버전공유](/etc/2024/07/15/unity_version.html){:target=_blank} : 유니티를 개발하기 위한 버전공유
* [xiaoesp32c3 보드문제](/arduino/2024/07/15/xiaoesp32c3.html){:target=_blank}

---

### 기능 요약
* [arduino lcd simple code 아두이노 액정 디스플레이 요약](/arduino/2024/07/15/arduino_lcd.html){:target=_blank}
* [arduino BLE bluetooth simple code 아두이노 저전력 블루투스 요약](/arduino/2024/07/16/arduino_ble_bluetooth.html){:target=_blank}
* [arduino mpu6050 simple code 아두이노 6축 회전센서 요약](/arduino/2024/07/16/arduino_mpu6050.html){:target=_blank}

```c++
void setup(){
    pinMode(A0, INPUT);         // ADC
}
uint32_t Vbatt = 0;
void loop(){
    Vbatt = 0;
    for(int i = 0; i < 16; i++) {
        Vbatt = Vbatt + analogReadMilliVolts(A0); // ADC with correction   
    }
    float Vbattf = 2 * Vbatt / 16 / 1000.0;     // attenuation ratio 1/2, mV --> V
}
```
* 4.1볼트 : 전원연결 스위치 오프
* 3.3볼트 : 전원연결 스위치 온
* 2.9볼트 : 전원제거
* 2.7볼트 (2분) : 블루투스 끊김
* 2.6볼트 (2분 40초) : LCD 화면 깜빡임
---

## 제작
* [esp32, lcd, mpu6050, ble bluetooth, source code 종합 소스코드](/arduino/2024/07/16/source_code.html){:target=_blank}
* [unity esp32, lcd, mpu6050, ble bluetooth, source code 종합 소스코드](/unity/2024/07/18/unity_source.html){:target=_blank}

---

# 2024-07-19 중간보고
## 개선 전
<iframe width="560" height="315" src="https://www.youtube.com/embed/RECcc1bKkm8?si=Xt2H5IR6eD2MeAVl" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
## 개선 후
<iframe width="560" height="315" src="https://www.youtube.com/embed/AzvyD4t8cBA?si=q5h504MjdxCqNqtW" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

* 센서 켈리브레이션 작업은 추가로 필요합니다.
* 배터리 표시 및 LCD 화면 출력은 미구현입니다.
* 센서값을 Unity로 보내고 좌표를 계산하는 부분이 개선 되었습니다. (esp32 소스코드 전면 수정)

---

# 2024-08-07 파일전달
## 유니티 파일
* [Unity project](https://onethelab-my.sharepoint.com/:u:/p/gh_cho/EQSIc0Akr7VBvrPtyzTXV0wBRC1S52AZYJB3ldglxwi9pw?e=xCmAu8)
* Unity Editor version : 2022.3.27f1
* 프로젝트를 안드로이드로 빌드하면 apk파일이 생성됩니다. 이 파일을 스마트 폰으로 옮겨서 실행하면됩니다.

## 아두이노 파일
* [mpu6050 캘리브레이션](https://onethelab-my.sharepoint.com/:u:/p/gh_cho/EQoLnK2Y9eZEhwtRYpbI5V0BgfV4cu8AMpMXgqklylBJXQ?e=AT87Dp)
* [esp32 디바이스](https://onethelab-my.sharepoint.com/:u:/p/gh_cho/EXCO5RkCyCpMroZKncDWfa8BU_053r6eHnzBBlYgOq2xeQ?e=VuqMlz)

## 아두이노 라이브러리
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1723041907.jpg" />
* MPU6050 by Electronic Cats 라이브러리를 설치 합니다.
* 버전 1.3.1

## 아두이노 설치 방법
* 아두이노 라이브러리를 다운 받습니다.
* mpu6050 캘리브레이션 파일을 다운로드 받습니다.
* 아두이노에 업로드 합니다.
* 기기를 수평으로 하고 시리얼 모니터에 엔터를 입력하면 켈리브레이션을 시작합니다. (수초에서 수분 소요될 수 있습니다.)
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1723042313.jpg" />

* 캘리브레이션을 마치고 얻을수 있는 값의 각각의 명칭을 확인합니다.

* esp32 디바이스 소스코드에서 다음의 내용 찾아서 캘리브레이션 결과 값을 입력에 넣습니다.
  
```c++
mpu.setXAccelOffset(-481);
mpu.setYAccelOffset(1422);
mpu.setZAccelOffset(1807);
mpu.setXGyroOffset(-75);
mpu.setYGyroOffset(56);
mpu.setZGyroOffset(40);
```
* 아두이노에 업로드 합니다.

