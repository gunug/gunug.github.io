---
layout: post
title: Coroutine 코루틴
category: unity3d
tags: unity3d c#
---

# 코루틴
```c#
void Start(){
    StartCoroutine(coroutineFunction());
}
IEnumerator coroutineFunction(){
    yield return new WaitForSeconds(0.5f);
    Debug.Log("coroutine");
}
```

```c#
void Start(){
    StartCoroutine(coroutineFunction("send massage"));
}
IEnumerator coroutineFunction(string msg){
    yield return new WaitForSeconds(0.5f);
    Debug.Log(msg);
}
```