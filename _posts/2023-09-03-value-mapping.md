---
layout: post
title: value mapping 값 매핑
category: unity-asset
tags: c# simple-code
---

```c#
public static float map( float origin, float inputMin, float inputMax, float outputMin, float outputMax )
{
  return outputMin + ( origin - inputMin ) * ( outputMax - outputMin ) / ( inputMax - inputMin );
}
```

```c#
float map(float s, float a1, float a2, float b1, float b2)
{
    return b1 + (s-a1)*(b2-b1)/(a2-a1);
}
```