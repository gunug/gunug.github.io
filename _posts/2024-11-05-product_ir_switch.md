---
layout: post
title: arduino product ir switch
category: arduino
tags: product
---

# product ir switch
```c++
#include <SimpleKalmanFilter.h>
#include <EEPROM.h>

int distance_limit = 0;
void setup() {
  distance_limit = EEPROM.read(10)*2;
}

#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_E6  1319
#define NOTE_G7  3136

float value = 0;
float e_mea = 1; //측정값 달라지는 양
float e_est = 1; //kalman필터가 값을 조정함으로 e_mea와 동일값 입력
float q = 0.005; // 0.001 ~ 1 : 측정이 얼마나 빨리 움직이는지 (권장: 0.01) 필요에 따라 조정
SimpleKalmanFilter kf = SimpleKalmanFilter(e_mea, e_est, q);


bool beep_mode = false;
bool button_pushed = false;
bool distance_saved = false;
bool isIn = false;
int noteDuration = 20;

// 20cm ~ 150cm
// 2.5V ~ 0.5V
// 20 ~ 500 analog value
int button_hold_counter = 0;

void loop() {
  value = analogRead(A0);  
  float estimated_x = kf.updateEstimate(value);
  //Serial.println(estimated_x);
  //delay(10);
  if(beep_mode){
    if(estimated_x > distance_limit + 10){
      if(!isIn){
        beep_note(NOTE_G7);
        isIn = true;
      }
    }else{
      if(isIn){
        beep_note(NOTE_E6);
        isIn = false;
      }
    }
  }

  bool digital_signal = digitalRead(10);
  if(digital_signal == HIGH){
    //tone(9, NOTE_C4, 4);
    digitalWrite(9,HIGH);
    button_pushed = false;
    distance_saved = false;
    button_hold_counter = 0;
  }else{
    if(button_pushed == false){
      button_pushed = true;
      change_mode();
    }else{
      button_hold_counter++;
      if(button_hold_counter > 1000){
        //10초이상 홀드시
        if(!distance_saved){
          set_new_distance(estimated_x);
          distance_saved = true;
        }
      }
    }
  }
}

void set_new_distance(int distance){
  distance_limit = distance;
  EEPROM.write(10, distance/2);
  beep_note(NOTE_C4);
  beep_note(NOTE_E4);
  beep_note(NOTE_G4);
}

void change_mode(){
  if(beep_mode){
    beep_note(NOTE_E4);
    beep_note(NOTE_D4);
    beep_note(NOTE_C4);
  }else{
    beep_note(NOTE_C4);
    beep_note(NOTE_D4);
    beep_note(NOTE_E4);
  }
  beep_mode = !beep_mode;
}

void beep_note(int note){
  tone(9, note, noteDuration);
  delay(noteDuration);
  noTone(9);
  digitalWrite(9,HIGH);
}
```