---
layout: post
title: Google Gemini CLI
category: AI
tags: gemini cli google
---

# CLI란?

CLI(Command Line Interface)는 텍스트 명령어를 입력하여 컴퓨터와 상호작용하는 인터페이스이다. 마우스로 클릭하는 GUI(Graphical User Interface)와 달리, 키보드로 명령어를 직접 타이핑하여 프로그램을 실행하고 제어한다. 개발자들이 자주 사용하는 터미널(Terminal), 명령 프롬프트(cmd), PowerShell 등이 CLI 환경에 해당한다.

![CLI 터미널 환경 예시](/data_image/cli_terminal_example.png)

---

# Google Gemini CLI 개요

![Gemini CLI 실행 화면](/data_image/gemini_cli_screenshot.png)

Gemini CLI는 Google이 만든 오픈소스 AI 에이전트로, 터미널에서 직접 Gemini 모델을 사용할 수 있게 해주는 커맨드라인 도구이다. 코드 생성, 파일 편집, 프로젝트 탐색 등 다양한 개발 작업을 터미널 환경에서 AI의 도움을 받아 수행할 수 있다.

- GitHub: [https://github.com/google-gemini/gemini-cli](https://github.com/google-gemini/gemini-cli)
- 공식 문서: [https://geminicli.com/docs/](https://geminicli.com/docs/)

---

# 설치 방법

## 사전 요구사항

| 항목 | 요구사항 |
|---|---|
| OS | macOS 15+, Windows 11 24H2+, Ubuntu 20.04+ |
| RAM | 일반 사용: 4GB+, 고급 사용: 16GB+ |
| 런타임 | **Node.js 20.0.0 이상** |
| 셸 | Bash, Zsh, 또는 PowerShell |

## Node.js 설치 (사전 설치)

Node.js가 설치되어 있지 않다면 먼저 설치해야 한다.

### Windows
[https://nodejs.org](https://nodejs.org) 에서 LTS 버전 다운로드 후 설치

### macOS (Homebrew)
```bash
brew install node
```

### Ubuntu/Debian
```bash
curl -fsSL https://deb.nodesource.com/setup_20.x | sudo -E bash -
sudo apt-get install -y nodejs
```

설치 확인:
```bash
node --version  # v20.0.0 이상이어야 함
```

## Gemini CLI 설치

### npm 글로벌 설치 (권장)
```bash
npm install -g @google/gemini-cli
```

### Homebrew (macOS/Linux)
```bash
brew install gemini-cli
```

### 설치 없이 바로 실행 (npx)
```bash
npx @google/gemini-cli
```

### Conda 환경
```bash
conda create -y -n gemini_env -c conda-forge nodejs
conda activate gemini_env
npm install -g @google/gemini-cli
```

## 실행

설치 후 터미널에서 다음 명령으로 실행:
```bash
gemini
```

최초 실행 시 Google 계정으로 로그인 인증이 필요하다.

---

# 요금 정책

## 무료 버전 (Free Tier)

### Google 계정 로그인 (Gemini Code Assist for individuals)

| 항목 | 제한 |
|---|---|
| 일일 요청 수 | **1,000 요청 / 사용자 / 일** |
| 분당 요청 수 | **60 요청 / 사용자 / 분** |
| 사용 모델 | Gemini 모델 패밀리 전체 |
| 비용 | **무료** |

### Gemini API Key (무료 등급)

| 항목 | 제한 |
|---|---|
| 일일 요청 수 | **250 요청 / 사용자 / 일** |
| 분당 요청 수 | **10 요청 / 사용자 / 분** |
| 사용 모델 | **Flash 모델만** |
| 비용 | **무료** |

> Google 계정 로그인 방식이 무료 이용량이 훨씬 많으므로 개인 사용자에게 권장된다.

## 유료 버전

### Google AI Pro / Ultra 구독
- Google의 고정 가격 구독 플랜
- 구독 등급에 따라 쿼터 상향

### Gemini Code Assist (Cloud Console)

| 등급 | 일일 요청 | 분당 요청 |
|---|---|---|
| Standard | 1,500 요청 / 사용자 / 일 | 120 요청 / 사용자 / 분 |
| Enterprise | 2,000 요청 / 사용자 / 일 | 120 요청 / 사용자 / 분 |

### Pay-As-You-Go (종량제)
- **Vertex AI:** 토큰 단위 과금, 모델별 요금 상이
- **Gemini API Key (유료):** 토큰/호출 단위 과금, 쿼터 제한 없음

## 사용량 확인

세션 중 `/stats model` 명령으로 실시간 토큰 사용량과 쿼터 정보를 확인할 수 있다.
