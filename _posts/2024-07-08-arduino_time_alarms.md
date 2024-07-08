---
layout: post
title: arduino TimeAlarms 라이브러리
category: arduino
tags: 
---

# arduino TimeAlarms 라이브러리

```c++
  Alarm.alarmRepeat(8,30,0, MorningAlarm);  // 8:30am every day
  Alarm.alarmRepeat(17,45,0,EveningAlarm);  // 5:45pm every day
  Alarm.alarmRepeat(dowSaturday,8,30,30,WeeklyAlarm);  // 8:30:30 every Saturday
```