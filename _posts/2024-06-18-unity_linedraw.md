---
layout: post
title: unity line draw 라인그리기
category: unity3d
tags: 
---

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CustomUtil : MonoBehaviour
{
    private void Start()
    {
        DrawLine(new Vector3(0, 0, 0), new Vector3(0, 0, 10));
        DrawLine(new Vector3(0, 0, 0), new Vector3(10, 0, 0));
        DrawLine(new Vector3(0, 0, 0), new Vector3(0, 10, 0));
    }

    public static void DrawLine(Vector3 start, Vector3 end)
    {
        GameObject myLine = new GameObject();
        myLine.transform.position = start;
        LineRenderer line_renderer = myLine.AddComponent<LineRenderer>();
        line_renderer.material = new Material(Shader.Find("Particles/Standard Unlit"));
        line_renderer.SetColors(Color.red, Color.green);
        line_renderer.SetWidth(0.1f, 0.1f);
        line_renderer.SetPosition(0, start);
        line_renderer.SetPosition(1, end);
        //GameObject.Destroy(myLine, 5f);
    }
}
```