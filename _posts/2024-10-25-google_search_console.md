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

---

# 네이버 검색 최적화
* <https://searchadvisor.naver.com/guide/seo-help>

---

# 색인이 생성되지 않은 이유
* 참고링크 : <https://support.google.com/webmasters/answer/9012289#live_test_results>
* URL 상태가 'URL을 Google에 등록할 수 없음' 또는 'URL이 Google에 등록되어 있지 않음'이면 색인 생성 가능 여부 섹션을 펼칩니다.
* 색인 생성 가능 여부 섹션 헤더에는 URL의 색인을 생성할 수 없는 이유를 간략하게 설명하는 라벨이 있습니다. 값 및 가능한 해결 방법 안내의 목록을 확인하세요. 라벨이 Google에는 아직 알려지지 않은 URL이라면 Google에서 이전에 URL을 보지 못한 것이므로 페이지의 색인 생성을 요청해야 합니다. 색인 생성에는 일반적으로 며칠이 걸립니다.
* 크롤링 허용 여부가 '아니요'인 경우, Google이 페이지를 크롤링하지 못하게 막는 robots.txt 규칙으로 인해 Google에서 페이지를 크롤링할 수 없다는 의미입니다. 문제를 확인하고 해결하는 방법 알아보기
* 색인 생성 허용 여부가 '아니요'인 경우, 사이트에서 Google이 페이지의 색인을 생성하지 못하게 막는 'NOINDEX' 태그 또는 헤더를 반환하여 Google 검색결과에 표시할 수 있다는 의미입니다. Google에서 색인을 생성하기 전에 이 태그나 헤더를 페이지에서 삭제해야 합니다.

## 중복 페이지 url 표준화 및 표준 태그 사용
* 참고링크 : <https://developers.google.com/search/docs/crawling-indexing/consolidate-duplicate-urls?hl=ko>
* 