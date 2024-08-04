---
layout: post
title: ChatGPT STT (Speech-To-Text)
category: subpage
tags: 
---

# ChatGPT STT (Speech-To-Text)

---

## 오디오 클립을 mp3로 변환
* Unity3D-save-audioClip-to-MP3

* <https://github.com/BeatUpir/Unity3D-save-audioClip-to-MP3>

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719864316.jpg" />

* 파일을 다운로드 받은 후 압축해제
* audioToMP3.unitypackage 파일을 더블클릭 실행하여 import
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722772006.jpg" />

---

## STT(Speech-To-Text)

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722756929.jpg" />
* Unity3D의 Project 창 빈공간에 마우스 우클릭
* Create > C# Script 선택하여 새 c# 스트립트 생성
* 파일명을 ```OpenAI_STT```으로 작성

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using OpenAI_API;
using OpenAI_API.Audio;
using System;

public class OpenAI_STT : MonoBehaviour
{
    //OpenAIAPI.Transcriptions
    private String my_api_key;
    private OpenAIAPI api;
    private AudioSource audioSource;
    private AudioClip clip;
    private string path = "file.mp3";
    public int deviceIndex = 0;
    public OpenAIController openAIController; //★ OpenAIController 스크립트 참조
    private void Start()
    {
        openAIController = gameObject.GetComponent<OpenAIController>(); //★ OpenAIController 스크립트 추가
        my_api_key = Environment.GetEnvironmentVariable("OPENAI_API_KEY", EnvironmentVariableTarget.User); //환경변수로 부터 API 키를 가져옴
        api = new OpenAIAPI(my_api_key); //API 키를 이용하여 API 객체 생성

        //transcriptions.GetTextAsync("path/to/file.mp3");
        //get microphone name
        int counter = 0;
        foreach (string device in Microphone.devices)
        {
            Debug.Log("[Device index:"+counter+"] [Device Name: " + device +"]");
            counter++;
        }

        //get audio source reference
        AudioSource audioSource = GetComponent<AudioSource>();
    }

    private void Update(){
        //push q key for start recording
        if(Input.GetKeyDown(KeyCode.Q)){
            clip = Microphone.Start(Microphone.devices[deviceIndex], true, 10, 44100); //녹음 시작
        }
        //push w key for stop recording
        if(Input.GetKeyDown(KeyCode.W)){
            Microphone.End(Microphone.devices[deviceIndex]); //녹음 종료
        }

        //push space key for get text
        if(Input.GetKeyDown(KeyCode.E)){
            EncodeMP3.convert (clip, path, 44100); //녹음된 오디오 파일을 mp3로 변환
            GetTextAsync(path); //변환된 mp3 파일을 텍스트로 변환
        }

        //push z key for start end recording and get text
        if(Input.GetKeyDown(KeyCode.Z)){
            clip = Microphone.Start(Microphone.devices[deviceIndex], true, 10, 44100);
        }
        if(Input.GetKeyUp(KeyCode.Z)){
            Microphone.End(Microphone.devices[deviceIndex]);
            EncodeMP3.convert (clip, path, 44100);
            GetTextAsync(path);
        }
    }

    async void GetTextAsync(string path)
    {
        string text = await api.Transcriptions.GetTextAsync(path);
        openAIController.GetResponse(text); //★ OpenAIController의 GetResponse 함수 호출
        Debug.Log("입력된 글:"+text);
    }
}
```
