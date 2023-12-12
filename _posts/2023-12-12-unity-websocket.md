---
layout: post
title: unity websocket 웹소캣
category: unity3d
tags: websocket
---


* [https://timeboxstory.tistory.com/69](https://timeboxstory.tistory.com/69)

* 예제소스내에 connect 참조가 0

```c#
using System.Collections.Generic;
using UnityEngine;
using WebSocketSharp;
using System;
using System.Threading;
using System.Text;


public class WebsocketClient : MonoBehaviour
{
    private string IP = "192.168.137.100";
    private string PORT = "20000";
    //서버 서비스 이름
    private string SERVICE_NAME = "";

    public WebSocketSharp.WebSocket m_Socket = null;

    private void Start()
    {
        try
        {
            Debug.Log("try connect");
            m_Socket = new WebSocketSharp.WebSocket("ws://" + IP + ":" + PORT + SERVICE_NAME);
            m_Socket.OnMessage += Recv;
            m_Socket.OnClose += CloseConnect;
            m_Socket.OnError += (sender, e) =>
            {
                Debug.Log("error:" + e);
            };
            m_Socket.OnOpen += (sender, e) =>
            {
                Debug.Log("open:" + e);
            };
            Connect();
        }
        catch (Exception e)
        {
            Debug.Log("connect fail:" + e);
        }

    }


    //서버 연결함수
    public void Connect()
    {
        try
        {
            if (m_Socket == null || !m_Socket.IsAlive)
                m_Socket.Connect();

        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    private void CloseConnect(object sender, CloseEventArgs e)
    {
        DisconncectServer();
    }
    //연결 해제 함수
    public void DisconncectServer()
    {
        try
        {
            if (m_Socket == null)
                return;

            if (m_Socket.IsAlive)
                m_Socket.Close();

            Debug.Log("disconnect to server");
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    //서버로 데이터 전송할 함수
    public void SendMessage(string msg)
    {
        if (!m_Socket.IsAlive)
            return;
        try
        {
            m_Socket.Send(Encoding.UTF8.GetBytes(msg));
        }
        catch (Exception)
        {

            throw;
        }

    }
    //서버로 부터 받은 데이터 처리
    public void Recv(object sender, MessageEventArgs e)
    {
        Debug.Log("receive");
        //string 데이터
        Debug.Log(e.Data);

        //bytes 데이터
        Debug.Log(e.RawData);
    }

    private void OnApplicationQuit()
    {
        DisconncectServer();
    }
}
```