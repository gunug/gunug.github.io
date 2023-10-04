---
layout: post
title: unity socket communication 유니티 소캣통신
category: unity3d
tags: c# simple-code server
---

# 블럭, 논블럭, 동기, 비동기
* [https://okky.kr/article/442803](https://okky.kr/article/442803)

# 사설, 공인 아이피 구하기
* [참고링크](https://blog.edit.kr/entry/C-%EC%82%AC%EC%84%A4-%EA%B3%B5%EC%9D%B8-IP-%EA%B5%AC%ED%95%98%EA%B8%B0-Internal-External-IP-Address)

```c#
using System.Net.Sockets; //for AddressFamily 

public static string GetInternalIPAddress()
{
    var host = Dns.GetHostEntry(Dns.GetHostName());
    foreach (var ip in host.AddressList)
    {
	if (ip.AddressFamily == AddressFamily.InterNetwork)
	{
	    return ip.ToString();
	}
    }
    throw new Exception("No network adapters with an IPv4 address in the system!");
}
public static string GetExternalIPAddress()
{
    string externalip = new WebClient().DownloadString("http://ipinfo.io/ip").Trim(); //http://icanhazip.com
    if (String.IsNullOrWhiteSpace(externalip))
    {
	externalip = GetInternalIPAddress();//null경우 Get Internal IP를 가져오게 한다.
    }
    return externalip;
}
```

---

# TCP Server, TCP Client
## 통신포트
* [참고링크](https://coderzero.tistory.com/entry/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-TcpServer-TcpClient-%EA%B5%AC%EC%A1%B0%EC%B2%B4-%EC%A0%84%EC%86%A1-Socket)
* 0 사용하지 않음
* 1~1023 잘 알려진 포트 (wall-known port)
* 1024~49151 등록된 포트 (Registered port)
* 49152 ~ 65535 동적 포트 (Dynamic port)
* 그래서 권장포트는 49152 ~ 65535

## 전송 패키지 사이즈
* TCP헤더와 IP 헤더를 제외하면 1460byte
* 편의상 1024byte가 사용하기 적당함
    * 유니티와 유니티, 또는 C#과의 통신, 또는 C++와의 통신
    * 클래스 : Socket
    * 개체 직렬화 : Marshal
    * 전송 패킷 : 구조체 ↔ 바이트 배열

---

# 에코서버 형태로 변경, 쓰레드가 적용된 최종본

## Server
```c#
using System; 
using UnityEngine; 
using System.Net; 
using System.Net.Sockets; 
using System.Runtime.InteropServices; 
using System.Threading;

public class SocketServer : MonoBehaviour {

   private Socket m_Server, m_Client;
   public int m_Port = 50001;
   public ToClientPacket m_SendPacket = new ToClientPacket();
   public ToServerPacket m_ReceivePacket = new ToServerPacket();
   private EndPoint m_RemoteEndPoint;
   private Thread t;
   void Start()
   {
       ThreadStart th = new ThreadStart(InitServer); //1.InitServer메소드를 위임. 
       t = new Thread(th);                     //2.쓰레드생성.
       t.Start();                              //3.시작 
       //InitServer();
   }
   void Update()
   {
       Receive();
       Send();
   }
   void OnApplicationQuit()
   {
       Debug.Log("Application ending after " + Time.time + " seconds");
       t.Abort(); //강제종료
       CloseServer();
   }
   void InitServer()
   {
       // SendPacket에 배열이 있으면 선언 해 주어야 함.
       m_SendPacket.m_IntArray = new int[2];
       m_Server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
       m_RemoteEndPoint = new IPEndPoint(IPAddress.Any, m_Port);
       m_Server.Bind(m_RemoteEndPoint);
       m_Server.Listen(10); // client 접속을 기다림.
       m_Client = m_Server.Accept(); // client가 하나만 사용.
       SetSendPacket();
   }
   void Receive()
   {
       int receive = 0;
       byte[] packet = new byte[1024];
       try
       {
           receive = m_Client.Receive(packet);
           //receive = m_Server.Receive(packet);
       }
       catch (Exception ex)
       {
           Debug.Log(ex.ToString());
           return;
       }
       m_ReceivePacket = ByteArrayToStruct<ToServerPacket>(packet);
       if (receive > 0)
       {
           DoReceivePacket(); // 받은 값 처리
       }
   }
   void DoReceivePacket()
   {
       Debug.LogFormat($"m_IntArray[0] = {m_ReceivePacket.m_IntArray[0]} " +
           $"m_IntArray[1] = {m_ReceivePacket.m_IntArray[1] } " +
           $"FloatlVariable = {m_ReceivePacket.m_FloatlVariable} " +
           $"StringlVariable = {m_ReceivePacket.m_StringlVariable}" +
           $"BoolVariable = {m_ReceivePacket.m_BoolVariable} " +
           $"IntlVariable = {m_ReceivePacket.m_IntVariable} ");
       //출력: m_IntArray[0] = 7 m_IntArray[1] = 47 FloatlVariable = 2020 StringlVariable = Coder ZeroBoolVariable = True IntlVariable = 13 
       SetSendPacketFromReceive();
   }
   void SetSendPacketFromReceive()
   {
       m_SendPacket.m_BoolVariable = m_ReceivePacket.m_BoolVariable;
       m_SendPacket.m_IntVariable = m_ReceivePacket.m_IntVariable;
       m_SendPacket.m_IntArray[0] = m_ReceivePacket.m_IntArray[0];
       m_SendPacket.m_IntArray[1] = m_ReceivePacket.m_IntArray[1];
       m_SendPacket.m_FloatlVariable = m_ReceivePacket.m_FloatlVariable;
       m_SendPacket.m_StringlVariable = m_ReceivePacket.m_StringlVariable;
   }
   void Send()
   {
       try
       {
           //SetSendPacket();
           byte[] sendPacket = StructToByteArray(m_SendPacket);
           m_Client.Send(sendPacket, 0, sendPacket.Length, SocketFlags.None);
           //m_Server.Send(sendPacket, 0, sendPacket.Length, SocketFlags.None);
       }
       catch (Exception ex)
       {
           Debug.Log(ex.ToString());
           return;
       }
   }
   void SetSendPacket()
   {
       m_SendPacket.m_BoolVariable = true;
       m_SendPacket.m_IntVariable = 13;
       m_SendPacket.m_IntArray[0] = 7;
       m_SendPacket.m_IntArray[1] = 47;
       m_SendPacket.m_FloatlVariable = 2020;
       m_SendPacket.m_StringlVariable = "Coder Zero";
   }
   void CloseServer()
   {
       if (m_Client != null)
       {
           m_Client.Close();
           m_Client = null;
       }
       if (m_Server != null)
       {
           m_Server.Close();
           m_Server = null;
       }
   }
   byte[] StructToByteArray(object obj)
   {
       int size = Marshal.SizeOf(obj);
       byte[] arr = new byte[size];
       IntPtr ptr = Marshal.AllocHGlobal(size);
       Marshal.StructureToPtr(obj, ptr, true);
       Marshal.Copy(ptr, arr, 0, size);
       Marshal.FreeHGlobal(ptr);
       return arr;
   }
   T ByteArrayToStruct<T>(byte[] buffer) where T : struct
   {
       int size = Marshal.SizeOf(typeof(T));
       if (size > buffer.Length)
       {
           throw new Exception();
       }
       IntPtr ptr = Marshal.AllocHGlobal(size);
       Marshal.Copy(buffer, 0, ptr, size);
       T obj = (T)Marshal.PtrToStructure(ptr, typeof(T));
       Marshal.FreeHGlobal(ptr);
       return obj;
   }
}
```

## Client
```c#
using System; 
using UnityEngine; 
using System.Net; 
using System.Net.Sockets; 
using System.Runtime.InteropServices;

public class SocketClient : MonoBehaviour {

   private Socket m_Client;
   public string m_Ip = "127.0.0.1";
   public int m_Port = 50001;
   public ToServerPacket m_SendPacket = new ToServerPacket();
   public ToClientPacket m_ReceivePacket = new ToClientPacket();
   private IPEndPoint m_ServerIpEndPoint;
   private EndPoint m_RemoteEndPoint;
   void Start()
   {
       InitClient();
       SetSendPacket();
   }

   void Update()
   {
       Receive();
       Send();
   }
   void OnApplicationQuit()
   {
       CloseClient();
   }
   void InitClient()
   {
       Debug.Log("client init");
       // SendPacket에 배열이 있으면 선언 해 주어야 함.
       m_SendPacket.m_IntArray = new int[2];
       m_ServerIpEndPoint = new IPEndPoint(IPAddress.Parse(m_Ip), m_Port);
       m_Client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
       m_Client.Connect(m_ServerIpEndPoint);
   }
   void SetSendPacket()
   {
       m_SendPacket.m_BoolVariable = true;
       m_SendPacket.m_IntVariable = 13;
       m_SendPacket.m_IntArray[0] = 7;
       m_SendPacket.m_IntArray[1] = 47;
       m_SendPacket.m_FloatlVariable = 2020;
       m_SendPacket.m_StringlVariable = "Coder Zero";
   }
   void Send()
   {
       Debug.Log("client send");
       try
       {
           //SetSendPacket();
           byte[] sendPacket = StructToByteArray(m_SendPacket);
           m_Client.Send(sendPacket, 0, sendPacket.Length, SocketFlags.None);
       }
       catch (Exception ex)
       {
           Debug.Log(ex.ToString());
           return;
       }
   }
   void Receive()
   {
       Debug.Log("client receive");
       int receive = 0;
       Debug.Log("m_Client.Available:" + m_Client.Available);
       //Socket.Available = 네트워크에서 받아서 읽을 수 있는 데이터의 양.
       if (m_Client.Available != 0)
       {
           byte[] packet = new byte[1024];
           try
           {
               receive = m_Client.Receive(packet);
           }
           catch (Exception ex)
           {
               Debug.Log(ex.ToString());
               return;
           }
           m_ReceivePacket = ByteArrayToStruct<ToClientPacket>(packet);
           Debug.Log("receive length:" + receive);
           if (receive > 0)
           {
               DoReceivePacket(); // 받은 값 처리
           }
       }
   }
   void DoReceivePacket()
   {
       Debug.LogFormat($"m_IntArray[0] = {m_ReceivePacket.m_IntArray[0]} " +
          $"m_IntArray[1] = {m_ReceivePacket.m_IntArray[1] } " +
          $"FloatlVariable = {m_ReceivePacket.m_FloatlVariable} " +
          $"StringlVariable = {m_ReceivePacket.m_StringlVariable}" +
          $"BoolVariable = {m_ReceivePacket.m_BoolVariable} " +
          $"IntlVariable = {m_ReceivePacket.m_IntVariable} ");
       //출력: m_IntArray[0] = 7 m_IntArray[1] = 47 FloatlVariable = 2020 StringlVariable = Coder ZeroBoolVariable = True IntlVariable = 13 
   }
   void CloseClient()
   {
       if (m_Client != null)
       {
           m_Client.Close();
           m_Client = null;
       }
   }
   byte[] StructToByteArray(object obj)
   {
       int size = Marshal.SizeOf(obj);
       byte[] arr = new byte[size];
       IntPtr ptr = Marshal.AllocHGlobal(size);
       Marshal.StructureToPtr(obj, ptr, true);
       Marshal.Copy(ptr, arr, 0, size);
       Marshal.FreeHGlobal(ptr);
       return arr;
   }
   T ByteArrayToStruct<T>(byte[] buffer) where T : struct
   {
       int size = Marshal.SizeOf(typeof(T));
       if (size > buffer.Length)
       {
           throw new Exception();
       }
       IntPtr ptr = Marshal.AllocHGlobal(size);
       Marshal.Copy(buffer, 0, ptr, size);
       T obj = (T)Marshal.PtrToStructure(ptr, typeof(T));
       Marshal.FreeHGlobal(ptr);
       return obj;
   }
}
```

## Packet
```c#
using System; 
using System.Runtime.InteropServices;

[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)] [Serializable] public struct ToClientPacket {

   [MarshalAs(UnmanagedType.Bool)]
   public bool m_BoolVariable;
   public int m_IntVariable;
   [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
   public int[] m_IntArray;
   public float m_FloatlVariable;
   [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
   public string m_StringlVariable;
}


[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)] [Serializable] public struct ToServerPacket {

   [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
   public int[] m_IntArray;
   public float m_FloatlVariable;
   [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
   public string m_StringlVariable;
   [MarshalAs(UnmanagedType.Bool)]
   public bool m_BoolVariable;
   public int m_IntVariable;
}
```

<b style="color:red">단일 접속에만 해당하여 더 개선이 필요합니다</b>

---

# error 에러
* SocketException: 대상 컴퓨터에서 연결을 거부했으므로 연결하지 못했습니다. //서버가 실행되어 있지 않아서 일어나는 문제
* m_Client = m_Server.Accept(); // client가 하나만 사용. 
    * 상황에서 무한대기(유니티가 진행되지 않음)