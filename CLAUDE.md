# CLAUDE.md - One The Lab (gunug.github.io)

## 프로젝트 개요
- **사이트:** https://onethelab.com — 조건희(Cho Gun-Hee)의 포트폴리오 + 기술 블로그
- **기술 스택:** Jekyll 4.3.2 (Ruby) + GitHub Pages + Lunr.js 검색
- **언어:** 한국어 중심, 마크다운 포스트

## 핵심 디렉토리 구조
```
_posts/          # 블로그 포스트 (627+개, 2008~2026)
_protected/      # 암호화 대상 비공개 포스트 (Gulp로 AES 암호화 → _posts로 출력)
_layouts/        # 레이아웃 템플릿 (default, post, home, portfolio, profile 등)
_includes/       # HTML 파셜 (sidebar, head, toc, post, footer 등)
_pages/          # 정적 페이지 (about, portfolio, research, education)
_scss/           # SCSS 파셜 (_post.scss - TOC 스타일)
public/css/      # 메인 CSS (style.css) + Rouge 구문강조 테마
public/img/      # 사이트 이미지 (로고, 아이콘)
js/              # Lunr.js 검색 스크립트
code/            # Arduino .ino 파일
file/            # 기타 첨부파일 (csv, pdf, png, zip)
fabicon/         # 파비콘 세트 + manifest.json
```

## 포스트 작성 규칙
```yaml
---
layout: post
title: 포스트 제목
category: unity3d    # 주요: unity3d, web, arduino, coding, portfolio, vr, AI, education 등
tags: tag1 tag2
teaser: https://image.onethelab.com/thumbnail/xxxxx.jpg  # 외부 이미지 CDN
---
```
- 파일명 형식: `YYYY-MM-DD-slug.md`
- `future: true` 설정으로 미래 날짜 포스트도 발행됨

## 빌드 & 실행
```bash
bundle exec jekyll serve                  # 기본 로컬 서버 (jekyll.bat)
bundle exec jekyll serve --force_polling  # Windows 파일 감시 (start.bat)
node server.js                           # Node.js 대체 서버 (포트 3000)
gulp firewall:encrypt                    # _protected/ → _posts/ 암호화
```

## 배포
- GitHub Pages (gunug/gunug.github.io) + CNAME: onethelab.com
- 소스 push 시 자동 배포

## 주요 특수 기능
1. **포스트 암호화:** `_protected/` 파일을 Gulp+CryptoJS로 AES 암호화하여 공개 배포
2. **클라이언트 검색:** Lunr.js 기반 전문 검색 (CJK 지원)
3. **자동 TOC:** pure-Liquid TOC 생성기 (75em 이상에서 우측 플로팅)
4. **코드 복사 버튼:** 포스트 내 `<code>` 블록에 자동 복사 버튼 삽입

## 설정 참고
- **테마:** jekyll-theme-monos 기반 커스텀 (minima gem은 미사용)
- **플러그인:** jekyll-feed, jekyll-sitemap
- **구문강조:** Rouge + monokai 테마
- **폰트:** Noto Sans KR, Nanum Gothic, Nanum Myeongjo, Roboto
- **이미지 CDN:** image.onethelab.com (테저 이미지 외부 호스팅)
