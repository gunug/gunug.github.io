---
layout: post
title: Unity chatGPT TTS Avatar
category: unity3d
tags:
---

# Unity chatGPT TTS Avatar

## NuGetForUnity
* https://github.com/GlitchEnzo/NuGetForUnity
* 우측메뉴 Release
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715476796.jpg" />

* NuGetForUnity.4.1.0.unitypackage 다운
* Unity Project에 import

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715476936.jpg" />

* Main Manu > NuGet > Manage NuGet Packages
* Microsoft.Extensions.DependencyInjection 설치
* Microsoft.Extensions.Http 설치
* Newtonsoft.Json 설치

---

## OpenAI 키등록
* https://platform.openai.com/settings/organization/billing/overview
* 키 등록전 지불(Payment)방법 등록을 해야합니다. 키생성을 먼저하면 지불방법 등록후 다시 키등록 해야함

* https://platform.openai.com/api-keys
* Create new secret key
* 생성된 key는 생성시 한번만 볼 수 있습니다. 잘 보관해야합니다.

* 윈도우 > 시작메뉴 > cmd(터미널)
* ```setx OPENAI_API_KEY 키값``` 환경변수로 키 등록

---

## OpenAI API Dotnet

* https://github.com/OkGoDoIt/OpenAI-API-dotnet
* Download 압축 해제 후, OpenAI_API 폴더째로 드래그 드랍하여 import

## C# Script 작성
* OpenAIController.cs
```c#
using System;
using System.Collections.Generic;
using OpenAI_API;
using OpenAI_API.Chat;
using OpenAI_API.Models;
using UnityEngine;

public class OpenAIController : MonoBehaviour
{
    private OpenAIAPI api;
    private List<ChatMessage> messages;
    private Conversation chat;

    // Start is called before the first frame update
    void Start()
    {
        api = new OpenAIAPI(Environment.GetEnvironmentVariable("OPENAI_API_KEY", EnvironmentVariableTarget.User));
        StartConversation();
    }

    public void StartConversation()
    {
        messages = new List<ChatMessage>{
            new ChatMessage(ChatMessageRole.System, "당신은 한국인입니다. 한국어를 합니다. 항상 50글자 이내로 말합니다 그렇지 않으면 잘라버립니다.")
        };
    }

    private async void GetResponse()
    {
        Debug.Log("GetResponse");
        if (input_string.Length < 1) return;
        isTypeable = false; //typing lock

        ChatMessage userMessage = new ChatMessage();
        userMessage.Role = ChatMessageRole.User;
        userMessage.TextContent = input_string;
        if (userMessage.TextContent.Length > 100)
        {
            // limit message length to 100 characters
            userMessage.TextContent = userMessage.TextContent.Substring(0, 100);
        }
        output_string += string.Format("{0}:{1}", userMessage.rawRole, userMessage.TextContent) + "\n";
        Debug.Log(output_string);
        messages.Add(userMessage);

        input_string = ""; //clear the input field

        //Send the message to the API
        var chatResult = await api.Chat.CreateChatCompletionAsync(
            new ChatRequest()
            {
                Model = Model.ChatGPTTurbo,
                Temperature = 0.1,
                MaxTokens = 50,
                Messages = messages
            }
        );

        //get the response
        ChatMessage responseMessage = new ChatMessage();
        responseMessage.Role = chatResult.Choices[0].Message.Role;
        responseMessage.TextContent = chatResult.Choices[0].Message.TextContent;
        Debug.Log(string.Format("{0}:{1}", responseMessage.rawRole, responseMessage.TextContent));
        output_string += string.Format("{0}:{1}", responseMessage.rawRole, responseMessage.TextContent) + "\n";

        //Add the response to the list of messages
        messages.Add(responseMessage);

        isTypeable = true; //typing unlock
    }
    private string input_string = "";
    private string output_string = "";
    private Vector2 scroll_pos = Vector2.zero;
    private int font_size = 20;
    private bool isTypeable = true;
    private void OnGUI(){
        if(Event.current.type == EventType.KeyDown && Event.current.keyCode == KeyCode.Return){
            GetResponse();
        }
        GUIStyle LabelStyle = new GUIStyle(GUI.skin.label);
	    LabelStyle.fontSize = font_size;
        GUIStyle TextAreaStyle = new GUIStyle(GUI.skin.textArea);
        TextAreaStyle.fontSize = font_size;
        GUIStyle verticalScrollbar = GUI.skin.verticalScrollbar;

        GUILayout.BeginVertical();
            scroll_pos = GUILayout.BeginScrollView(scroll_pos, GUILayout.Width(400), GUILayout.Height(300));
                GUILayout.Label(output_string, TextAreaStyle);
            GUILayout.EndScrollView();
            scroll_pos.y = Mathf.Infinity; //scroll_pos update last line
            if(isTypeable){
                input_string = GUILayout.TextField(input_string, TextAreaStyle);
            }else{
                GUILayout.Label(input_string, TextAreaStyle);
            }
        GUILayout.EndVertical();
    }
}
```

---

# audio
* https://www.youtube.com/watch?v=_Ldw3jLkijE
* https://platform.openai.com/docs/api-reference/audio

```c#
using OpenAI_API.Audio;
using static OpenAI_API.Audio.TextToSpeechRequest;
```
* using 구문이 추가됨

```c#
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
        FileInfo file_ = await api.TextToSpeech.SaveSpeechToFileAsync(request, "speak_tamp.mp3"); //save to file
        Debug.Log(file_.FullName);
        var www = new WWW(file_.FullName);
        AudioSource audioSource = gameObject.AddComponent<AudioSource>();
        audioSource.clip = www.GetAudioClip(true, true, AudioType.MPEG);
        audioSource.Play();
    }
```

* 특정 구문을 소리내어 읽는 기능 추가
* 해당기능은 파일로 드랍되어 audio source에서 재생해야함

---

# Ready to me 아바타 사용하기
* <https://readyplayer.me/>
* <https://assetstore.unity.com/packages/tools/game-toolkits/ready-player-me-avatar-and-character-creator-259814?locale=ko-KR>

## Avatar comfigure
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434259.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434478.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434387.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434431.jpg" />

* <https://readyplayer.me/>

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434554.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434599.jpg" />

---

# Oculus Lipsync Unity
* https://developer.oculus.com/downloads/package/oculus-lipsync-unity/
* DownLoad 눌러서 파일 다운로드
* 압축 해제 후 OculusLipSync.unitypackage 파일 열어서 유니티에 import

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715500744.jpg" />

* OVRLipSyncContextMorphTarget.ms 파일수정

```c#
CheckVisemeKey(visemeTestKeys[i], i, 100); //100을 1로
skinnedMeshRenderer.SetBlendShapeWeight(
                    visemeToBlendTargets[i],
                    frame.Visemes[i] * 100.0f); //100.0f를 1.0f로
skinnedMeshRenderer.SetBlendShapeWeight(
                laughterBlendTarget,
                laughterScore * 100.0f); //100.0f를 1.0f로
lipsyncContext.SetLaughterBlend(100); //100을 1로
```

