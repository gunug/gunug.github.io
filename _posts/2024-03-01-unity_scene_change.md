---
layout: post
title: unity scene change 씬 변경
category: unity3d
tags: 
---

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement; //SceneManagement를 불러옵니다.
 
public class dont_destroy : MonoBehaviour { 
    void gotoScene(int Scene_num)
    {
        SceneManager.LoadScene(Scene_num); //Scene을 교체합니다.
    }

    void Start () {
        DontDestroyOnLoad(transform.gameObject); //Scene 교체시에도 남겨둡니다. 
    }
}
```
