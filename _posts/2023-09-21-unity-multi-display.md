---
layout: post
title: Multi Display 멀티 디스플레이
category: unity3d
tags: c#
---

# Multi Display 멀티 디스플레이
* https://docs.unity3d.com/Manual/MultiDisplay.html
* https://docs.unity3d.com/kr/530/Manual/MultiDisplay.html

## 멀티 디스플레이 활성화
```c#
using UnityEngine;
using System.Collections;

public class DisplayScript : MonoBehaviour
{
    // Use this for initialization
    void Start()
    {
        Debug.Log("displays connected: " + Display.displays.Length);
        // Display.displays[0] is the primary, default display and is always ON.
        // Check if additional displays are available and activate each.
        if (Display.displays.Length > 1)
            Display.displays[1].Activate();
        if (Display.displays.Length > 2)
            Display.displays[2].Activate();
        

        //Display.displays[1].Activate(2560,1440,60); //가로, 세로, 주사율
    }
    // Update is called once per frame
    void Update()
    {

    }
}
```