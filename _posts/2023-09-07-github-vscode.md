---
layout: post
title: Github 가입하고 visual studio code와 연결하기
category: web
tags: web github
---

# Github 가입하고 visual studio code와 연결하기

## Github 회원가입
* [https://github.com/](https://github.com/){:target="_blnak"}
* "Sign up"선택
* Username, Email Adress, Password등 입력등 가입절차 진행
* 계정유형은 "Free 무료" 선택
* 이메일 인증절차 수행

## 로그인 후 저장소(repository) 생성
* New를 눌러서 새 저장소 생성

![image](https://github.com/gunug/gunug.github.io/assets/52345276/e0bac860-a2b6-427d-8f29-cbdcb680fa38)

* Repository Name은 "아이디.github.io" 입력
* "Add a README file" 체크
* "Create repository" 선택하여 새 저장소 만들기


---

## visual studio code와 연동
![image](https://github.com/gunug/gunug.github.io/assets/52345276/9148cb29-58f0-4b12-bb59-4ddfc38d2f9a)

* [https://git-scm.com/](https://git-scm.com/){:target="_blank"}
* Latest source Release 다운로드하여 설치
* vscode 실행
* F1키 누르기
* git clone 입력
* Git:Clone 메뉴 선택

![image](https://github.com/gunug/gunug.github.io/assets/52345276/3ef0e157-a6bf-466a-ae09-e6d2f47d9805)
* Clone Repository 선택

![image](https://github.com/gunug/gunug.github.io/assets/52345276/c85ee0ee-1b7e-442e-bc8d-1edc09d89b45)
* github.com에서 repository 상세, code에서 복사 버튼 클릭하여 주소를 복사
* vscode의 입력창에 붙여넣기 한 후 엔터

* 클론 시킬 폴더(위치 설정)

---

## 작성한 문서를 github에 업로드 하기
![image](https://github.com/gunug/gunug.github.io/assets/52345276/ded6bade-39e9-47fe-b693-e762e45c67a6)
* git>source control에 사유 입력하기>commit옆 화살표>commit & sync 선택 하여 git에 업로드

---

## user.name, user.email 에러 해결
* 시작메뉴 cmd 입력하여 터미널 실행

```markdown
git config --global user.name '유저네임'
git config --global user.email '이메일주소'
```

---

# mac에서 git연동하기
* [https://git-scm.com/](https://git-scm.com/) 접속
* honebrew 링크 클릭
* [https://brew.sh/](https://brew.sh/) 사이트로 이동됨

* install homebrew 하단의 터미널 명령 복사

```markdown
$ /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```
* 패스워드를 입력 후 계속진행
* 다음의 설명

```markdown 
Next steps: Run these two commands in your terminal to add Homebrew
to your PATH: (echo: echo 'eval "$(/opt/homebrew/bin/brew shellenv)"') >> /
Users/vechanshon/.zprofile eval "$(/opt/homebrew/bin/brew shellenv)”
```

* 홈브류 버전확인

```markdown
$ brew --version
```

* 다음과 같은 에러가 나온다면 경로 추가

```markdown
zsh: command not found: brew
```

```markdown
$ echo 'export PATH=/opt/homebrew/bin:$PATH' >> ~/.zshrc
$ source ~/.zshrc
```
