---
layout: post
title: Minecraft server 마인크래프트 서버
category: game
tags: 
---

# 강종시 문제발생 
우분투 read-only 문제해결 참고

# 서버이름 지정하기 
* https://minecraft-ko.gamepedia.com/Server.properties
* ```cd /```
* ```cd /home/minecraft```
* ```vi server.properties```
* motd= 부분 우측 수정 : ex2. \u00A7eApplet \u00A7bCloud

# 마인크래프트 서버 구동하기 
```java -Xmx768M -Xms768M -jar mine```
* -Xms<size>        set initial Java heap size.........................
* -Xmx<size>        set maximum Java heap size.........................
* 서버의 가상메모리 swap.img가 30GB로 설정되어 있습니다.
* http://epthffh.tistory.com/entry/JVM-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EA%B4%80%EB%A0%A8-%EC%84%A4%EC%A0%95

# 구동 자바 확인 및 강제종료 
* 확인 : ```ps -ef | grep java```
* 강종 : ```ps kill 프로세스아이디```
* 자동 재실행 기능이 있어서 강종 해도 바로 다시 켜지더라

---

# vultr내에서 제공하는 마크서버 명령어들 
* https://www.vultr.com/docs/one-click-minecraft

# 커멘드 명령어 
* https://namu.wiki/w/%EB%A7%88%EC%9D%B8%ED%81%AC%EB%9E%98%ED%94%84%ED%8A%B8/%EB%AA%85%EB%A0%B9%EC%96%B4
* help 또는 ? : 모든 명령얼르 보여줍니다.
* kick [닉네임] : [닉네임]을 강퇴합니다.
* ban [닉네임] : [닉네임]을 영구추방합니다.
* pardon [닉네임] : [닉네임]의 영구추방을 해제 합니다.
* ban-ip [아이피] : [아이피]를 영구추방합니다.
* pardon-ip [아이피] : [아이피]의 영구추방을 해제 합니다.
* op [닉네임] : [닉네임]에게 아이템을 소환할 수 있는 치트권한을 줍니다.
* deop [닉네임] : 치트권한 해제
* tp [닉네임(나)] [닉네임(상대방)] : 상대방으로 순간이동
* tp [닉네임(1)] [닉네임(2)] : 1을 2로 순간이동
* give [닉네임] [아이템코드] [아이템 갯수] : 아이템 생성하기
* tell [닉네임] [할말] : 귓말
* stop : 서버중지
* save-all: 서버저장
* save-on : 서버켜기
* save-off : 서버끄기
* list : 서버에 접속자 리스트
* say [할말] : 접속자에게 말하기

---

# 오프섭에 새로 만들기 (우분투 부터 설치) 
* http://physics2.mju.ac.kr/juhapruwp/?p=1135
* 서버 버전으로 설치하자 (x window나 이런저런 잡다한 유틸이 없어서 가벼움)
* https://www.ubuntu.com/download/server
* 참고 : http://greenfishblog.tistory.com/251
* ```sudo apt-get install -y default-jre-headless```
* 마크섭 최신버전 확인 : https://minecraft.net/en-us/download/server/
* ```cd /home```
* ```mkdir minecraft```, ```cd minecraft```
* ```sudo su```
* 최신섭 링크 (Download minecraft_server.1.13.1.jar and run it with the following command:) 글중에 마우스 우클릭, 링크주소 복사
* ```wget 마우스우클릭(붙여넣기)```
* ```sudo java -Xms500M -Xmx7G -jar server.jar nogui``` 구동하면 바로 꺼짐
* ```vi eula.txt``` 내부의 eula = true;로 변경
* ```sudo reboot``` 우분투 서버 재시작 하기
* 이상태 대로라면 SSH종료 즉시 자바서버도 내려감. 따라서 screen 추가 설치 필요
* ```apt-get install -y screen```
* ```sudo screen -S mcs java -Xms500M -Xmx7G -jar server.jar nogui```를 통해 새로운 screen 세션에서 java 명령을 실행합니다. screen 세션의 id는 mcs로 지정합니다.
  * 안돼서 ```sudo screen -S mcs```로 스크린을 열고 ```sudo java -Xms500M -Xmx7G -jar server.jar nogui``` 명령어로 따로 실행후 빠져나오기 사용함
* ```CTRL+a, d``` 차례로 눌러 빠져나오기
* SSH로 접속하는 경우 screen -r mcs를 누르면, java를 실행했던 screen화면으로 복귀
* 25565 방화벽 설정
* motd=\u00A7eGunajona \u00A7bMinecraft

# op 등록하기 
* ops.json
  
```json
[
  {
    "uuid": "UUID-goes-here",
    "name": "notch",
    "level": 4
  },
  {
    "uuid": "UUID-goes-here",
    "name": "user1",
    "level": 4
  },
  {
    "uuid": "UUID-goes-here",
    "name": "player1",
    "level": 4
  }
]
```
* UUIDs can be found by using various websites that allow you to search for them via player name.
* https://ko.namemc.com/profile/Gunajona.1 : UUID 확인

---

# screen 닫기 
* 스크린 진입 <source lang="javascript" line>screen -R mcs```
* ```Ctrl+a, K```

# 재부팅과 초기 셋팅 
* 아이피 220.117.108.36 포트는 22포트 아님
* 아이디/패스 : gunajona / 중간레벨 패스워드
* ```sudo reboot```

# 기본서버 부팅 
* ```sudo screen -S mcs```
* /home/minecraft 로 이동
* ```sudo java -Xms2G -Xmx2G -jar server.jar nogui```
* ```CTRL+a, d```

# 고대서버 부팅 
* ```sudo screen -S mcs2```
* /home/minecraft_origin 로 이동
* ```sudo java -Xms2G -Xmx2G -jar server.jar nogui```
* ```CTRL+a, d```

# 종료 
* SSH 종료

# 원블럭모드 
* 1.16.4
