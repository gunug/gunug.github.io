---
layout: post
title: CES2024 arduino sample
category: work
tags: 
---

# CES2024 arduino sample

---

```c++
#include <TimerOne.h>
#include <MultiFuncShield.h>

void setup() {
  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
}
char ledChar[4]="1234";
char dataCount=0;
String full_string;
String cut_string;
int device_id = 0;
int state_id = 0;
void loop() {
  full_string = "";
  while (Serial.available() > 0) {
    char chr = Serial.read();
    String str(chr);
    full_string += str;
  }
  if(full_string != ""){
    Serial.print(full_string);
    cut_string = full_string.substring(1);
    device_id = cut_string.substring(0,2).toInt();
    state_id = cut_string.substring(2,4).toInt();
    cut_string.toCharArray(ledChar, 5);
    MFS.write(ledChar);
    /*
    if(device_id != 0)MFS.beep(5, 5, device_id, 1, 50);
    delay(500);
    if(state_id != 0)MFS.beep(5, 5, state_id, 1, 50);
    */ //beep횟수가 많아지니 문제가 되어서 사용하지 않기로함
    MFS.beep(5, 5, 2, 1, 50); //2회 beep로 통일
  }
  //
  byte btn = MFS.getButton();

   if (btn)
  {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;
    String bn_str = String(buttonNumber);
    if (bn_str == "1" && buttonAction == BUTTON_PRESSED_IND)Serial.println(10101);
    if (bn_str == "2" && buttonAction == BUTTON_PRESSED_IND)Serial.println(10102);
    if (bn_str == "3" && buttonAction == BUTTON_PRESSED_IND)Serial.println(10103);
  }
}
```