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
* 프로젝트 생성, 기본 세팅
  
## 마우스 숨기기, 센터 고정

```csharp
Cursor.visible = false;
Cursor.lockState = CursorLockMode.Locked;
```

## 마우스 좌표 반영, 아래버튼 좌표 리셋
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

# 실험 절차 - 기물
* 목표 : 묽은 염산과 수산화 나트륨 수용액을 이용하여 중화반응의 원리를 설명할 수 있다.
* 준비물 : 0.1M 묽은 염산, 0.1M 수산화 나트륨 수용액, 삼각 플라스크 3개, 눈금 실린더 2개, 비커 2개, 교반기, 마그네틱바, 마그네틱 리트리버, 페놀프탈레인 용액, 장갑, 보안경
* 0.1L 수산화 나트륨 + 1L 증류수 = 0.1M 수산화 나트륨 수용액
  
1. 장갑, 보안경, 실험복 착용 필수
2. 염산 + 증류수 = 0.1M HCL
3. 수산화 나트륨 + 증류수 = 0.1M NaOH
4. 수산화 나트륨 수용액이 반응해야 하기때문에 몰 농도는 중요합니다.
5. 눈금 실린더를 이용해 0.1M 묽은 염산을 삼각 플라스크 3개에 각각5ml, 10ml, 15ml씩 넣는다 (비커>눈금실린더>삼각플라스크)
6. 0.1M 묽은 염산 5ml가 담긴 삼각 플라스크를 교반기 위에 올려놓고, 마그네틱 바를 넣은 후, 교반기를 작동시키고, 페놀프탈레인 용액 몇 방울을 넣는다 (삼각플라스크>교반기>마그네틱바>교반기작동>스포이드)
7. 새로운 눈금 실린더를 이용해 0.1M 수산화 나트륨 수용액 15ml를 0.1M 묽은 염산 5ml가 담긴 삼각 플라스크에 넣는다
8. 10ml, 15ml 반복

* 수산화 나트륨이 많으면 액성이 염기성을 띄고 페놀프탈레인 용액이 붉은색이 됨
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1732588795.jpg" />

---

# dialogue
* 묽은 염산과 수산화 나트룸 수용액을 이용하여 중화 반응의 원리를 알아보는 실험입니다.
* 이번 실험에서는 강산과 강염기를 사용하니 장갑과 보안경 실험복을 반드시 착용해야 합니다.
* 

* 실험에 사용되는 산과 염기 수용액은 염산과 수산화 나트륨인데요 각 수용액의 농도는 0.1M로 맞췄습니다.
* 0.1M농도는 0.1M의 염산과 0.1M의 수산화 나트륨이 용액 1L에 각각 용해되어 있는 것을 의미하는데요
* 수용액이 반응할때 같은양만큼의 수소이온과 수산화 이온이 반응해야 하기 때문에 몰 농도는 매우 중요합니다.

* 그럼 지금부터 실험을 해보겠습니다. 먼저, 눈금 실린더를 이용해 삼각플라스크 세개에 묽은염산을 각각 5ml, 10ml, 15ml 씩 넣습니다.
* 그리고 나서 묽은염산 5ml가 담긴 삼각플라스크를 교반기 위에 올려놓습니다.
* 그리고 마그네틱 바를 넣은 후, 교반기를 작동시킵니다. 그다음 페놀프탈레인 용액 몇 방울을 넣습니다.
* 그리고 새로운 눈금 실린더를 이용해, 수산화 나트륨 수용액 15ml를 묽은 염삼 5ml가 담긴 삼각 플라스크에 넣습니다.
* 어떤 변화가 일어날까요?

* 용액의 색이 붉게 변하죠?
* 0.1M 농도의 묽은염산 5ml와 0.1M 농도의 수산화나트륨 수용액 15ml가 반응하면 수산화 이온이 과량으로 존재하게 됩니다.
* 따라서 혼합용액의 액성이 염기성이 되죠 그래서 용액의 색깔이 붉게 변하는 것입니다.

* 자, 이번에는 묽은염산 10ml가 남긴 삼각 플라스크를 교반기 위에 놓고 마그네틱바를 넣습니다.
* 그다음 페놀프탈레인 용액 몇방울을 넣고 교반기를 작동시킵니다.
* 그리고는 눈금 실린더를 이용하여 수산화나트륨수용액 10ml를 묽은염산 10ml가 담긴 삼각 플라스크에 넣습니다.

* 용액이 무색으로 변하죠?
* 몰 농도 0.1의 묽은염산 10ml와 0.1M농도의 수산화나트륨 수용액 10ml가 반응하면
* 수소이온과 수산화이온이 1:1로 반응하므로 혼합용액의 액성은 중성이 됩니다.
* 그래서 용액의 색깔이 무색으로 변하는 것이죠.

* 마지막으로 묽은염산 15ml가 담긴 삼각 플라스크를 교반기위에 놓고 마그네틱바를 넣고 교반기를 작동시킵니다.
* 그다음 페놀프탈레인 용액 몇방울을 넣습니다.
* 눈금 실린더를 이용해서 수산화나트륨 수용액 5ml를 묽은 염산 15ml가 담긴 삼각 플라스크에 넣습니다.
* 그러자 용액이 무색으로 변합니다.

* 0.1M 농도의 묽은염산 15ml와 0.1M 농도의 수산화나트륨 수용액 5ml가 반응하면
* 수소이온이 과량으로 존재하게 되죠. 그래서 혼합용액의 액성은 산성이 되고 용액의 색깔이 무색으로 변하는 것을 관찰 할 수 있습니다.

* 오늘 실험을 통해 중화반응은 산의 수소이온의 몰수와 염기의 수산화이온의 몰수가 항상 1:1 반응해야 한다는 것을 알 수 있습니다.
* 때문에 과량으로 존재하는 이온이 있다면, 그 액상은 그 이온에 따라 달라지는 것이죠.

---

# Assets 구입내역
* [Modern Physics Lab](https://assetstore.unity.com/packages/3d/environments/sci-fi/modern-physics-lab-275536) : 24.99$ : 실험실 배경
* [Chemistry Laboratory Equipment](https://assetstore.unity.com/packages/3d/props/tools/chemistry-laboratory-equipment-163610) : 9$ : 실험도구, 기물
* [Dialogue System for Unity](https://assetstore.unity.com/packages/tools/behavior-ai/dialogue-system-for-unity-11672) : 42.5$(50% 할인) : 전체 실험 프로세스를 제어하기 위한 도구
* [Quick Outline](https://assetstore.unity.com/packages/tools/particles-effects/quick-outline-115488) : free : 사물의 외곽선 표시
* [Object Labels / Notes](https://assetstore.unity.com/packages/tools/utilities/object-labels-notes-55959) : free : 사물의 이름표시 - 사용하지 않음
* [Dynamic Label](https://assetstore.unity.com/packages/tools/gui/dynamic-label-295717): 4.99$ : 사물의 이름표시

---

# 문의내역
## android용 google cardboard xr Plugin이 ios에서 동작하지 않음
* 참고링크 : <https://developers.google.com/cardboard/develop/ios/quickstart?hl=ko>
* Android OS와 ios용 SDK가 다릅니다. 위 링크에서 다운로드 주소 및 사용법을 확인 하실 수 있습니다.
* android : <https://github.com/googlevr/cardboard-xr-plugin.git>
* ios: <https://github.com/googlevr/cardboard.git>