---
layout: post
title: Unity AI(ChatGPT) NPC 제작
category: education
tags: AI
teaser: https://image.onethelab.com/thumbnail/1715503381.jpg
---

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
### API key 가져오기
* <https://openai.com/ko-KR/> 접속, 회원가입 또는 로그인
* <https://platform.openai.com/api-keys> 

## 키생성

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719827630.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719827582.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719827760.jpg" />

* 생성직후 우측의 copy 버튼을 클릭하여 키를 복사합니다 
* <b style="color:red;">키 생성 이후 팝업을 닫으면 다시는 키를 확인할 수 없습니다. 잃어버렸을 경우 키를 재생성 해야합니다.</b>

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

    public int maxResponseWordLimit = 10;

    [TextArea(3,10)]
    public string personality = "질문과 답변 과정에서 학생과 선생님은 서로 의견을 교환하며 이해도를 높입니다. 수업 중에 질문을 주고받는 분위기는 학생들의 참여도를 높이고 적극적인 학습을 유도합니다. 선생님은 친절하고 인내심을 갖춘 태도로 학생들의 질문에 답변하며, 학생들은 호기심과 탐구심을 가지고 질문을 제기합니다.";
    [TextArea(3,10)]
    public string scene = "일반적으로 학교 내에서 수업이 이루어지는 주요 장소입니다. 교실은 학생들과 선생님이 서로 상호작용할 수 있는 환경을 제공합니다. 학습 활동, 토론, 질문과 답변 등이 활발히 진행됩니다.";
    public void StartConversation()
    {
        string defult_content = "You are a teacher and will answer to the message the player ask you. \n" +
            "You must reply to the player message only using the information from your Personnality and the Scene that are provided afterwards. \n" +
            "Do not invent or create response that are not mentionned in these information. \n" +
            "Do not break character or mention you are an AI or a teacher. \n" +
            "You must answer in less than " + maxResponseWordLimit + "words. \n" +
            "Here is the information about your Personnality : \n" + personality + "\n" +
            "Here is the information about the Scene around you : \n" + scene + "\n" +
            "Here is the message of the player : \n";
        messages = new List<ChatMessage>{
            new ChatMessage(ChatMessageRole.System, defult_content)
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

# Unity3D-save-audioClip-to-MP3
* <https://github.com/BeatUpir/Unity3D-save-audioClip-to-MP3>
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719864316.jpg" />

* 파일을 다운로드 받은 후 압축해제
* audioToMP3.unitypackage 파일을 더블클릭 실행하여 import

## STT(Speech-To-Text)
```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using OpenAI_API;
using OpenAI_API.Audio;
using System;

public class STT : MonoBehaviour
{
    //OpenAIAPI.Transcriptions
    private String my_api_key;
    private OpenAIAPI api;
    private AudioSource audioSource;
    private AudioClip clip;
    private string path = "file.mp3";
    public int deviceIndex = 0;

    private void Start()
    {
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
        Debug.Log("입력된 글:"+text);
    }
}
```

---

## 3D 캐릭터 연동, 립싱크
## Ready Player Me Asset
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716442715.jpg" />

* <https://assetstore.unity.com/packages/tools/game-toolkits/ready-player-me-avatar-and-character-creator-259814>
* 에셋을 구입하고 Unity에서 열기하여 download, import 과정 진행

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443233.jpg" />

* 최초등장하는 팝업은 x를 눌러서 닫기

# Ready to me 아바타 사용하기
* <https://readyplayer.me/>
* <https://assetstore.unity.com/packages/tools/game-toolkits/ready-player-me-avatar-and-character-creator-259814?locale=ko-KR>

## Avatar comfigure
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434259.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434478.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434387.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715434431.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443315.jpg" />

* <https://readyplayer.me/hub> 우측하단 공유버튼 클릭
* 팝업에서 Copy avatar link 클릭하여 아바타 링크주소 복사

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1716443403.jpg" />

* Main Manu > Tools > Ready Player Me > Avatar Loader 선택
* 팝업창의 Avatar URL에 붙여넣기 (Ctrl+V, Command+V)하여 아바타 링크주소 입력
* Load Avatar into Current Scene 선택

---

# Lipsync
## Oculus Lipsync Unity
* <https://developer.oculus.com/downloads/package/oculus-lipsync-unity/>
* DownLoad 눌러서 파일 다운로드
* 압축 해제 후 OculusLipSync.unitypackage 파일 열어서 유니티에 import

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1715500744.jpg" />

* Add Component : OVR Lip Sync Context, OVR Lip Sync Context Morph Target, Eye Animation Handler
* OVR Lip Sync Context > audio loop back 체크

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