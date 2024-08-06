---
layout: post
title: animation talk 말 하는 몸 동작
category: subpage
tags: 
---

# animation talk 말 하는 몸 동작

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722874636.jpg" />

* mixamo에 talk를 검색하여 말하는 듯한 몸 동작을 다운로드

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722872211.jpg" />

* 다운로드시 Format을 FBX for Unity(.fbx)로 변경 후 download 버튼 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722868355.jpg" />

* Animation 폴더를 선택한 후 다운로드 받은 애니메이션 파일을 드래그 드랍

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722874810.jpg" />

* project창에서 다운로드 받은 애니메이션을 선택
* Inspector창 Rig탭 Animation Type을 Humanoid로 변경 후 Apply 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722874914.jpg" />

* Project창에서 다운로드 받은 talk animation을 드래그 하여 Animator창에 드롭

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722874999.jpg" />

* Animator창에서 Talk에 마우스 우클릭 한 뒤 Make Transition 선택
* idle로 마우스 커서를 이동한 뒤 클릭

---

## 트랜지션
* 트랜지션은 애니메이션과 애니메이션 사이를 자연스럽게 연결하여 변화하는 모습을 만들어 줍니다.
* 말하기(Talk) 애니메이션 후 대기(idle) 애니메이션으로 자연스럽게 넘어갈 것입니다.

---

## 말하기 애니메이션 재생용 스크립트

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722756929.jpg" />
* Unity3D의 Project 창 빈공간에 마우스 우클릭
* Create > C# Script 선택하여 새 c# 스트립트 생성
* 파일명을 ```OpenAIAnimator```로 작성

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;


[System.Serializable]
public class AnimationTrigger
{
    public string triggerWord = "Trigger";
    public string animationName = "Animation";
}

public class OpenAIAnimator : MonoBehaviour
{
    public string default_animation_name = "Talk";
    public AnimationTrigger[] animationTriggers;
    private bool isPlaying = false;
    public Animator target_animator;
    public void playAniamtion(string chat_content)
    {
        isPlaying = false;
        foreach (var item in animationTriggers) //모든 트리거를 확인
        {
            if (chat_content.Contains(item.triggerWord)) //트리거 단어가 채팅에 포함되어있는지 확인
            {
                //채팅에 포함되어 있으면 해당 애니메이션을 실행
                target_animator.Play(item.animationName);
                isPlaying = true;
                break; //애니메이션이 실행되었으므로 더이상 확인할 필요가 없음
            }
        }
        if (!isPlaying) //애니메이션이 실행되지 않았다면 기본 애니메이션 실행
        {
            target_animator.Play(default_animation_name);
        }
    }
}
```


<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722875739.jpg" />

* 만들어진 script를 드래그 하여 아바타의 Randerer_head 부분에 드랍

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722875885.jpg" />

* 아바타의 Randerer_head를 선택한 뒤 inpector창의 OpenAIAnimator > Target animator 위치에
* 아바타를 드래그 하여 드롭

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722876128.jpg" />

* OpenAIAnimato > default_animation_name 은 Animator에 있는 Animation 이름과 동일하게 작성 (띄어쓰기 개수, 대소문자까지 동일해야합니다)

---

## OpenAIController에 기능을 추가
* OpenAIAnimator가 추가 되었음으로 이를 실행시켜줄 구문을 OpenAIController에 추가해야 합니다.

```c#
using System;
using System.Collections.Generic;
using OpenAI_API;
using OpenAI_API.Chat;
using OpenAI_API.Models;
using UnityEngine;


public enum ChatMessageSampleRole
{
    System,
    User,
    Assistant
}

[System.Serializable]
public class ChatMessageSample
{
    public ChatMessageSampleRole role = ChatMessageSampleRole.System;
    public string content = "Hello, World!";
}

public class OpenAIController : MonoBehaviour
{
    private OpenAIAPI api;
    private List<ChatMessage> messages;
    private Conversation chat;
    // Start is called before the first frame update
    private OpenAI_TTS tts; //★
    private OpenAIAnimator animator; //★
    void Start()
    {
        api = new OpenAIAPI(Environment.GetEnvironmentVariable("OPENAI_API_KEY", EnvironmentVariableTarget.User));
        tts = gameObject.GetComponent<OpenAI_TTS>(); //★
        animator = gameObject.GetComponent<OpenAIAnimator>(); //★
        //환경 변수로 부터 API KEY를 받아오기
        StartConversation();
    }

    public int maxResponseWordLimit = 10;

    [TextArea(3,10)]
    public string personality = "수학에 관련된 답변만 해줍니다. 수학의 역사, 수에 관한 재밌는 이야기 등. 수학과 관련이 있다면 다른 과목이라도 답변을 해줍니다. 답변의 마지막엔 수학에 관한 재미있는 이야기를 하나 알려줍니다. 도덕적으로 옳지 못한것을 바로잡아줍니다.";
    [TextArea(3,10)]
    public string scene = "교실입니다";

    public ChatMessageSample[] sample_message; //★;
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
        //새 시스템 메세지를 생성하는 것으로 캐릭터 설정
        foreach (var item in sample_message)
        {
            if(ChatMessageSampleRole.System == item.role)
                messages.Add(new ChatMessage(ChatMessageRole.System, item.content));
            else if(ChatMessageSampleRole.User == item.role)
                messages.Add(new ChatMessage(ChatMessageRole.User, item.content));
            else if(ChatMessageSampleRole.Assistant == item.role)
                messages.Add(new ChatMessage(ChatMessageRole.Assistant, item.content));
        }
        //시스템 메세지를 추가하는 것으로 캐릭터 강화
    }

    public async void GetResponse(string ins_input_string = null)
    {
        Debug.Log("GetResponse");
        if (ins_input_string != null) input_string = ins_input_string;
        if (input_string.Length < 1) return;
        isTypeable = false; //typing lock

        ChatMessage userMessage = new ChatMessage();
        userMessage.Role = ChatMessageRole.User;
        userMessage.TextContent = input_string;
        if (userMessage.TextContent.Length > 100)
        {
            // limit message length to 100 characters
            userMessage.TextContent = userMessage.TextContent.Substring(0, 100);
        } //사용자 메세지 100글자 제한 (넘을 경우 잘라냄)
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
                MaxTokens = 150,
                Messages = messages
            }
        );
        //메세지를 발송하고 답변을 기다림

        //get the response
        ChatMessage responseMessage = new ChatMessage();
        responseMessage.Role = chatResult.Choices[0].Message.Role;
        responseMessage.TextContent = chatResult.Choices[0].Message.TextContent;
        Debug.Log(string.Format("{0}:{1}", responseMessage.rawRole, responseMessage.TextContent));
        output_string += string.Format("{0}:{1}", responseMessage.rawRole, responseMessage.TextContent) + "\n";
        tts.text_to_speech(responseMessage.TextContent); //★
        animator.playAniamtion(responseMessage.TextContent); //★
        //메세지를 전달 받으면 UI에 출력

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
        //return; //이 코드를 주석 해제하면 GUI가 출력되지 않음
        //Graphic User Interface 출력
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

* (추가된 부분에 별표 주석되어 있습니다.)
* 소스코드를 전체 복사하여 기존 소스코드에 붙여넣어(Ctrl+V) 전체 덮어씌우기

