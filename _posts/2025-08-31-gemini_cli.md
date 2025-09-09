---
layout: post
title:  "Gemini CLI 설치 및 사용법"
date:   2025-08-31 10:14:09 +0900
categories: jekyll update
---

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
