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