---
layout: post
title: unity esp32, lcd, mpu6050, ble bluetooth, source code 종합 소스코드
category: unity
tags:
---


# BlueToothManagerCustom
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
    public DataSetter ds;
    //string SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
    //string SERVICE_UUID = "0xFFE0";
    string SERVICE_UUID = "0000FFE0-0000-1000-8000-00805F9B34FB";
    //string CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";
    //string CHARACTERISTIC_UUID = "0xFFE1";
    string CHARACTERISTIC_UUID = "0000FFE1-0000-1000-8000-00805F9B34FB";

    private string switch1 = "0";
    private string switch2 = "0";
    private string q_x = "0";
    private string q_y = "0";
    private string q_z = "0";
    private string q_w = "0";
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
                data_string = "Received data from" + characteristic.getName() + "\n";
                Debug.Log(BitConverter.ToString(value));
                string receivedString = System.Text.Encoding.UTF8.GetString(value);
                //string[] values = receivedString.Split(',');
                data_string = "receivedString" + receivedString + "\n";

                switch1 = receivedString.ToString().Substring(0, 1);
                switch2 = receivedString.ToString().Substring(1, 1);
                q_x = receivedString.ToString().Substring(2, 4);
                q_y = receivedString.ToString().Substring(6, 4);
                q_z = receivedString.ToString().Substring(10, 4);
                q_w = receivedString.ToString().Substring(14, 4);
                data_string += "switch1 : " + switch1 + "\n";
                data_string += "switch2 : " + switch2 + "\n";
                data_string += "q_x : " + q_x + "\n";
                data_string += "q_y : " + q_y + "\n";
                data_string += "q_z : " + q_z + "\n";
                data_string += "q_w : " + q_w + "\n";
                
                if(switch2 == "1")
                {
                    ds.switch2_clicked(false);
                }
                else
                {
                    ds.switch2_clicked(true);
                }
                if(switch1 == "1")
                {
                    ds.switch1_clicked(false);
                }
                else
                {
                    ds.switch1_clicked(true);
                }
                data_string += "switch1 : " + switch1 + "\n";
                data_string += "switch2 : " + switch2 + "\n";
                //values[0] switch1
                //values[1] switch2
                //values[2] battery
                // float x = Convert.ToSingle(values[2]);
                // float y = Convert.ToSingle(values[3]);
                // float z = Convert.ToSingle(values[4]);
                // float w = Convert.ToSingle(values[5]);

                float x = Convert.ToSingle(q_x)/1000-2;
                float y = Convert.ToSingle(q_y)/1000-2;
                float z = Convert.ToSingle(q_z)/1000-2;
                float w = Convert.ToSingle(q_w)/1000-2;

                // rt.FirstValue(roll, pitch, yaw);
                // rt.BLERot(roll, pitch, yaw);
                // rt.setBLEMoveData(roll, pitch, yaw);

                data_string += "\n start//";
                data_string += receivedString;
                data_string += "\n /device/";
                data_string += switch1+":"+switch2+":"+q_x+":"+q_y+":"+q_z+":"+q_w;
                data_string += "\n /quaternion/";
                data_string += w+":"+x+":"+y+":"+z;

                ds.setdata(x, y, z, w);

                // float x = Convert.ToSingle(values[6]);
                // float y = Convert.ToSingle(values[7]);
                // float z = Convert.ToSingle(values[8]);
                // data_string += "\n /xyz/";
                // data_string += x+":"+y+":"+z;

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

# DataSetter.cs
```c#
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEngine;

public class DataSetter : MonoBehaviour
{
    private Quaternion bodyQuat;
    public GameObject raw_cube;
    public GameObject made_cube;
    public GameObject look_target_cube;
    public void setdata(float x, float y, float z, float w)
    {
        bodyQuat = new Quaternion(y,-z,-x,w);
        raw_cube.transform.rotation = bodyQuat;
        made_cube.transform.rotation = bodyQuat;
        made_cube.transform.Rotate(offset_angles, Space.World);
    }
    private bool switch2_clicked_flag = false;
    public void switch2_clicked(bool flag)
    {
        if(switch2_clicked_flag == false && flag == true)
        {
            made_cube.SetActive(true);
            switch2_clicked_flag = true;
        }
        else if(switch2_clicked_flag == true && flag == false)
        {
            made_cube.SetActive(false);
            switch2_clicked_flag = false;
        }
    }
    private bool switch1_clicked_flag = false;
    public void switch1_clicked(bool flag)
    {
        if(switch1_clicked_flag == false && flag == true)
        {
            made_cube.SetActive(true);
            cube_child_rotation_reset();
            switch1_clicked_flag = true;
        }
        else if(switch1_clicked_flag == true && flag == false)
        {
            made_cube.SetActive(false);
            switch1_clicked_flag = false;
        }
    } //엄지 손가락 스위치

    Transform look_cube_transform;
    Vector3 offset_angles = new Vector3(0,0,0);
    public void cube_child_rotation_reset()
    {
        look_cube_transform = raw_cube.transform.GetChild(0);
        look_cube_transform.LookAt(look_target_cube.transform); //looking at target
        offset_angles.y = look_cube_transform.eulerAngles.y - bodyQuat.eulerAngles.y;
    }
    private void Update(){
        //made_cube.transform.localEulerAngles = raw_cube.transform.localEulerAngles;
        //made_cube.transform.Rotate(offset_angle, Space.Self);
    }
}
```