---
layout: post
title: google search console 구글 서치 콘솔
category: web
tags: 
---

# google search console 구글 서치 콘솔
* <https://support.google.com/webmasters/answer/9128669?utm_source=wnc_20079900&utm_medium=panel&utm_campaign=wnc_20079900&utm_content=msg_20079900&hl=ko#zippy=%2C%EC%B4%88%EB%B3%B4-%EC%82%AC%EC%9A%A9%EC%9E%90%EB%B0%B0%EC%9A%B8-%EC%9D%98%ED%96%A5%EC%9D%B4-%EC%9E%88%EB%8A%94-%EC%82%AC%EC%9A%A9%EC%9E%90>

* <https://support.google.com/webmasters/answer/10267942?sjid=10433777505104968787-AP>
* 보안문제,정책위반,페이지발견 체크

---

* ```site:웹사이트주소```를 입력하여 검색결과를 확인해 볼 수 있음
* 인덱싱 요청, 사이트맵 제출, robot.txt 및 메타 태그 확인, 링크 구조 점검, 품질 문제 점검, 서버 이슈 확인

---

# 사이트맵 만들기
* <https://www.check-domains.com/>
* <https://www.xml-sitemaps.com/> - 무료500페이지, 그 이상은 유료
* jeykll내에 사이트맵을 만들어주는 plugin이 있다고 하여 설정하여 사이트맵 생성하도록 함
* [jekyll sitemap 지킬 사이트 맵](/blog/2024/11/06/jekyll_sitemap.html){:target="_blank"}

---

# 네이버 웹 마스터 도구
* <https://searchadvisor.naver.com/>
* 웹 마스터 도구

---

# history
* 2024-11-01 
  * image.onethelab.com의 해킹으로 인한 서버 리셋, 네임서버를 교체함
  * image.onethelab.com의 잘못된 색인을 삭제 요청함, google search console에서는 아직 잘못된 색인이 그대로 존재하는 상태
  * robot.txt로 크롤링 방지하는거 보다는 <noindex>를 사용하는것이 맞다고 하여 변경
  * onethelab.com의 본래 색인이 제대로 되지 않아서 아직 google에서 검색이 안되는데 요청이 밀려있어서 일것이라 추정 (현재 44만개)