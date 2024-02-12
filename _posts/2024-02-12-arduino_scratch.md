---
layout: post
title: arduino scratch 아두이노 스크래치
category: arduino
tags: arduino
---

* http://deneb21.tistory.com/369
* 2017.12.19.상황
* 윈도우8.1 이상 internet explorer : 컴퓨터가 크래쉬나는 문제가 있음
* Chrome, Firefox : NPAPI  지원중단으로 인하여 plugin이 동작하지 않음

# firefox ESR 
* https://kocoafab.cc/tutorial/view/566 : 댓글참고
* https://www.mozilla.org/en-US/firefox/organizations/all/ 에서 ESR 버전 다운로드

# ESR NPAPI 제외 
* https://support.mozilla.org/ko/questions/1184304
* The last Firefox 52 ESR update will likely be 52.8.0 esr out when Firefox 60.0 is Released next year on May 8, 2018. Unless Mozilla decides to extend this ESR branch.
* 2018. 5월 8일 업데이트때 ESR에서도 NPAPI가 제거될 예정

# 도저히 안되겠어서 다른 방법 리서칭 
* MIT App Inventor를 가지고 블루투스 연결하여 arduino 블루투스하고 통신 할 수 있는듯 하다.
* https://www.wadiz.kr/web/campaign/detail/1882
* https://codei.kr/codeiSW_DIY/9723 : 코드아이 플러스

# S4A (Snap 4 Arduino) 
* http://s4a.cat/
* 스크래치를 이용하여 아두이노를 제어 할 수 있도록 해줌
 * S4A16.zip를 압축해제하여 설치합니다.
 * S4AFirmware16.ino를 Arduino IDE를 이용하여 아두이노 보드에 업로드합니다.

# S4A 블록만들기 
* http://blog.s4a.cat/2015/03/13/Extending-Firmata-for-Snap4Arduino.html
