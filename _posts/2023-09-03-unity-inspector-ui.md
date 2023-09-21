---
layout: post
title: inspector ui
category: unity3d
tags: ui c#
---

# inspector ui
```c#
[Range(0.0f, 1.0f)]
public float sliderFloat;

void OnValidate(){
    Debug.Log(sliderFloat);
}
```

```c#
public class ChatersName
{
    [HideInInspector] //인스펙터에서 해당 변수를 숨긴다
    public string FontName; //예약어 같은데 element0 대신에 사용된다
    public float delay_time;
}

ChatersName[] cp_name;
```