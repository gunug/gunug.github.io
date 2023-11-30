---
layout: post
title: Coroutine 코루틴
category: unity3d
tags: c#
---

# 코루틴
```c#
void Start(){
    StartCoroutine(coroutineFunction());
}
IEnumerator coroutineFunction(){
    yield return new WaitForSeconds(0.5f);
    Debug.Log("coroutine");
    yield return null;
}
```

```c#
void Start(){
    StartCoroutine(coroutineFunction("send massage"));
}
IEnumerator coroutineFunction(string msg){
    yield return new WaitForSeconds(0.5f);
    Debug.Log(msg);
    yield return null;
}
```