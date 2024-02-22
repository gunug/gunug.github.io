---
layout: post
title: visual studio code ftp 설정
category: etc
tags: 
---

# visual studio code ftp 설정

---
## ftp-simple
* 참고 : https://mu08.tistory.com/88
* extension : FTP-simple 설치
* F1 또는 ```Ctrl + Shift + P``` 눌러서 검색창 활성시킨 후 FTP 검색
* ftp-simple: Config - FTP connection setting 선택
* name, host, username, password 입력하고 저장
* ftp-simple: Remote directory open to workspace 선택
* 입력해둔 서버정보중 하나를 선택
* 기본으로 설치되는 위치는 ```AppData/Roaming/Code/User/ftp-simple/remote-workspace-temp```
* 변경 하려면 vscode > file > preferences > settings > extensions > ftp-simple 에서 workspace 입력
## 단점
* 임시폴더(temp)에 일시적으로 당겨와서 수정후 업로드 하는 인스턴트방식인 것 같음
  
---

## SFTP
* 참고 : https://yuddomack.tistory.com/entry/vscode-ftp%EB%A1%9C-%EC%9B%90%EA%B2%A9%EC%A0%91%EC%86%8D-%EC%BD%94%EB%93%9C-%EB%8F%99%EA%B8%B0%ED%99%94
* extension : SFTP 설치 (Natizyskunk)
* f1 > SFTP:Config 선택하면 sftp.json파일 생성됨
* json에 frp 서버내용 입력하고
* f1 > SFTP:List All
* 접속이 완료 되면 파일을 내려 받을 수 있음.
* 그 이후부터는 파일리스트에 마우스 우클릭 local -> remote, remote -> local로 사용

## Permission denied
* 해당 가입자가 해당 폴더에 쓰기 권한이 없어서 발생하는일
* 기본적으로 새로만든 폴더는 root에만 읽기쓰기 권한이 있음
* ```chown 유저명:그룹명 폴더명`` 으로 권한을 넘겨줌
* ```ls -al```로 권한 변경 확인

---