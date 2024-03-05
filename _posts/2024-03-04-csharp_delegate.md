---
layout: post
title: C# Delegate 대리자
category: c#
tags: c#
---

* 참고내용 : https://docs.microsoft.com/ko-kr/dotnet/csharp/programming-guide/delegates/using-delegates?source=recommendations

```c#
using System.IO;
namespace root{
    public class delegate_sample{
        public void init(){
            // Instantiate the delegate.
            Del d1 = DelegateMethod; //유형이 맞으면 대리자 등록
            Del d2 = DelegateMethod2;
            Del handler = d1 + d2; //대리자를 덧셈으로 추가 가능
            handler += d2; //가산식 적용가능
            // 뺄셈이나 감산식 적용가능

            // Call the delegate.
            handler("delegate sample activate!");

            MethodWithCallback(0,1,handler); //대리자를 메서드에 전달하여 콜백용으로 사용

            int invocationCount = handler.GetInvocationList().GetLength(0); //대리자에 포함된 메서드 숫자 알아내기
            Console.WriteLine("invocationCount:"+invocationCount);
        }

        public void CallBackFunction(){
            Console.WriteLine("call back function activate!");
        }

        public delegate void Del(string message); //대리자 선언

        public static void DelegateMethod(string message){
            Console.WriteLine(message);
        }
        public static void DelegateMethod2(string message){
            Console.WriteLine("is from 2 :"+message);
        }

        public static void MethodWithCallback(int param1, int param2, Del callback)
        {
            callback("The number is: " + (param1 + param2).ToString());
        }
    }
}
```
