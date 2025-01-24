---
layout: post
title: unity image size
category: unity3d
tags: simple-code
---

# unity image size
* raw image의 set native size 기능을 이용하려다가 이미지의 크기가 아닌 텍스쳐 크기(2의 배수로 변경된)를 반영하는 문제
* 자료 출처 : <https://discussions.unity.com/t/getting-original-size-of-texture-asset-in-pixels/494353/21>

```csharp
using System;
using System.Reflection;
using System.Collections.Generic;
using System.IO;
using System.Linq;


public class Vector2Int
{
    public int x;
    public int y;
   
    public Vector2Int( int _x, int _y )
    {
        x = _x;
        y = _y;
    }
}

/// <summary>
/// Taken from http://stackoverflow.com/questions/111345/getting-image-dimensions-without-reading-the-entire-file/111349
/// Minor improvements including supporting unsigned 16-bit integers when decoding Jfif and added logic
/// to load the image using new Bitmap if reading the headers fails
/// </summary>
public static class ImageHeader
{
    const string errorMessage = "Could not recognise image format.";

    private static Dictionary<byte[], Func<BinaryReader, Vector2Int>> imageFormatDecoders = new Dictionary<byte[], Func<BinaryReader, Vector2Int>>()
    {
        { new byte[] { 0x42, 0x4D }, DecodeBitmap },
        { new byte[] { 0x47, 0x49, 0x46, 0x38, 0x37, 0x61 }, DecodeGif },
        { new byte[] { 0x47, 0x49, 0x46, 0x38, 0x39, 0x61 }, DecodeGif },
        { new byte[] { 0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A }, DecodePng },
        { new byte[] { 0xff, 0xd8 }, DecodeJfif },
    };

    /// <summary>       
    /// Gets the dimensions of an image.       
    /// </summary>       
    /// <param name="path">The path of the image to get the dimensions of.</param>       
    /// <returns>The dimensions of the specified image.</returns>       
    /// <exception cref="ArgumentException">The image was of an unrecognised format.</exception>       
    public static Vector2Int GetDimensions(string path)
    {
        try
        {
            using (BinaryReader binaryReader = new BinaryReader(File.OpenRead(path)))
            {
                try
                {
                    return GetDimensions(binaryReader);
                }
                catch (ArgumentException e)
                {
                    string newMessage = string.Format("{0} file: '{1}' ", errorMessage, path);

                    throw new ArgumentException(newMessage, "path", e);
                }
            }
        }
        catch (ArgumentException)
        {
            UnityEngine.Debug.LogError("And error occured");
            return new Vector2Int(0,0);
        }
    }

    /// <summary>       
    /// Gets the dimensions of an image.       
    /// </summary>       
    /// <param name="path">The path of the image to get the dimensions of.</param>       
    /// <returns>The dimensions of the specified image.</returns>       
    /// <exception cref="ArgumentException">The image was of an unrecognised format.</exception>           
    public static Vector2Int GetDimensions(BinaryReader binaryReader)
    {
        int maxMagicBytesLength = imageFormatDecoders.Keys.OrderByDescending(x => x.Length).First().Length;
        byte[] magicBytes = new byte[maxMagicBytesLength];
        for (int i = 0; i < maxMagicBytesLength; i += 1)
        {
            magicBytes[i] = binaryReader.ReadByte();
            foreach (var kvPair in imageFormatDecoders)
            {
                if (StartsWith(magicBytes, kvPair.Key))
                {
                    return kvPair.Value(binaryReader);
                }
            }
        }

        throw new ArgumentException(errorMessage, "binaryReader");
    }

    private static bool StartsWith(byte[] thisBytes, byte[] thatBytes)
    {
        for (int i = 0; i < thatBytes.Length; i += 1)
        {
            if (thisBytes[i] != thatBytes[i])
            {
                return false;
            }
        }

        return true;
    }

    private static short ReadLittleEndianInt16(BinaryReader binaryReader)
    {
        byte[] bytes = new byte[sizeof(short)];

        for (int i = 0; i < sizeof(short); i += 1)
        {
            bytes[sizeof(short) - 1 - i] = binaryReader.ReadByte();
        }
        return BitConverter.ToInt16(bytes, 0);
    }

    private static ushort ReadLittleEndianUInt16(BinaryReader binaryReader)
    {
        byte[] bytes = new byte[sizeof(ushort)];

        for (int i = 0; i < sizeof(ushort); i += 1)
        {
            bytes[sizeof(ushort) - 1 - i] = binaryReader.ReadByte();
        }
        return BitConverter.ToUInt16(bytes, 0);
    }

    private static int ReadLittleEndianInt32(BinaryReader binaryReader)
    {
        byte[] bytes = new byte[sizeof(int)];
        for (int i = 0; i < sizeof(int); i += 1)
        {
            bytes[sizeof(int) - 1 - i] = binaryReader.ReadByte();
        }
        return BitConverter.ToInt32(bytes, 0);
    }

    private static Vector2Int DecodeBitmap(BinaryReader binaryReader)
    {
        binaryReader.ReadBytes(16);
        int width = binaryReader.ReadInt32();
        int height = binaryReader.ReadInt32();
        return new Vector2Int(width, height);
    }

    private static Vector2Int DecodeGif(BinaryReader binaryReader)
    {
        int width = binaryReader.ReadInt16();
        int height = binaryReader.ReadInt16();
        return new Vector2Int(width, height);
    }

    private static Vector2Int DecodePng(BinaryReader binaryReader)
    {
        binaryReader.ReadBytes(8);
        int width = ReadLittleEndianInt32(binaryReader);
        int height = ReadLittleEndianInt32(binaryReader);
        return new Vector2Int(width, height);
    }

    private static Vector2Int DecodeJfif(BinaryReader binaryReader)
    {
        while (binaryReader.ReadByte() == 0xff)
        {
            byte marker = binaryReader.ReadByte();
            short chunkLength = ReadLittleEndianInt16(binaryReader);
            if (marker == 0xc0)
            {
                binaryReader.ReadByte();
                int height = ReadLittleEndianInt16(binaryReader);
                int width = ReadLittleEndianInt16(binaryReader);
                return new Vector2Int(width, height);
            }

            if (chunkLength < 0)
            {
                ushort uchunkLength = (ushort)chunkLength;
                binaryReader.ReadBytes(uchunkLength - 2);
            }
            else
            {
                binaryReader.ReadBytes(chunkLength - 2);
            }
        }

        throw new ArgumentException(errorMessage);
    }
}
```
* 클래스를 만들고

```csharp
Vector2Int imgSize  = ImageHeader.GetDimensions(Application.persistentDataPath+"/Mouse.png");
Debug.Log("imgSize.x =" + imgSize.x);
Debug.Log("imgSize.y =" + imgSize.y);
```

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using UnityEditor;

public class SetImageSizeOnece : MonoBehaviour
{
    void Awake()
    {
        RawImage _raw_image = GetComponent<RawImage>();
        Texture myTexture = _raw_image.texture;
        string texturePath = AssetDatabase.GetAssetPath(myTexture); 
        Debug.Log("texturePath ="+ texturePath);
        Vector2Int imgSize  = ImageHeader.GetDimensions(texturePath);
        Debug.Log("imgSize.x =" + imgSize.x);
        Debug.Log("imgSize.y =" + imgSize.y);
        //set rect transform to imgSize
        RectTransform rt = GetComponent<RectTransform>();
        rt.sizeDelta = new Vector2(imgSize.x, imgSize.y);
    }
}
```
* 사용

---

# 에러
* 'AssetDatabase' does not exist in the current context
* 에디터에서만 사용할 수 있는 코드로 빌드시 에러

* 결국 런타임에서 파일의 메타데이터에 접근하려면 AssetDatabase를 이용하거나
* Streaming assets, Resources 이용하는 수 밖에 없어서 런타임에서 width, height를 기록하여 제공할 예정

```csharp
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

#if UNITY_EDITOR
using UnityEditor;
#endif

public class SetImageSizeOnece : MonoBehaviour
{
    public Vector2 keep_size;
    public Vector2 get_size;
    void Awake()
    {
        RectTransform rt = GetComponent<RectTransform>();
        #if UNITY_EDITOR
            RawImage _raw_image = GetComponent<RawImage>();
            Texture myTexture = _raw_image.texture;
            string texturePath = AssetDatabase.GetAssetPath(myTexture); 
            Debug.Log("texturePath ="+ texturePath);
            Vector2Int imgSize  = ImageHeader.GetDimensions(texturePath);
            Debug.Log("imgSize.x =" + imgSize.x);
            Debug.Log("imgSize.y =" + imgSize.y);
            get_size = new Vector2(imgSize.x, imgSize.y);
            if(keep_size == null){
                keep_size = get_size;
                rt.sizeDelta = new Vector2(imgSize.x, imgSize.y);
            }else{
                rt.sizeDelta = keep_size;
            }
        #else
            if(keep_size != null)rt.sizeDelta = keep_size;
        #endif
    }
}
```