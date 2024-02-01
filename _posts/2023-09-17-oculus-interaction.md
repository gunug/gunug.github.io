---
layout: post
title: oculus interaction 오큘러스 인터렉션
category: vr
tags: c# unity3d oculus
---

# oculus interaction 오큘러스 인터렉션
```c#
using Oculus.Interaction.Locomotion;
public LocomotionGate locoGate;
locoGate.ActiveMode == LocomotionGate.LocomotionMode.TeleportDown;
locoGate.ActiveMode == LocomotionGate.LocomotionMode.TeleportUp;
```

---

```c#
using Oculus.Interaction.Locomotion;

public PlayerLocomotor locmotor;
// locomotor로 제어하려면 LocomotionEvent를 핸들러로 부터 넘겨 받아야 하는데. 직접 내용을 채워 넣을 수 없어서 방식만 차용하기로 함
```

```c#
   [SerializeField]
    private Transform _playerOrigin;
    [SerializeField]
    private Transform _playerHead;

    private void MoveLocationLocomotorStyle(LocationName index) //locomotor에서 확인한 이동로직 (로테이션 문제가 없음)
    { //locomotor를 차용하여 이동방식을 일치시킵니다.
        Vector3 targetPosition = new Vector3();
        Quaternion targetRotation = new Quaternion();
        targetPosition = locations[(int)index % locations.Length].position;
        targetRotation = locations[(int)index % locations.Length].rotation;

        Vector3 positionOffset = _playerOrigin.position - _playerHead.position;
        positionOffset.y = 0f;
        _playerOrigin.position = targetPosition + positionOffset;
        Vector3 headForward = Vector3.ProjectOnPlane(_playerHead.forward, _playerOrigin.up).normalized;
        Quaternion headFlatRotation = Quaternion.LookRotation(headForward, _playerOrigin.up);
        Quaternion rotationOffset = Quaternion.Inverse(_playerOrigin.rotation) * headFlatRotation;
        _playerOrigin.rotation = Quaternion.Inverse(rotationOffset) * targetRotation;
    }

    private void MoveLocationLegacy(LocationName index)  //기존 이동로직 (로테이션에 문제를 일으킴)
    {
        VR_root.transform.position = locations[(int)index % locations.Length].position;
        VR_root.transform.eulerAngles = locations[(int)index % locations.Length].eulerAngles;
    }

```