---
layout: post
title: Google adsense 구글애드센스
category: business
tags: 
---

# Google adsense 구글애드센스
* 광고 단위 정보 : <https://support.google.com/adsense/answer/9183549?hl=ko>
* 싱가폴세금정보 : 홈택스에서 거주자 증명서 발급받아서 제출 (일반 민원이랑 달라서 발급에 1시간 정도 소요될 수 있음)

# 검토
* <https://www.google.com/adsense/new/u/0/pub-9319681514128117/onboarding/overview>

---

# 조치필요
* <https://support.google.com/adsense/answer/12176698?sjid=7968382523347030568-AP>
  
## 가치가 별로 없는 콘텐츠
* <https://support.google.com/adsense/answer/10502938?visit_id=638550554015713502-3714178014&rd=1#minimum_content_requirements>
* 불법 콘텐츠
* 지적 재산권 남용
* 위험하거나 모욕적인 내용
* 동물 학대
* 허위 내용
* 부정직한 행동 조장
* 성적으로 노골적인 콘텐츠
* 보상된 성행위
* 우편 주문 신부 - 외국인과의 결혼을 촉진
* 가족 콘텐츠의 성인용 테마
* 아동 성적 학대 및 착취
  
## 문제 수정 후 재검토 요청하기
* <https://www.google.com/adsense/new/u/0/pub-9319681514128117/sites/detail/url=onethelab.com>

## 광고 코드 삽입
* <https://support.google.com/adsense/answer/9190028>
* 광고페이지: <https://www.google.com/adsense/new/u/0/pub-9319681514128117/myads/sites>
* 코드 가져오기 클릭
* ```<head></head>``` 사이에 붙여넣기

---

# 애드센스 콘텐츠 및 사용자 경험
* 고유하고 가치 있는 콘텐츠가 있어야 하며 좋은 사용자 경험을 제공해야 합니다.
* 고유한 콘텐츠를 충분히 제공하세요.
* <https://trends.google.com/trends/> 에서 키워드별 트렌드 검색 가능
* <https://analytics.google.com/analytics/web/#/> 에서 사이트 분석 가능
* onethelab site 분석 보고서 : <https://analytics.google.com/analytics/web/#/p448014326/reports/reportinghub>

---

# 페이지 작성하고 많은 시간이 흘렀는데 구글검색이 안되고 있다
* google search console : <https://search.google.com/search-console/welcome?utm_source=about-page>
* DNS 인증해야 한다고 해서 DNS 기록후 인증완료
* URL 검사에서 확인해보니 특정 페이지가 google에 등록되어있지 않음
* sitemap 만든는 방법 : <https://developers.google.com/search/docs/crawling-indexing/sitemaps/build-sitemap?hl=ko>
* xml 사이트맵 생성기 : <https://www.xml-sitemaps.com/>
* 사이트맵을 생성하여 등록함
* 색인 생성 여부 확인 : <https://search.google.com/search-console/index?resource_id=sc-domain%3Aonethelab.com>

---

# 광고 게재가 준비되지 않은 사이트
* <https://www.google.com/adsense/new/u/0/pub-9319681514128117/sites/detail/url=onethelab.com>

---

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719979561.jpg" />

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1719980153.jpg" />

* 리디렉션이 포함된 페이지
* 도메인 루트에서 서브페이지로 바로 리디렉션 시켰더니 해당 도메인 모든 페이지에 색인이 실시되지 않음

---

# 구글 검색 개선
* google search console : <https://search.google.com/search-console/welcome?utm_source=about-page>
* 상관없는 검색어에 노출이 되고 있음.

* 유용하고 신뢰할 수 있는 사용자 중심 콘텐츠 제작하기 <https://developers.google.com/search/docs/fundamentals/creating-helpful-content?hl=ko>
* 검색엔진 최적화(SEO) 기본 가이드 <https://developers.google.com/search/docs/fundamentals/seo-starter-guide?hl=ko>
* Google 검색에서 내 페이지가 누락된 이유는 무엇인가요? <https://support.google.com/webmasters/answer/7474347?hl=ko>
* 사이트 트래픽이 떨어지는 이유 <https://support.google.com/webmasters/answer/9079473?hl=ko>
* Google 검색의 작동 방식에 대한 상세 가이드 <https://developers.google.com/search/docs/fundamentals/how-search-works?hl=ko>
* Google 검색 순위 시스템 가이드 <https://developers.google.com/search/docs/appearance/ranking-systems-guide?hl=ko>
* Google 검색 트래픽 감소 파헤치기 <https://developers.google.com/search/docs/monitor-debug/debugging-search-traffic-drops?hl=ko>

---

# Robot.txt 설정
* <https://developers.google.com/search/docs/crawling-indexing/robots/create-robots-txt?hl=ko>
* <https://seo.tbwakorea.com/blog/robots-txt-complete-guide/>

## 구성요소
* User-agent: robots.txt 에서 지정하는 크롤링 규칙이 적용되어야 할 크롤러를 지정합니다.
* Allow: 크롤링을 허용할 경로입니다 (/ 부터의 상대 경로).
* Disallow: 크롤링을 제한할 경로입니다 (/ 부터의 상대 경로).
* Sitemap: 사이트맵이 위치한 경로의 전체 URL입니다 (https:// 부터 /sitemap.xml 까지의 전체 절대경로 URL).

## 봇이름
* 구글: Googlebot
* 네이버: Yeti
* 다음: Daum
* 빙: Bingbot
* 덕덕고: DuckDuckBot

# robot.txt 파일 존재여부 확인
* <https://search.google.com/search-console/settings/robots-txt?resource_id=sc-domain%3Aonethelab.com>

---


# Google SEO
* <https://developers.google.com/search/docs/fundamentals/seo-starter-guide?hl=ko>
* 검색엔진 최적화

---

# google search console 개선
## 리디렉션이 포함된 페이지
## 5xx 오류


Google 검색 콘솔에서 나에게 게시하지 않은 검색결과가 노출되었다는 보고가 있을 경우 몇 가지 가능한 원인을 고려해볼 수 있습니다.
1. **스팸 또는 해킹**: 웹사이트가 해킹당해 스팸 콘텐츠가 추가되었을 수 있습니다. 이 경우, Google에서 해킹된 페이지를 인덱싱하여 검색결과에 표시될 수 있습니다. 웹사이트의 보안을 점검하고 해킹된 부분을 제거해야 합니다.
2. **스크래핑 또는 복사된 콘텐츠**: 다른 웹사이트가 당신의 콘텐츠를 무단으로 복사하여 자신의 사이트에 게시했을 수 있습니다. 이 경우 원본과 복사본이 모두 검색결과에 나타날 수 있습니다. 이러한 경우 Google에 DMCA 요청을 통해 조치를 취할 수 있습니다.
3. **도메인 또는 URL 오타**: 잘못된 도메인 설정이나 URL 입력 오류로 인해 다른 페이지가 검색결과에 표시될 수 있습니다. 검색 콘솔에서 "URL 검사" 기능을 사용하여 문제의 URL을 점검해보세요.
4. **리디렉션 설정 오류**: 리디렉션 규칙이 잘못 설정되어 다른 페이지로 사용자가 안내되고 있을 수 있습니다. 서버의 리디렉션 설정을 점검하여 수정해야 합니다.
위의 문제점들을 조사하고 해결하는 것이 중요합니다. 문제가 지속될 경우, 웹사이트 보안 전문가의 도움을 받아 자세한 점검을 받는 것도 고려해보세요.

---
### Apache에서의 리디렉션 설정
Apache 웹 서버에서는 `.htaccess` 파일이나 서버 설정 파일(httpd.conf)을 통해 리디렉션을 설정할 수 있습니다.
1. **.htaccess 파일 이용**:
   - 웹사이트의 루트 디렉터리(또는 특정 디렉터리)에 `.htaccess` 파일을 생성하거나 편집합니다.
   - 아래와 같은 리디렉션 코드를 추가합니다 (예: http://example.com/old-page를 http://example.com/new-page로 리디렉션):
     ```apache
     Redirect 301 /old-page /new-page
     ```
   - `Redirect 301`은 영구 리디렉션을 의미합니다.

- 아파치 기본 설정    : sudo vi /etc/apache2/apache2.conf
- 포트 설정              :  /etc/apache2/ports.conf
-  public 파일 설정    :  /etc/apache2/mods-enabled/dir.conf
- 언어셋관련 설정      :  /etc/apache2/mods-enabled/autoindex.conf
- 파일타입 설정        :  /etc/apache2/mods-enabled/mime.conf
- 웹서비스 설정        :    /etc/apache2/sites-enabled/000-default
