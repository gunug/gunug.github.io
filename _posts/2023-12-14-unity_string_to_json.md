---
layout: post
title: string to json
category: unity3d
tags: dotnet simple-code
---

# Newtonsoft json library
* 출처[https://gofogo.tistory.com/64](https://gofogo.tistory.com/64)
* package manager > + > add package my name
* com.unity.nuget.newtonsoft-json 를 입력 후  Version 은 선택이지만 2.0.0를 입력 후 [Add]한다.

* 출처: [https://www.delftstack.com/ko/howto/csharp/convert-string-to-json-in-csharp/](https://www.delftstack.com/ko/howto/csharp/convert-string-to-json-in-csharp/)

```c#
using Newtonsoft.Json.Linq;
using System;
namespace fina {
  class Program {
    static void Main(string[] args) {
      string str =
          "{ \"context_name\": { \"lower_bound\": \"value\", \"upper_bound\": \"value\", \"values\": [ \"value1\", \"valueN\" ] } }";
      JObject json = JObject.Parse(str);
      foreach (var e in json) {
        Console.WriteLine(e);
      }
    }
  }
}
```

* 출처 [https://ojui.tistory.com/90](https://ojui.tistory.com/90)
* 유니티 자체 내장클래스를 사용하면 dll 추가없이 간편하지만 이중 구조는 파싱이 안된다는 것 같다.
* 공식문서 [https://docs.unity3d.com/ScriptReference/JsonUtility.html](https://docs.unity3d.com/ScriptReference/JsonUtility.html)
