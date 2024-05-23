---
layout: post
title: Unity third person 삼인칭 캐릭터
category: unity3d
tags:
---

# Unity third person
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716437845.jpg" />

* <https://assetstore.unity.com/packages/essentials/starter-assets-thirdperson-updates-in-new-charactercontroller-pa-196526>

---

## Material Shader 변경
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716438661.jpg" />

* Project창 > StartAssets > ThirdPersonController > Character > Material 폴더안 모든 Material 전체선택
* Inspector창 > Shader > Standard로 변경

---

## 삼인칭 캐릭터 올리기
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716440115.jpg" />

* Project창 > StartAssets > ThirdPersonController > Prefabs > NestedParentArmature_Unpack 드래그 하여 Scene창에 드랍
* MainCamera 삭제
* UI_Canvas_StarterAssetsInputs_Joysticks 삭제
* UI_EventSystem 삭제

---

## 캐릭터 바꾸기

# Jammo Character | Mix and Jam
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716161741.jpg" />

* <https://assetstore.unity.com/packages/3d/characters/jammo-character-mix-and-jam-158456>

---

## rigging setting
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716161863.jpg" />

* Jammo-character / models / Jammo_LowPoly 선택
* Inspector > Rig > Animation Type : Humanoid 선택
* Avatar Defination : Create From This Model 선택
* Apply 적용

---

## third person controller에 캐릭터 적용
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716442035.jpg" />

* Jammo-character / models / Jammo_LowPoly 드래그하여 NestedParentArmature_Unpack > PlayerAmature에 드랍
* Geomatry 삭제
* Skeleton 삭제

## Avatar 적용
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716442309.jpg" />

* Hierarchy창에서 PlayerAmature 선택
* Inspector창에서 Animator > Avatar 확인
* Jammo-character / models / Jammo_LowPoly 우측 화살표를 클릭하여 패키지 펼치기
* 패키지 내부에 있는 jammo-LowPoly 아바타를 드래그하여 inspector창 > Animator > Avatar에 집어 넣기

---

## Ready Player Me
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716442955.jpg" />

* <https://readyplayer.me/hub>
* My Avatars > +버튼 > 카메라 버튼 > 사진등록 또는 노트북의 웹캠을 이용하여 사진 캡쳐
* 자동으로 아바타가 생성되고 고유번호가 나옴


---

## Ready Player Me Asset
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716442715.jpg" />

* <https://assetstore.unity.com/packages/tools/game-toolkits/ready-player-me-avatar-and-character-creator-259814>
* 에셋을 구입하고 Unity에서 열기하여 download, import 과정 진행

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443233.jpg" />

* 최초등장하는 팝업은 x를 눌러서 닫기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443315.jpg" />
* <https://readyplayer.me/hub> 우측하단 공유버튼 클릭
* 팝업에서 Copy avatar link 클릭하여 아바타 링크주소 복사

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443403.jpg" />
* Main Manu > Tools > Ready Player Me > Avatar Loader 선택
* 팝업창의 Avatar URL에 붙여넣기 (Ctrl+V, Command+V)하여 아바타 링크주소 입력
* Load Avatar into Current Scene 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443565.jpg" />
* 생성된 아바타를 드래그하여 NestedParentArmature_Unpack > PlayerAmature에 드랍

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443661.jpg" />
* Hierarchy창에서 아바타를 선택하고 inspector창 Animator > Avatar 클릭하면 Avatar가 어디있는지 쉽게 찾을 수 있음

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443764.jpg" />
* 패키지 내부에 있는 아바타를 드래그하여 inspector창 > Animator > Avatar에 집어 넣기
* 기존에 있던 Jammo_LowPoly는 삭제

---

## 만들어진 삼인칭 캐릭터 프리팹(prefab)화 하기
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443979.jpg" />

* Hierarchy창 NestedParentArmature_Unpack 마우스 우클릭
* prefab > Unpack Completely


<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716444119.jpg" />

* NestedParentArmature_Unpack이름을 MyAvatar로 바꾸기
* Project창 폴더위치를 Assets로 변경
* Hierarchy창에서 Project창으로 MyAvatar를 드래그 드롭
* 이렇게 Prefab등록된 삼인칭 캐릭터는 다시 Scene으로 드래그 하는 방식으로 사용가능

---

## 카메라 스위칭하기
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraSwitch : MonoBehaviour
{
    public Camera camera1;
    public Camera camera2;

    private void Update()
    {
        if (Input.GetKeyDown(KeyCode.Z))
        {
            camera1.enabled = true; //카메라1 활성화
            camera2.enabled = false; //카메라2 비활성화
        }
        if (Input.GetKeyDown(KeyCode.X))
        {
            camera1.enabled = false; //카메라1 비활성화
            camera2.enabled = true; //카메라2 활성화
        }
    }
}
```