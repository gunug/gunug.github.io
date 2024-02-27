---
layout: post
title: air update 플래시 에어 업데이트
category: etc
tags: flash air
---

# air update 플래시 에어 업데이트

1. air.update를 이용하기 위하여 framework를 다운로드 받습니다.
2. 내부의 framework폴더를 swc링크하면 class를 사용가능합니다.
3. update.xml파일을 air의 패키지에 import 합니다. (이하 내용)

```xml
<?xml version="1.0" encoding="utf-8"?> 
<configuration xmlns="http://ns.adobe.com/air/framework/update/configuration/1.0" >
   <delay>1</delay>

   <!-- URL that points to the new version of the AIR file. Required. -->
   <!--<url>http://www.junkmemory.com/air_downloads/air_test.air</url>-->
   <url>http://www.junkmemory.com/air_downloads/update.xml</url>

   <!-- Description of the new application version that can be displayed in the update process. Optional. -->
   <description>
      <text xml:lang="en"><![CDATA[English description]]></text>
      <text xml:lang="ja"><![CDATA[日本語 description]]></text>
      <text xml:lang="ja"><![CDATA[한국어 description]]></text>
   </description>
</configuration>
```

4. update.xml파일을 서버의 air의 패키지와 동일 위치에 놓습니다. (이하 내용)

```xml
<?xml version="1.0" encoding="utf-8"?>
<update xmlns="http://ns.adobe.com/air/framework/update/description/1.0">
<!-- Update Descriptor File Template for Update Framework
 Specifies information related to new version of the application that is available for download
-->

  <!-- The new version of the AIR file. Required. -->
  <version>1.1</version>
  
  <!-- URL that points to the new version of the AIR file. Required. -->
  <url>http://www.junkmemory.com/air_downloads/air_test.air</url>
  
  <!-- Description of the new application version that can be displayed in the update process.
      May have multiple values for each language. Check the update-localized-template.xml
         You cannot mix simple description with localized description.
    Optional. -->
  <description><![CDATA[
  New version includes:
      * Feature 1
      * Feature 2
      * Feature 3        
    ]]></description>
</update>
```

---

# 플래시에 들어가는 as소스
```javascript
import air.update.events.DownloadErrorEvent;
import air.update.events.StatusUpdateErrorEvent;
import air.update.events.StatusUpdateEvent;
import air.update.events.UpdateEvent;
import air.update.ApplicationUpdater;
import flash.filesystem.File;

var applicationUpdater:ApplicationUpdater;

var log:TextField = new TextField();
//log.autoSize = TextFieldAutoSize.LEFT;
log.width = stage.stageWidth;
log.height = stage.stageHeight;
log.multiline = true;
log.wordWrap = true;
addChild(log);

function applicationCompleteHandler():void 
{ 
 // 현재버전 찍기
 var appXml:XML = NativeApplication.nativeApplication.applicationDescriptor;
 var ns:Namespace = appXml.namespace();
 var appVersion:String = appXml.ns::version[0];
 log.text += "현재 어플리케이션버전 : " + appVersion + "\n";
 
 // ApplicationUpdater초기화
 applicationUpdater = new ApplicationUpdater();
 applicationUpdater.configurationFile = new File("app:/update.xml");
 
 // initialize할 때
 applicationUpdater.addEventListener(UpdateEvent.INITIALIZED, initializedUpdateEventHandler);
 applicationUpdater.addEventListener(ErrorEvent.ERROR, errorErrorEventHandler);
 
 // checkNow할 때
 applicationUpdater.addEventListener(StatusUpdateEvent.UPDATE_STATUS, updateStatusStatusUpdateEventHandler);
 applicationUpdater.addEventListener(UpdateEvent.CHECK_FOR_UPDATE, checkForUpdateUpdateEventHandler);
 applicationUpdater.addEventListener(StatusUpdateErrorEvent.UPDATE_ERROR, updateErrorStatusUpdateEventHandler);
 
 // downloadUpdate할 때                
 applicationUpdater.addEventListener(UpdateEvent.DOWNLOAD_START, downloadStartUpdateEventHandler);
 applicationUpdater.addEventListener(ProgressEvent.PROGRESS, progressProgressEventHandler);
 applicationUpdater.addEventListener(UpdateEvent.DOWNLOAD_COMPLETE, downloadCompleteUpdateEventHandler);
 applicationUpdater.addEventListener(DownloadErrorEvent.DOWNLOAD_ERROR, downloadErrorDownloadErrorEventHandler);
 
 // installUpdate할 때
 applicationUpdater.addEventListener(UpdateEvent.BEFORE_INSTALL, beforeInstallUpdateEventHandler);
 
 // 초기화
 applicationUpdater.initialize();
}

function initializedUpdateEventHandler(event:UpdateEvent):void
{
 log.text += "initialized : " + applicationUpdater.currentState +"\n";
 applicationUpdater.checkNow();
}

function errorErrorEventHandler(event:ErrorEvent):void
{
 log.text += "error : " + applicationUpdater.currentState + "\n";
}

function updateStatusStatusUpdateEventHandler(event:StatusUpdateEvent):void
{
 event.preventDefault();
 log.text += "update_status : " + applicationUpdater.currentState +"\n";
 log.text += "version : " + event.version + "\n";
 log.text += "available : " + event.available + "\n";
 
 if (event.available)
 {
  applicationUpdater.downloadUpdate();
 }
}

function updateErrorStatusUpdateEventHandler(event:StatusUpdateErrorEvent):void
{
 log.text += "update_error : " + applicationUpdater.currentState + "\n";
}

function checkForUpdateUpdateEventHandler(event:UpdateEvent):void
{
 log.text += "check_for_update : " + applicationUpdater.currentState + "\n";
}

/////////////////////////////////////////////////////////////////////////////////////////

function downloadStartUpdateEventHandler(event:UpdateEvent):void
{
 log.text += "download_start : " + applicationUpdater.currentState + "\n";
}

function progressProgressEventHandler(event:ProgressEvent):void
{
 log.text += "progress : " + event.bytesLoaded + "/" + event.bytesTotal +"|";// + "\n";
}

function downloadCompleteUpdateEventHandler(event:UpdateEvent):void
{
 event.preventDefault();
 log.text += "download_complete : " + applicationUpdater.currentState + "\n";
 //btnInstall.visible = true;
 bts1.visible = true;
 addChild(bts1);
}

function downloadErrorDownloadErrorEventHandler(event:DownloadErrorEvent):void
{
 log.text += "download_error : " + applicationUpdater.currentState + "\n";    
 log.text += "error_type : " + event.errorID + "\n";
 log.text += "error_detail : " + event.subErrorID + "\n";
}

function beforeInstallUpdateEventHandler(event:UpdateEvent):void
{
 log.text += "before_install : " + applicationUpdater.currentState + "\n";
}

bts1.visible = false;
bts1.addEventListener(MouseEvent.CLICK,clickInstallHandler);
function clickInstallHandler(event:MouseEvent):void
{
 trace("install start");
 applicationUpdater.installUpdate();
}


applicationCompleteHandler();
```

* 버전 0.15에서 버전 0.2로는 업데이트가 없다고 나옴 (소숫점 1자리까지 일지도)
* air로 설치하면 자동 업데이트가되는데, exe로 설치하면 자동업데이트가 안됨
