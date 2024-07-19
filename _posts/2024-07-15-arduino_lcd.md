---
layout: post
title: arduino lcd simple code 아두이노 액정 디스플레이 요약
category: arduino
tags: simple-code
---

# arduino lcd simple code 아두이노 액정 디스플레이 요약

## LCD부분
```c++
Downloading Adafruit BusIO@1.16.1
Adafruit BusIO@1.16.1
Installing Adafruit BusIO@1.16.1
Installed Adafruit BusIO@1.16.1
Downloading Adafruit GFX Library@1.11.9
Adafruit GFX Library@1.11.9
Installing Adafruit GFX Library@1.11.9
Installed Adafruit GFX Library@1.11.9
Downloading Adafruit SSD1306@2.5.10
Adafruit SSD1306@2.5.10
Installing Adafruit SSD1306@2.5.10
Installed Adafruit SSD1306@2.5.10
```
* Adafruit BusIO
* Downloading Adafruit GFX Library
* Adafruit SSD1306
* 총 세가지 라이브러리 설치

```c++
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
Adafruit_SSD1306 display = Adafruit_SSD1306(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire);

void setup() {
    Serial.begin(115200);
    if(display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation success"));
        display.setTextSize(1);      // Normal 1:1 pixel scale
        display.setTextColor(SSD1306_WHITE); // Draw white text
        display.setCursor(0, 0);     // Start at top-left corner
        display.cp437(true);         // Use full 256 char 'Code Page 437' font
    }else{
        Serial.println(F("SSD1306 allocation failed"));
        return;
    }
    delay(2000); //esp32c3 특수로 인한 필수 딜레이
}
void loop(){
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Hello World!"); 
    display.println("test 01");

    display.setCursor(0, 31);
    display.print("test 02");

    display.setCursor(0, 16);
    display.print("test 03");
    display.display();

    delay(2000); //esp32c3 특수로 인한 필수 딜레이
}
```