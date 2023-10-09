---
layout: post
title: arduino serial communication 아두이노 시리얼통신
category: arduino
tags: c++ simple-code 
---

# arduino serial communication 아두이노 시리얼통신

```c#
char dataChar[10];
int charCount = 0;
boolean reading = false;

  if(Serial.available()){
     char val;
     val = Serial.read();
     if(val == ']'){
       Serial.print("[data:");
       Serial.print(dataChar);
       Serial.print("]");
       Serial.print("\n");
       if(dataChar[0] == 's'){
         loopNum = 0;
       }else if(dataChar[0] == 'c'){
         loopNum = 1;
       }else if(dataChar[0] == 'w'){
          loopNum = 2;
       }else{
         reading = false;
         val_int = atoi(dataChar);
         //Serial.print(val_int);
         //rolling(val_int);
         //rolling(100);
       }
     }
     if(reading){
       dataChar[charCount] = val;
       charCount ++;
     }
     if(val == '['){
       reading = true;
       for(int i=0; i<10; i++){
         dataChar[i] = 0;
       }
       charCount = 0;
     }
   }
```
* [시작, ]끝, 으로 내부에 명령어를 넣고 아두이노에서 명령어를 걸러내는 방식
