---
layout: post
title: arduino CR LF 캐리지리턴 라인피드
category: arduino
tags:
---

# CR LF
* CR(캐리지리턴) : 화면이나 프린터로 출력할 때, 줄의 맨 앞으로 오게 하는 특수문자 코드
* LF(라인피드) : 화면이나 프린터로 출력할 때, 다음 줄로 넘어하게 하는 특수문자 코드

```c++
CR = \r = 0x0D
LF = \n = 0x0A
```
* 순서상으로 0x0D, 0x0A로 전달되는 것이 맞을 것으로 보임
* 윈도우 에서는 CR, LF 연속된 2바이트를 사용함
* 유닉스 에서는 개행코드로 LF만 사용함

```markdown
Line ending 없음 : none
새줄 : LF
캐리지 리턴 : CR
Both NL & CR : CR,LF
```

```
Serial.write(0x0D); 작동하지 않음?
Serial.write(0x0A); 만으로 작동함?
0x0A 문자를 둘다 CR+LF 인것 처럼 작동하여 다음줄의 시작 부분으로 이동합니다.

아두이노에서
Serial.println();
Serial.print('\n');
Serial.write(0x0A);

모두 같은 기능을 수행한다
```