---
layout: post
title: unity sound trigger 특정 위치에서 소리 출력하기
category: unity3d
tags: 
---

# unity sound trigger 특정 위치에서 소리 출력하기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730306924.jpg" />
* Hierarchy창 빈공간 마우스 우클릭
* 3D Object > Cube 선택하여 큐브 생성
* inspector창에서 MashRenderer 체크 해제

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1731475451.jpg" />
* 큐브를 Player와 부딧칠 수 있도록 경로상에 배치

# 스크립트 생성

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730329628.jpg" />

* Project창 마우스 우클릭 Create > c# script
* 이름을 ```SoundTrigger```로 지정
* 다음의 내용을 작성

```csharp
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class SoundTrigger : MonoBehaviour
{
    private AudioSource audioSource;
    public void Start()
    {
        audioSource = GetComponent<AudioSource>(); // audioSource를 가져옴
    }
    public void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player")) // trigger 안에 들어온 object가 player인지 확인
        {
            audioSource.Play(); // trigger 안에 들어온 object가 player라면 audioSource를 재생
        }
    }
}
```
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1731475057.jpg" />
* 작성된 스크립트를 cube에 드래그 드랍하여 전달

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1731475132.jpg" />
* cube에 mp3파일을 드래그 드랍
* AudioSource componant가 자동으로 생성됨

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1731475234.jpg" />
* AudioSource componant의 Play On Awake(깨어나면 재생) 항목을 체크 해제

---

# Follower를 Player로 설정, 충돌할 수 있도록 컴퍼넌트 추가

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307642.jpg" />
* Follower 선택 후, inspector 창에서 addComponent클릭
* 검색창에 Collider 입력 BoxCollider 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307722.jpg" />
* addCompoment 클릭
* 검색창에 rigid 입력 RigidBody 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730307853.jpg" />
* Follower선택
* tag 선택 Player로 설정