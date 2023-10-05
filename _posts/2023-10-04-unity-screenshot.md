---
layout: post
title: unity screenshot 스크린샷
category: unity3d
tags: etc
---

* [참고링크](https://dhkvmf88.tistory.com/8)

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
 
public class ScreenShot : MonoBehaviour {
    public Camera camera;       //보여지는 카메라.
 
    private int resWidth;
    private int resHeight;
    string path;
    // Use this for initialization
    void Start () {
        resWidth = Screen.width;
        resHeight = Screen.height;
        path = Application.dataPath+"/ScreenShot/";
        Debug.Log(path);
    }
 
    public void ClickScreenShot()
    {
        DirectoryInfo dir = new DirectoryInfo(path);
        if (!dir.Exists)
        {
            Directory.CreateDirectory(path);
        }
        string name;
        name = path + System.DateTime.Now.ToString("yyyy-MM-dd_HH-mm-ss") + ".png";
        RenderTexture rt = new RenderTexture(resWidth, resHeight, 24);
        camera.targetTexture = rt;
        Texture2D screenShot = new Texture2D(resWidth, resHeight, TextureFormat.RGB24, false);
        Rect rec = new Rect(0, 0, screenShot.width, screenShot.height);
        camera.Render();
        RenderTexture.active = rt;
        screenShot.ReadPixels(new Rect(0, 0, resWidth, resHeight), 0, 0);
        screenShot.Apply();
 
        byte[] bytes = screenShot.EncodeToPNG();
        File.WriteAllBytes(name, bytes);
    }
}
```