---
layout: post
title: react, Github 세팅중 에러 모음
category: web
tags: 
---

# react, Github 세팅중 에러 모음

## 원격 저장소가 제대로 설정되지 않음
```
Error: Failed to get remote.origin.url (task must either be run in a git repository with a configured origin remote or must be configured with the "repo" option).
    at C:\ReactRepository\react-porfolio\node_modules\gh-pages\lib\git.js:214:13
    at process.processTicksAndRejections (node:internal/process/task_queues:105:5)
```
* Visual Studio Code에서 GitHub에 파일을 업로드할 때, 해당 프로젝트가 Git 저장소로 초기화되지 않았거나 **원격 저장소(remote origin)**가 제대로 설정되지 않았을 때 발생
* Git 저장소 초기화: 터미널에서 프로젝트 폴더로 이동한 후, 다음 명령어를 입력하여 Git 저장소를 초기화합니다.

```
git init
```

* 원격 저장소 연결: GitHub에 있는 원격 저장소의 URL을 복사한 후, 아래 명령어를 사용하여 로컬 저장소와 연결합니다. <원격 저장소 URL> 부분에 복사한 URL을 붙여넣으세요.

```
git remote add origin <원격 저장소 URL>
```

* 파일 커밋 후 푸시: 이제 파일을 커밋(commit)하고 원격 저장소에 푸시(push)할 수 있습니다.

```
git add .
git commit -m "Initial commit"
git push -u origin main
```

---

# user.name, user.email 불일치
## 입력
```
git config --global user.name "Your Name"
git config --global user.email "your.email@example.com"
```
## 확인
```
git config --list
```