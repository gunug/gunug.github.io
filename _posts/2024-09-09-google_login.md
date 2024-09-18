---
layout: post
title: google login 구글 로그인
category: web
tags: 
---

# Google Login
## 참고자료 
* <https://notspoon.tistory.com/45>
* <https://notspoon.tistory.com/46>
* <https://notspoon.tistory.com/47>

---

# Google Developer 설정
* <https://console.cloud.google.com/>

## 프로젝트 생성
* 좌측 상단에 프로젝트 명이 적혀있는 콤보박스 클릭
* 새 프로젝트, 이름 입력후 확인하여 새 프로젝트 생성

## OAuth 동의
### OAuth 동의 화면
* 검색창에 ```oauth``` 입력 'OAuth 동의화면' 선택
* User Type 외부 선택 후 만들기 클릭
* 필수정보 입력

### 범위
* '범위 추가 또는 삭제' 버튼 클릭
* 최상단 3개 항복 선택 후 업데이트 클릭
* 저장 후 계속 클릭

### 테스트 사용자
* google 로그인 테스트를 위한 계정 추가 (누구나 사용하기 위해선 별도 애플리케이션 심사 필요)

## 사용자 인증 정보
* '사용자 인증정보 만들기' 선택
* OAuth 클라이언트 ID 만들기
* 애플리케이션 유형 > 웹 애플리케이션
* 승인된 Javascript 원본 : 구글 로그인을 사용할 홈페이지 주소 입력
* 승인된 리디렉션 URI 항목에 구글 로그인 후 Redirect할 주소 입력
* 클라이언트 ID와 보안 비밀번호가 표시됨

# 개발 환경 설정
# 초기화 및 로그인 구현하기