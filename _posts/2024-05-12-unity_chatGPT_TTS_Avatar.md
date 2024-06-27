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
* <https://help.openai.com/en/articles/5112595-best-practices-for-api-key-safety> 환경변수를 이용한 키설정 참고
* ```echo %OPENAI_API_KEY%``` 등록된 키 보기

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

---

# 성격 부여하기
* 당신은 비디오 게임 캐릭터이고 플레이어가 묻는 말에 답한다
* 제공되는 성격 및 장면의 정보만 활용하여 대답한다. 이 정보에서 언급되지 않은 답변을 고안하거나 작성하지 않는다
* 캐릭터를 깨트리거나 자신이 AI 또는 비디오 게임 캐릭터라고 언급하지 않는다
* 최대 00단어로 대답한다.
* 여기에 당신의 성격에 대한 정보가 있습니다 : 서술
* 여기에 당신의 주변 장면에 대한 정보가 있습니다 : 서술
* 플레이어의 메시지는 다음과 같습니다 : 서술

* ChatMessage의 Content로 기본 서술을 제공 이후 대화는 누적(+)하여 서술

```c#
public string GetInstructions()
{
    string instructions = 
    "You are a video game character and will answer to the message the player ask you. \n" + 
    "You must reply to the player message only using the information from your Personnality and the Scene that are provided afterwards. \n" +
    "Do not invent or create response that are not mentionned inthese information. \n" +
    "Do not break character or mention you are an AI or a video game character. \n" +
    "You must answer in less than " + maxResponseWordLimit + "words. \n" +
    "Here is the information about your Personnality : \n" + personality + "\n" +
    "Here is the information about the Scene around you : \n" + scene + "\n" +
    "Here is the message of the player : \n";
    return instructions;
}

public async void AskChatGPT(string newText)
{
    ChatMessage newMessage = new ChatMessage();
    newMessage.Content = GetInstructions() + newText;
    newMessage.Role = "user";
    messages.Add(newMessage);
    CreateChatCompletionRequest request = new CreateChatCompletionRequest();
    request.Messages = messages;
    request.Model = "gpt-3.5-turbo-0301";
    var response = await openAI.CreateChatCompletion(request);
    if (response.Choices != null && response.Choices.Count > 0)
    {
    var chatResponse = response.Choices[0].Message;
    messages.Add(chatResponse);
    Debug.Log(chatResponse.Content);
    OnResponse.Invoke(chatResponse.Content);
    }
}
```
