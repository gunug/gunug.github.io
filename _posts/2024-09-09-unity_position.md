---
layout: post
title: Unity3d 좌표계산
category: unity3d
tags:
---

```c#
using UnityEngine;

public class CalculateDestination : MonoBehaviour
{
    public Transform startPoint;
    public float distance;

    void Start()
    {
        Vector3 destinationPosition = CalculateDestinationPosition(startPoint.position, startPoint.eulerAngles, distance);
        Debug.Log("Destination Position: " + destinationPosition);
    }

    Vector3 CalculateDestinationPosition(Vector3 startPosition, Vector3 rotationEulerAngles, float distance)
    {
        Quaternion rotation = Quaternion.Euler(rotationEulerAngles);
        Vector3 direction = rotation * Vector3.forward;
        Vector3 destinationPosition = startPosition + direction * distance;
        return destinationPosition;
    }
}
```