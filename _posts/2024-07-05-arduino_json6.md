---
layout: post
title: Arduino Json6 아두이노 json 변환
category: arduino
tags: 
---

# ArduinoJson 6

---

* ArduinoJson 6로 Json 파싱 및 노드접근 샘플코드 만들어서 공유 드립니다.
  
# 소스코드

```c++
#include <ArduinoJson.h>

String json_str = "{\"DOmdks42skdjqQsia1Cha4\":{\"email\":\"test@test.com\",\"name\":\"\\\"테스트용1\\\"\",\"uid\":\"tttttttt\"},\"I1R2Wr0QBgSecD3hahOvjQ3WrCy2\":{\"email\":\"test@test.com\",\"name\":\"tset\",\"uid\":\"ttttttt\"}}";
JsonObject obj;
StaticJsonDocument<200> doc;

void setup() {
  DeserializationError error = deserializeJson(doc, json_str); //역직렬화 시도후 에러시 기록
  if (error) { //파싱 실패시 에러메세지 출력
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.f_str());
    return;
  }
  Serial.begin(9600);
}

void loop() {
  //Serial.println(json_str);
  String value_root = doc["DOmdks42skdjqQsia1Cha4"]; 
  Serial.println(value_root);
  String value_email = doc["DOmdks42skdjqQsia1Cha4"]["email"]; 
  Serial.println(value_email);
  delay(1000);
}
```

---

# 참고자료

- ArduinoJson6 마이그레이션 : https://arduinojson.org/v6/doc/upgrade/
- ArduinoJson6 예제코드 : https://forum.arduino.cc/t/example-of-converting-string-for-use-with-arduinojson/424902/5