---
layout: post
title: Google Gemini CLI 설치 가이드
category: AI
tags: gemini cli google
---

# CLI란?

CLI(Command Line Interface)는 텍스트 명령어로 컴퓨터를 제어하는 인터페이스이다. GUI와 달리 키보드로 명령어를 직접 입력한다.

![CLI 터미널 환경 예시](/data_image/cli_terminal_example.png)

# AI를 CLI로 사용하는 장점

- **프로젝트 폴더에서 바로 실행:** 작업 중인 폴더에서 AI를 호출하므로 파일 복사/붙여넣기 없이 코드를 직접 읽고 수정할 수 있다.
- **파일 일괄 처리:** 여러 파일을 한 번에 분석하거나 수정하는 작업을 명령어 하나로 처리할 수 있다.
- **브라우저 불필요:** 웹 채팅창을 오갈 필요 없이 터미널 안에서 코딩과 AI 질의를 동시에 수행한다.
- **자동화 연계:** 셸 스크립트, CI/CD 파이프라인 등과 조합하여 반복 작업을 자동화할 수 있다.
- **리소스 절약:** GUI가 없으므로 메모리와 CPU 사용이 적고, 원격 서버(SSH)에서도 그대로 사용 가능하다.

# Gemini CLI

![Gemini CLI 실행 화면](/data_image/gemini_cli_screenshot.png)

Google이 만든 오픈소스 터미널 AI 도구. 터미널에서 Gemini 모델로 코드 생성, 파일 편집 등을 수행한다.

- GitHub: [https://github.com/google-gemini/gemini-cli](https://github.com/google-gemini/gemini-cli)
- 공식 문서: [https://geminicli.com/docs/](https://geminicli.com/docs/)

---

# Windows 설치

## 1. Node.js 설치

[https://nodejs.org](https://nodejs.org) 에서 LTS 버전 다운로드 후 설치

설치 확인:
```bash
node --version
```

## 2. Gemini CLI 설치

```bash
npm install -g @google/gemini-cli
```

## 3. 실행

```bash
gemini
```

최초 실행 시 Google 계정 로그인 필요.

---

# macOS 설치

## 1. Node.js 설치

```bash
brew install node
```

설치 확인:
```bash
node --version
```

## 2. Gemini CLI 설치

npm 방식:
```bash
npm install -g @google/gemini-cli
```

또는 Homebrew 방식:
```bash
brew install gemini-cli
```

## 3. 실행

```bash
gemini
```

최초 실행 시 Google 계정 로그인 필요.

---

# 요금 정책

## 무료 (Google 계정 로그인)

| 항목 | 제한 |
|---|---|
| 일일 요청 수 | **1,000 요청 / 사용자 / 일** |
| 분당 요청 수 | **60 요청 / 사용자 / 분** |
| 사용 모델 | Gemini 모델 패밀리 전체 |

## 무료 (API Key)

| 항목 | 제한 |
|---|---|
| 일일 요청 수 | **250 요청 / 사용자 / 일** |
| 분당 요청 수 | **10 요청 / 사용자 / 분** |
| 사용 모델 | **Flash 모델만** |

> Google 계정 로그인 방식이 이용량이 훨씬 많으므로 권장.

## 유료

| 등급 | 일일 요청 | 분당 요청 |
|---|---|---|
| Standard | 1,500 / 일 | 120 / 분 |
| Enterprise | 2,000 / 일 | 120 / 분 |

사용량 확인: 세션 중 `/stats model` 명령 입력
