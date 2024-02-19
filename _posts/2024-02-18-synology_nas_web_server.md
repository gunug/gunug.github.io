---
layout: post
title: synology nas web server 시놀로지 나스 웹서버
category: etc
tags: 
---

# synology nas web server 시놀로지 나스 웹서버

* 참고링크 : https://sung-sung.tistory.com/167
* 제어판 : Web Station 활성화
* 패키지 센터 : phpMyAdmin / MariaDb

---

# 패키지 센터
* Web Station, WebDAV Server 설치
* Apache HTTP Server 2.4 설치
* PHP 8.2, phpMyAdmin(설치되면서 자동으로 php 8.0) 설치
* MariaDB 10 설치 (3306)
* 5005포트에서 사이트 준비중 페이지를 볼 수 있음

## MariaDB 아이디 패스워드 변경
* 기본값인 root/null 로 접속하려고 하면 dsm를 통해서 패스워드를 변경하라고 함
* 유틸리티 > MariaDB 10 > 루트 패스워드 재설정

---

# quickconnect
* QuickConnect 릴레이 서비스를 통해 DSM을(를) 연결하는 경우 설정을 수정할 수 없습니다. 설정을 수정하려면 다른 연결방법을 사용하십시오.
* 아이피를 이용하여 DSM에 접속하면 quick connect 설정을 변경 할수 있음. 네트워크 인터페이스 항목에서 IP:5000 확인
* 참고 : DSM 4.3 이하에서는 웹 포털 서비스를 지원하지 않습니다.

---

# 접속주소
* DSM <http://192.168.0.175:5000>
* Web service <http://192.168.0.175>
* phpMyAdmin <http://192.168.0.175/phpmyadmin/>

---

# 퀵커넥트 접속주소
* DSM <http://QuickConnect.to/onethelab>
* 퀵커넥트로 web survice, phpMyAdmin 안됨

---

* 참고링크 : https://blog.naver.com/mythee1/222113905757

* "사용자 홈"이 비활성화 되었습니다. 먼저 사용자 페이지로 이동하여 활성화 하십시오.
* 사용자 및 그룹 > 고급 > 사용자 홈 > 사용자 홈 서비스 활성화
* 제어판 > 외부 액세스 > DDNS > 추가
* 서비스 공급자 : synology 선택하면 synologe.me 주소 생김
* 외부주소는 lan1 설정하면 됨

* Web service <http://onethelab.synology.me/>
* phpMyAdmin <http://onethelab.synology.me/phpmyadmin/>

---