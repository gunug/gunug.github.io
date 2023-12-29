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

---

# 특이사항
* 메인스레드가 아닌곳에서 코루틴 호출시 무시됨
* 에러메세지나 알림도 뜨지 않고 그냥 작동하지 않아서 원인파악이 힘들었다.