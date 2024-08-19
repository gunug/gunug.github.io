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