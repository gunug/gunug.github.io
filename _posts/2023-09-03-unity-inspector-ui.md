---
layout: post
title: inspector ui
category: unity3d
tags: unity3d c#
---

# inspector ui
```javascript
[Range(0.0f, 1.0f)]
public float sliderFloat;

void OnValidate(){
    Debug.Log(sliderFloat);
}
```