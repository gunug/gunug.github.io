---
layout: post
title: Function Send 함수를 인자값으로 전달
category: unity3d
tags: unity3d c#
---

# 함수를 인자값으로 전달

* 참고 : https://developer-talk.tistory.com/208
* Func, Action, Predicate

* Func 대리자 : 0~16개의 입력 매개 변수를 가지며, void형을 제외한 반환 타입을 가지는 메서드를 참조하는 대리자
* Action 대리자 : 0~16개의 입력 매개 변수를 가지며, 반환 타입이 void형인 메서드를 참조하는 대리자
* Predicate 대리자 : 무조건 1개의 입력 매개 변수를 가지며, 반환 타입이 bool형인 메서드를 참조하는 대리자

---

# 메서드 그룹과 델리게이트

* 참고 : https://www.delftstack.com/howto/csharp/method-groups-in-csharp/