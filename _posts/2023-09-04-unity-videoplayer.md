---
layout: post
title: VideoPlayer 비디오플레이어
category: unity3d
tags: video
---

# progress bar 프로그레스바
```c#
VideoPlayer VP;
if(VP.frameCount > 0) { 
    slider_value = (float)VP.frame / (float)VP.frameCount;
}
```

# 동영상 총길이
```c#
VideoClip VC;
VC.length;
VideoPlayer VP;
VP.clip.length; //초단위
```

# 초를 시분초로 변환

```c#
using System;
TimeSpan seconds = TimeSpan.FromSeconds(value);
string time = seconds.ToString(@"hh\:mm\:ss");
Debug.Log(time);
```

# 0~1 프로그래스로 time 제어
```c#
_video.time = Progress * _video.clip.length;
```

---

## 동적 출력

```c#
public VideoPlayer _videoPlayer;

void Awake()
{
    _videoPlayer.prepareCompleted += OnVideoPrepared;
    _videoPlayer.clip = Resources.Load<VideoClip>("ExamClip");
    _videoPlayer.Prepare();
}

void OnVideoPrepared(VideoPlayer source_)
{
    _videoPlayer.Play();
}
```