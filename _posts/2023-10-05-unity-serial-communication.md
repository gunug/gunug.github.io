---
layout: post
title: unity serial communication 유니티 시리얼통신
category: unity3d
tags: c# simple-code 
---

# unity serial communication 유니티 시리얼통신
* 출처 : https://forum.unity.com/threads/serial-communication-between-unity-5-and-arduino.331005/
* Change the API Compatibility Level from ".NET 2.0 Subset" to ".NET 2.0" in Player Settings.
* File > Build Setting > Player Setting > Other Settings > Configuration > Api Compatibility Lavel > .NET 2.0

---

```c#
using System.IO.ports;

public SerialPort serialPort;
public void Start(){
    foreach(string str in SerialPort.GetPortNames())
    {
        Debug.Log(str);
    }
}
* System.IO.ports 없음
* Api Compatibility Level : .NET 4.x
```

---

```c#
 using UnityEngine;
 using System.Collections;
 using System.IO;
 using System.IO.Ports;
 using System.Threading;
 using System.Collections.Generic;
  
 public class serialExample : MonoBehaviour
 {
     //public static SerialPort serialPort = new SerialPort("/dev/tty.usbmodem1411", 9600, Parity.None, 8, StopBits.One);
     public static SerialPort serialPort = new SerialPort("\\\\.\\COM13", 9600, Parity.None, 8, StopBits.One);
     public static string strIn;
  
     void Start()
     {
         GetPortNames();
         OpenConnection();
     }
  
     void Update()
     {
         serialPort.Write("1");
     }
  
     void GetPortNames()
     {
         int p = (int)System.Environment.OSVersion.Platform;
         List<string> serial_ports = new List<string>();
    
         if(p == 4 || p == 128 || p == 6)
         {
             string[] ttys = Directory.GetFiles("/dev/", "tty.*");
             foreach(string dev in ttys)
             {
                 if (dev.StartsWith("/dev/tty.*"))
                     serial_ports.Add(dev);
                 Debug.Log (System.String.Format(dev));
             }
         }
     }
  
     public void OpenConnection()
     {
         if(serialPort != null)
         {
             if(serialPort.IsOpen)
             {
                 serialPort.Close();
                 Debug.Log("Closing port, because it was already open!");
             }
             else
             {
                 serialPort.Open();
                 serialPort.ReadTimeout = 50;
                 Debug.Log("Port Opened!");
             }
          }
          else
          {
             if(serialPort.IsOpen)
             {
                 print("Port is already open");
             }
             else
             {
                 print("Port == null");
             }
         }
     }
        
     void OnApplicationQuit()
     {
         serialPort.Close();
         Debug.Log("Port closed!");
     }
 }
```

## try catch  추가하여 string 데이터 받아오기

```c#
 using System.Collections;
 using System.Collections.Generic;
 using UnityEngine;
 using System.Collections;
 using System.IO;
 using System.IO.Ports;
 using System.Threading;
 using System.Collections.Generic;
 
 public class RecoilGun : MonoBehaviour {
      //public static SerialPort serialPort = new SerialPort("/dev/tty.usbmodem1411", 9600, Parity.None, 8, StopBits.One);
      public static SerialPort serialPort = new SerialPort("\\\\.\\COM13", 9600, Parity.None, 8, StopBits.One);
      public static string strIn;
 
     void Start()
     {
         //GetPortNames();
         OpenConnection();
     }

    private string tmp;
    void Update()
    {
        try
        {
            if (serialPort.IsOpen)
            {
                tmp = serialPort.ReadLine();
                Debug.Log(tmp);
                process_data(tmp);
                serialPort.ReadTimeout = 30;
            }
        }
        catch (System.TimeoutException e)
        {
            //Debug.Log(e);
        }
        //serialPort.Write("1");
    }

    void process_data(string tmp)
    {
        
    }

    void GetPortNames()
    {
        int p = (int)System.Environment.OSVersion.Platform;
        List<string> serial_ports = new List<string>();

        if (p == 4 || p == 128 || p == 6)
        {
            string[] ttys = Directory.GetFiles("/dev/", "tty.*");
            foreach (string dev in ttys)
            {
                if (dev.StartsWith("/dev/tty.*"))
                    serial_ports.Add(dev);
                Debug.Log(System.String.Format(dev));
            }
        }
    }

    public void OpenConnection()
    {
        if (serialPort != null)
        {
            if (serialPort.IsOpen)
            {
                serialPort.Close();
                Debug.Log("Closing port, because it was already open!");
            }
            else
            {
                serialPort.Open();
                serialPort.ReadTimeout = 50;
                Debug.Log("Port Opened!");
            }
        }
        else
        {
            if (serialPort.IsOpen)
            {
                print("Port is already open");
            }
            else
            {
                print("Port == null");
            }
        }
    }

    void OnApplicationQuit()
    {
        serialPort.Close();
        Debug.Log("Port closed!");
    }
}
```

## 제대로 되는 시리얼 통신
* https://answers.unity.com/questions/400222/arduino-with-unity-bad-framerate.html
* Unity 는 Mono 베이스이기 때문에 리시브 이벤트 핸들러가 동작하지 않는다 -_-;
* https://code-examples.net/ko/q/1c9f1ef
* 위 문제때문에 시리얼통신 누적으로 딜레이가 생겼는데. 얼추 30FPS로 맞춰서 전송해서 해결함

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.Collections;
using System.IO;
using System.IO.Ports;
using System.Threading;
using System.Collections.Generic;
using UnityEngine.UI;
using UnityEngine.Events;
using System.Text.RegularExpressions;

public class RecoilGun : MonoBehaviour {
    //public static SerialPort serialPort = new SerialPort("/dev/tty.usbmodem1411", 9600, Parity.None, 8, StopBits.One);
    public static SerialPort stream = new SerialPort("\\\\.\\COM13", 9600, Parity.None, 8, StopBits.One);
    public static string strIn;
    
    public GameObject slider_x;
    public GameObject slider_y;
    public GameObject joy_bt;
    public GameObject bt1;
    public GameObject bt2;
    public GameObject bt3;
    public GameObject bt4;

    private Slider slider_x_;
    private Slider slider_y_;
    private Toggle joy_bt_;
    private Toggle bt1_;
    private Toggle bt2_;
    private Toggle bt3_;
    private Toggle bt4_;
    void Start()
    {
        //GetPortNames();
        OpenConnection();
        slider_x_ = slider_x.GetComponent<Slider>();
        slider_y_ = slider_y.GetComponent<Slider>();
        joy_bt_ = joy_bt.GetComponent<Toggle>();
        bt1_ = bt1.GetComponent<Toggle>();
        bt2_ = bt2.GetComponent<Toggle>();
        bt3_ = bt3.GetComponent<Toggle>();
        bt4_ = bt4.GetComponent<Toggle>();
        stream.ErrorReceived += DataErrorReceivedHandler;
        /*
        try
        {
            stream.Open();
            stream.DataReceived += DataReceivedHandler;
        }
        catch (System.TimeoutException e)
        {
            Debug.Log("Could not open serial port: " + e.Message);

        }
        */
    }
    private string tmp;
    void Update()
    {
        try
        {
            if (stream.IsOpen)
            {
                string pre_tmp = null;
                tmp = null;
                /*
                do {
                    tmp = null;
                    pre_tmp = tmp;
                    tmp = stream.ReadLine();
                    Debug.Log(tmp);
                } while (tmp != null);
                */
                tmp = stream.ReadLine();
                //while (stream.ReadByte() != null) { }
                //pre_tmp = find_last_one(tmp);
                Debug.Log("tmp:"+tmp);
                process_data(tmp);
                //stream.ReadTimeout = 30;
            }
        }
        catch (System.Exception e)
        {
            Debug.Log(e);
        }
        //serialPort.Write("1");
    }
    private string find_last_one(string raw_data)
    {
        string result_data = "nope";
        Debug.Log("raw_data:"+ raw_data);
        string pattern = "^s(.*)e$";
        Match mat;
        mat = Regex.Match(raw_data, pattern);
        Debug.Log("mat.Length:"+mat.Length);
        Debug.Log("mat.Value:"+ mat.Value);
        result_data = mat.Value;
        return mat.Value;
    }
    public void OpenConnection()
    {
        if (stream != null)
        {
            if (stream.IsOpen)
            {
                stream.Close();
                Debug.Log("Closing port, because it was already open!");
            }
            else
            {
                stream.DtrEnable = true;    // Data-terminal-ready
                stream.RtsEnable = true;    // Request-to-send
                //stream.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
                stream.DataReceived += DataReceivedHandler;
                stream.Open();
                stream.ReadTimeout = 50;
                Debug.Log("Port Opened!");
                //stream.DataReceived += new SerialDataReceivedEventHandler(DataReceivedHandler);
                //stream.DataReceived += DataReceivedHandler;
            }
        }
        else
        {
            if (stream.IsOpen)
            {
                print("Port is already open");
            }
            else
            {
                print("Port == null");
            }
        }
    }
    private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
    {
        Debug.Log("why do not");
        SerialPort sp = (SerialPort)sender;
        //serialPort.ReadTimeout = 30;
        try
        {
            string b = sp.ReadLine();
            Debug.Log(b);
            process_data(b);
        }
        catch (System.TimeoutException ex)
        {
            Debug.Log(ex);
        }
    }

    private void DataErrorReceivedHandler(object sender,SerialErrorReceivedEventArgs e)
    {
        Debug.Log("Serial port error:"+e.EventType.ToString("G"));
    }

    private string[] datas;
    void process_data(string tmp)
    {
        Debug.Log("why do not?");
        datas = tmp.Split('|');
        //Debug.Log(datas[3]);
        // x,y,s bt1,bt2,bt3,bt4
        slider_x_.value = int.Parse(datas[0].Substring(1));
        slider_y_.value = int.Parse(datas[1]);
        joy_bt_.isOn = (datas[2]=="1");
        bt1_.isOn = (datas[3] == "1");
        bt2_.isOn = (datas[4] == "1");
        bt3_.isOn = (datas[5] == "1");
        bt4_.isOn = (datas[6] == "1]");
    }

    public void send_recoil()
    {
        stream.Write("1");
        stream.DiscardOutBuffer();
        Debug.Log("send recoil request");
    }

    void GetPortNames()
    {
        int p = (int)System.Environment.OSVersion.Platform;
        List<string> serial_ports = new List<string>();

        if (p == 4 || p == 128 || p == 6)
        {
            string[] ttys = Directory.GetFiles("/dev/", "tty.*");
            foreach (string dev in ttys)
            {
                if (dev.StartsWith("/dev/tty.*"))
                    serial_ports.Add(dev);
                Debug.Log(System.String.Format(dev));
            }
        }
    }

    void OnApplicationQuit()
    {
        stream.DiscardOutBuffer();
        stream.DiscardInBuffer();
        stream.Close();
        stream.DataReceived -= new SerialDataReceivedEventHandler(DataReceivedHandler);
        stream = null;
        Debug.Log("Port closed!");
    }
}
```

## 스레드를 이용한 시리얼통신
* 어쨋든 시리얼이 한번 누적되기 시작하면 딜레이누적으로 문제가 생긴다
* 스레드를 이용하여 데이터를 모두 덜어낼 수 있어야 문제가 없다.

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;
using System.Threading; //쓰레드를 쓰겠다고 선언.

public class SerialPortReporter : MonoBehaviour
{
    static private SerialPort my_serial;
    public string portName = "\\\\.\\COM35";
    private int baudRate = 57600;
    private string[] chars = new string[20];
    [Range(0, 1)]
    public int[] digital_pins = new int[14];
    [Range(0, 1)]
    public float[] analog_pins = new float[6];
    void Start()
    {
        foreach (string str in SerialPort.GetPortNames()) { Debug.Log(string.Format("Existing COM port: {0}", str)); }
        my_serial = new SerialPort(portName, baudRate);
        try
        {
            my_serial.DataReceived += DataReceivedHandler;
            my_serial.ReadTimeout = 10;
            my_serial.Open();
            Debug.Log("open");
        }
        catch (System.TimeoutException e)
        {
            Debug.Log("Could not open serial port: " + e.Message);

        }

        Debug.Log("시작");
        ThreadStart th = new ThreadStart(work); //1.work메소드를 위임. 
        t = new Thread(th);                     //2.쓰레드생성.
        t.Start();                              //3.시작 
        Debug.Log("끝!");
    }
    private Thread t;
    static private string RawData = "";
    public static void work() {
        while (my_serial.IsOpen)
        {
            string value = my_serial.ReadLine(); //Read the information
            value = value.Trim(); //remove whitespace around our values
            RawData = value;
            //Debug.Log("ReadLine():" + value);
        }
    }

    private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
    {
        Debug.Log("is working?");
        Debug.Log(e);
    }

    private string tmp;
    private void Update()
    {
        //Debug.Log("RawData:" + RawData);
        chars = RawData.Split('|');
        for (int i = 0; i < 14; i++)
        {
            //Debug.Log("chars[i]:" + chars[i]);
            digital_pins[i] = int.Parse(chars[i]);
        }
        for (int i=0; i<6; i++)
        {
            analog_pins[i] = float.Parse(chars[14+i])/1023;
        }
    }

    private string[] datas;
    void process_data(string tmp)
    {
        //데이터를 처리합니다.
        datas = tmp.Split('|');
        //Debug.Log(datas[3]);
        // x,y,s bt1,bt2,bt3,bt4
    }

    void OnApplicationQuit()
    {
        Debug.Log("Application ending after " + Time.time + " seconds");
        t.Abort(); //강제종료
        my_serial.Close();
    }
}
```

## 통신속도차이에 의한 timeout을 해소한 버전
* nano보드는 통신속도가 느려서(그마저도 최신 부트로더에서는 해결되었다던데..) unity쪽에서 timeout을 길게 기다려주지 않으면 통신에러가 난다.
* 아래는 무한정 기다리도록 하여 타임아웃이 나지 않도록 한 버전

```c#
 using System.Collections;
 using System.Collections.Generic;
 using UnityEngine;
 using System.IO.Ports;
 using System.Threading; //쓰레드를 쓰겠다고 선언.
 using System;
 
 public class SerialPortReporter : MonoBehaviour
 {
     static private SerialPort my_serial;
     public string portName = "\\\\.\\COM35";
     private int baudRate = 57600;
     private string[] chars = new string[20];
     [Range(0, 1)]
     public int[] digital_pins = new int[14]; //디지털핀 14종
     [Range(0, 1)]
     public float[] analog_pins = new float[6]; //아날로그핀 6종
     void Start()
     {
         foreach (string str in SerialPort.GetPortNames()) {
             Debug.Log(string.Format("Existing COM port: {0}", str));
        }
         my_serial = new SerialPort(portName, baudRate);
         
         try
         {
             my_serial.DataReceived += DataReceivedHandler;
             my_serial.ReadTimeout = 100;
             my_serial.Open();
             Debug.Log("open");
         }
         catch (System.TimeoutException e)
         {
             Debug.Log("Could not open serial port: " + e.Message);
 
         }
 
         Debug.Log("시작");
         ThreadStart th = new ThreadStart(work); //1.work메소드를 위임. 
         t = new Thread(th);                     //2.쓰레드생성.
         t.Start();                              //3.시작 
         Debug.Log("끝!");
     }
     private Thread t;
     static private string RawData = "";
     public static void work()
     {
         while (my_serial.IsOpen)
         {
             //Debug.Log("my_serial.IsOpen:" + my_serial.IsOpen);
             string value = "";
             try
             {
                 value = my_serial.ReadLine(); //Read the information
                 my_serial.ReadTimeout = SerialPort.InfiniteTimeout; //타임아웃설정을 길게잡아야 짧게 기다리고 포기하지 않는다.
                 //nano쪽 시리얼 통신속도가 느려서 unity가 기다리지 않고 포기하는 상황이 자주 발생함
                 //value = my_serial.ReadByte();
                 //Debug.Log("my_serial.ReadLine():" + value);
                 value = value.Trim(); //remove whitespace around our values
                 RawData = value;
                 //Debug.Log("ReadLine():" + value);
             }
             catch (Exception e)
             {
                 Debug.Log("Exception:" + e);
             }
         }
         Debug.Log("work end");
     }
 
     private void DataReceivedHandler(object sender, SerialDataReceivedEventArgs e)
     {
         Debug.Log("is working?");
         Debug.Log(e);
     }
 
     private string tmp;
     private void Update()
     {
         //Debug.Log("RawData:" + RawData);
         if (RawData == "") return;
         chars = RawData.Split('|');
         if (chars.Length < 21) return;
         for (int i = 0; i < 14; i++)
         {
             //Debug.Log("chars[i]:" + chars[i]);
             digital_pins[i] = int.Parse(chars[i]);
         }
         for (int i = 0; i < 6; i++)
         {
             analog_pins[i] = float.Parse(chars[14 + i]) / 1023;
         }
     }
 
     private string[] datas;
     void process_data(string tmp)
     {
         //데이터를 처리합니다.
         datas = tmp.Split('|');
         //Debug.Log(datas[3]);
         // x,y,s bt1,bt2,bt3,bt4
     }
 
     void OnApplicationQuit()
     {
         Debug.Log("Application ending after " + Time.time + " seconds");
         t.Abort(); //강제종료
         my_serial.Close();
     }
 }
```
* 통신 타임아웃을 무한으로 잡아놓으면. 통신이 끊기거나 무응답시 무한루프 발생.. 높은 값으로 고쳐야 합니다.

## 동권형 버전
* SerialCommunication.cs

```c#
using System;
using System.Threading;
using System.IO;
using System.IO.Ports;
using UnityEngine;
using DG.Tweening;

public class SerialCommunication : MonoBehaviour
{
    private ServerState state;
    private string[] availablePorts;
    private int availableCount;
    private int timeout = 1000;
    private int length = 3;
    private SerialPort port;
    private Thread thread;
    private SendData result;

    public static SerialCommunication Instance
    {
        get;
        private set;
    }

    private void Awake()
    {
        if (Instance == null)
        {
            Instance = this;
        }

        this.state = ServerState.ready;
    }

    private void Start()
    {
        StartCommunication();
    }

    private void OnDestroy()
    {
        StopCommunication();
    }

    // start serialport
    private void StartCommunication()
    {
        this.availableCount = 0;
        availablePorts = SerialPort.GetPortNames();
        state = ServerState.start;

        if(availablePorts.Length > 0)
        {
            StartAvablePort();
            StartReadThred();
        } else
        {
            Debug.Log("serial port : Not Avable Port");
        }
    }

    // close 
    private void StopCommunication()
    {
        if (port != null && port.IsOpen)
        {
            state = ServerState.stop;
            port.Close();
            port = null;
        }

        if (thread != null && thread.IsAlive)
        {
            thread.Abort();
            thread = null;
        }
    }

    private void StartReadThred()
    {
        if (thread != null && thread.IsAlive)
        {
            thread.Abort();
            thread = null;
        }
        thread = new Thread(ReadPort);
        thread.Start();
    }

    // open serialport
    private void StartAvablePort()
    {
        try
        {
            if (port != null && port.IsOpen) StopCommunication();

            state = ServerState.running;

            port = new SerialPort(this.availablePorts[this.availableCount]);
            port.BaudRate = 2400;
            port.DataBits = 8;
            port.Parity = Parity.None;
            port.Handshake = Handshake.None;
            port.StopBits = StopBits.One;
            port.Open();
            port.ReadTimeout = timeout;
            port.WriteTimeout = timeout;
            
            SendSerial("success");
            Debug.Log(string.Format("[OPEN] serial port : {0}", this.availablePorts[this.availableCount]));
        }
        catch (IOException ex)
        {
            Debug.Log(string.Format("[IOERROR] {0}, avable count : {1}", ex.Message, this.availableCount));
            DOVirtual.DelayedCall(0.5f, NextPortOpen);
        
        }
        catch (Exception ex)
        {
            Debug.Log(string.Format("[ERROR] {0}", ex.Message));
        }
    }

    // next port
    private void NextPortOpen()
    {
        state = ServerState.start;
        this.availableCount++;
        if (this.availableCount >= this.availablePorts.Length)
        {
            this.availableCount = 0;
        }
        this.StartAvablePort();
    }

    // write
    public void SendSerial(string message)
    {
        if (port.IsOpen)
        {
            string msg = message;
            try
            {
                port.Write(msg);
                msg = "";
            }
            catch (TimeoutException exception)
            {
                string exceptionMessage = exception.Message;
            }
        }
    }

    // read
    private void ReadPort()
    {
        while(state == ServerState.running)
        {
            if (port != null && port.IsOpen)
            {
                string msg;
                try
                {
                    msg = port.ReadLine();
                    print(msg);
                    //if (!string.IsNullOrEmpty(msg))
                    //{
                    //    print(msg);
                    //    //result = new SendData(msg);
                    //    //print(result.ToString());

                    //    if(result.model == "DK")
                    //    {

                    // 프로토콜이 맞지 않을 경우 다른 포트로 연결 시도

                    /**********************************************
                    state = ServerState.start;
                    DOVirtual.DelayedCall(1.0f, () =>
                    {
                        StopCommunication();
                        DOVirtual.DelayedCall(1.0f, () =>
                        {
                            StartReadThred();
                            NextPortOpen();
                        });

                        state = ServerState.running;
                    });
                    **********************************************/

                    //    }
                    //}
                }
                catch (TimeoutException exception)
                {
                    //Debug.Log(string.Format("[TIMEOUT ERROR] {0}", exception.Message));
                }
                catch (Exception exception)
                {
                    Debug.Log(string.Format("[ERROR] {0}", exception.Message));
                }
            }
            Thread.Sleep(500);
        }
    }
}
```

* SandData.cs

```c#
public struct SendData
{
    public char start;
    public string model;
    public int num;
    public char end;

    public SendData(string model, int num)
    {
        this.start = '[';
        this.model = model;
        this.num = num;
        this.end = ']';
    }

    public SendData(string data)
    {
        string newData = data.Replace("\r", "").Replace("\n", "").Replace(" ", "");
        this.start = '[';
        this.model = newData.Substring(1, 2);
        this.num = int.Parse(newData.Substring(4, 1));
        this.end = ']';
    }

    public override string ToString()
    {
        return string.Format("{0}{1}_{2}{3}", this.start, this.model, this.num, this.end);
    }
}
```

* ServerState

```c#
public enum ServerState
{
    ready,
    start,
    running,
    stop
}
```