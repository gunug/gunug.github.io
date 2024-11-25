---
layout: post
title: project air mouse vr 에어마우스 입력장치
category: project
tags: 
---

# project air mouse vr 에어마우스 입력장치
## 프로젝트 개요
* URP, 2022.3.27f1

## 절차
* <https://www.youtube.com/watch?v=67_lLs2ONpI>

## 기능
* 레이케스트, 스냅턴, 텔레포트
* 용액 붓기, 용액 색변화
* 물건집기 (눈금 실린더, 삼각플라스크, 스포이드, 마그네틱바)
* 물건 내려놓기 (특정 위치에 스냅하여 붙여넣기)
* 스탭별 실험 설명 UI(그래픽 작업)
* 실험 절차 구성

---

# assets
* <https://assetstore.unity.com/packages/3d/props/tools/chemistry-laboratory-equipment-163610>
* <https://assetstore.unity.com/packages/3d/laboratory-equipment-93314>

---

# 진행상황
## 2024-11-06
* 프로젝트 생성, 기본 세팅
  
## 2024-11-19
## 마우스 숨기기, 센터 고정

```csharp
Cursor.visible = false;
Cursor.lockState = CursorLockMode.Locked;
```

## 마우스 좌표 반영, 하단 클릭시 좌표 리셋
```csharp
    void Update()
    {
        float mouseX = Input.GetAxis("Mouse X") * mouseSensitivity * Time.deltaTime;
        float mouseY = Input.GetAxis("Mouse Y") * mouseSensitivity * Time.deltaTime;

        xRotation -= mouseY;
        yRotation += mouseX;

        transform.localRotation = Quaternion.Euler(xRotation, yRotation, 0f);
        this.transform.Rotate(Vector3.up * mouseX);
        this.transform.Rotate(Vector3.right * mouseY);

        //key down arrow for reseting the rotation
        if (Input.GetKeyDown(KeyCode.DownArrow))
        {
            xRotation = 0;
            yRotation = 0;
        }
    }
```

---

## 2024-11-23

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Pointer : MonoBehaviour
{
    public float mouseSensitivity = 100f;
    private float xRotation = 0f;
    private float yRotation = 0f;
    void Start()
    {
        //Set Cursor to not be visible
        Cursor.visible = false;
        Cursor.lockState = CursorLockMode.Locked;
    }
    void Update()
    {
        float mouseX = Input.GetAxis("Mouse X") * mouseSensitivity * Time.deltaTime;
        float mouseY = Input.GetAxis("Mouse Y") * mouseSensitivity * Time.deltaTime;

        xRotation -= mouseY;
        yRotation += mouseX;

        transform.localRotation = Quaternion.Euler(xRotation, yRotation, 0f);
        this.transform.Rotate(Vector3.up * mouseX);
        this.transform.Rotate(Vector3.right * mouseY);

        //key down arrow for reseting the rotation
        if (Input.GetKeyDown(KeyCode.DownArrow))
        {
            xRotation = 0;
            yRotation = 0;
        }
    }
}
```

---

# Assets 구입내역
* [Modern Physics Lab](https://assetstore.unity.com/packages/3d/environments/sci-fi/modern-physics-lab-275536) : 24.99$
* [Chemistry Laboratory Equipment](https://assetstore.unity.com/packages/3d/props/tools/chemistry-laboratory-equipment-163610) : 9$