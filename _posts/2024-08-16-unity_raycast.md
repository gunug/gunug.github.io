---
layout: post
title: Unity3d Raycast 레이캐스트
category: unity3d
tags:
---

# Unity3d Raycast 레이캐스트
* 참고링크 : https://ssabi.tistory.com/29
* 시작점(Origin)과 방향(Direction)으로 최대거리(maxDistance)만큼 레이를 쏘는 함수
* Physics.Raycast(transform.position, transform.forward, out hit, maxDistance)

```c#
private RaycastHit hit;
void Update () 
{
    if (Physics.Raycast(transform.position, transform.forward, out hit))
    {
        Debug.Log("hit point : " + hit.point + ", distance : " + hit.distance + ", name : " + hit.collider.name);
        Debug.DrawRay(transform.position, transform.forward * hit.distance, Color.red);
    }
    else
    {
        Debug.DrawRay(transform.position, transform.forward * 1000f, Color.red);
    }
}
```

---

# LineRenderer 라인렌더러

```c++
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RayController : MonoBehaviour
{
    public LineRenderer lineRenderer;
    // Start is called before the first frame update
    void Start()
    {
        lineRenderer = gameObject.AddComponent<LineRenderer>();
        lineRenderer.startWidth = 0.1f;
        lineRenderer.endWidth = 0.1f;
        lineRenderer.positionCount = 2;
        lineRenderer.startColor = Color.red;
        lineRenderer.endColor = Color.red;
        lineRenderer.SetPosition(0, transform.position);
        lineRenderer.SetPosition(1, transform.position + transform.forward * 10);
    }
}
```

---


```c#
using UnityEngine;

public class RaycastExample : MonoBehaviour
{
    void Update()
    {
        // 마우스 클릭을 체크합니다.
        if (Input.GetMouseButtonDown(0))
        {
            // 카메라에서 클릭 위치로 Ray를 쏩니다.
            Ray ray = Camera.main.ScreenPointToRay(Input.mousePosition);
            RaycastHit hit;

            // 레이캐스트를 실행하여 Collider와 충돌했는지 확인합니다.
            if (Physics.Raycast(ray, out hit))
            {
                // 히트한 위치를 얻습니다.
                Vector3 hitPoint = hit.point;
                Debug.Log("Ray hit point: " + hitPoint);
                
                // 필요한 다른 로직을 이곳에 추가하세요.
            }
        }
    }
}
```