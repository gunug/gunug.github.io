---
layout: post
title: ChatGPT 챗봇
category: subpage
tags: 
---

# ChatGPT 챗봇

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722756929.jpg" />
* Unity3D의 Project 창 빈공간에 마우스 우클릭
* Create > C# Script 선택하여 새 c# 스트립트 생성
* 파일명을 ```OpenAIController```으로 작성

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
    private OpenAI_TTS tts; //★
    void Start()
    {
        api = new OpenAIAPI(Environment.GetEnvironmentVariable("OPENAI_API_KEY", EnvironmentVariableTarget.User));
        tts = gameObject.GetComponent<OpenAI_TTS>(); //★
        //환경 변수로 부터 API KEY를 받아오기
        StartConversation();
    }

    public int maxResponseWordLimit = 10;

    [TextArea(3,10)]
    public string personality = "한국어만 사용합니다. 영어로 대답하지 않습니다. 수학에 관련된 답변만 해줍니다. 수학의 역사, 수에 관한 재밌는 이야기 등. 수학과 관련이 있다면 다른 과목이라도 답변을 해줍니다. 답변의 마지막엔 수학에 관한 재미있는 이야기를 하나 알려줍니다.";
    [TextArea(3,10)]
    public string scene = "교실입니다";
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

---


<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722770291.jpg" />

* 추가로 OpenAIController.cs파일의 MaxTokens 값을 조정하면 더 긴 답변을 받을 수 있습니다.