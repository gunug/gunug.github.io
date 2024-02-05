---
layout: post
title: arduino passive buzzer 아두이노 패시브 부져
category: arduino
tags: arduino
---

# arduino passive buzzer 아두이노 패시브 부져
* 참고 : http://makeshare.org/bbs/board.php?bo_table=Wiki2&wr_id=18

![image](https://github.com/gunug/gunug.github.io/assets/52345276/cf6262d1-6aa8-48ab-893f-3ea67f8765fa)


```c++
int speakerPin = 5;

void playTone(int tone, int duration)
{
  for (long i = 0; i < duration * 1000L; i += tone * 2)
  {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}

void playNote(char note, int duration)
{
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };         //음계 함수 설정
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };   // 음계 톤 설정
  for (int i = 0; i < 8; i++)
  {
    if (names[i] == note)
    {
      playTone(tones[i], duration);
    }
  }
}

void setup()
{
  pinMode(speakerPin, OUTPUT);
}
void loop() {
  playNote('c', 300);
  playNote('d', 300);
}
```
