---
layout: post
title: FPS counter 프레임 출력기
category: unity3d
tags: c# simple-code
---

# FPS counter 프레임 출력기

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FPSCounter : MonoBehaviour
{
    [Range(10, 150)]
    public int fontSize = 50;
    private int counter = 0;
    private void OnGUI()
    {
        //Rect position = new Rect(width, height, Screen.width, Screen.height);
        Rect position = new Rect(0, 0, 100, 100);

        float fps = 1.0f / Time.deltaTime;
        float ms = Time.deltaTime * 1000.0f;

        string text = "";
        if (counter > 100)
        {
            text = string.Format("{0:N1} FPS ({1:N1}ms)", fps, ms);
            counter = 0;
        }
        counter++;

        GUIStyle style = new GUIStyle();
        style.fontSize = fontSize;
        style.normal = new GUIStyleState();
        style.normal.textColor = Color.white;
        style.normal.background = Texture2D.blackTexture;

        GUI.Label(position, text, style);
    }
}
```