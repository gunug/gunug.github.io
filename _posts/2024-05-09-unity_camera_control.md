---
layout: post
title: Unity Camera Control 카메라 제어
category: unity3d
tags:
---

# Unity Camera Control 카메라 제어

---

# 카메라 생성
* Hierarchy창 마우스 우클릭
* Camera 선택하여 새 카메라 생성 (5번 반복하여 5개의 카메라 생성)
* Scene창에서 원하는 위치로 이동
* MainMenu > GameObject > align with view : 현재 보고 있는 위치로 카메라를 이동
* MainMenu > GameObject > align view to selected : 현재 선택되어 있는 위치로 눈(view)을 이동
* 카메라 5대를 각각의 위치에 배치 합니다

---

# 카메라 끄기
* 카메라는 위치(position)값을 사용하기 위해 만들었습니다.
* 이후는 Main Camera가 각 카메라 위치를 이동하면서 촬영하게 됩니다.
* Hierarchy창에서 카메라 선택
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715221541.jpg" />

* Camera 컴퍼넌트 왼쪽 체크를 해제하여 비활성화(disable)
* 5개 카메라 모두 비활성화 합니다. Main Camera는 비활성화 하지 않습니다.

---

## iTween 들여오기
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715221815.jpg" />

* [에셋 스토어 링크](https://assetstore.unity.com/packages/tools/animation/itween-84)
* [사용 설명서 링크](https://www.pixelplacement.com/itween/documentation.php)
* <https://assetstore.unity.com> 에서 iTween을 검색하여 무료버전 다운 가능

---

# C# script 생성
* MainCamera.cs
  
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MainCamera : MonoBehaviour
{
	public Camera[] subCameras; 
	//public Camera subCameras;
	public void MoveCamera(int index){
        //메인 카메라의 위치를 서브 카메라의 위치로 이동 시킨다.
        //1. 메인 카메라 위치 this.gameObject.transform.postion
        //2. 서브 카메라 위치 subCameras[숫자].gameObject.transform.position
        //메인 카메라 위치 = 서브 카메라 위치;
        //this.gameObject.transform.position = subCameras[index].gameObject.transform.position;
        //this.gameObject.transform.eulerAngles = subCameras[index].gameObject.transform.eulerAngles;
        //rotation. 오일러각, 쿼터니언
        iTween.MoveTo(this.gameObject, iTween.Hash("position", 
            subCameras[index].gameObject.transform.position, "easetype", 
            iTween.EaseType.easeOutBack, "time", 5.0f));

        iTween.RotateTo(this.gameObject, iTween.Hash("rotation", 
            subCameras[index].gameObject.transform.eulerAngles, "easetype", 
            iTween.EaseType.easeOutBack, "time", 5.0f));
	}
}
```

---

# 스크립트를 카메라에 등록
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715221976.jpg" />

* Project창에서 스크립트를 드래그 하여 Main Camera에 드롭

---

# 스크립트에 카메라를 등록
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715222024.jpg" />

* Inspector창에 MainCamera 컴퍼넌트 Sub Camera 숫자를 5로 변경
* 5개의 빈칸이 나오면 각각의 빈칸에 Camera를 드래그 드랍하여 연결

---

# c# script 생성
* CameraButton.cs
  
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraButton : MonoBehaviour
{
	public MainCamera target_camera;
	public int target_index = 0;
	void OnMouseDown(){
		Debug.Log("버튼 눌림");
		//MoveCamera(0); 호출
		target_camera.MoveCamera(target_index);
	}
}
```

---

# 큐브 버튼 생성후 배치
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715222156.jpg" />

* MainCamera 선택
* MainCamera 위에서 마우스 우클릭 3D Object > Cube를 선택하여 Cube생성

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715222210.jpg" />

* MainCamera의 촬영 방향에 맞추어 카메라의 촬영범위에 들어갈 수 있도록 큐브를 이동

---

# 큐브에 스크립트 등록
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715222281.jpg" />

* 만들어진 CameraButton.cs를 큐브에 드래그 드랍으로 등록

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715222351.jpg" />

* Cube선택후 inspector창의 target camera에 MainCamera를 드래그 드랍

---

# 큐브 복제, target index 값 입력
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715222389.jpg" />

* 복사(ctrl+c) 붙여넣기(ctrl+v)로 큐브를 복제
* target index가 각각 0,1,2,3,4가 될 수 있도록 입력