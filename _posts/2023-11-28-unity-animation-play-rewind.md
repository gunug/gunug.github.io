---
layout: post
title: animation play rewind 애니메이션 재생 되돌리기
category: unity3d
tags: c#
---

# Animator에서 Animation 속도를 조절하려다 생긴 문제

* Animation에 접근할수 있다면 speed를 음수로 변경하면됨
* Animator만 있다면 AnimationClip에 접근할수 있지만 Animation이라는 class는 없음
* Animator의 speed를 직접 제어하면 음수는 입력불가 - 에러
* Animator에 float parameter를 만든다음 안에 있는 Animation에 multiplier에 연결한다음 SetFloat으로 parameter를 음수로 조정하면 됨
* +쪽엔 Play(0);을 넣고 -쪽엔 안넣는게 맞음.

---

# AnimationClip 의 마지막을 지나쳤는데도 카운트가 계속되는 문제
* 롤오버를 길게 하고 있을경우 돌아오는데까지 시간이 걸림

```c#
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public class HoverButton : MonoBehaviour
{
    Animator ani_;
    float current_time = 0;
    void Start()
    {
        ani_ = GetComponent<Animator>();
        ani_.SetFloat("speed_multiple", 0);
    }

    private void setCurrentTime()
    {
        current_time = ani_.GetCurrentAnimatorStateInfo(0).normalizedTime;
        //받아온 normalizedTime이 0보다 작거나 1보다 큰 경우가 생김. 후처리
        if (current_time < 0) current_time = 0;
        if (current_time > 1) current_time = 1;
    }

    private void OnMouseEnter()
    {
        setCurrentTime();
        ani_.SetFloat("speed_multiple", 1);
        ani_.Play(0, 0, current_time);
    }
    private void OnMouseExit()
    {
        setCurrentTime();
        ani_.SetFloat("speed_multiple", -1);
        ani_.Play(0, 0, current_time);
    }
}
```

* play의 맨 마지막 인자값 normaledTime을 추가하면 되는데.. 현재 시간을 알수가 없어서 최댓값 최솟값을 넣는것은 퀄리티 문제가 있었다.
* ani_.GetCurrentAnimatorStateInfo(0).normalizedTime 애니메이터의 첫번째 클립의 스테이트 인포베이션을 얻어오는것으로 해결

---

# string 이름으로 애니메이션 클립 찾기


```c#
public AnimationClip FindAnimation (Animator animator, string name) 
{
   foreach (AnimationClip clip in animator.runtimeAnimatorController.animationClips)
   {
      if (clip.name == name)
      {
         return clip;
      }
   }

   return null;
}
```