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

## 퀵커넥트 설정
* <https://kb.synology.com/ko-kr/DSM/tutorial/Quick_Start_External_Access#x_anchor_id5>
* 서비스 포트리스트 : <https://kb.synology.com/ko-kr/SRM/tutorial/What_network_ports_are_used_by_SRM_services>

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
* 외부주소는 lan1 설정하면 됨 - 사설 아이피 주소로 외부에서 접속 안되는 문제

* Web service <http://onethelab.synology.me/>
* phpMyAdmin <http://onethelab.synology.me/phpmyadmin/>

---

# 라우터 브릿지 모드
* 두 개 이상의 라우터가 네트워크에 있습니다. 모뎀/라우터를 브릿지 모드에 설정하는데 대해 인터넷 서비스 제공업체에 문의하거나...
* <https://kb.synology.com/ko-kr/DSM/tutorial/two_or_more_routers_were_found>
* cmd > traseroute 8.8.8.8 - 구글로 가는 홉을 테스트
* NAT/라우터 관리 > 기타기능 설정 > 포트포워드 UPnP 릴레이 > 중단
* DHCP 서버 중단을 설정하여 iptime 공유기를 인터넷 허브로 쓸수 있다.
* 벽체 렌포트가 2개라서 일단 공유기를 제거하고 벽체로 테스트
* UPnP를 지원하지 않는 라우터라 수동설치를 해야함

---

# 웹서버 구축하기
* https://redmilk.co.kr/8294
* 시놀로지 공식문서 : https://kb.synology.com/ko-kr/DSM/help/WebStation/application_webserv_virtualhost?version=7
* 외부 억세스: https://kb.synology.com/ko-kr/DSM/tutorial/Quick_Start_External_Access

# Quick Connect 지원
* https://kb.synology.com/ko-kr/DSM/tutorial/Which_services_support_QuickConnect
* 다음 서비스와 응용 프로그램은 QuickConnect를 지원 하지 않습니다.
  * Synology 장치를 Windows 네트워크 드라이브 또는 Mac Finder에 매핑
  * SMB, AFP, FTP, NFS 또는 WebDAV를 통해 Synology 장치의 파일에 액세스
  * Synology NAS의 파일을 원격 Synology NAS에 백업
  * VPN 클라이언트를 사용하여 Synology NAS에 연결 (VPN 서버로)
  * iSCSI 클라이언트를 통해 Synology NAS의 iSCSI Target에 연결
  * Web Station에서 구현 된 웹 서비스