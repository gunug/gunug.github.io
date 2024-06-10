---
layout: post
title: asset arduino bluetooth api
category: unity-asset
tags: 
---

* <https://assetstore.unity.com/packages/tools/input-management/arduino-bluetooth-plugin-98960#description>
* 본 플러그인을 받으신 후에는 "BluetoothAPI" 폴더에서 주요 에셋 폴더로 PLUGIN 폴더를 이동하십시오. 본 플러그인은 Unity 2018.3 이상을 지원합니다.

* <https://studylib.net/doc/25685860/arduino-unity-plugin> 플러그인 관련문서
  
```c#
ScanNearbyDevices()
•Scan for nearby Bluetooth devices
•Return true if scan has started
•Calling this function is a must when using BLE technology before connecting to a BLE device.
•Invokes 1 event:i.OnScanEnded: returns a list of devices found
•Not available for Windows PC(Desktop App)
• Windows PC(데스크톱 앱)에서는 사용할 수 없습니다.
```

```c#
using System.Collections.Generic;
using UnityEngine;
using TMPro;
using ArduinoBluetoothAPI;
using System;

#if UNITY_ANDROID
    using UnityEngine.Android;
#endif

public class BLEServicesManagerCustom : MonoBehaviour
{
    private BluetoothHelper bluetoothHelper;
    private float timer;
    //public RotateTest rt;

    //string SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
    //string SERVICE_UUID = "0xFFE0";
    string SERVICE_UUID = "0000FFE0-0000-1000-8000-00805F9B34FB";
    //string CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";
    //string CHARACTERISTIC_UUID = "0xFFE1";
    string CHARACTERISTIC_UUID = "0000FFE1-0000-1000-8000-00805F9B34FB";
    void Start()
    {

    #if UNITY_ANDROID
        //var callbacks = new PermissionCallbacks();
        //callbacks.PermissionDenied += PermissionCallbacks_PermissionDenied;
        //callbacks.PermissionGranted += PermissionCallbacks_PermissionGranted;
        //callbacks.PermissionDeniedAndDontAskAgain += PermissionCallbacks_PermissionDeniedAndDontAskAgain;
        if (!Permission.HasUserAuthorizedPermission("android.permission.BLUETOOTH_SCAN"))
        {
            Permission.RequestUserPermission("android.permission.BLUETOOTH_SCAN");
        }
        if (!Permission.HasUserAuthorizedPermission("android.permission.BLUETOOTH_ADVERTISE"))
        {
            Permission.RequestUserPermission("android.permission.BLUETOOTH_ADVERTISE");
        }
        if (!Permission.HasUserAuthorizedPermission("android.permission.BLUETOOTH_CONNECT"))
        {
            Permission.RequestUserPermission("android.permission.BLUETOOTH_CONNECT");
        }
        if (!Permission.HasUserAuthorizedPermission("android.permission.ACCESS_FINE_LOCATION"))
        {
            Permission.RequestUserPermission("android.permission.ACCESS_FINE_LOCATION");
        }
    #endif
        setupBluetooth();
        timer = 0;
    }

    private void OnScanEnded(BluetoothHelper helper, LinkedList<BluetoothDevice> devices)
    {
        Debug.Log("Found " + devices.Count);
        data_string += "Found " + devices.Count + "\n";
        if (devices.Count == 0)
        {
            bluetoothHelper.ScanNearbyDevices();
            return;
        }

        foreach (var d in devices)
        {
            Debug.Log(d.DeviceName);
        }

        try
        {
            bluetoothHelper.setDeviceName("Motion0002");
            bluetoothHelper.Connect();
            Debug.Log("Connecting");
            data_string += "Connecting \n";
            //contxt.text = "Connect";
        }
        catch (Exception ex)
        {
            bluetoothHelper.ScanNearbyDevices();
            Debug.Log(ex.Message);
            //contxt.text = ex.Message;
        }

    }

    void OnDestroy()
    {
        if (bluetoothHelper != null)
            bluetoothHelper.Disconnect();
    }

    void Update()
    {
        if (bluetoothHelper == null)
            return;
        if (!bluetoothHelper.isConnected())
            return;
        timer += Time.deltaTime;

        if (timer < 5)
            return;
        timer = 0;
        read();
        //sendData();
    }

    /*
    void sendData(){
        // Debug.Log("Sending");
        // BluetoothHelperCharacteristic ch = new BluetoothHelperCharacteristic("FFE1");
        // ch.setService("FFE0"); //this line is mandatory!!!
        // bluetoothHelper.WriteCharacteristic(ch, new byte[]{0x44, 0x55, 0xff});

        Debug.Log("Sending");
        BluetoothHelperCharacteristic ch = new BluetoothHelperCharacteristic(CHARACTERISTIC_UUID);
        ch.setService(SERVICE_UUID); //this line is mandatory!!!
        //bluetoothHelper.WriteCharacteristic(ch, "1234");
    }
    */

    void read()
    {
        BluetoothHelperCharacteristic ch = new BluetoothHelperCharacteristic(CHARACTERISTIC_UUID);
        ch.setService(SERVICE_UUID);//this line is mandatory!!!
        bluetoothHelper.ReadCharacteristic(ch);
    }

    void PermissionCallbacks_PermissionDeniedAndDontAskAgain(string permissionName)
    {
        Debug.Log($"{permissionName} PermissionDeniedAndDontAskAgain");
    }

    void PermissionCallbacks_PermissionDenied(string permissionName)
    {
        Debug.Log($"{permissionName} PermissionCallbacks_PermissionDenied");
    }

    void PermissionCallbacks_PermissionGranted(string permissionName)
    {
        Debug.Log($"{permissionName} PermissionCallbacks_PermissionGranted");

        setupBluetooth();
    }

    void setupBluetooth()
    {
        try
        {
            if (bluetoothHelper != null) return;
            Debug.Log("HI");
            data_string += "HI \n";

            BluetoothHelper.BLE = true;  //use Bluetooth Low Energy Technology
            bluetoothHelper = BluetoothHelper.GetInstance();
            bluetoothHelper.OnConnected += (helper) =>
            {
                List<BluetoothHelperService> services = helper.getGattServices();
                foreach (BluetoothHelperService s in services)
                {
                    Debug.Log("Service : " + s.getName());
                    foreach (BluetoothHelperCharacteristic item in s.getCharacteristics())
                    {
                        Debug.Log(item.getName());
                    }
                }

                Debug.Log("Connected");
                data_string += "Connected \n";
                //contxt.text = "No Connect";
                BluetoothHelperCharacteristic c = new BluetoothHelperCharacteristic(CHARACTERISTIC_UUID);
                c.setService(SERVICE_UUID);
                bluetoothHelper.Subscribe(c);
                //sendData();
            };
            bluetoothHelper.OnConnectionFailed += (helper) =>
            {
                Debug.Log("Connection failed");
                //contxt.text = "No Connect";
            };
            bluetoothHelper.OnScanEnded += OnScanEnded;
            bluetoothHelper.OnServiceNotFound += (helper, serviceName) =>
            {
                Debug.Log(serviceName);
            };
            bluetoothHelper.OnCharacteristicNotFound += (helper, serviceName, characteristicName) =>
            {
                Debug.Log(characteristicName);
            };
            bluetoothHelper.OnCharacteristicChanged += (helper, value, characteristic) =>
            {
                //�����Ͱ� ���۵Ǹ� �޴� �κ�
                //Debug.Log(characteristic.getName());
                //Debug.Log(value[0]);
                Debug.Log("Received data from " + characteristic.getName());
                Debug.Log(BitConverter.ToString(value));
                string receivedString = System.Text.Encoding.UTF8.GetString(value);
                string[] values = receivedString.Split(',');

                //values[0] switch1
                //values[1] switch2
                //values[2] battery
                float roll = Convert.ToSingle(values[3]);
                float pitch = Convert.ToSingle(values[4]);
                float yaw = Convert.ToSingle(values[5]);

                // rt.FirstValue(roll, pitch, yaw);
                // rt.BLERot(roll, pitch, yaw);
                // rt.setBLEMoveData(roll, pitch, yaw);

                data_string = "start//";
                data_string += value.Length;
                data_string += "\n /str/";
                data_string += receivedString;
                data_string += "\n /raw/";
                data_string += value.ToString();
                data_string += "\n //";
                data_string += BitConverter.ToString(value);
                data_string += "\n /rpy/";
                data_string += roll+":"+pitch+":"+yaw;

                float x = Convert.ToSingle(values[6]);
                float y = Convert.ToSingle(values[7]);
                float z = Convert.ToSingle(values[8]);
                data_string += "\n /xyz/";
                data_string += x+":"+y+":"+z;

                //data_string = rt.convertData(roll, pitch, yaw);
                //data_string = rt.BLERot(roll, pitch, yaw);
                //
            };

            // BluetoothHelperService service = new BluetoothHelperService("FFE0");
            // service.addCharacteristic(new BluetoothHelperCharacteristic("FFE1"));
            // BluetoothHelperService service2 = new BluetoothHelperService("180A");
            // service.addCharacteristic(new BluetoothHelperCharacteristic("2A24"));

            // BluetoothHelperService service = new BluetoothHelperService(SERVICE_UUID);
            // BluetoothHelperCharacteristic ch = new BluetoothHelperCharacteristic(CHARACTERISTIC_UUID);
            // service.addCharacteristic(ch);

            //bluetoothHelper.Subscribe(service);
            //bluetoothHelper.setDeviceName("Motion0002");

            //BluetoothHelperService service2 = new BluetoothHelperService("180A");
            //service.addCharacteristic(new BluetoothHelperCharacteristic("2A24"));
            //bluetoothHelper.Subscribe(service);
            //bluetoothHelper.Subscribe(service2);
            Debug.Log("Scanning");
            data_string += "Scanning \n";
            bluetoothHelper.ScanNearbyDevices();
        }
        catch (Exception ex)
        {
            Debug.Log(ex.StackTrace);
            data_string += ex.StackTrace + "\n";
        }
    }
    
    private int font_size = 40;
    private string data_string = "default string \n";

    private void OnGUI(){
        GUIStyle LabelStyle = new GUIStyle(GUI.skin.label);
	    LabelStyle.fontSize = font_size;
        GUIStyle TextAreaStyle = new GUIStyle(GUI.skin.textArea);
        TextAreaStyle.fontSize = font_size;
        GUIStyle verticalScrollbar = GUI.skin.verticalScrollbar;

        GUILayout.BeginVertical();
            GUILayout.Label(data_string, TextAreaStyle);
        GUILayout.EndVertical();
    }
}
```
* 유니티쪽 소스코드
* .Net framework

---

*  BLE는 패킷당 최대 20바이트의 전송을 허용

---

# 값 누락 문제
* BLE bluetooth의 경우 패킷당 최대 20바이트 전송을 하기 때문에 값이 누락됩니다.
* 디바이스 및 유니티가 전송 방식을 합의 하여 같이 수정해야합니다.

# 값이 상이한 문제
* 필요한 값과 실제 전달되고 있는 값이 상이하여 결과가 원하는 대로 나오지 않습니다.
* 값을 일방적으로 반영하여 드릴 수는 있으나 의미있는 결과가 나오지 않습니다.
* 실제 전달되고 있는 값을 연산하여 필요한 값으로 만들어서 전달해 주셔야합니다.

>
## 필요한 값
* 디바이스의 x,y,z 회전 각도 값 : 오일러 각
* 디바이스의 x,y,z 이동량 : 회전 각도 값이 반영된 이동량

>
## 실제 전달되고 있는 값
* 자이로센서 : x,y,z 회전 가속도 값
* 가속도센서 : x,y,z 직선 가속도 값
* 지자기센서 : x,y,z 자기장의 방향 성분

---

# 참고자료
* <https://youtu.be/zN89M_MjVKo>
* <https://youtu.be/L4WfHT_58Dg>
* MPU9250 library 써야하나
* <https://github.com/hideakitai/MPU9250>

```c++
//센서 로우 데이터를 통해 만들어진 회전량
float getRoll() const;
float getPitch() const;
float getYaw() const;

float getEulerX() const;
float getEulerY() const;
float getEulerZ() const;

//쿼터니언 (짐벌락 방지)
float getQuaternionX() const;
float getQuaternionY() const;
float getQuaternionZ() const;
float getQuaternionW() const;

//센서 로우 데이터
float getAccX() const;
float getAccY() const;
float getAccZ() const;
float getGyroX() const;
float getGyroY() const;
float getGyroZ() const;
float getMagX() const;
float getMagY() const;
float getMagZ() const;

//중력 성분을 제거한 선형 가속도
float getLinearAccX() const;
float getLinearAccY() const;
float getLinearAccZ() const;


```
Byte Size: 58
 1, 1,0.05,-0.04,-0.04,0.64,-0.90,0.20,-1620,-70,-773,4.13
Byte Size: 58
 1, 1,0.05,-0.04,-0.02,0.64,-0.90,0.20,-1635,-65,-788,4.14
Byte Size: 58
 1, 1,0.04,-0.04,-0.01,0.63,-0.91,0.20,-1613,-80,-757,4.14
Byte Size: 58
 1, 1,0.04,-0.03,-0.01,0.63,-0.91,0.20,-1632,-57,-770,4.13
Byte Size: 58
 1, 1,0.04,-0.04,-0.02,0.64,-0.91,0.20,-1603,-90,-786,4.14
Byte Size: 58
 1, 1,0.04,-0.04,-0.03,0.62,-0.91,0.19,-1632,-72,-767,4.14
Byte Size: 58
 1, 1,0.04,-0.04,-0.02,0.63,-0.89,0.19,-1635,-95,-757,4.14
Byte Size: 58
 1, 1,0.04,-0.03,-0.02,0.63,-0.91,0.19,-1613,-82,-757,4.13
Byte Size: 58
 1, 1,0.04,-0.03,-0.03,0.63,-0.91,0.20,-1645,-75,-755,4.12
Byte Size: 58
```

* 스위치(1, 1),자이로센서(0.04,-0.04,-0.03),가속도센서(0.64,-0.90,0.20),지자계센서(-1627,-75,-747),4.11