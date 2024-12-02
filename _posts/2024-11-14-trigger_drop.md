---
layout: post
title: trigger parent null 특정위치에서 부모연결하기, 끊기
category: unity3d
tags: 
---

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730306924.jpg" />
* Hierarchy창 빈공간 마우스 우클릭
* 3D Object > Cube 선택하여 큐브 생성
* inspector창에서 MashRenderer 체크 해제

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1731475451.jpg" />
* 큐브를 Player와 부딧칠 수 있도록 경로상에 배치

# 스크립트 생성
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730329628.jpg" />

* Project창 마우스 우클릭 Create > c# script
* 이름을 ```TriggerDrop```로 지정
* 다음의 내용을 작성

```csharp
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class TriggerDrop : MonoBehaviour
{
    public GameObject target_player;
    public void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player")) // trigger 안에 들어온 object가 player인지 확인
        {
            target_player.transform.parent = null; // trigger 안에 들어온 object가 player라면 player의 부모를 없앰
            target_player.transform.rotation = Quaternion.Euler(0, 0, 0); // player의 회전값을 초기화
        }
    }
}
```

* 작성된 스크립트를 cube에 드래그 드랍하여 전달

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1731509382.jpg" />

* Follower안에 있는 drop될 대상 (예시의 경우는 OVR Camera Rig)을 그래그 하여 target_player에 연결

---

# 부모 연결하기
```csharp
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class TriggerDrop2 : MonoBehaviour
{
public GameObject target_player;
public GameObject target_parent;
public void OnTriggerEnter(Collider other){
        if (other.CompareTag("Player")) // trigger 안에 들어온 object가 player인지 확인
        {
            target_player.transform.parent = target_parent.transform; // trigger 안에 들어온 object가 player라면 target_parent를 부모로 등록
            target_player.transform.rotation = Quaternion.Euler(0, 0, 0); // player의 회전값을 초기화
            target_player.transform.location = Vector3(0,0,0); //player의 위치값을 초기화
        }
    }
}
```