---
layout: post
title: arduino BLE bluetooth simple code 아두이노 저전력 블루투스 요약
category: arduino
tags: simple-code
---

# arduino BLE bluetooth simple code 아두이노 저전력 블루투스 요약

```c++
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define SERVICE_UUID        "0000FFE0-0000-1000-8000-00805F9B34FB"
#define CHARACTERISTIC_UUID "0000FFE1-0000-1000-8000-00805F9B34FB"
#define DEVICE_NAME         "Motion0002"
//상기 3가지 값이 BLE 디바이스를 찾고 연결하는데 사용됩니다. 유니티에서도 동일하게 입력되어야 함

BLEServer* pServer = NULL;
BLECharacteristic* pCharacteristic = NULL;
bool deviceConnected = false;
bool oldDeviceConnected = false;

void setup() {
    Serial.begin(115200);
    ble_bluetooth_init();
    delay(2000); //esp32c3 특수로 인한 필수 딜레이
}

unsigned int buff_size = 20; //BLE bluetooth 패킷은 최대 20바이트
String data_str = "";
char buf[20] = "";
uint8_t values[20];
void loop(){
    connect_check();
    set_data();
    send_data();
    delay(2000); //esp32c3 특수로 인한 필수 딜레이
}

void connect_check(){
  // disconnecting
  if (!deviceConnected && oldDeviceConnected) {
      delay(500); // give the bluetooth stack the chance to get things ready
      pServer->startAdvertising(); // restart advertising
      oldDeviceConnected = deviceConnected;
  }
  // connecting
  if (deviceConnected && !oldDeviceConnected) {
      // do stuff here on connecting
      oldDeviceConnected = deviceConnected;
  }
}

void set_data(){
    data_str = "1234567890";
    data_str.toCharArray(buf, buff_size);
    for(int i=0;i<buff_size;i++)
    {
      values[i] = buf[i];
    }
}

void send_data(){
  if (deviceConnected) {
      pCharacteristic->setValue(values, buff_size);
      pCharacteristic->notify();
      delay(10); // bluetooth stack will go into congestion, if too many packets are sent, in 6 hours test i was able to go as low as 3ms
  }
}

class ServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* pServer) {
      deviceConnected = true;
      BLEDevice::startAdvertising();
    };

    void onDisconnect(BLEServer* pServer) {
      deviceConnected = false;
    }
};

void ble_bluetooth_init()
{
  // Create the BLE Device
  BLEDevice::init(DEVICE_NAME);

  // Create the BLE Server
  pServer = BLEDevice::createServer();
  pServer->setCallbacks(new ServerCallbacks());

  // Create the BLE Service
  BLEService *pService = pServer->createService(SERVICE_UUID);

  // Create a BLE Characteristic
  pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID, BLECharacteristic::PROPERTY_NOTIFY);

  // https://www.bluetooth.com/specifications/gatt/viewer?attributeXmlFile=org.bluetooth.descriptor.gatt.client_characteristic_configuration.xml
  // Create a BLE Descriptor
  pCharacteristic->addDescriptor(new BLE2902());

  // Start the service
  pService->start();

  // Start advertising
  BLEAdvertising *pAdvertising = BLEDevice::getAdvertising();
  pAdvertising->addServiceUUID(SERVICE_UUID);
  pAdvertising->setScanResponse(false);
  pAdvertising->setMinPreferred(0x0);  // set value to 0x00 to not advertise this parameter
  BLEDevice::startAdvertising();
  Serial.println("Waiting a client connection to notify...");
}
```