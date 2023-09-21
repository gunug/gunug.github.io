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