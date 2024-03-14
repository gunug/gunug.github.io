---
layout: post
title: c# action 대리자 가변성
category: c#
tags: c#
---

* https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/concepts/covariance-contravariance/using-variance-for-func-and-action-generic-delegates

* https://geojun.tistory.com/m/64 
* https://young-94.tistory.com/196

* 매개 변수가 하나이고 값을 반환하지 않는 매서드를 캡슐화

using System;

* Action을 사용하면 여러 함수를 동적으로 호출할 수 있습니다.
* Action는 인수가 없음으로 호출하는 함수에도 인수가 없어야 합니다.