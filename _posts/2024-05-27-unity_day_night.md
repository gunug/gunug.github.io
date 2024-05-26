---
layout: post
title: Unity Day Night 낮과밤
category: unity3d
tags:
---

# Unity Day Night 낮과밤

## Free HDR Sky
* 이미 실습한적이 있는 경우는 별도로 asset다운로드 및 import 과정이 필요하지 않습니다.
* 스카이박스 에셋 : [https://assetstore.unity.com/packages/2d/textures-materials/sky/free-hdr-sky-61217](https://assetstore.unity.com/packages/2d/textures-materials/sky/free-hdr-sky-61217){:target="_blank"}
* Package Manager 창에서 download 클릭
* 다운로드가 완료되면 import버튼 클릭
* import Unity Package 창에서 import 버튼 클릭

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1714290644.jpg" />

* Project창 Skybox / Materials / Skybox_Sunset
* Scene창에 드래그 드랍

---

## 스카이박스 교체하기
* SkyboxChanger.cs
  
```c#
 using System.Collections;
 using System.Collections.Generic;
 using UnityEngine;
 
 public class SkyboxChanger : MonoBehaviour
 {
     public Material sky_day;
     public Material sky_night;
     private void Update(){
        if(Input.GetKeyDown(KeyCode.O)){
            RenderSettings.skybox = sky_day;
            //스카이박스를 낮으로 교체
        }
        if(Input.GetKeyDown(KeyCode.P)){
            RenderSettings.skybox = sky_night;
            //스카이박스를 밤으로 교체
        }
     }
 }
```

## 빛 각도 조절하기
* LightAngle.cs
  
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class LightAngle : MonoBehaviour{
    private Vector3 day_angle = new Vector3(50,-30,0);
    private Vector3 night_angle = new Vector3(-5,-30,0);
    public GameObject dir_light;
    private void Update(){
        if(Input.GetKeyDown(KeyCode.O)){
            ///dir_light.transform.eulerAngles = day_angle;
            //방향조명.변형.오일러각도 = 낮 각도
            iTween.RotateTo(dir_light, iTween.Hash("rotation", 
            day_angle, "easetype", iTween.EaseType.easeOutCubic, "time", 1.0f));
        }
        if(Input.GetKeyDown(KeyCode.P)){
            //dir_light.transform.eulerAngles = night_angle;
            //방향조명.변형.오일러각도 = 밤 각도
            iTween.RotateTo(dir_light, iTween.Hash("rotation", 
            night_angle, "easetype", iTween.EaseType.easeOutCubic, "time", 1.0f));
        }
    }
}
```

---

## 빈 게임오브젝트 만들기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716765787.jpg" />

* Hirerchy창 마우스 우클릭 Create Empty 하여 새 GameObject 만들기
* 이름을 'DayNight'로 변경

---

## 스크립트 연결 및 참조 연결

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716766838.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716767115.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716766974.jpg" />