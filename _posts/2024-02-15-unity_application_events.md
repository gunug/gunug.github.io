---
layout: post
title: Unity application events
category: unity3d
tags: c#
---

# Unity application events
```c#
OnApplicationPause(){}
//어플리케이션의 일시정지
OnApplicationQuit(){}
//어플리케이션의 종료
OnApplicationFocus(bool pauseStatus){}
//true, false로 포커스가 변경될때 마다 알려줌
//안드로이드의 경우 키보드로 포커스가 나가는(false)상황도 파악가능
```
## 백그라운드의 앱은 언제든지 OS에 의하여 종료될 수 있다
* <https://forum.unity.com/threads/onapplicationpause-focus-not-being-triggered-after-game-is-on-background-for-a-long-time-mobile.1393522/>
* 그게 정확히 무슨 뜻인가요? 이러한 콜백은 앱이 포그라운드에 있을 때만 실행될 수 있습니다. Unity는 포그라운드 애플리케이션이므로 앱이 백그라운드에 있을 때는 코드가 실행되지 않습니다. 또한 OnApplicationPause에서 서버 요청을 수행하는 것은 응답이 장치에 도착할 때 애플리케이션이 이미 백그라운드에 있기 때문에 기본적으로 완료할 수 없는 비동기 프로세스이기 때문에 쉽게 실패할 수 있습니다.

* Android의 백그라운드 앱은 본질적으로 일시 중지됩니다. 그러나 OS는 메모리가 필요한 경우 언제든지 백그라운드 앱을 종료하기로 결정할 수 있습니다. 따라서 앱이 오랫동안 백그라운드에 있으면 종료될 가능성이 높으므로 다시 전환하면 앱이 실제로 다시 시작됩니다.

* 정확한 관찰 내용과 해당 콜백 내에서 실제로 수행 중인 작업에 대한 정보를 추가할 수 있습니다. 어떤 경우에도 앱이 백그라운드로 전환되는 경우 관련 데이터를 로컬에 저장해야 합니다.

```c#
using UnityEngine;

public class AppPaused : MonoBehaviour
{
    bool isPaused = false;

    void OnGUI()
    {
        if (isPaused)
            GUI.Label(new Rect(100, 100, 50, 30), "Game paused");
    }

    void OnApplicationFocus(bool hasFocus)
    {
        isPaused = !hasFocus;
    }

    void OnApplicationPause(bool pauseStatus)
    {
        isPaused = pauseStatus;
    }
}
```

---

* System.net.socket;
* m_client.Close();
* 소캣을 닫을시에 마지막 패킷이 전송되는 문제
* 소캣을 닫지 않을 경우는 문제가 발생하지 않음
* 소캣을 닫을때 receive 이벤트가 발생하는데 영향이 있는지 확인
* receive를 통으로 막았을때 문제가 발생하지 않음
* close전에, m_client.Shutdown(SocketShutdown.Both); 사용해보았으나 효과 없음
* send는 막아도 문제가 여전히 발생하는것으로 보면 receive문제일듯 한데

```c#
try
{
    m_client.Shutdown(SocketShutdown.Both);
}
finally
{
    m_client.Close();
}
```
* try finally 구문이 있네
* 적용 안되어서 종료전에 빈패킷 한번 날리고 종료. 여전히 종료직후 빈패킷을 추가전송하는 절차는 남아 있음