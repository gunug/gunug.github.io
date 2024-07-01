---
layout: post
title: Unity AI(ChatGPT) NPC 제작2
category: education
tags: AI
teaser: https://image.onethelab.com/thumbnail/1715503381.jpg
---

<b style="color:red">※ 제작중인 튜토리얼. 내용은 언제든지 변경될 수 있으며, 다음의 내용을 따라하지 않는 것이 좋습니다.</b>

# Unity AI(ChatGPT) NPC 제작2
## API import

* <https://github.com/srcnalt/OpenAI-Unity> 접속

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719808368.jpg" />

* Code > Copy 버튼을 눌러서 url 복사

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719809040.jpg" />

* Main Menu > Window > Package Manager

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719809089.jpg" />

* Package Manager 창 > +버튼 > Add package from git URL... 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719810188.jpg" />

* 복사된 URL을 붙여넣기(Ctrl+V)하고 Add를 버튼 클릭
* install 버튼 클릭하여 인스톨 과정 진행

---

## API key 가져오기
* <https://openai.com/ko-KR/> 접속, 회원가입 또는 로그인
* <https://platform.openai.com/api-keys> 

## 키생성

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719827630.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719827582.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719827760.jpg" />

* 생성직후 우측의 copy 버튼을 클릭하여 키를 복사합니다 
* <b style="color:red;">키 생성 이후 팝업을 닫으면 다시는 키를 확인할 수 없습니다. 잃어버렸을 경우 키를 재생성 해야합니다.</b>

## Organization ID 조직 아이디

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719827972.jpg" />

---

## API key 등록
* C:사용자/사용자이름/ 위치에 .openai 폴더생성
* .openai 폴더 안에 auth.json 파일생성
* 파일의 내용을 다음과 같이 작성
  
```json
{
    "api_key": "sk-...W6yi",
    "organization": "org-...L7W"
}
```
* 위 예시는 전체키가 생략된 일부분 입니다.
* api_key와 organization 값을 실제값으로 변경하여야 합니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719828270.jpg" />

* 위치, 폴더명, 파일명이 다르면 unity 에러 발생

```c#
private async void SendRequest()
{
    var req = new CreateChatCompletionRequest
    {
        //Model = "gpt-3.5-turbo",
        Model = "gpt-4o", //모델선택
        Messages = new List<ChatMessage>()
        {
            new ChatMessage()
            {
                Role = "user", //역할 설정
                Content = "Hello!" //대화 내용
            }
        }
    };
    var res = await openai.CreateChatCompletion(req);
    Debug.Log(res.Choices[0].Message.Content); //결과 출력
}
```


```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using OpenAI;
using System;

public class OpenAIManager : MonoBehaviour
{
    private OpenAIApi openai = new OpenAIApi();

    private void Start()
    {
        Debug.Log("Starting OpenAI");
        SetDefault();
        //SendRequest();
    }
    private List<ChatMessage> chatMessages;

    private async void SetDefault(){
        chatMessages = new List<ChatMessage>();
        chatMessages.Add(new ChatMessage()
        {
            Role = "system",
            Content = "당신은 한국인 입니다. 한국어를 합니다. 항상 10단어 이하로 말합니다"
        });
        var req = new CreateChatCompletionRequest
        {
            Model = "gpt-3.5-turbo",
            Messages = chatMessages
        };
        var res = await openai.CreateChatCompletion(req);
    }
    private async void SendRequest()
    {
        chatMessages.Add(new ChatMessage()
        {
            Role = "user",
            Content = input_string
        });
        input_string = "";
        var req = new CreateChatCompletionRequest
        {
            Model = "gpt-3.5-turbo",
            Messages = chatMessages
        };
        var res = await openai.CreateChatCompletion(req);
        output_string += "AI: " + res.Choices[0].Message.Content + "\n";
        Debug.Log(res.Choices[0].Message.Content);
    }
    private string input_string = "";
    private string output_string = "";
    private Vector2 scroll_pos = Vector2.zero;
    private int font_size = 20;
    private bool isTypeable = true;
    private void OnGUI(){
        if(Event.current.type == EventType.KeyDown && Event.current.keyCode == KeyCode.Return){
            output_string += "user: " + input_string + "\n";
            SendRequest();
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