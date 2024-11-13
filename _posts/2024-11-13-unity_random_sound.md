---
layout: post
title: unity random sound 무작위 소리출력
category: unity3d
tags: 
---

# unity random sound 무작위 소리출력
* 아래의 두 스크립트중 하나를 선택하여 c# script파일을 생성한 다음 AudioSource 컴퍼넌트가 있는 대상에게 드래그 드랍

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomSound : MonoBehaviour
{
    public AudioSource source;
    public float minWaitBetweenPlays = 1f; //최소 대기시간
    public float maxWaitBetweenPlays = 5f; //최대 대기시간
    public float waitTimeCountdown = -1f;

    void Start()
    {
        source = GetComponent<AudioSource>();
    }
    void Update()
    {
        if (!source.isPlaying)
        {
            if (waitTimeCountdown < 0f)
            {
                source.Play(); //소리재생
                waitTimeCountdown = Random.Range(minWaitBetweenPlays, maxWaitBetweenPlays); //대기시간을 최소와 최대 사이에서 무작위(random)로 선정
            }
            else
            {
                waitTimeCountdown -= Time.deltaTime; //대기시간을 흐른시간 만큼 제외(-)하기
            }
        }
    }
}
```

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class RandomSoundList : MonoBehaviour
{
    public List<AudioClip> audioClips; //소리모음
    public AudioClip currentClip;
    public AudioSource source;
    public float minWaitBetweenPlays = 1f; //최소 대기시간
    public float maxWaitBetweenPlays = 5f; //최대 대기시간
    public float waitTimeCountdown = -1f;

    void Start()
    {
        source = GetComponent<AudioSource>();
    }
    void Update()
    {
        if (!source.isPlaying)
        {
            if (waitTimeCountdown < 0f)
            {
                currentClip = audioClips[Random.Range(0, audioClips.Count)]; //audio clip중에 하나를 무작위(random)로 선택
                source.clip = currentClip;
                source.Play();
                waitTimeCountdown = Random.Range(minWaitBetweenPlays, maxWaitBetweenPlays);
            }
            else
            {
                waitTimeCountdown -= Time.deltaTime;
            }
        }
    }
}
```