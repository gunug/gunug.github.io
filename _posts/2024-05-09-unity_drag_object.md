---
layout: post
title: Unity Drag Object 드래그
category: unity3d
tags:
---

## Cube 만들기
* Hierarchy창 빈공간 마우스 우클릭
* 3D Object > Cube 선택하여 큐브 만들기
* 큐브 선택후 Inspector창에서 Add Component
* <del>Physics > RigidBody 선택하여 강체(rigidBody)컴퍼넌트 추가</del> rigidBody를 사용하지 않습니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715238321.jpg" />

* World : 가상 3D공간 안에서의 3차원 좌표 (x,y,z)
* Screen : 모니터에 투영되는 2차원 좌표(x,y)
* 서로 다르기 때문에 좌표변환이 필요함
* WorldToScreenPoint : 3차원 좌표를 2차원 좌표로
* ScreenToWorldPoint : 2차원 좌표를 3차원 좌표로

## C# script
* DragObject.cs

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DragObject : MonoBehaviour
{
    private Vector3 mouse_offset; //마우스가 어긋난 양
    private float screen_z; //스크린의 깊이(z)값
    //private Rigidbody myRigid; //물체의 강체

    /*
    void Start()
    {
        myRigid = GetComponent<Rigidbody>(); //강체의 참조를 가져오기
    }
    */
    void OnMouseDown()
    {
        screen_z = Camera.main.WorldToScreenPoint(this.gameObject.transform.position).z;
        //메인 카메라로부터 이(this)게임오브젝트를 봤을때의 z값
        mouse_offset = gameObject.transform.position - GetMouseWorldPos();
        //offset 변위차
    }
    private Vector3 GetMouseWorldPos()
    {
        Vector3 mousePoint = Input.mousePosition; //입력장치로 부터 마우스 위치를 받기
        mousePoint.z = screen_z;

        return Camera.main.ScreenToWorldPoint(mousePoint);
    }

    void OnMouseDrag()
    {
        transform.position = GetMouseWorldPos() + mouse_offset;
        //myRigid.velocity = Vector3.zero; //물리력 0으로
    }
}
```


# 스크립트 등록

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715238374.jpg" />

* DragObject.cs 드래그 하여 큐브에 등록
* 태그를 MainCamera로 변경 해주어야 함. 아니면 null에러
* RigidBody를 추가하면 물리적인 움직임도 가능함
* Collider에 Physics Material을 추가하여 마찰이나 탄성을 변경 가능

---

# Collider
* 참고: <https://docs.unity3d.com/kr/2018.4/Manual/class-MeshCollider.html>
* Convex : Convex 메시 콜라이더는 삼각형 255개로 제한됩니다.
* inflate Mesh : 부풀게 하다 (2018.3 부터는 더이상 사용되지 않습니다)
* skin width : 부푸는 정도
* cooking options가 2017.3 버젼부터 추가되었습니다.
  * None : 모두 비활성화
  * Everything : 모두 활성화
  * Cook for Faster Simulation : 빠른 시뮬레이팅을 위해 엔진이 메시를 쿠킹하도록 함 (런타임 성능에 최적화) 이 설정이 비활성화 되면 물리 엔진이 빠른 쿠킹타임을 사용하여 가능한 빠르게 결과물을 생성
  * Enable Mesh Cleaning : 물리엔진이 메시를 청소하도록 함. 활성화 되어 있으면 손상된 삼각형과 다른 지오메트리 결함을 제거 하려고 시도함. 효과적인 메시를 만들고 더 정확한 히트 포인트를 생성하기 위한 옵션
  * Weld Colocated Vertices : 같은 버텍스 삭제. 동일한 표지션의 버텍스가 결함됨

---

# rigidbody
* Mass : 질량
* Drag : 영항력 (물체가 물리력을 얼마나 빨리 잃어버리는지에 대한 값)
* Angular Drag : 각속도 영향력 (각속도를 얼마나 빨리 잃어버리는지에 대한 값)
* Use Gravity : 중력에 영향을 받는지 (중력 셋팅을 Project Settings > Physics 에서 할수 있음: 기본값=-9.81)
* is Kinematic : 물리력에 반응하는지에 대한 여부 (이를 선택하면 남에게 물리력을 미치지만 자신은 물리력에 반응하지 않음)
* interpolate : 떨림현상 해결용 물리적 영향력을 전달 한 이후 부드러운 움직임이 되도록 보간을 할지에 대한 여부
  * none : 없음 (보간하지 않음)
  * interpolate : 보간법 - 이전프래임 기반 값을 부드럽게
  * extrapolate : 보외법 - 이후프래임 기반 값을 부드럽게
* collision detection
  * Discrete : 별 문제가 없다면 Discrete 사용을 권장.
  * Continuous : 빠른 물체를 위한 옵션, 정적 지오메트리와 상호작용을 함
  * Continuous Dynamic : 빠른 물체를 위한 옵션, 동적 지오메트리와 상호작용을 함
* Constraints : 제약
  * Freeze Position : 특정방향 움직임 막기
  * Freeze Rotation : 특정방향 회전 막기
