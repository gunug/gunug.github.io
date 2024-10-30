---
layout: post
title: follower trigger 기능 만들기
category: vr
tags: 
---

# 출발하기, 멈추기, 속도 조절

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730329628.jpg" />

* Project창 마우스 우클릭 Create > c# script
* 이름을 ```SpeedChager```로 지정
* 다음의 내용을 작성

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class SpeedChanger : MonoBehaviour
{
    public void ChangeSpeed(float speed)
    {
        PathCreation.Examples.PathFollower pathFollower = GetComponent<PathCreation.Examples.PathFollower>();
        //path creator 컴퍼넌트 찾기

        pathFollower.speed = speed;
        //속도 변경
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKeyDown(KeyCode.Alpha0)) ChangeSpeed(0); // 0을 누르면 속도 0으로 변경
        if(Input.GetKeyDown(KeyCode.Alpha1)) ChangeSpeed(1); // 1을 누르면 속도 1으로 변경
        if(Input.GetKeyDown(KeyCode.Alpha2)) ChangeSpeed(2); // 2을 누르면 속도 2으로 변경
        if(Input.GetKeyDown(KeyCode.Alpha3)) ChangeSpeed(3); // 3을 누르면 속도 3으로 변경
        if(Input.GetKeyDown(KeyCode.Alpha4)) ChangeSpeed(4); // 4을 누르면 속도 4으로 변경
        if(Input.GetKeyDown(KeyCode.Alpha5)) ChangeSpeed(5); // 5을 누르면 속도 5으로 변경
        //언제? 키보드의 0키를 눌렀을때, 무엇을? 속도를 0으로
        //속도를 0으로 == 기차를 멈춤
    }
}
```

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730306731.jpg" />
* Follower에 드래그 드랍하여 script를 전달
* 게임을 실행하고 Game창을 마우스로 한번 클릭한 후, 키보드 0,1,2,3,4,5를 누르면 속도를 변경할 수 있습니다.



# follower trigger
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730306924.jpg" />
* Hierarchy창 빈공간 마우스 우클릭
* 3D Object > Cube 선택하여 큐브 생성
* inspector창에서 MashRenderer 체크 해제

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307081.jpg" />
* 생성된 Cube 선택
* inspector 창 하단 AddComponent
* collider 검색창에 입력
* BoxCollider 선택하여 컴퍼넌트 추가
* isTrigger 체크

# 스크립트 생성

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730329628.jpg" />

* Project창 마우스 우클릭 Create > c# script
* 이름을 ```TriggerSetSpeed```로 지정
* 다음의 내용을 작성

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TriggerSetSpeed : MonoBehaviour
{
    public PathCreation.Examples.PathFollower pathFollower;
    public float speed = 0;

    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            pathFollower.speed = speed;
        }
    }
}
```

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307459.jpg" />
* cube 선택 후 script를 드래그 하여 inspector창에 전달

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307537.jpg" />
* Follow를 드래그 하여 pathFollwer에 드랍하여 연결

---

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307642.jpg" />
* Follower 선택 후, inspector 창에서 addComponent클릭
* 검색창에 Collider 입력 BoxCollider 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307722.jpg" />
* addCompoment 클릭
* 검색창에 rigid 입력 RigidBody 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307853.jpg" />
* Follower선택
* tag 선택 Player로 설정