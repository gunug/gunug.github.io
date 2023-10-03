---
layout: post
title: Unity .net 이용하기
category: unity3d
tags: dotnet
---

#  unity .net 이용하기
* Projector setting > player > other settings > configuration > api compatibility level
* .NET Standard 2.1
* 이쪽 버전 문제인지 SoundPlayer 내용이 적다

---

# .NET 4.x로 업그레이드
* [https://learn.microsoft.com/ko-kr/visualstudio/gamedev/unity/unity-scripting-upgrade](https://learn.microsoft.com/ko-kr/visualstudio/gamedev/unity/unity-scripting-upgrade)
* 전제조건 Unity 2022.2이상, Visual Studio 2019 이상
* .NET frameworks로 선택 (.NET 4.x가 frameworks라는 이름으로 통합되었다는 이야기가 있습니다)

---

# SoundPlayer
```c#
using System.Media;
SoundPlayer snd = new SoundPlayer();

```

---

# nAudio
* [https://github.com/naudio/NAudio](https://github.com/naudio/NAudio)
* [naudio-with-unity3d](https://code.google.com/archive/p/naudio-with-unity3d/downloads)
* 유니티 에셋 파일 안에 Plugins 파일을 만들어 주고 그 안에 dll 파일을 넣어준다.
* [사용법 설명 블로그 글](https://blog.naver.com/PostView.naver?blogId=nuren1&logNo=220931574360)
* .NET Standard 2.1 선택 (frameworks에서는 dll이 찾아지지 않음)

```c#
using UnityEngine;
using System.IO;
using System;
using NAudio;
using NAudio.Wave;

public static class NAudioPlayer {
    public static AudioClip FromMp3Data(byte[] data)
    {
        // Load the data into a stream
        MemoryStream mp3stream = new MemoryStream(data);
        // Convert the data in the stream to WAV format
        Mp3FileReader mp3audio = new Mp3FileReader(mp3stream);
        WaveStream waveStream = WaveFormatConversionStream.CreatePcmStream(mp3audio);
        // Convert to WAV data
        WAV wav = new WAV(AudioMemStream(waveStream).ToArray());
        Debug.Log(wav);
        AudioClip audioClip = AudioClip.Create("testSound", wav.SampleCount, 1,wav.Frequency, false);
        audioClip.SetData(wav.LeftChannel, 0);
        // Return the clip
        return audioClip;
    }

    private static MemoryStream AudioMemStream(WaveStream waveStream)
    {
        MemoryStream outputStream = new MemoryStream();
        using (WaveFileWriter waveFileWriter = new WaveFileWriter(outputStream, waveStream.WaveFormat)) 
        { 
            byte[] bytes = new byte[waveStream.Length]; 
            waveStream.Position = 0;
            waveStream.Read(bytes, 0, Convert.ToInt32(waveStream.Length)); 
            waveFileWriter.Write(bytes, 0, bytes.Length); 
            waveFileWriter.Flush(); 
        }
        return outputStream;
    }
}

/* From http://answers.unity3d.com/questions/737002/wav-byte-to-audioclip.html */
public class WAV  {

    // convert two bytes to one float in the range -1 to 1
    static float bytesToFloat(byte firstByte, byte secondByte) {
        // convert two bytes to one short (little endian)
        short s = (short)((secondByte << 8) | firstByte);
        // convert to range from -1 to (just below) 1
        return s / 32768.0F;
    }

    static int bytesToInt(byte[] bytes,int offset=0){
        int value=0;
        for(int i=0;i<4;i++){
            value |= ((int)bytes[offset+i])<<(i*8);
        }
        return value;
    }
    // properties
    public float[] LeftChannel{get; internal set;}
    public float[] RightChannel{get; internal set;}
    public int ChannelCount {get;internal set;}
    public int SampleCount {get;internal set;}
    public int Frequency {get;internal set;}

    public WAV(byte[] wav){

        // Determine if mono or stereo
        ChannelCount = wav[22];     // Forget byte 23 as 99.999% of WAVs are 1 or 2 channels

        // Get the frequency
        Frequency = bytesToInt(wav,24);

        // Get past all the other sub chunks to get to the data subchunk:
        int pos = 12;   // First Subchunk ID from 12 to 16

        // Keep iterating until we find the data chunk (i.e. 64 61 74 61 ...... (i.e. 100 97 116 97 in decimal))
        while(!(wav[pos]==100 && wav[pos+1]==97 && wav[pos+2]==116 && wav[pos+3]==97)) {
            pos += 4;
            int chunkSize = wav[pos] + wav[pos + 1] * 256 + wav[pos + 2] * 65536 + wav[pos + 3] * 16777216;
            pos += 4 + chunkSize;
        }
        pos += 8;

        // Pos is now positioned to start of actual sound data.
        SampleCount = (wav.Length - pos)/2;     // 2 bytes per sample (16 bit sound mono)
        if (ChannelCount == 2) SampleCount /= 2;        // 4 bytes per sample (16 bit stereo)

        // Allocate memory (right will be null if only mono sound)
        LeftChannel = new float[SampleCount];
        if (ChannelCount == 2) RightChannel = new float[SampleCount];
        else RightChannel = null;

        // Write to double array/s:
        int i=0;
        while (pos < wav.Length) {
            LeftChannel[i] = bytesToFloat(wav[pos], wav[pos + 1]);
            pos += 2;
            if (ChannelCount == 2) {
                RightChannel[i] = bytesToFloat(wav[pos], wav[pos + 1]);
                pos += 2;
            }
            i++;
        }
    }

    public override string ToString ()
    {
        return string.Format ("[WAV: LeftChannel={0}, RightChannel={1}, ChannelCount={2}, SampleCount={3}, Frequency={4}]", LeftChannel, RightChannel, ChannelCount, SampleCount, Frequency);
    }
}
```

* 사용 예시

```c#
WWW www = new WWW (musicUrl);
while(!www.isDone){
    yield return 0;
}
GetComponent<AudioSource> ().clip = NAudioPlayer.FromMp3Data(www.bytes);
```