---
layout: post
title: value mapping 값 매핑
category: c#
tags: c# simple_code
---

```c#
public static float map( float origin, float inputMin, float inputMax, float outputMin, float outputMax )
{
  return outputMin + ( origin - inputMin ) * ( outputMax - outputMin ) / ( inputMax - inputMin );
}
```