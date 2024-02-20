---
layout: post
title: arduino lcd 아두이노 액정디스플레이
category: arduino
tags:
---

# arduino lcd 아두이노 액정디스플레이

```c++
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
//RS, Inable, data1,2,3,4);

void setup() {
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2); //(16*2)사이즈의 LCD입니다. LCD 초기화
  // Print a message to the LCD.
  lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1); //(가로지점,세로지점)
  // print the number of seconds since reset:
  lcd.print(millis()/1000);
  //millis()는 아두이노 구동시점을 0으로 하여 밀리초단위로 증가하는 함수
}

LiquidCrystal()
begin()
clear() //지우기
home() //커서를 0,0으로 옮기기
setCursor() //커서를 특정위치로 옮기기
write()
print() //문자쓰기
cursor() //커서켜기
noCursor() //커서끄기
blink() 
noBlink()
display()
noDisplay()
scrollDisplayLeft() //디스플레이를 왼쪽으로 한칸
scrollDisplayRight() //디스플레이를 오른쪽으로 한칸
autoscroll() //자동으로 움직이기
noAutoscroll()
leftToRight()
rightToLeft()
createChar()

0.1초 정도 간격을 두고 갱신하는게 좋다
```
