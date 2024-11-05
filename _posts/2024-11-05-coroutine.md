---
layout: post
title: 코루틴 coroutine, 큐 스택 리스트 queue stack list, 싱글톤 singleton
category: unity3d
tags: simple-code
---

# 코루틴 coroutine

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Coroutine : MonoBehaviour
{
    public void Start(){
        StartCoroutine(Fade(new GameObject()));
    }
    
    IEnumerator Fade(GameObject target) {
        yield return new WaitForSeconds(0.1f);
        yield return null;
    }
}
```

---

# 큐 스택 리스트 queue stack list

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class QueueStackList : MonoBehaviour
{
    //Queue, Stack, List
    public GameObject one_gameobject;
    public Queue<GameObject> queue_gameobject;
    public Stack<GameObject> stack_gameobject;
    public List<GameObject> list_gameobject;
    public GameObject[] gameObjects = new GameObject[20]();
    public void Start(){
        queue_gameobject.Enqueue(new GameObject()); //끝 부분에 추가(큐에 추가됨)
        GameObject one_gameobject = queue_gameobject.Dequeue(); //시작 부분에서 반환(큐에서 제거됨)
        GameObject one_gameobject = queue_gameobject.Peek(); //시작 부분에서 반환(큐에 유지)

        stack_gameobject.Push(new GameObject()); //시작 부분에 추가(스택에 추가됨)
        GameObject one_gameobject = stack_gameobject.Pop(); //시작 부분에서 반환(큐에서 제거됨)
        GameObject one_gameobject = stack_gameobject.Peek(); //시작 부분에서 반환(큐에 유지)

        list_gameobject.Add(new GameObject());
        list_gameobject.Insert(1, new GameObject());
        list_gameobject.Remove("gameObject");
        list_gameobject.RemoveAt(1);
    }
}
```

---

# 싱글톤 singleton

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SingletonClass : MonoBehaviour
{
    
    //싱글톤 패턴
    public static SingletonClass instance;
    //static 정적인 , dynamic 동적인
    //dynamic : instance = new SingletonClass(); 동적생성
    //static : SingletonClass.instance

    public Awake(){
        init();
    }

    public SingletonClass init(){
        if(instance == null){
            instance = new SingletonClass();
        }
        return instance;
    }
}
```