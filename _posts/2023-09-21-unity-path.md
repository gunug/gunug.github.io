---
layout: post
title: Unity path 유니티 경로
category: unity3d
tags: c#
---

# 유니티 경로
* [Application.dataPath](https://docs.unity3d.com/ScriptReference/Application-dataPath.html)
* Unity Editor: <path to project folder>/Assets
* Mac player: <path to player app bundle>/Contents
* iOS player: <path to player app bundle>/<AppName.app>/Data (this folder is read only, use Application.persistentDataPath to save data).
Win/Linux player: <path to executablename_Data folder> (note that most Linux installations will be case-sensitive!)
* WebGL: The absolute url to the player data file folder (without the actual data file name)
* Android: Normally it points directly to the APK. If you are running a split binary build, it points to the OBB instead.
* Windows Store Apps: The absolute path to the player data folder (this folder is read only, use Application.persistentDataPath to save data)

---
* [자료 출처](https://geukggom.tistory.com/9)

1. Application.dataPath
 : 제가 원래 사용하고 있었던 데이터 저장 경로입니다. 읽기 전용이며, 런타임 중에 파일 수정, 작성을 할 수 없습니다. 
- 저장 경로 : 프로젝트 폴더 내부(Asset)

1. Application.streamingAssetsPath (Application.dataPath + "/StreamingAssets")
 : dataPath와 마찬가지로 읽기 전용이며, 런타임 시점에 여기서 파일을 수정하거나 작성할 수 없다고 합니다.
서버에서 다운받는 데이터를 아직 서버가 마련되지 않아 파일 형식으로 유니티에 포함시킬 때 사용합니다. 
- 저장 경로 : 프로젝트 폴더내부(StreamingAsset)
*  Application.streamingAssetsPath

1. Application.persistentDataPath   
 : 제가 원하던 쓰기 가능한 폴더의 위치입니다. 특정 운영체제에서 앱이 사용할 수 있도록 허용한 경로입니다.
- 저장 경로 : C:\Users\[user name]\AppData\LocalLow\[company name]\[product name]
(저장 경로 파일명([company name], [product name])의 이름을 바꾸는 방법은 아래 링크 걸어뒀습니다!)

---

# 파일 존재 여부 확인
```c#
using System.IO;
if(File.Exists(file_path))
{
  // 파일이 존재하는 경우
}
else 
{
  // 파일이 존재하지 않는 경우
}
```

---

# UnityWebRequest
```c#
using UnityEngine.Networking; //for UnityWebRequest

string path_ = Application.dataPath + "/StreamingAssets/" + "sample_script_kr_1.mp3";
//WWW www = new WWW(path_);
UnityWebRequest www = new UnityWebRequest(path_);
```
* www.byte 부분이 서로 달라서 사용하지 못하고 있음