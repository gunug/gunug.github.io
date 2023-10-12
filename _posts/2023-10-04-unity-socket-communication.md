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

---

# 업그레이드
* 기존 방식은 update내에서 호출이 빈번하여 문제가 많이 발생할 수 있음
* 패킷 수신 후 패킷이 존재할때만 발송할수 있도록 변경예정
* 다중 클라이언트 접속 추가예정

---

```c#
using System;
using UnityEngine;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Threading;
using System.Text;
using System.Collections;
using System.Collections.Generic;

public class GunaServer : MonoBehaviour
{
    private Socket m_server, m_client;
    private static List<Socket> r_clients = new List<Socket>();
    public List<string> ips = new List<string>();
    public int m_port = 50001;
    public static GunaPacket m_packet = new GunaPacket();
    private EndPoint m_endpoint;
    private Thread m_gate;
    public static ManualResetEvent allDone = new ManualResetEvent(false);
    void Start()
    {
        m_port = ServerUiManager.server_port;
        ThreadStart ins_th = new ThreadStart(initServer);
        m_gate = new Thread(ins_th);
        m_gate.Start();
    }

    void OnApplicationQuit()
    {
        //Debug.Log("application end");
        closeServer();
        if (m_gate != null) m_gate.Abort();
    }

    void initServer()
    {
        //Debug.Log("server init start");
        m_server = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        m_endpoint = new IPEndPoint(IPAddress.Any, m_port);
        try
        {
            m_server.Bind(m_endpoint);
            m_server.Listen(10); // client 접속을 기다림.
            //Debug.Log("server stared");
            while (true)
            {
                allDone.Reset();
                //Debug.Log("Guna wait client...");
                m_server.BeginAccept(new AsyncCallback(acceptCallback), m_server);
                allDone.WaitOne();
            }
        }
        catch(Exception e)
        {
            Debug.Log(e.ToString());
            return;
        }
    }

    private static void broadcast()
    {
        foreach(Socket element in r_clients)
        {
            Send(element);
        }
    }

    private static void Send(Socket handler)
    {
        //Debug.Log("send progress");
        try {        
        byte[] sendPacket = StructToByteArray(m_packet);

        // Begin sending the data to the remote device.  
        handler.BeginSend(sendPacket, 0, sendPacket.Length, 0, new AsyncCallback(SendCallback), handler);
        // m_client.BeginSend(sendPacket, 0, sendPacket.Length, 0, new AsyncCallback(SendCallback), m_client); //클라이언트쪽 내용 (참고자료)
        }
        catch (Exception ex)
        {
            Debug.Log(ex.ToString());
            return;
        }
    }

    void acceptCallback(IAsyncResult ar) 
    {
        //Debug.Log("client accept!!!");
        allDone.Set();
        try
        {
            Socket listener = (Socket)ar.AsyncState;
            Socket handler = listener.EndAccept(ar);
            r_clients.Add(handler);
            string ip = ((IPEndPoint)(handler.RemoteEndPoint)).Address.ToString();
            //Debug.Log("client accept: " + ip);
            //Debug.Log("total_clients:" + r_clients.Count);
            ips.Add(ip);
            GunaStateObject state = new GunaStateObject();
            state.workSocket = handler;
            handler.BeginReceive(state.buffer, 0, GunaStateObject.BufferSize, 0, new AsyncCallback(ReceiveCallback), state);
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
            return;
        }
    }

    private static void SendCallback(IAsyncResult ar)
    {
        //Debug.Log("send progress : each client");
        try
        {
            // Retrieve the socket from the state object.  
            Socket handler = (Socket)ar.AsyncState;

            // Complete sending the data to the remote device.  
            int bytesSent = handler.EndSend(ar);
            //Console.WriteLine("Sent {0} bytes to client.", bytesSent);

            //handler.Shutdown(SocketShutdown.Both);
            //handler.Close();
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    public static void ReceiveCallback(IAsyncResult ar)
    {
        //Debug.Log("data received");
        GunaStateObject state = (GunaStateObject)ar.AsyncState;
        Socket handler = state.workSocket;
        //int bytesRend = handler.EndReceive(ar); //read data from the client socket
        int receive = 0;

        try
        {
            //receive = handler.Receive(state.buffer);
            receive = handler.EndReceive(ar);
        }
        catch (Exception ex)
        {
            Debug.Log(ex.ToString());
            Debug.Log("exception appeared");
            return;
        }
        m_packet = ByteArrayToStruct<GunaPacket>(state.buffer);
        showPacket();
        broadcast(); //받자마자 바로 브로드케스트 해보자
        //Debug.Log("receive length:" + receive);
        handler.BeginReceive(state.buffer, 0, GunaStateObject.BufferSize, 0, new AsyncCallback(ReceiveCallback), state); //이것으로 다회차 리시브가 될것인가
    }

    static void showPacket()
    {
        /*
        Debug.LogFormat($"m_IntArray[0] = {m_packet.m_IntArray[0]} " +
            $"m_IntArray[1] = {m_packet.m_IntArray[1] } " +
            $"FloatlVariable = {m_packet.m_FloatlVariable} " +
            $"StringlVariable = {m_packet.m_StringlVariable}" +
            $"BoolVariable = {m_packet.m_BoolVariable} " +
            $"IntlVariable = {m_packet.m_IntVariable} ");
        */
        //출력: m_IntArray[0] = 7 m_IntArray[1] = 47 FloatlVariable = 2020 StringlVariable = Coder ZeroBoolVariable = True IntlVariable = 13 
    }

    void closeServer()
    {
        if(m_server != null)m_server.Close();
        //Debug.Log("server closed");
    }

    static byte[] StructToByteArray(object obj)
    {
        int size = Marshal.SizeOf(obj);
        byte[] arr = new byte[size];
        IntPtr ptr = Marshal.AllocHGlobal(size);

        Marshal.StructureToPtr(obj, ptr, true);
        Marshal.Copy(ptr, arr, 0, size);
        Marshal.FreeHGlobal(ptr);
        return arr;
    }

    static T ByteArrayToStruct<T>(byte[] buffer) where T : struct
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

---

```c#
using System;
using UnityEngine;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices;
using System.Threading;

public class GunaClient : MonoBehaviour
{
    private Socket m_client;
    public string m_ip = "127.0.0.1";
    public int m_port = 50001;
    public GunaPacket m_packet = new GunaPacket();
    private IPEndPoint m_server_endpoint;
    private EndPoint m_client_endpoint;

    private static ManualResetEvent connectDone = new ManualResetEvent(false);
    private static ManualResetEvent sendDone = new ManualResetEvent(false);
    private static ManualResetEvent receiveDone = new ManualResetEvent(false);

    private Thread m_gate;

    void Start()
    {
        m_ip = ServerUiManager.server_ip;
        m_port = ServerUiManager.server_port;
        ThreadStart ins_th = new ThreadStart(initClient);
        m_gate = new Thread(ins_th);
        m_gate.Start();
        //initClient();
    }

    void initClient()
    {
        //Debug.Log("client init");
        m_server_endpoint = new IPEndPoint(IPAddress.Parse(m_ip), m_port);
        m_client = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        m_client.BeginConnect(m_server_endpoint, new AsyncCallback(ConnectCallback), m_client);
        connectDone.WaitOne();

        //m_client.Shutdown(SocketShutdown.Both);
        //m_client.Close();
    }

    void ConnectCallback(IAsyncResult ar)
    {
        try
        {
            Socket client = (Socket)ar.AsyncState;
            client.EndConnect(ar);
            //Debug.Log("■ Socket connected to: " + client.RemoteEndPoint.ToString());
            Send();
            sendDone.WaitOne();
            //입장하자마자 센딩 해보자

            Receive(client);
            //receiveDone.WaitOne();

            connectDone.Set();
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    private void Receive(Socket client)
    {
        try
        {
            // Create the state object.  
            GunaStateObject state = new GunaStateObject();
            state.workSocket = client;

            // Begin receiving the data from the remote device.  
            client.BeginReceive(state.buffer, 0, GunaStateObject.BufferSize, 0, new AsyncCallback(ReceiveCallback), state);
            //handler.BeginReceive(state.buffer, 0, GunaStateObject.BufferSize, 0, new AsyncCallback(ReceiveCallback), state); //서버쪽 리시버 (참고용)
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    private void ReceiveCallback(IAsyncResult ar)
    {
        //Debug.Log("client: received !!");
        try
        {
            // Retrieve the state object and the client socket
            // from the asynchronous state object.  
            GunaStateObject state = (GunaStateObject)ar.AsyncState;
            Socket client = state.workSocket;

            int receive = 0;
            // Read data from the remote device.
            //Debug.Log("client.Available:" + client.Available);
            //client.Available 네트워크에서 받아서 읽을수 있는 데이터의 양
            
            try
            {
                receive = client.EndReceive(ar);
            }
            catch (Exception ex)
            {
                Debug.Log(ex.ToString());
                return;
            }
            if (receive > 0)
            {
                //Debug.Log("■ client: packet received");
                //m_packet = ByteArrayToStruct<GunaPacket>(state.buffer);
                m_packet = ByteArrayToStruct<GunaPacket>(state.buffer);
                showPacket();
                //Debug.Log("receive length:" + receive);
                // 받은 값 처리
                client.BeginReceive(state.buffer, 0, GunaStateObject.BufferSize, 0, new AsyncCallback(ReceiveCallback), state); //이것으로 다회차 리시브가 될것인가
            }
            //receiveDone.Set(); //이게 문제인거 같다 셋을 안해주면 시스템이 락걸리넹
        }
        catch (Exception e)
        {
            Console.WriteLine(e.ToString());
        }
    }


    void showPacket()
    {
        /*
        Debug.LogFormat($"m_IntArray[0] = {m_packet.m_IntArray[0]} " +
            $"m_IntArray[1] = {m_packet.m_IntArray[1] } " +
            $"FloatlVariable = {m_packet.m_FloatlVariable} " +
            $"StringlVariable = {m_packet.m_StringlVariable}" +
            $"BoolVariable = {m_packet.m_BoolVariable} " +
            $"IntlVariable = {m_packet.m_IntVariable} ");
        */
        //출력: m_IntArray[0] = 7 m_IntArray[1] = 47 FloatlVariable = 2020 StringlVariable = Coder ZeroBoolVariable = True IntlVariable = 13 
    }

    void OnApplicationQuit()
    {
        closeClient();
        if (m_gate != null) m_gate.Abort();
    }

    void closeClient()
    {
        if(m_client != null)
        {
            m_client.Close();
            m_client = null;
        }
    }

    public void Send()
    {
        //Debug.Log("client send");
        try
        {
            //SetSendPacket();

            byte[] sendPacket = StructToByteArray(m_packet);
            //m_client.Send(sendPacket, 0, sendPacket.Length, SocketFlags.None);
            m_client.BeginSend(sendPacket, 0, sendPacket.Length, 0, new AsyncCallback(SendCallback), m_client);
        }

        catch (Exception ex)
        {
            Debug.Log(ex.ToString());
            return;
        }
    }

    void SendCallback(IAsyncResult ar)
    {
        try
        {
            // Retrieve the socket from the state object.  
            Socket client = (Socket)ar.AsyncState;

            // Complete sending the data to the remote device.  
            int bytesSent = client.EndSend(ar);

            // Signal that all bytes have been sent.  
            sendDone.Set();
        }
        catch (Exception e)
        {
            Debug.Log(e.ToString());
        }
    }

    void SetSendPacket()
    {
        /*
        m_packet.m_BoolVariable = true;
        m_packet.m_IntVariable = 13;
        m_packet.m_IntArray = new int[2];
        m_packet.m_IntArray[0] = 7;
        m_packet.m_IntArray[1] = 47;
        m_packet.m_FloatlVariable = 2020;
        m_packet.m_StringlVariable = "Coder Zero";
        */
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

---

```c#
using System;
using System.Runtime.InteropServices;
using System.Net.Sockets;
using System.Text;

public class GunaStateObject
{
    // Size of receive buffer.  
    public const int BufferSize = 1024;

    // Receive buffer.  
    public byte[] buffer = new byte[BufferSize];

    // Received data string.
    public StringBuilder sb = new StringBuilder();

    // Client socket.
    public Socket workSocket = null;
}

[StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi, Pack = 1)]
[Serializable]
public struct GunaPacket
{
    public const int VIDEO_STOP = 0;
    public const int VIDEO_PLAY = 1;
    public const int VIDEO_PAUSE = 2;
    /*
    [MarshalAs(UnmanagedType.Bool)]
    public bool m_BoolVariable;
    public int m_IntVariable;
    [MarshalAs(UnmanagedType.ByValArray, SizeConst = 2)]
    public int[] m_IntArray;
    public float m_FloatlVariable;
    [MarshalAs(UnmanagedType.ByValTStr, SizeConst = 32)]
    public string m_StringlVariable;
    */
    public int m_VideoState;
    public double m_VideoSeeks;
    public int m_MideaReference_index;
    public int m_animation_index;
}

```

---

```c#
using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using System.Net;
using System.Net.NetworkInformation;
using System.Net.Sockets;

public class ServerUiManager : MonoBehaviour
{
    public static string server_ip = "127.0.0.1";
    public static int server_port = 50002;
    public Text global_ip_text;
    public Text local_ip_text;
    public InputField server_ip_input;
    public InputField server_port_input;
    void Awake()
    {
        global_ip_text.text = "global ip : " + GetExternalIPAddress();
        local_ip_text.text = "local ip : " + GetLocalIPAddress();
        //Debug.Log("[global_ipv4:" + GetExternalIPAddress() + "]");
        //Debug.Log("[local_ipv4:" + GetLocalIPAddress() + "]");
        getPlayerPrefs();
    }

    private void getPlayerPrefs()
    {
        //Debug.Log("PlayerPrefs setting");
        if (PlayerPrefs.HasKey("server_ip"))
        {
            //Debug.Log("server_ip:" + PlayerPrefs.GetString("server_ip"));
            server_ip_input.text = PlayerPrefs.GetString("server_ip");
            server_ip = PlayerPrefs.GetString("server_ip");
        }
        if (PlayerPrefs.HasKey("server_port"))
        {
            //Debug.Log("server_port:" + PlayerPrefs.GetString("server_port"));
            server_port_input.text = PlayerPrefs.GetString("server_port");
            server_port = int.Parse(PlayerPrefs.GetString("server_port"));
        }
    }
    private void setPlayerPrefs()
    {
        PlayerPrefs.SetString("server_ip", server_ip_input.text);
        PlayerPrefs.SetString("server_port", server_port_input.text);
    }

    public void SaveIpPort()
    {
        /*
        Debug.Log(server_ip_input.text);
        Debug.Log(server_port_input.text);
        */
        setPlayerPrefs();
        getPlayerPrefs();
    }

    public string GetLocalIPAddress()
    {
        var host = Dns.GetHostEntry(Dns.GetHostName());
        foreach (var ip in host.AddressList)
        {
            if (ip.AddressFamily == AddressFamily.InterNetwork)
            {
                return ip.ToString();
            }
        }
        throw new System.Exception("No network adapters with an IPv4 address in the system!");
    }

    public string GetExternalIPAddress()
    {
        string externalip = new WebClient().DownloadString("http://ipinfo.io/ip").Trim(); //http://icanhazip.com
        if (String.IsNullOrWhiteSpace(externalip))
        {
            //Debug.Log("global ip is null");
            externalip = GetLocalIPAddress();//null경우 Get Internal IP를 가져오게 한다.
        }
        return externalip;
    }
}

```