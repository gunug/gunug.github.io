---
layout: post
title: arduino 투명 터치 패드
category: etc
tags: 
---

* 제품 : https://www.devicemart.co.kr/goods/view?no=12380586

* 1:VCC
* 2:Event (Low일 때 터치 발생함)
* 3:UART (Txd)
* 4:UART (Rxd)
* 5:GND

- 네모부분이 VCC

---
* 38400 BPS
* 8 Bit, 1 Stop, Non parity

Serial1.begin(38400,SERIAL_8N1);
//8비트 논패러티 정지비트 1개가 기본옵션임
* 관련자료 : https://www.arduino.cc/reference/en/language/functions/communication/serial/begin/

---

문의사항

* touch Event핀은 최초 전기 연결시 HIGH 였다가, 터치를 하면 LOW로 내려가서 다시 HIGH 변하지 않습니다.
* TX,RX 시리얼선 연결 후 테스트시 'R'을 전달하여도 아무런 반응이 없습니다.
* 전원 LED및 터치 LED는 정상적으로 점멸 합니다.

* R을 입력시 리드모드가 되어서 <ABC> 데이터값을 지속적으로 발송하여 주는것인지 또는 R을 주기적으로 입력해 주어야 하는 것인지요?
* 

```C++
void setup() {
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(38400); //USB시리얼 시작
  while(!Serial) { }
  Serial1.begin(38400); //하드웨어시리얼 시작
  while(!Serial1) { }
}

void loop() {
  digitalWrite(13,digitalRead(7)); //7번 핀으로 들어오는 Event HIGH, LOW를 그대로 LED에 반영
  
  if(Serial1.available() > 0){
    Serial.write(Serial1.read());
  }//하드웨어 시리얼을 USB 시리얼로 출력
  
  if(Serial.available() > 0){
    Serial1.write(Serial.read());
  }//USB 시리얼을 하드웨어 시리얼로 출력
  
  Serial1.write(0x52); //'R' 값을 주기적으로 전송
  delay(100);
}
```

---

# Capacitive Sensing Library
* 참고영상 : https://www.youtube.com/watch?v=e9pl7Z6UOes&t=457s
* 라이브러리 주소 : https://playground.arduino.cc/Main/CapacitiveSensor/
* 5버전으로 업데이트 됨 : https://github.com/PaulStoffregen/CapacitiveSensor

```C++
#include <CapacitiveSensor.h>

CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2); //송신부,수신부

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop(){
  long sensor_1 = cs_3_2.capacitiveSensor(30); //00~255
  Serial.println(sensor_1);
  if(sensor_1 > 500){
    digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
  }
}
```

---

# 최종소스 코드
```c++
#include <CapacitiveSensor.h>
#include <SimpleKalmanFilter.h>

float e_mea = 1; //측정값 달라지는 양
float e_est = 1; //kalman필터가 값을 조정함으로 e_mea와 동일값 입력
float q = 0.005; // 0.001 ~ 1 : 측정이 얼마나 빨리 움직이는지 (권장: 0.01) 필요에 따라 조정
SimpleKalmanFilter kf = SimpleKalmanFilter(e_mea, e_est, q);
CapacitiveSensor   cs_3_2 = CapacitiveSensor(3,2); //송신부,수신부

void setup(){
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}

void loop(){
  long sensor_1 = cs_3_2.capacitiveSensor(30); //00~255
  float estimated_sensor_1 = kf.updateEstimate(sensor_1);
  //Serial.println(estimated_sensor_1);
  if(estimated_sensor_1 > 500){
    digitalWrite(13,HIGH);
    Serial.print('1');
  }else{
    digitalWrite(13,LOW);
    Serial.print('0');
  }
  delay(10);
}
```

---

* 기술문의 답변
안녕하십니까.
우정하이텍 기술연구소 입니다.
하기 문의주신 내용 답변 드립니다.

문의사항
l   touch Event핀은 최초 전기 연결시 HIGH 였다가, 터치를 하면 LOW로 내려가서 다시 HIGH 변하지 않습니다.
Touch Event의 경우, Active Low로 동작하며, Low상태에서 Read(‘R’)를 하기 전까지는 Low 상태를 유지합니다.
l   TX,RX 시리얼선 연결 후 테스트시 'R'을 전달하여도 아무런 반응이 없습니다.

보내주신 코드를 확인해본 결과, 컴파일이 제대로 진행되지 않았고, 이에 따라 ‘R’이 제대로 전달되지 않은 것으로 보입니다. 동작 Test를 마친 수정된 Code를 회신 드리오니 확인 부탁 드립니다.
또한, 이전에 제가 투명 터치 필름 컨트롤러를 아두이노에 연결하여 Test를 진행했던 Code를 주석으로 첨부하였으니 참고 부탁 드립니다.
l   전원 LED및 터치 LED는 정상적으로 점멸 합니다.

l   R을 입력시 리드모드가 되어서 데이터값을 지속적으로 발송하여 주는것인지 또는 R을 주기적으로 입력해 주어야 하는 것인지요?

R을 입력할 때마다 데이터 값(5 Bytes)을 수신하도록 되어 있습니다.

* 결국 제대로 동작하지 않는듯 하여 콘덴서를 이용한 제작을 함.

---

```C++
char buffer[5] = {0,};
int n = 0;
void setup() 
{
  Serial.begin (38400);        // Baud Rate 설정
}

void loop() 
{
  Serial.write('R'); // Transmit Read Command
  while(Serial.available()>0)
  {
    buffer[n] = Serial.read(); // Read Status
    n++;
  }
  for(int i=0;i<5;i++)
  {
    Serial.write(buffer[i]); // Status Output
  }
  Serial.write("\n");
  n = 0;
  delay(100);
}
```

---

#레오나르도용 통합
```C++
void setup() {
  pinMode(7,INPUT);
  pinMode(13,OUTPUT);
  Serial.begin(38400); //USB시리얼 시작
  while(!Serial) { }
  Serial1.begin(38400); //하드웨어시리얼 시작
  while(!Serial1) { }
}
char buffer[5] = {0,};
int n = 0;
void loop() {
  digitalWrite(13,digitalRead(7)); //7번 핀으로 들어오는 Event HIGH, LOW를 그대로 LED에 반영

  while(Serial1.available()>0)
  {
    buffer[n] = Serial1.read(); // Read Status
    n++;
  }
  for(int i=0;i<5;i++)
  {
    Serial.write(buffer[i]); // Status Output
  }//하드웨어 시리얼을 USB 시리얼로 출력
  
  if(Serial.available() > 0){
    Serial1.write(Serial.read());
  }//USB 시리얼을 하드웨어 시리얼로 출력
  
  Serial1.write(0x52); //'R' 값을 주기적으로 전송
  Serial1.write("\n");
  n = 0;
  delay(100);
}
```