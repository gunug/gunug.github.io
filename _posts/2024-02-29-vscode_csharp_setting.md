---
layout: post
title: visual studio code c# setting
category: etc
tags: etc
---

# visual studio code c# setting
* Visual Studio Code 셋팅
* https://code.visualstudio.com/docs/languages/csharp
* Ctrl+Shift+X  'C#' 검색
* Dotnet SDK 설치
* Visual Studio Code를 관리자 권한으로 실행
* Open folder를 이용하여 새 폴터를 오픈
* cmd에서 dotnet new console 입력하여 새 프로젝트를 폴더에 세팅
* cmd에서 dotnet run입력하면 Program.cs가 수행됨

```c#
  using System.IO;
  
  namespace root{
    public class base_class{
        static void Main(String[] args) {
            Console.WriteLine("run!");
            Sub();
        }
        static void Sub(){
            Console.WriteLine("Hello, World!");
        }        
    }
  }
```

* https://docs.microsoft.com/ko-kr/dotnet/csharp/
* https://docs.microsoft.com/en-us/learn/paths/csharp-first-steps/?WT.mc_id=dotnet-35129-website
