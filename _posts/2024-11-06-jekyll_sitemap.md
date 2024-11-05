---
layout: post
title: jekyll sitemap 지킬 사이트 맵
category: blog
tags: 
---

# 지킬 사이트 맵
* 참고링크 : <https://chaerim-kim.github.io/jekyll%20blog/Jekyll-1/>
* Gamfile의 plugins 부분에 jekyll-sitemap을 추가

```
group :jekyll_plugins do
  gem "jekyll-feed", "~> 0.12"
  gem "jekyll-sitemap", "~> 1.4" # sitemap
end
```

* cmd에서 ```bundle``` 명령어 입력시 bundle complete 메세지 나오면 설치가능
* ```gem install jekyll-sitemap``` 입력하여 플러그인 설치
  
* _config.yml파일의 plugins: 부분에 jekyll-sitemap 추가

```
plugins:
  - jekyll-feed
  - jekyll-sitemap
```

* sitemap.xml 파일을 열었을때 내용이 차있으면 성공