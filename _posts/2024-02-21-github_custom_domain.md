---
layout: post
title: github custom domain 깃허브 커스텀 도메인
category: etc
tags: 
---

# github custom domain 깃허브 커스텀 도메인

* 별칭 (CNAME): 별칭을 지정하면 실제 도메인으로 연결
* 호스트IP (A): 도메인에 실 서버 IP를 설정하는 레코드

---

## CNAME
* github.com > repositorie 선택
* Settings > pages > Custom domain란에 구입한 도메인 입력
* Save후 저장소로 가보면 CNAME 파일이 생성되어 있음

---

## A
* https://docs.github.com/en/pages/configuring-a-custom-domain-for-your-github-pages-site/managing-a-custom-domain-for-your-github-pages-site
* 위 링크에서 Github의 ip주소를 알 수 있음

```
185.199.108.153
185.199.109.153
185.199.110.153
185.199.111.153
```

* 이중 하나를 선택하여 입력하면 됨

---

# HTTPS 문제
* https://docs.github.com/ko/pages/getting-started-with-github-pages/securing-your-github-pages-site-with-https
* github.com > Repositorie > settings > Pages > Enforce HTTPS
* 인증서를 프로비저닝 하는 중이라는 메세지 경우 15분 정도 이후에 HTTPS 활성화를 할수 있음
* DNS설정할때 onethelab.com, www.onethelab.com을 모두 A로 설정하였더니 DNS설정 에러 메세지가 나옴
* www은 CNAME으로 변경해야함