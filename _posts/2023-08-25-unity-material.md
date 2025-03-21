---
layout: post
title: Material 메테리얼
category: unity3d
tags: c#
---

# 유니티 메테리얼

* Diffuse = albedo : 이미지의 모습으로 오브젝트 표면의 모습과 색상을 결정한다.
* Specular =Metalic: 이미지에 저장된 정보에 따라 빛을 반사하는 수준을 결정한다.
* Normal : 이미지에 저장된 정보에 따라 표면이 입체적으로 보아게 한다.
* Height :이미지에 저장된 정보에 따라 표면의 고도를 결정한다.
* Occlusion : 이미지에 저장된 정보에 따라 빛을 난반사하는 수준을 결정한다.

---

## 메테리얼 스크립트 접근
```c#
Randerer _renderer = GetComponent<Renderer>();
Texture _texture;
//_renderer.material.SetTexture("_MainTex", _texture);
_renderer.material.mainTexture = _texture;
//_texture.width,_texture.height = 128,256,512,1024
```

---

# texture width, height가 2의 배수인 문제

* 참고 링크 : https://forum.unity.com/threads/getting-original-size-of-texture-asset-in-pixels.165295/

```c#
using UnityEditor;
using System.Reflection;

public static bool GetImageSize(Texture asset, out int width, out int height) {
    if (asset != null) {
        string assetPath = AssetDatabase.GetAssetPath(asset);
        TextureImporter importer = AssetImporter.GetAtPath(assetPath) as TextureImporter;
 
        if (importer != null) {
            object[] args = new object[2] { 0, 0 };
            MethodInfo mi = typeof(TextureImporter).GetMethod("GetWidthAndHeight",
            BindingFlags.NonPublic | BindingFlags.Instance);
            mi.Invoke(importer, args);
 
            width = (int)args[0];
            height = (int)args[1];
 
            return true;
        }
    }
 
    height = width = 0;
    return false;
}

Texture _texture;
int _w = 0;
int _h = 0;
GetImageSize(_texture,out _w, out _h);
Debug.Log(_w);
Debug.Log(_h);

```
* 실제 이미지 사이즈를 얻을 수 있음
* AssetDatabase 관련 build에러가 있음 (Editor모드일때만 사용 가능 하다고 함)

---

# 텍스쳐 사이즈 2승수 관련
* 참고 : https://www.devkorea.co.kr/qna/9466?sst=wr_hit&sod=desc&sop=and&page=14
* 텍스쳐 선택 > inspector창 > advanced > Non Power of 2 > ToNearest를 None으로 변경