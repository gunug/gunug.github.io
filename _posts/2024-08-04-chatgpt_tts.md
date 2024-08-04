---
layout: post
title: ChatGPT TTS (Text-To-Speech)
category: subpage
tags: 
---

# ChatGPT TTS (Text-To-Speech)

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722756929.jpg" />
* Unity3D의 Project 창 빈공간에 마우스 우클릭
* Create > C# Script 선택하여 새 c# 스트립트 생성
* 파일명을 ```OpenAI_TTS```으로 작성

```c#
using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using UnityEngine;
using OpenAI_API;
using OpenAI_API.Chat;
using OpenAI_API.Models;
using OpenAI_API.Audio;
using static OpenAI_API.Audio.TextToSpeechRequest;


public class OpenAI_TTS : MonoBehaviour
{
    private OpenAIAPI api;
    private static AudioSource audioSource;
    public void Start()
    {
        api = new OpenAIAPI(Environment.GetEnvironmentVariable("OPENAI_API_KEY", EnvironmentVariableTarget.User));
        audioSource = gameObject.AddComponent<AudioSource>();
    }
    public async void text_to_speech(string str)
    {
        Debug.Log("text_to_speech");
        var request = new TextToSpeechRequest()
        {
            Input = str,
            ResponseFormat = ResponseFormats.MP3,
            Model = Model.TTS_HD,
            Voice = Voices.Nova,
            Speed = 0.9
        };
        FileInfo file_ = await api.TextToSpeech.SaveSpeechToFileAsync(request, "speak_temp.mp3"); //save to file
        Debug.Log(file_.FullName);
        var www = new WWW(file_.FullName);
        
        audioSource.clip = www.GetAudioClip(true, true, AudioType.MPEG);
        audioSource.Play();
    }
}
```
## 대상 생성

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722757110.jpg" />

* Hierarchy창 빈공간에 마우스 우클릭
* Create Empty 선택하여 빈 GameObject 생성
* 이름은 ```OpenAiController```로 변경

## 스크립트 전달

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722757241.jpg" />

* Project창에 만들어진 OpenAI_TTS.cs 파일을 드래그
* Hierarchy창에 있는 OpenAiController에 드롭하여 script를 전달

---
