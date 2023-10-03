---
layout: post
title: dotween 두트윈
category: unity-asset
tags: c#
---
# dotween 두트윈
* 설명 블로그 : https://loadofprogrammer.tistory.com/tag/DOTween
* 두트윈 설명 : https://velog.io/@livelyjuseok/Unity-DOTween-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0
* 두트윈 사용법 : https://postpiglet.netlify.app/posts/unity-dotween/
* 시퀀스 관련내용 : https://blog.naver.com/PostView.naver?blogId=dooya-log&logNo=221332052854&categoryNo=9&parentCategoryNo=6
* 두트윈 공식문서 : http://dotween.demigiant.com/documentation.php

---

# DoTween 설치
* setup dotween 선택하여 설치과정을 진행하여야 함
* create ASMDEF

---

```c#
using DG.Tweening;
Color targetColor = new Color();
float targetAlpha = 0.0f;
transform.GetComponent<Renderer>().material.DOColor(targetColor, 3);
transform.GetComponent<Renderer>().materials[0].DOFade(targetAlpha,1);
```

---
## Sequence 시퀀스

```c#
Sequence _sequence = DOTween.Sequence();
_sequence.Append(transform.DOMoveX(45,1))
    .Append(transform.DORotate(new Vector3(0,180,0),1))
    .PrependInterval(1)
    .Insert(0, transform.DOScale(new Vector3(3,3,3), mySequence.Duration())
);
```

* NULL 시퀀스 에러가 있어서 다음과 같이 수정

```c#
Sequence _sequence = DOTween.Sequence()
        .Append(_renderer.materials[0].DOFade(0.0f, 1))
        .AppendCallback(change_time)
        .Append(_renderer.materials[0].DOFade(1.0f, 1));
private void change_time(){
    Debug.Log("change time");
}
```

* 시퀀스 생성과 동시에 시퀀스 내용을 명시해야함

---

```c#
DOTween.To(() => my_post.weight, x => my_post.weight = x, 1, TWEEN_TIME);
```

```c#
transform.DOMove(default_location, TWEEN_TIME).SetEase(Ease.OutCubic); 
transform.DOScale(new Vector3(1, 1, 1), TWEEN_TIME).SetEase(Ease.OutCubic); 
Color new_color = new Color(1, 1, 1, 1); 
self.material.DOColor(new_color, TWEEN_TIME).SetEase(Ease.OutCubic); 
DOVirtual.DelayedCall(1.0f, () =>{setContent(0);});
```

* RawImage인 경우는 .material빼고 직접 RawImage를 연결하면 됨