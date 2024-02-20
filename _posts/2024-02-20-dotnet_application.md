---
layout: post
title: .Net Application 닷넷 어플리케이션
category: etc
tags: 
---

# 링크 
* https://dotnet.microsoft.com/learn/dotnet/hello-world-tutorial/intro

# 새 앱 만들기 
* <source inline>dotnet new console -o myApp</source>
* <source inline>cd myApp</source>
* 들어가보면 program.cs파일이 생겨 있음

# 빌드하기 
* https://docs.microsoft.com/ko-kr/dotnet/core/tools/dotnet-build
# 배포파일 만들기 
* https://dzone.com/articles/generate-an-exe-for-net-core-console-apps-net-core
* <source inline>dotnet publish -c Debug -r win10-x64</source>
* \bin\Debug\netcoreapp3.0 위치에 실행파일 생성됨
* <source inline>dotnet publish -c Release -r win10-x64</source>

---

# GUI 환경 만들기 
* https://docs.microsoft.com/ko-kr/dotnet/framework/winforms/how-to-create-a-windows-forms-application-from-the-command-line

# .Net application 종류 
* https://docs.microsoft.com/en-us/visualstudio/get-started/csharp/tutorial-console?view=vs-2019
* Create your first C# app
* Create a web app
* Create a UWP app (Universal Windows Platform application)
* Create a WPF application (그래프와 차트를 표현하는 어플들이 예시로 검색 되더라)
* Create a Windows Forms app

# 연산자 오버로딩 
* 연산자 오버로딩 구현 함수 형식
* ```return_type operator op ( argments );```
* 0p 는 연산자 ( +-/* )

---

# opencv 프로젝트 셋팅 
* 프로젝트 > 프로젝트 속성
  * C,C++ 일반 / 추가 포함 디렉터리 : C:\opencv\build\include
  * 링커 일반 / 추가 라이브러리 디렉터리 : C:\opencv\build\x64\vc15\lib
  * 링커 입력 / 추가 종속성 : opencv_world412.lib , opencv_world412d.lib
* 프로젝트 만들때 '미리 컴파일된 헤더' 체크 해제 해야함.
