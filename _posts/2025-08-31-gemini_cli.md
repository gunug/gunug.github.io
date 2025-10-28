---
layout: post
title:  "Gemini CLI 설치 및 사용법"
date:   2025-08-31 10:14:09 +0900
categories: jekyll update
---

* 마지막 업데이트 : 2025-10-28

## Gemini CLI 설치

Gemini CLI는 Google의 AI 모델을 터미널에서 직접 사용할 수 있게 해주는 도구입니다.

### 사전 요구 사항

-   Node.js (버전 18 이상) <https://nodejs.org/ko/>
-   npm (Node Package Manager) : Node.js 설치시 이용할수 있음

### 설치

터미널에서 다음 명령어를 실행하여 Gemini CLI를 전역으로 설치합니다.
* 시작메뉴에서 'cmd'로 검색한뒤 실행하여 터미널창을 실행
* 윈도우 탐색기 경로입력창에 'cmd'입력한 뒤 엔터키를 눌러 터미널창을 실행

```bash
npm install -g @google/gemini-cli
```

### 최초 설정 및 인증

1.  **CLI 실행**: 터미널에 `gemini`를 입력하여 CLI를 시작합니다.

    ```bash
    gemini
    ```

2.  **테마 선택**: 첫 실행 시, 인터페이스의 색상 테마를 선택하라는 메시지가 표시됩니다.

3.  **인증**: "Login with Google"을 선택하여 Google 계정으로 로그인합니다. 이를 통해 분당 60개, 하루 1,000개의 요청을 무료로 사용할 수 있는 Gemini 2.5 Pro 모델을 사용할 수 있습니다.

### 시작하기

인증이 완료되면 Gemini와 상호작용할 준비가 된 것입니다. 코드베이스 이해, 버그 수정, 문서 생성 등 다양한 작업을 요청할 수 있습니다.

사용 가능한 명령어 및 기능 목록을 보려면 Gemini CLI 프롬프트 내에서 `/help`를 입력하십시오.

---

# Unity3D 에서 Gemini CLI 사용하기
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1761612845.jpg" />
* project창 > Assets 마우스 우클릭 > Create > Folder
* 폴더명은 "GeminiScript"로 작성 (자유롭게 작성해도 되나, 혼란을 방지하기 위함)

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1761613191.jpg" />
* project창 > GeminiScript 마우스 우클릭 > Show in Exploerer 선택하여 폴더위치 열기

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1761613346.jpg" />
* 폴더 위치가 열리면 GeminiScript 폴더를 더블클릭하여 안으로 이동

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1761613421.jpg" />
* 경로가 적혀있는 입력창에 ```cmd``` 입력하고 엔터

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1761613498.jpg" />
* 터미널에서 ```gemini``` 입력하고 엔터

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1761613591.jpg" />
* gimini 프롬프트가 뜨면 사용준비 완료

---

# 세션 유지
* Gemini는 Gemini.md 파일에 세션에 관련된 정보를 기록하고 다음 세션에서 유지할 수 있습니다.
* 일반적으로는 세션이 종료되면 각 세션에서 요청했던 내용은 저장되지 않고. 다음 세션에서 다시 설명해야 합니다.
* 'Gemini.md파일을 생성하고 세션을 유지할 수 있도록 내용을 기록해줘' 라는 요청등으로 세션 기록사항을 유지할 수 있습니다.