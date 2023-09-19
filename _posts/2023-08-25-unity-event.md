---
layout: post
title: Event 이벤트
category: unity3d
tags: c# simple_code delegate
---

# 유니티 이벤트

---

```c#
using UnityEngine.Events;
public UnityEvent onPlayerDead; //이벤트 선언
void Start(){
    onPlayerDead.Invoke; //이벤트 발생
}
```

---

## Addlistener
* 참고 : https://m.blog.naver.com/PostView.naver?isHttpsRedirect=true&blogId=pxkey&logNo=221366003568

```c#
using UnieyEngine.UI;

public Button btnVisible;
void Awake(){
    btnVisible.Addlistener(activeFunction); //버튼의 OnClick 이벤트 받기
    btnVisible.RemoveAllListeners(); //전체 이벤트 삭제
    btnVisible.RemoveListener(activeFuncion); //특정 이벤트 삭제
}
public void activeFunction(){
    Debug.Log("active");
}
```

```c#
btnVisible.Addlistener(()=>activeFuncion()) //람다식
btnVisible.Addlistener(()=>{/* 소스코드 */})
btnVisible.Addlistener(()=>massageFunction("인자값")) //인자값을 전달해야 하는 경우
public void massageFunction(string msg){

}
```

---

# Event Handler

*참고 : https://coderzero.tistory.com/entry/%EC%9C%A0%EB%8B%88%ED%8B%B0-C-%EA%B0%95%EC%A2%8C-17-%EC%9D%B4%EB%B2%A4%ED%8A%B8Event-%EB%8C%80%EB%A6%AC%EC%9E%90-%EB%8D%B8%EB%A6%AC%EA%B2%8C%EC%9D%B4%ED%8A%B8-Delegate

```c#
using System;
using UnityEngine;
class EventSender{
    public event EventHandler _handler; //이벤트 정의
    _handler(this, EventArgs.Empty); //이벤트 핸들러 호출
}
class EventGetter{
    public EventSender _sender = new EventSender();
    _sender.Click = new EventHandler(clickFunction);

    void clickFunction(object sender, EventArgs e){
        Debug.Log("버튼 클릭");
    }
}
```

---

# 이벤트 등록, 호출 (인자값 없음)

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public class EventSender
{
    public event EventHandler _handler; //이벤트 정의
    private static EventSender _instance;
    public static EventSender instance{
        get{
            if (object.ReferenceEquals(_instance, null))
            {
                _instance = new EventSender(); //인스턴스가 없다면 생성해서 제공
            }
            return _instance; //있다면 그냥 제공
        }
    }
    public void sendEvent()
    {
        if (this._handler != null)
        {
            _instance._handler(this, EventArgs.Empty); //샌드 이벤트를 이용하여 이벤트 호출
        }
    }
}

public class TestEvent : MonoBehaviour
{
    private void Awake()
    {
        EventSender.instance._handler += new EventHandler(activeFunction); //이벤트 등록
    }
    private void Start()
    {
        EventSender.instance.sendEvent(); //이벤트 호출
    }
    void activeFunction(object sender, EventArgs e)
    {
        Debug.Log("이벤트 호출됨");
    }
}

```
* 생성자 있는 싱글톤

---

# 이벤트 송수신기 Simple code
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System;

public enum ContentEventType
{
    Chapter1,
    Chapter2
}

public class EventSender
{
    public EventMathod[] _handlers = new EventMathod[System.Enum.GetValues(typeof(ContentEventType)).Length];
    private static EventSender _instance;
    public static EventSender instance{
        get{
            if (object.ReferenceEquals(_instance, null))
            {
                _instance = new EventSender(); //인스턴스가 없다면 생성해서 제공
            }
            return _instance; //있다면 그냥 제공
        }
    }
    public void CallEvent(ContentEventType target_event)
    {
        int event_number = (int)target_event;
        if (this._handlers[event_number] != null)
        {
            _instance._handlers[event_number](); //샌드 이벤트를 이용하여 이벤트 호출
        }
    }

    public delegate void EventMathod();
    public void AddEvent(EventMathod target_method, ContentEventType event_type)
    {
        int event_number = (int)event_type;
        _handlers[event_number] += new EventMathod(target_method);
    }
}

public class TestEvent : MonoBehaviour
{
    private void Awake()
    {
        //EventSender.instance._handler += new EventHandler(activeFunction); //이벤트 등록
        EventSender.instance.AddEvent(activeFunction, ContentEventType.Chapter1); //이벤트 등록
        EventSender.instance.AddEvent(activeFunction2, ContentEventType.Chapter2); //이벤트 등록
    }
    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.K)) EventSender.instance.CallEvent(ContentEventType.Chapter1); //이벤트 호출
        if (Input.GetKeyDown(KeyCode.L)) EventSender.instance.CallEvent(ContentEventType.Chapter2); //이벤트 호출
    }
    void activeFunction()
    {
        Debug.Log("이벤트 호출됨");
    }
    void activeFunction2()
    {
        Debug.Log("이벤트 호출됨2");
    }
}
```

```c#
    EventSender.instance.AddEvent(함수, 컨텐츠이벤트타입); //이벤트 등록
    EventSender.instance.CallEvent(컨텐츠이벤트타입); //이벤트 호출
```