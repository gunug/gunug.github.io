---
layout: post
title: Unity PlayerPrefs 플레이어 정보저장
category: unity3d
tags: c#
---

# Unity PlayerPrefs 플레이어 정보저장

```c#
PlayerPrefs.SetString("변수명", 값);
PlayerPrefs.SetInt("변수명", 값);
PlayerPrefs.SetFloat("변수명", 값);

public void Awake(){
    if(PlayerPrefs.HasKey("변수명")){
        PlayerPrefs.GetString("변수명");
        PlayerPrefs.GetInt("변수명");
        PlayerPrefs.GetFloat("변수명");
    }
}
```