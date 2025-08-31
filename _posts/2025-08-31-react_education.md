---
layout: post
title: react 리액트 수업
category: web
tags: 
---


# React 리액트 수업

---

## 필요 프로그램 설치
### node.js <https://nodejs.org/ko/>
* 최신버전 설치(이미 설치되어 있는 경우는 다음단계를 진행하여보고 문제가 있다면 설치)

### visual studio code <https://code.visualstudio.com/>
* 이미 설치되어있다면 설치과정 생략

---

## Visual Studio Code의 Terminal
* 상단 Menu > Terminal > New Terminal로 터미널 창 열기
* ```npm -v```, ```node -v``` 명령어를 입력했을때 버전이 출력되면 정상적으로 설치됨

---

## 프로젝트 생성
* visual studio code의 menu > File > Open Folder 를 이용하여 저장소 위치를 선택
* ```npm create vite@latest```
* Project name : 'react-portfolio' (되도록 대문자 사용 하지 않기)
* Select a Framework : React
* Select a variant : JavaScript + SWC

## 프로젝트 생성 후
* visual studio code의 menu > File > Open Folder
* 생성된 Project name이 적혀있는 폴더를 선택하여 폴더열기를 할 수 있도록 합니다.

## 프로젝트 추가 설치
* ```npm install```
* ```npm install react-router-dom```

## 프로젝트 확인
* ```npm run dev```
* terminal에 출력되는 url 주소로 로컬서버에 접속하여 확인가능
* Ctrl+C, Y로 로컬서버 종료

---

## 발생할 수 있는 에러들
* "npm command not found..." : 에디터 새로 시작, node.js가 제대로 설치 되지 않았거나 최신이 아님, 맥북에서 brew 사용하지 않고 웹사이트에서 직접 다운로드하여 설치하기, 한글 폴더명 사용금지, 윈도우는 onedive 폴더 하위에 생성하지 않기
* "npm install, npm run dev" 명령어 에러 : 한글 폴더명 금지
* 맥북에서 "permisson"관련 에러 : 명령어 앞에 'sudo' 단어를 추가하여 명령어 입력, 비밀번호는 맥북 비밀번호 입력
* 윈도우에서 "허가되지 않은 스크립트"에러 : 윈도우 실행메뉴 검색창에 Powershell 검색, 우클릭 '관리자 권한'으로 실행 ```Set-ExecutionPolicy RemoteSigned``` 입력, 동의 화면에서 Y입력, 터미널 재시작
* "The engine "node" is incompatible with this module"에러 : node.js 버전에 너무 낮거나 높음, 에러메세지 에서 요구하는 버전으로 재설치.
* 환경변수 설정관련은 <https://imspear.tistory.com/31> 내용 참고.

---

## 부연설명
* node.js는 npm 명령어를 사용하기 위해 설치함, npm 명령어를 이용하면 여러가지 라이브러리를 명령어 만으로 쉽게 설치가 가능한데 위 경우는 'create vite'를 사용하였음
* App.tsx는 메인페이지에 들어갈 HTML짜는 곳
* public/index.html는 최종적으로 컴파일된 파일 main.tsx, app.tsx등에서 영향을 받음
* ```style="color:red; font-size:30px;"```가 ```style={ {color:'blue', fontSize:'30px'} }```로 변경 (대시 기호대신 케멀케이스 속성명)

---

# github 연결
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1756650993.jpg" />
* Source Control > Publish to GitHub 선택
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1756651094.jpg" />
* Public repository 선택