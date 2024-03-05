---
layout: post
title: Arduino EEPROM 내장 메모리에 변수 저장하기
category: arduino
tags: arduino
---

# Arduino EEPROM 내장 메모리에 변수 저장하기

* 참고 : https://m.blog.naver.com/damtaja/220217759177

```c++
EEPROM.write(i, randomNumber); // write(주소, 값)
randomNumber = EEPROM.read(i); // read(주소)
```