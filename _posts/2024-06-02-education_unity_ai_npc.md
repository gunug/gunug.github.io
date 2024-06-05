---
layout: post
title: Unity AI(ChatGPT) NPC 제작
category: education
tags: AI
teaser: https://image.onethelab.com/thumbnail/1715503381.jpg
---

<b style="color:red">※ 제작중인 튜토리얼. 내용은 언제든지 변경될 수 있으며, 다음의 내용을 따라하지 않는 것이 좋습니다.</b>

# Unity AI(ChatGPT) NPC 제작

## 프로젝트 시작
### 새 프로젝트 만들기
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1717317536.jpg" />
* All Templates > 3D (Built-in Render Pipeline)
* 프로젝트 명은 ```project_chatgpt_npc```입력
* Unity Organization은 가장 위에 선택할수 있는 것을 선택 (일반적으로 사용자 아이디)
* Connect to Unity Cloud 해제
* Create Project 선택하여 새 프로젝트 생성

### NuGetForUnity
* <https://github.com/GlitchEnzo/NuGetForUnity>{:target="_blank"}
* 우측메뉴 Release
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715476796.jpg" />

* NuGetForUnity.4.1.0.unitypackage 다운
* Unity Project에 import

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715476936.jpg" />

* Main Manu > NuGet > Manage NuGet Packages
* ```Microsoft.Extensions.DependencyInjection``` 설치
* ```Microsoft.Extensions.Http``` 설치
* ```Newtonsoft.Json``` 설치

---

## OpenAI 설정


### OpenAI 키등록
* <https://platform.openai.com/settings/organization/billing/overview>{:target="_blank"}
* 키 등록전 지불(Payment)방법 등록을 해야합니다. 키생성을 먼저하면 지불방법 등록후 다시 키등록 해야함

* https://platform.openai.com/api-keys
* Create new secret key
* 생성된 key는 생성시 한번만 볼 수 있습니다. 잘 보관해야합니다.

* 윈도우 > 시작메뉴 > cmd(터미널)
* ```setx OPENAI_API_KEY 키값``` 환경변수로 키 등록
* ```echo %OPENAI_API_KEY%``` 등록된 키 보기
* <https://help.openai.com/en/articles/5112595-best-practices-for-api-key-safety>{:target="_blank"} 환경변수를 이용한 키설정 참고

### OpenAI API Dotnet
* <https://github.com/OkGoDoIt/OpenAI-API-dotnet>{:target="_blank"}
* Download 압축 해제 후, OpenAI_API 폴더째로 드래그 드랍하여 import

---

## ChatGPT 챗봇
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

## TTS(Text-To-Speech)

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


public class TTS : MonoBehaviour
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

---

## STT(Speech-To-Text)

## 3D 캐릭터 연동, 립싱크

## 캐릭터 배경, 성격부여