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
#include <MultiFuncShield.h>

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1); 
}

void loop() {
  byte btn = MFS.getButton();
  
  if (btn)
  {
    byte buttonNumber = btn & B00111111;
    byte buttonAction = btn & B11000000;

    if (buttonAction == BUTTON_PRESSED_IND){}
    if (buttonAction == BUTTON_SHORT_RELEASE_IND){}
    if (buttonAction == BUTTON_LONG_PRESSED_IND){}
    if (buttonAction == BUTTON_LONG_RELEASE_IND){}
  }
}
```

---

# LED 디스플레이

```c++
#include <TimerOne.h>
#include <MultiFuncShield.h>

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  
  MFS.write("Hi");
  MFS.write(-273);
  MFS.write(3.141, 2);  // display to 2 decimal places.
}

int counter=0;
byte ended = false;
String str = "test";
char cha[4] = "base";

void loop() {
    str.toCharArray(cha, 5); 
    //원본.CharArray로 변환(대상, 길이);
    //왜 legnth를 하나더 길게 넣어야 하는지는 의문
    MFS.write(cha); //글자의 경우 string이 아닌 char array로 집어넣어야 함
    MFS.blinkDisplay(DIGIT_ALL, ON);
}
```

---

# beeper

```c++
#include <TimerOne.h>
#include <MultiFuncShield.h>

void setup() {
  // put your setup code here, to run once:

  Timer1.initialize();
  MFS.setBeeperReversePolarity(true);  // try setting to true if your beeper is always on by default with KNARCO brand boards
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  MFS.beep(5, 5, 4, 3, 50);
  // deep 50 milliseconds, silent 50 milliseconds, repeat 4 times, loop 3 times, wait 500 milliseconds between loop
  // 4 short beeps, repeated 3 times.
}
void loop() {
  // put your main code here, to run repeatedly:
}
//비프 후 켜진 상태로 종료
```
* 루프중에도 소리가 계속나옴 (사용 비추천)

```c++
#include <TimerOne.h>
#include <MultiFuncShield.h>

void setup() {
  // put your setup code here, to run once:

  Timer1.initialize();
  MFS.initialize(&Timer1);    // initialize multi-function shield library
  // NOTE beep control is performed in the background, i.e. beep() is non blocking.
  // short beep for 200 milliseconds
  MFS.beep(); // 소리 멈추는 주요 코드인듯
  MFS.beep(5, 5, 4, 3, 50);
  // deep 50 milliseconds, silent 50 milliseconds, repeat 4 times, loop 3 times, wait 500 milliseconds between loop
  // 4 short beeps, repeated 3 times.

}
void loop() {
  // put your main code here, to run repeatedly:
}
//비프 후 꺼진 상태로 종료
```