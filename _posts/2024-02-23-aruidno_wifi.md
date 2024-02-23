---
layout: post
title: arduino wifi 아두이노 와이파이
category: arduino
tags: arduino simple-code
---

# arduino wifi 아두이노 와이파이

```c++
#include <WiFi.h>

char ssid[] = "yourNetwork";     //  your network SSID (name) 
char pass[] = "12345678";    // your network password
int status = WL_IDLE_STATUS;     // the Wifi radio's status

void setup() {
  // initialize serial:
  Serial.begin(9600);

  // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  status = WiFi.begin(ssid, pass);

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
  }
}

void loop() {
  // do nothing
}
```
