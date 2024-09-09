---
layout: post
title: Unity3d event 이벤트
category: unity3d
tags: simple-code
---

# Unity3d event 이벤트
## 기본
```csharp
using UnityEngine.Events;
public class MainClass : MonoBehaviour{
    public UnityEvent simpleEvent;

    public void Start(){
        simpleEvent.AddListener(Ping); //이벤트 등록
        simpleEvent.Invoke(); //이벤트 호출
    }
    public void Ping(){
        Debug.Log("ping!");
    }
}
```

## 커스텀

```csharp
using UnityEngine.Events;

[Serializable]
public class RayEvent : UnityEvent<string,GameObject>{}

public class MainClass : MonoBehaviour{
    public RayEvent pressEvents;
    public RayEvent releaseEvents;
}
```