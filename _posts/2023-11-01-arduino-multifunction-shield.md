---
layout: post
title: arduino multifunction shield 멀티펑션 쉴드
category: arduino
tags: basic
---

# arduino multifunction shield 멀티펑션 쉴드

![image](https://github.com/gunug/gunug.github.io/assets/52345276/0ff72046-edb9-4448-8258-bfbf5601d2b9)
* [라이브러리 링크](https://github.com/hpsaturn/MultiFuncShield-Library)

---

* 라이브러리 포함하기 : MultiFunctionShield by Florian
* Library only for Arduino Uno, Nano and so on with ATmega328
* 레오나르도 지원 안되는듯하여 다른 방법 찾자

---

# 버튼 예제
* TimeOne.h를 위해 TimeOne라이브러리를 검색해서 설치함
```c++
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
}


void loop() {
  // put your main code here, to run repeatedly:

  byte btn = MFS.getButton(); // Normally it is sufficient to compare the return
                              // value to predefined macros, e.g. BUTTON_1_PRESSED,
                              // BUTTON_1_LONG_PRESSED etc.
  
  if (btn)
  {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;
    
    Serial.print("BUTTON_");
    Serial.write(buttonNumber + '0');
    Serial.print("_");
    
    if (buttonAction == BUTTON_PRESSED_IND)
    {
      Serial.println("PRESSED");
    }
    else if (buttonAction == BUTTON_SHORT_RELEASE_IND)
    {
      Serial.println("SHORT_RELEASE");
    }
    else if (buttonAction == BUTTON_LONG_PRESSED_IND)
    {
      Serial.println("LONG_PRESSED");
    }
    else if (buttonAction == BUTTON_LONG_RELEASE_IND)
    {
      Serial.println("LONG_RELEASE");
    }
  }
}
```

---

# LED 디스플레이

```c++
#include <TimerOne.h>
#include <Wire.h>
#include <MultiFuncShield.h>

void setup() {
  // put your setup code here, to run once:
  
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  
  MFS.write("Hi");
  delay(2000);
  MFS.write(-273);
  delay(2000);
  MFS.write(3.141, 2);  // display to 2 decimal places.
  delay(2000);
}

int counter=0;
byte ended = false;

void loop() {
  // put your main code here, to run repeatedly:

  if (counter < 200)
  {
    MFS.write((int)counter);
    counter++;
  }
  else if (!ended)
  {
    ended = true;
    MFS.write("End");
    MFS.blinkDisplay(DIGIT_ALL, ON);
  }
  delay(50);
}
```