---
layout: post
title: arduino lcd shield
category: arduino
tags: basic
---

# arduino lcd shield

![image](https://github.com/gunug/gunug.github.io/assets/52345276/32f79d6e-069f-4058-b440-503aaa3805be)


* [참고링크](https://eduino.kr/product/detail.html?product_no=37)
* up 0
* down 140
* left 325
* right 500
* select 737

```c++
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // LCD패널에 사용되는 핀 설정
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
int read_LCD_buttons() {
  adc_key_in = analogRead(0);                 // 키패드 값을 받음
  if (adc_key_in > 1000) return btnNONE;
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;
  return btnNONE;
}
void setup() {
  lcd.begin(16, 2);               // 라이브러리 시작
  lcd.setCursor(0, 0);            // 첫번째 줄 LCD 커서 위치 설정
  lcd.print("Push the buttons");  // 첫번째 줄에 출력
}
void loop() {
  lcd.setCursor(9, 1);            // 두번째 줄 LCD 커서 위치 설정
  lcd.print(millis() / 1000);     // 숫자 카운트 출력
  lcd.setCursor(0, 1);            // 두번째 줄 LCD 커서 위치 설정
  lcd.print("        ");
  lcd_key = read_LCD_buttons();   // 키패드 값을 읽음
  lcd.setCursor(0, 1);
  lcd.print(adc_key_in);
  /*
  switch (lcd_key) {              // 키패드 이름 출력
    case btnRIGHT: {
        lcd.print("RIGHT ");
        break;
      }
    case btnLEFT: {
        lcd.print("LEFT   ");
        break;
      }
    case btnUP: {
        lcd.print("UP    ");
        break;
      }
    case btnDOWN: {
        lcd.print("DOWN  ");
        break;
      }
    case btnSELECT: {
        lcd.print("SELECT");
        break;
      }
    case btnNONE: {
        lcd.print("NONE  ");
        break;
      }
  }
  */
}

```

---

# 시리얼값을 input으로 첫줄에 출력, 버튼을 누르면 output으로 시리얼에 전송하는 소스코드

```c++
#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // LCD패널에 사용되는 핀 설정
int lcd_key     = 0;
int adc_key_in  = 0;
#define btnRIGHT  0
#define btnUP     1
#define btnDOWN   2
#define btnLEFT   3
#define btnSELECT 4
#define btnNONE   5
int read_LCD_buttons() {
  adc_key_in = analogRead(0);                 // 키패드 값을 받음
  //Serial.println(adc_key_in);
  if (adc_key_in > 1000) return btnNONE;
  if (adc_key_in < 50)   return btnRIGHT;
  if (adc_key_in < 195)  return btnUP;
  if (adc_key_in < 380)  return btnDOWN;
  if (adc_key_in < 555)  return btnLEFT;
  if (adc_key_in < 790)  return btnSELECT;
  return btnNONE;
}
void setup() {
  lcd.begin(16, 2);               // 라이브러리 시작
  Serial.begin(9600);
}
void loop() {
  lcd.setCursor(0, 0);
  lcd.print("input: ");
  if (Serial.available() > 0) {
    String teststr = Serial.readString();
    lcd.clear();
    lcd.setCursor(9, 0);
    lcd.print(teststr);
  }

  lcd_key = read_LCD_buttons();   // 키패드 값을 읽음
  lcd.setCursor(0, 1);
  lcd.print("output: ");
  lcd.setCursor(9, 1);
  switch (lcd_key) {              // 키패드 이름 출력
    case btnRIGHT: {
        Serial.println("0101");
        lcd.print("0101");
        break;
      }
    case btnLEFT: {
        Serial.println("0102");
        lcd.print("0102");
        break;
      }
    case btnUP: {
        Serial.println("0103");
        lcd.print("0103");
        break;
      }
    case btnDOWN: {
        Serial.println("0104");
        lcd.print("0104");
        break;
      }
    case btnSELECT: {
        Serial.println("0105");
        lcd.print("0105");
        break;
      }
    case btnNONE: {
        break;
      }
  }
  lcd_key = btnNONE;
  delay(10);
}

```
