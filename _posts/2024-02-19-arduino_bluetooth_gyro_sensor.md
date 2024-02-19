---
layout: post
title: arduino bluetooth gyro sensor 원격 자이로 센서
category: arduino
tags: 
---

# 이미지
# 제반지식
* [연구: arduino jy-mcu 블루투스 모듈](http://45.32.49.113/wiki/index.php/%EC%97%B0%EA%B5%AC:_arduino_jy-mcu_%EB%B8%94%EB%A3%A8%ED%88%AC%EC%8A%A4_%EB%AA%A8%EB%93%88)
* [연구: arduino mpu6050](http://45.32.49.113/wiki/index.php/%EC%97%B0%EA%B5%AC:_arduino_mpu6050)
  
# 소스코드

```c++
//#include <TimerOne.h>

#include <Wire.h>
#include <SoftwareSerial.h>
//#include <Wire.h>


int debug = 0;
// I2C device class (I2Cdev) demonstration Arduino sketch for MPU6050 class using DMP (MotionApps v2.0)
// 6/21/2012 by Jeff Rowberg <jeff@rowberg.net>
// Updates should (hopefully) always be available at https://github.com/jrowberg/i2cdevlib
//
// Changelog:
//      2013-05-08 - added seamless Fastwire support
//                 - added note about gyro calibration
//      2012-06-21 - added note about Arduino 1.0.1 + Leonardo compatibility error
//      2012-06-20 - improved FIFO overflow handling and simplified read process
//      2012-06-19 - completely rearranged DMP initialization code and simplification
//      2012-06-13 - pull gyro and accel data from FIFO packet instead of reading directly
//      2012-06-09 - fix broken FIFO read sequence and change interrupt detection to RISING
//      2012-06-05 - add gravity-compensated initial reference frame acceleration output
//                 - add 3D math helper file to DMP6 example sketch
//                 - add Euler output and Yaw/Pitch/Roll output formats
//      2012-06-04 - remove accel offset clearing for better results (thanks Sungon Lee)
//      2012-06-01 - fixed gyro sensitivity to be 2000 deg/sec instead of 250
//      2012-05-30 - basic DMP initialization working

/* ============================================
I2Cdev device library code is placed under the MIT license
Copyright (c) 2012 Jeff Rowberg

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
===============================================
*/

// I2Cdev and MPU6050 must be installed as libraries, or else the .cpp/.h files
// for both classes must be in the include path of your project
#include <I2Cdev.h>
//#include <I2C.h>
//#include <avr/wdt.h>

#include "MPU6050_6Axis_MotionApps20.h"
//#include "MPU6050.h" // not necessary if using MotionApps include file

// Arduino Wire library is required if I2Cdev I2CDEV_ARDUINO_WIRE implementation
// is used in I2Cdev.h
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  #include "Wire.h"
#endif

// class default I2C address is 0x68
// specific I2C addresses may be passed as a parameter here
// AD0 low = 0x68 (default for SparkFun breakout and InvenSense evaluation board)
// AD0 high = 0x69
MPU6050 mpu;
// MPU6050_setSleepDisabled();
// MPU6050 mpu(0x69); // <-- use for AD0 high

/* =========================================================================
   NOTE: In addition to connection 3.3v, GND, SDA, and SCL, this sketch
   depends on the MPU-6050's INT pin being connected to the Arduino's
   external interrupt #0 pin. On the Arduino Uno and Mega 2560, this is
   digital I/O pin 2.
 * ========================================================================= */

/* =========================================================================
   NOTE: Arduino v1.0.1 with the Leonardo board generates a compile error
   when using Serial.write(buf, len). The Teapot output uses this method.
   The solution requires a modification to the Arduino USBAPI.h file, which
   is fortunately simple, but annoying. This will be fixed in the next IDE
   release. For more info, see these links:

   http://arduino.cc/forum/index.php/topic,109987.0.html
   http://code.google.com/p/arduino/issues/detail?id=958
 * ========================================================================= */



// uncomment "OUTPUT_READABLE_QUATERNION" if you want to see the actual
// quaternion components in a [w, x, y, z] format (not best for parsing
// on a remote host such as Processing or something though)
#define OUTPUT_READABLE_QUATERNION

// uncomment "OUTPUT_READABLE_EULER" if you want to see Euler angles
// (in degrees) calculated from the quaternions coming from the FIFO.
// Note that Euler angles suffer from gimbal lock (for more info, see
// http://en.wikipedia.org/wiki/Gimbal_lock)
//#define OUTPUT_READABLE_EULER

// uncomment "OUTPUT_READABLE_YAWPITCHROLL" if you want to see the yaw/
// pitch/roll angles (in degrees) calculated from the quaternions coming
// from the FIFO. Note this also requires gravity vector calculations.
// Also note that yaw/pitch/roll angles suffer from gimbal lock (for
// more info, see: http://en.wikipedia.org/wiki/Gimbal_lock)
//#define OUTPUT_READABLE_YAWPITCHROLL

// uncomment "OUTPUT_READABLE_REALACCEL" if you want to see acceleration
// components with gravity removed. This acceleration reference frame is
// not compensated for orientation, so +X is always +X according to the
// sensor, just without the effects of gravity. If you want acceleration
// compensated for orientation, us OUTPUT_READABLE_WORLDACCEL instead.
//#define OUTPUT_READABLE_REALACCEL

// uncomment "OUTPUT_READABLE_WORLDACCEL" if you want to see acceleration
// components with gravity removed and adjusted for the world frame of
// reference (yaw is relative to initial orientation, since no magnetometer
// is present in this case). Could be quite handy in some cases.
//#define OUTPUT_READABLE_WORLDACCEL

// uncomment "OUTPUT_TEAPOT" if you want output that matches the
// format used for the InvenSense teapot demo
//#define OUTPUT_TEAPOT



#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)
#define RESET_PIN 11 //reset pin
bool blinkState = false;

// MPU control/status vars
bool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorInt16 aa;         // [x, y, z]            accel sensor measurements
VectorInt16 aaReal;     // [x, y, z]            gravity-free accel sensor measurements
VectorInt16 aaWorld;    // [x, y, z]            world-frame accel sensor measurements
VectorFloat gravity;    // [x, y, z]            gravity vector
float euler[3];         // [psi, theta, phi]    Euler angle container
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

// packet structure for InvenSense teapot demo
uint8_t teapotPacket[14] = { '$', 0x02, 0,0, 0,0, 0,0, 0,0, 0x00, 0x00, '\r', '\n' };



// ================================================================
// ===               INTERRUPT DETECTION ROUTINE                ===
// ================================================================

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high
void dmpDataReady() {
    mpuInterrupt = true;
    //if(debug==1)Serial.print("interrupt");
    //Timer1.detachInterrupt();
}



// ================================================================
// ===                      INITIAL SETUP                       ==
// ================================================================

//버튼, 진동모터 관련 애드온
int motorPin = A3;
const int buttonPin = 12;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int switchState = 0;
int gun_counter = 0;

#define LED_PIN 13 // (Arduino is 13, Teensy is 11, Teensy++ is 6)

void(* resetFunc)(void) = 0;
void reset_function(){
  /*
  if(debug==1)Serial.println("resetting");
  delay(1000);
  digitalWrite(RESET_PIN, LOW);
  if(debug==1)Serial.println("this never happens");
  //this never happens because Arduino resets
  */
  if(debug==1)Serial.println("resetting!!!!!!!!!!!!!!!!!!!!!");
  delay(3000);
  resetFunc();
}

void callBack(){
  if(debug==1)Serial.println("!!!! interrupt activate !!!!");
  //Timer1.detachInterrupt();
  //asm volatile ( "jmp 0");

  reset_function();
/*
  //setStart();
  Wire.begin();
  TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
  //Timer1.detachInterrupt();
  */
}

void scan_i2c(){
  byte error, address;
  int nDevices;
 
  if(debug==1)Serial.println("Scanning...");
 
  nDevices = 0;
  for(address = 1; address < 127; address++ )
  {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0)
    {
      if(debug==1)Serial.print("I2C device found at address 0x");
      if (address<16)
      if(debug==1)Serial.print("0");
      if(debug==1)Serial.print(address,HEX);
      if(debug==1)Serial.println("  !");
 
      nDevices++;
    }
    else if (error==4)
    {
      if(debug==1)Serial.print("Unknow error at address 0x");
      if (address<16)
        if(debug==1)Serial.print("0");
      if(debug==1)Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0){
    if(debug==1)Serial.println("No I2C devices found\n");
  }else{
    if(debug==1)Serial.println("done\n");
  }
 
  //delay(5000);           // wait 5 seconds for next scan
}

void setStart(){
    //new one
    // test the connection to the I2C bus, sometimes it doesn't connect
    // keep trying to connect to I2C bus if we get an error
    byte error = 1;
    if(debug==1)Serial.println("step1");
    //wdt_enable(WDTO_2S); //FOR RESET
    //Wire.setClock(400000);
    //Serial.print("address:");
    //Serial.println(mpu.devAddr);
    //try:
    //except OSError as er:
    /*
    Timer1.initialize(5000000);
    Timer1.attachInterrupt(callBack);
    */
  
    while (error) {
      if(debug==1)Serial.println("step2");
        Wire.beginTransmission(0x68);
        Wire.write("0x20");
        Wire.write("0x30");
        Wire.write("0x40");
        Wire.write("0x50");
        delay(1000);
        if(debug==1)Serial.println(Wire.available());
        error = Wire.endTransmission(); // if error = 0, we are properly connected
        //error 0 : 전송성공
        //error 1 : 데이터버퍼 길이 허용범위 초과
        //error 2 : 주소전송단계에서 NACK뱔생 즉 해당 주고값을 갖는 slave 기기 미존재
        //error 3 : 데이터 전송단계에서 NACK발생 데이터 전송실패
        //error 4 : 그외 모든 오류
        if(debug==1)Serial.print("error:");
        if(debug==1)Serial.println(error);
        //error = 0;
        //Serial.println("endTransmission try was failed!");
        if (error) { // if we aren't properly connected, try connecting again and loop
          if(debug==1) Serial.println("  ");
          if(debug==1)Serial.println("Not properly connected to I2C, trying again");
          if(debug==1)Serial.println(" ");
          Wire.begin();
          //TWBR = 24; // 400kHz I2C clock
          //TWBR = 12; // 200kHz I2C clock
          TWBR = 0x00;
        }else{
          if(debug==1)Serial.println("what?");
          //Timer1.detachInterrupt();
        }
    }
    if(debug==1)Serial.println("Properly connected to I2C");

    while (!Serial); // wait for Leonardo enumeration, others continue immediately

    // NOTE: 8MHz or slower host processors, like the Teensy @ 3.3v or Ardunio
    // Pro Mini running at 3.3v, cannot handle this baud rate reliably due to
    // the baud timing being too misaligned with processor ticks. You must use
    // 38400 or slower in these cases, or use some kind of external separate
    // crystal solution for the UART timer.

    // initialize device
    if(debug==1)Serial.println(F("Initializing I2C devices..."));
    //wdt_enable(WDTO_2S); //FOR RESET
    mpu.initialize();
    //Timer1.detachInterrupt();

    // verify connection
    if(debug==1)Serial.println(F("Testing device connections..."));
    if(debug==1)Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // wait for ready
    if(debug==1)Serial.println(F("\nSend any character to begin DMP programming and demo: "));
    /*
    while (Serial.available() && Serial.read()); // empty buffer
    while (!Serial.available());                 // wait for data
    while (Serial.available() && Serial.read()); // empty buffer again
    */
    // load and configure the DMP
    if(debug==1)Serial.println(F("Initializing DMP..."));
    devStatus = mpu.dmpInitialize();

    // supply your own gyro offsets here, scaled for min sensitivity
    int gun_number = 0;
    //-좌로기울여, +우로기울여
    switch(gun_number){
      case 0: mpu.setXAccelOffset(-1781);mpu.setYAccelOffset(1972);mpu.setZAccelOffset(1284);mpu.setXGyroOffset(21);mpu.setYGyroOffset(-24);mpu.setZGyroOffset(35); break;
      case 1: /*c1*/mpu.setXAccelOffset(-799);mpu.setYAccelOffset(-825);mpu.setZAccelOffset(1907);mpu.setXGyroOffset(-25);mpu.setYGyroOffset(7);mpu.setZGyroOffset(-4); break;
      case 2: /*c1*/mpu.setXAccelOffset(-2005);mpu.setYAccelOffset(2363);mpu.setZAccelOffset(2218);mpu.setXGyroOffset(29);mpu.setYGyroOffset(-31);mpu.setZGyroOffset(12); break;
      case 3: /*c1*/mpu.setXAccelOffset(-344);mpu.setYAccelOffset(785);mpu.setZAccelOffset(1918);mpu.setXGyroOffset(21);mpu.setYGyroOffset(0);mpu.setZGyroOffset(14); break;
      case 4: /*c4*/mpu.setXAccelOffset(-3285);mpu.setYAccelOffset(-461);mpu.setZAccelOffset(2142);mpu.setXGyroOffset(-103);mpu.setYGyroOffset(4);mpu.setZGyroOffset(2); break;
      case 5: /*c2*/mpu.setXAccelOffset(-1);mpu.setYAccelOffset(879);mpu.setZAccelOffset(1854);mpu.setXGyroOffset(72);mpu.setYGyroOffset(-1);mpu.setZGyroOffset(-1); break;
      case 6: /*ggc4*/mpu.setXAccelOffset(-3779);mpu.setYAccelOffset(-629);mpu.setZAccelOffset(2334);mpu.setXGyroOffset(-66);mpu.setYGyroOffset(62);mpu.setZGyroOffset(101); break;
      case 7: /*c2*/mpu.setXAccelOffset(-1000);mpu.setYAccelOffset(22);mpu.setZAccelOffset(2371);mpu.setXGyroOffset(-176);mpu.setYGyroOffset(20);mpu.setZGyroOffset(113); break;
      case 8: /*c3*/mpu.setXAccelOffset(92);mpu.setYAccelOffset(-152);mpu.setZAccelOffset(2345);mpu.setXGyroOffset(25);mpu.setYGyroOffset(30);mpu.setZGyroOffset(2); break;
      case 9: /*c2*/mpu.setXAccelOffset(366);mpu.setYAccelOffset(-1129);mpu.setZAccelOffset(2209);mpu.setXGyroOffset(-52);mpu.setYGyroOffset(-68);mpu.setZGyroOffset(17); break;
      /*1000: 745 -1095 2210 -53 -69 14*/
      /*3000: 745 -1096 2211 -53 -69 14*/
      case 10: /*ggc3*/mpu.setXAccelOffset(-107);mpu.setYAccelOffset(960);mpu.setZAccelOffset(1725);mpu.setXGyroOffset(93);mpu.setYGyroOffset(-34);mpu.setZGyroOffset(15); break;
      case 11: /*ggc3*/mpu.setXAccelOffset(-3191);mpu.setYAccelOffset(970);mpu.setZAccelOffset(2043);mpu.setXGyroOffset(31);mpu.setYGyroOffset(-16);mpu.setZGyroOffset(8); break;
      case 12: /*c3*/mpu.setXAccelOffset(-2970);mpu.setYAccelOffset(-568);mpu.setZAccelOffset(2335);mpu.setXGyroOffset(-44);mpu.setYGyroOffset(-44);mpu.setZGyroOffset(-16); break;
      case 13: /*c2*/mpu.setXAccelOffset(-2071);mpu.setYAccelOffset(982);mpu.setZAccelOffset(1993);mpu.setXGyroOffset(3);mpu.setYGyroOffset(39);mpu.setZGyroOffset(-8); break;
      case 14: /*c4*/mpu.setXAccelOffset(-2962);mpu.setYAccelOffset(-545);mpu.setZAccelOffset(2060);mpu.setXGyroOffset(85);mpu.setYGyroOffset(-66);mpu.setZGyroOffset(-37); break;
      case 15: /*ggc1*/mpu.setXAccelOffset(-3287);mpu.setYAccelOffset(-357);mpu.setZAccelOffset(1463);mpu.setXGyroOffset(51);mpu.setYGyroOffset(-44);mpu.setZGyroOffset(9); break;
      case 16: /*c4*/mpu.setXAccelOffset(364);mpu.setYAccelOffset(-854);mpu.setZAccelOffset(1701);mpu.setXGyroOffset(-27);mpu.setYGyroOffset(135);mpu.setZGyroOffset(-22); break;
      case 17: /*c3*/mpu.setXAccelOffset(-1566);mpu.setYAccelOffset(315);mpu.setZAccelOffset(2080);mpu.setXGyroOffset(53);mpu.setYGyroOffset(-18);mpu.setZGyroOffset(70); break;
      case 18: /*ggc4*/mpu.setXAccelOffset(-790);mpu.setYAccelOffset(1507);mpu.setZAccelOffset(1813);mpu.setXGyroOffset(64);mpu.setYGyroOffset(-26);mpu.setZGyroOffset(6); break;
     
    }
    /*
    mpu.setXAccelOffset(515);
    mpu.setYAccelOffset(-1082);
    mpu.setZAccelOffset(2189);
    
    mpu.setXGyroOffset(-54); //★
    mpu.setYGyroOffset(-74); //★
    mpu.setZGyroOffset(2); //★
    */
    // make sure it worked (returns 0 if so)
    if (devStatus == 0) {
        // turn on the DMP, now that it's ready
        if(debug==1)Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        if(debug==1)Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        if(debug==1)Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();

        //*****
        //mpuInterrupt = true;
    } else {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        if(debug==1)Serial.print(F("DMP Initialization failed (code "));
        if(debug==1)Serial.print(devStatus);
        if(debug==1)Serial.println(F(")"));
    }

    // configure LED for output
    pinMode(LED_PIN, OUTPUT);
}
SoftwareSerial mySerial(8, 9); // RX, TX
void setup() {
  Serial.begin(57600);
  //mySerial.begin(115200);
  mySerial.begin(57600);
  //mySerial.begin(9600);
  digitalWrite(RESET_PIN, HIGH); // if you want arduino keep running, you will make HIGH reset pin;
  //버튼, 진동모터 관련 애드온
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(RESET_PIN, OUTPUT);
    
    //I2c.begin();
    //TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)

    // initialize serial communication
    // (115200 chosen because it is required for Teapot Demo output, but it's
    // really up to you depending on your project)
    //Serial.begin(115200);
    //Serial.begin(57600);
    //Serial.begin(9600);
    
    //if(debug==1)Serial.println("wait 10sec for I2C");
    //delay(10000);
    // join I2C bus (I2Cdev library doesn't do this automatically)
    /*
    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();
        TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true);
    #endif
    */
    Wire.begin();
    TWBR = 24; // 400kHz I2C clock (200kHz if CPU is 8MHz)
    scan_i2c();
    setStart();
}





// ================================================================
// ===                    MAIN PROGRAM LOOP                     ===
// ================================================================
float new_yow = 0;
float yow_char = 0;
float save_ypr = 0;
float new_ypr = 0;
float yow_counter = 0;
int counter = 0;

void loop() {
  //wdt_reset(); //FOR RESET
    //버튼, 진동모터 관련 부분
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == LOW) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    gun_counter++;
    if(gun_counter < 4){
      analogWrite(motorPin, 255);
      switchState = HIGH;
    }else if(gun_counter < 20){
      analogWrite(motorPin, 0);
      switchState = LOW;
    }else{
      gun_counter = 0;
    }
  } else {
    switchState = LOW;
    // turn LED off:
    digitalWrite(ledPin, LOW);
    analogWrite(motorPin, 0);
    if(gun_counter > 0){
      gun_counter++;
      if(gun_counter > 20){
        gun_counter = 0;
      }
    }
  }
  //버튼, 진동모터 관련 부분
  
    // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize) {
        // other program behavior stuff here
        // .
        // .
        // .
        // if you are really paranoid you can frequently test in between other
        // stuff to see if mpuInterrupt is true, and if so, "break;" from the
        // while() loop to immediately process the MPU data
        // .
        // .
        // .
    }

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        if(debug==1)Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    } else if (mpuIntStatus & 0x02) {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        #ifdef OUTPUT_READABLE_QUATERNION
            // display quaternion values in easy matrix form: w x y z
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            /*
            Serial.print("quat\t");
            Serial.print(q.w);
            Serial.print("\t");
            Serial.print(q.x);
            Serial.print("\t");
            Serial.print(q.y);
            Serial.print("\t");
            Serial.println(q.z);
            */
            Serial.print(q.w);
            Serial.print(",");
            Serial.print(q.x);
            Serial.print(",");
            Serial.print(q.y);
            Serial.print(",");
            Serial.print(q.z);
            Serial.println();

            mySerial.print(q.w);
            mySerial.print(",");
            mySerial.print(q.x);
            mySerial.print(",");
            mySerial.print(q.y);
            mySerial.print(",");
            mySerial.print(q.z);
            mySerial.println();
        #endif

        #ifdef OUTPUT_READABLE_EULER
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetEuler(euler, &q);
            Serial.print("euler\t");
            Serial.print(euler[0] * 180/M_PI);
            Serial.print("\t");
            Serial.print(euler[1] * 180/M_PI);
            Serial.print("\t");
            Serial.println(euler[2] * 180/M_PI);
        #endif

        #ifdef OUTPUT_READABLE_YAWPITCHROLL
            // display Euler angles in degrees
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
            /*
            //Serial.print("ypr\t");
            //★★★★★
            //Serial.print(abs(save_ypr-ypr[0] * 180/M_PI * 1000));
            if(abs(save_ypr-ypr[0] * 180/M_PI * 1000)>9){
              yow_char = save_ypr/1000 - ypr[0] * 180/M_PI;
              new_yow = new_yow-yow_char;
            }
            save_ypr = ypr[0] * 180/M_PI * 1000;
            //★★★★★
            */
            Serial.print("[");
            Serial.print(switchState);
            Serial.print("|");
            //Serial.print(new_yow);
            float last_location = ypr[0] * 180/M_PI + yow_counter;
            while(last_location < -180){
              last_location  += 360;
            }
            while(last_location > 180){
              last_location  -= 360;
            }
            Serial.print(last_location);
            Serial.print("|");
            Serial.print(ypr[1] * 180/M_PI);
            Serial.print("|");
            Serial.print(ypr[2] * 180/M_PI);
            Serial.print("]");

            //if(debug==1)Serial.println(F("Enabling DMP..."));
            new_ypr = abs(ypr[0] * 180/M_PI) + abs(ypr[1] * 180/M_PI) + abs (ypr[2] * 180/M_PI);
              if(ypr[1] * 180/M_PI < -25 && ypr[1] * 180/M_PI > -80){
                if(abs(save_ypr - new_ypr) < 0.05){
                  counter ++;
                  if(counter > 1000){
                    counter = 0;
                    yow_counter = -ypr[0] * 180/M_PI;
                  }
                }else{
                  counter = 0;
                }
              }else{
                counter = 0;
              }
            if(debug==1)Serial.print( "condition1:" );
            if(debug==1)Serial.print( ypr[1] * 180/M_PI );
            if(debug==1)Serial.print( "condition2:" );
            if(debug==1)Serial.print( abs(save_ypr - new_ypr) );
            if(debug==1)Serial.print( "counter:" );
            if(debug==1)Serial.print( counter );
            save_ypr = new_ypr;
            Serial.println("");
        #endif

        #ifdef OUTPUT_READABLE_REALACCEL
            // display real acceleration, adjusted to remove gravity
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetAccel(&aa, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
            Serial.print("areal\t");
            Serial.print(aaReal.x);
            Serial.print("\t");
            Serial.print(aaReal.y);
            Serial.print("\t");
            Serial.println(aaReal.z);
        #endif

        #ifdef OUTPUT_READABLE_WORLDACCEL
            // display initial world-frame acceleration, adjusted to remove gravity
            // and rotated based on known orientation from quaternion
            mpu.dmpGetQuaternion(&q, fifoBuffer);
            mpu.dmpGetAccel(&aa, fifoBuffer);
            mpu.dmpGetGravity(&gravity, &q);
            mpu.dmpGetLinearAccel(&aaReal, &aa, &gravity);
            mpu.dmpGetLinearAccelInWorld(&aaWorld, &aaReal, &q);
            Serial.print("aworld\t");
            Serial.print(aaWorld.x);
            Serial.print("\t");
            Serial.print(aaWorld.y);
            Serial.print("\t");
            Serial.println(aaWorld.z);
        #endif
    
        #ifdef OUTPUT_TEAPOT
            // display quaternion values in InvenSense Teapot demo format:
            teapotPacket[2] = fifoBuffer[0];
            teapotPacket[3] = fifoBuffer[1];
            teapotPacket[4] = fifoBuffer[4];
            teapotPacket[5] = fifoBuffer[5];
            teapotPacket[6] = fifoBuffer[8];
            teapotPacket[7] = fifoBuffer[9];
            teapotPacket[8] = fifoBuffer[12];
            teapotPacket[9] = fifoBuffer[13];
            Serial.write(teapotPacket, 14);
            teapotPacket[11]++; // packetCount, loops at 0xFF on purpose
        #endif

        // blink LED to indicate activity
        blinkState = !blinkState;
        digitalWrite(LED_PIN, blinkState);
    }
}
```
