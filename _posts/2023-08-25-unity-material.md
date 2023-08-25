---
layout: post
title: 유니티 메테리얼
category: unity3d
tags: unity3d material c#
---

# 유니티 메테리얼
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