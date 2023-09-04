---
layout: post
title: VideoPlayer 비디오플레이어
category: unity3d
tags: unity3d c#
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