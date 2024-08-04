---
layout: post
title: Class Diagram 클래스 다이어그램
category: coding
tags: 
---

* [클래스 다이어그램 그리기](https://staruml.io/)

---

## c# class diagram 자동생성
* [vs code extension](https://marketplace.visualstudio.com/items?itemName=pierre3.csharp-to-plantuml)

* extansion 설치
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1721801716.jpg" />

* file > Preferences > Settings

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1721801875.jpg" />

* input path에 해당하는 파일을 읽어서 output path에 파일을 생성함

## 커멘드 입력

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1721801664.jpg" />

* 커멘드 확인 위치
* ```csharp2plantuml.classDiagram```

* ctrl + shift + p 키입력 후 커멘드 창에 입력
* plantuml 폴더가 생성됨

---

# plantUML
* [https://plantuml.com/ko/](https://plantuml.com/ko/)

## 설치하기
* 자바가 우선 설치되어 있어야 합니다.
* 터미널에 ```java -version``` 입력하여 자바 버전을 확인 할 수 있습니다.
* 없다면 공식 웹사이트 <https://www.oracle.com/java/technologies/> 통해서 설치

### GraphViz
* 윈도우의 경우 GraphViz의 컴파일된 버전인 PlantUML에 내장되어 있어 별도의 설치가 필요 없다.

### plantuml.jar
* <https://plantuml.com/ko/download> 위치에서 다운로드 가능
* 파일을 옮겨둔 폴더에서 다음 커멘드 입력
* ```java -jar plantuml-1.2024.6.jar -gui```
* GUI 파일을 실행한다음 디렉토리를 지정하면 디렉토리에 생성되어있던 puml파일을 png파일로 변환해줌

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1721803698.jpg" />

결과예시