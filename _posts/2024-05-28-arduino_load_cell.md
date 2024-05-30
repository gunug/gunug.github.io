---
layout: post
title: arduino load cell 로드셀
category: arduino
tags:
---

# arduino load cell 로드셀

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716882091.jpg" />

| Load cell |	HX711 |	명칭 |
|RED|	E+|	전원+|
|BLK|	E-|	전원-|
|WHT|	A-|	신호-|
|GRN|	A+|	신호+|
|YLW|	SD|	차폐 와이어(shield)|

---

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716882202.jpg" />

* Vcc : collector
* Vdd : drain
* Vee : emitter
* Vss : source

---

|Load cell|	arduino|	명칭|
|GND|	GND|	전원-|
|DAT|	D4|	데이터|
|CLK|	D5|	클럭|
|VCC|	5V|	전원+|
|VDD|	5V|	전원+|

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716882270.jpg" />
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716882289.jpg" />
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716882300.jpg" />

* https://github.com/olkal/HX711_ADC
* File->Examples->HX711_ADC->Calibration
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716882330.jpg" />
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716882348.jpg" />

* 시리얼 모니터에 T를 입력하여 켈리브레이션 시작
* 무게를 알수 있는 물체를 준비하여 로드셀 위에 얹고 무게를 입력
* Y를 입력하여 EEPROM에 켈리브레이션 값 기록
* 켈리브레이션을 마치고 나면 켈리브레이션 값을 얻을 수 있음

```c++
#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#endif

#define HX711_dout 4 //HX711 데이터핀
#define HX711_sck 5 //HX711 클럭핀

//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);
const int calVal_eepromAdress = 0;
unsigned long t = 0;

void setup() {
  Serial.begin(57600); delay(10);
  Serial.println();
  Serial.println("Starting...");

  float calibrationValue; // calibration value
  calibrationValue = 222.46; //직접값을 입력 (EEPROM데이터가 있다면 덮어씌어짐)
#if defined(ESP8266) || defined(ESP32)
  EEPROM.begin(512);
#endif
  EEPROM.get(calVal_eepromAdress, calibrationValue);
  //캘리브레이션 데이터가 있다면 EEPROM에서 가져옴.

  LoadCell.begin();
  //LoadCell.setReverseOutput();
  unsigned long stabilizingtime = 2000; //용기무게 측정 정밀도 향상을 위한안정화시간
  boolean _tare = true; //용기무게 측정이 필요치 않으면 false
  LoadCell.start(stabilizingtime, _tare);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
  }
  else {
    LoadCell.setCalFactor(calibrationValue); // set calibration factor (float)
    Serial.println("Startup is complete");
  }
  while (!LoadCell.update());
  Serial.print("Calibration value: ");
  Serial.println(LoadCell.getCalFactor());
  Serial.print("HX711 measured conversion time ms: ");
  Serial.println(LoadCell.getConversionTime());
  Serial.print("HX711 measured sampling rate HZ: ");
  Serial.println(LoadCell.getSPS());
  Serial.print("HX711 measured settlingtime ms: ");
  Serial.println(LoadCell.getSettlingTime());
  Serial.println("Note that the settling time may increase significantly if you use delay() in your sketch!");
  if (LoadCell.getSPS() < 7) {
    Serial.println("!!Sampling rate is lower than specification, check MCU>HX711 wiring and pin designations");
  }
  else if (LoadCell.getSPS() > 100) {
    Serial.println("!!Sampling rate is higher than specification, check MCU>HX711 wiring and pin designations");
  }
  //자체적으로 켈리브레이션을하고 센서 상태를 확인함
}

void loop() {
  static boolean newDataReady = 0;
  const int serialPrintInterval = 500; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
      float i = LoadCell.getData();
      Serial.print("Load_cell output val: ");
      Serial.println(i);
      newDataReady = 0;
      t = millis();
    }
  }
  if(i > 5000){ //로드셀로 부터 입력된 값이 5000그람(5KG)보다 크다면
    //모터정지
  }else{
    //모터회전
  }

  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }

}
```