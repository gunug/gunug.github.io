---
layout: post
title: arduino serial communication 아두이노 시리얼통신
category: arduino
tags: c++ simple-code 
---

# arduino serial communication 아두이노 시리얼통신

```c#
char dataChar[10];
int charCount = 0;
boolean reading = false;

  if(Serial.available()){
     char val;
     val = Serial.read();
     if(val == ']'){
       Serial.print("[data:");
       Serial.print(dataChar);
       Serial.print("]");
       Serial.print("\n");
       if(dataChar[0] == 's'){
         loopNum = 0;
       }else if(dataChar[0] == 'c'){
         loopNum = 1;
       }else if(dataChar[0] == 'w'){
          loopNum = 2;
       }else{
         reading = false;
         val_int = atoi(dataChar);
         //Serial.print(val_int);
         //rolling(val_int);
         //rolling(100);
       }
     }
     if(reading){
       dataChar[charCount] = val;
       charCount ++;
     }
     if(val == '['){
       reading = true;
       for(int i=0; i<10; i++){
         dataChar[i] = 0;
       }
       charCount = 0;
     }
   }
```
* [시작, ]끝, 으로 내부에 명령어를 넣고 아두이노에서 명령어를 걸러내는 방식

---

# 더 간소화
```c++
void setup() {
  Serial.begin(9600);
}
void loop() {
  if (Serial.available() > 0) {
    String str = Serial.readString();
    Serial.println(str);
  }
  delay(10);
}
```
* 구현은 쉬운편이지만 타임아웃까지 기다렸다가 후처리 하는 방식으로 2.5초 정도의 딜레이가 생긴다

---

# 다른방식
```c++
void setup() {
  Serial.begin(9600);
  pinMode(13,OUTPUT);
}
char dataChar[10];
char dataCount=0;
String full_string;
void loop() {
  full_string = "";
  while (Serial.available() > 0) {
    char chr = Serial.read();
    String str(chr);
    Serial.println(str);
    full_string += str;
  }
  if(full_string != "")Serial.println(full_string);
  if(full_string == "01000\n"){ //개행문자 \n 까지 포함하여 검사
    digitalWrite(13,HIGH);
  }else if(full_string == "02000\n"){
    digitalWrite(13,LOW);
  }
  delay(10);
}
```

* 한큐에 다 들어오기 때문에 받아지긴 하는데, 시스템에 따라 쪼개져서 들어오는 경우가 없는지 확인해야함

---

# 세마포(semaphore) 제한 시간이 만료되었습니다.
* 아두이노에 read 부분이 구현되어 있지않아 serial를 발송하였지만 받아주지 않았음
* Unity에서 송신 완료를 대기하다가 timeout 되는 증상이 발생