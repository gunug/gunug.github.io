---
layout: post
title: itween 아이트윈
category: unity3d
tags: unity3d c#
---
# itween 아이트윈
* 설명 블로그 : https://loadofprogrammer.tistory.com/tag/DOTween

```c#
GameObject target = main_pannel;
Vector3 amount = new Vector3(-5,0,0);
float time = 1.0f;
iTween.MoveBy(target, amount, time);
iTween.MoveTo(target, 
iTween.Hash("position",amount, "easetype",iTween.EaseType.easeInSine,"time",1.0f));

public iTween.EaseType easeType;
```
easeInQuad,
easeOutQuad,
easeInOutQuad,
easeInCubic,
easeOutCubic,
easeInOutCubic,
easeInQuart,
easeOutQuart,
easeInOutQuart,
easeInQuint,
easeOutQuint,
easeInOutQuint,
easeInSine,
easeOutSine,
easeInOutSine,
easeInExpo,
easeOutExpo,
easeInOutExpo,
easeInCirc,
easeOutCirc,
easeInOutCirc,
linear,
spring,
bounce,
easeInBack,
easeOutBack,
easeInOutBack,
elastic,
puch

```c#
amount = new Vector3(0,90,0);
iTween.RotateTo(target, 
iTween.Hash("rotation", amount, "easetype", iTween.EaseType.easeInSine,"time", time));
```

## 투명도 제어
```c#
iTween.FadeTo(this.gameObject, 
iTween.Hash("time", 1,"alpha", 1,"onCompleteTarget", this.gameObject,"onComplete", "FadeOut"));
void FadeOut(){
    Debug.Log("tween complete");
}
```

## 값제어
```c#
public void SlideATo(float position)
{
    Debug.Log("B " + position);
    iTween.ValueTo(gObjectA,
    iTween.Hash("from",percentageA,"to",position,"time",EasingSpeedA,"easetype",iTween.EaseType.easeInOutCubic,"onupdate","SlideAPercentage"));    
}
     
void SlideAPercentage(float p)
{
    percentageA=p;
}
```

## 문제 해결

* tween complete 함수는 디폴트로 대상이 되는 오브젝트에서 호출 됩니다 
* 그러니까 저 상태면 _wing 요 오브젝트에서 호출이 일어나고 있을겁니다. 
* 위의 코드에서 RotateFlyWing가 호출이 되게 하실려면 "oncompletetarget", this.gameObject 를 추가 해주시면 될 것 같습니다.
* 연달아 두개의 트윈을 걸어두면 이전 트윈이 날아가는 증상이 있음