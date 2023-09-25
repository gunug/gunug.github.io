---
layout: post
title: Stable diffusion 스테이블 디퓨젼
category: stable-diffusion
tags: ai
---

---

# 프롬프트 사이트
* https://www.ptsearch.info/articles/list_best/
* https://civitai.com/
* https://prompts.co.kr/

---

# 최적의 해상도
* 1024 * 1024 = 1,048,576
* 1048576 / 768 * 1344
* 1024 x 1024(1:1 정사각형)
* 1152x896(9:7)
* 896x1152(7:9)
* 1216x832 (19:13)
* 832 x 1216 (13:19)
* 1344 x 768(7:4 가로)
* 768 x 1344(4:7 세로)
* 1536 x 640(12:5 가로)
* 640 x 1536 (세로 5:12, iPhone 해상도에 가장 가깝습니다)

---

# 울티메이트 가이드
* [Stable Diffusion Ultimate Guide pt. 1: Setup](https://medium.com/@inzaniak/stable-diffusion-ultimate-guide-pt-1-setup-bd7dbcd5ce4b#id_token=eyJhbGciOiJSUzI1NiIsImtpZCI6IjZmNzI1NDEwMWY1NmU0MWNmMzVjOTkyNmRlODRhMmQ1NTJiNGM2ZjEiLCJ0eXAiOiJKV1QifQ.eyJpc3MiOiJodHRwczovL2FjY291bnRzLmdvb2dsZS5jb20iLCJhenAiOiIyMTYyOTYwMzU4MzQtazFrNnFlMDYwczJ0cDJhMmphbTRsamRjbXMwMHN0dGcuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJhdWQiOiIyMTYyOTYwMzU4MzQtazFrNnFlMDYwczJ0cDJhMmphbTRsamRjbXMwMHN0dGcuYXBwcy5nb29nbGV1c2VyY29udGVudC5jb20iLCJzdWIiOiIxMDc1OTQ5NDE3MjY1ODA5NDY3MDkiLCJlbWFpbCI6Imd1bnVnODUwQGdtYWlsLmNvbSIsImVtYWlsX3ZlcmlmaWVkIjp0cnVlLCJuYmYiOjE2OTUyNzA0NzUsIm5hbWUiOiJHdW5oZWUgQ2hvIiwicGljdHVyZSI6Imh0dHBzOi8vbGgzLmdvb2dsZXVzZXJjb250ZW50LmNvbS9hL0FDZzhvY0pWWjJUYTRSZ3dZWHpIWHJnYUxTZFNNSEpnVTJOU0l1V1liekFJajYyd215NFg9czk2LWMiLCJnaXZlbl9uYW1lIjoiR3VuaGVlIiwiZmFtaWx5X25hbWUiOiJDaG8iLCJsb2NhbGUiOiJrbyIsImlhdCI6MTY5NTI3MDc3NSwiZXhwIjoxNjk1Mjc0Mzc1LCJqdGkiOiI2MjJiOTNjZTkyY2JlOWY1ZWU5OTVjYjM2OTc1YjI1N2FjYmI1M2IwIn0.h87d40o_YbShSKcv0B82g1C4_u0TbvJ5B1Pnf3x5RFSD5UXbu4DR1RdkpYy-v8K9xrxRtIO04iWpQfjPHnQ1A8gE7wcsWth7DdQZaM-6pqywKxLktb19fAhg2lsVQ5lZdIyvoEHmqftlf0ReGE8qR_kmApUlBVP7X9RHmwvZtaD4ubdH12T6YggkgfdKD2t91Jy9o_3NrZGFV2NfpQ7srgyFGZzRY7-V9TN19Y9GgUHy3Dx45LWrr6FfrlqaB_tY4O39gyfHDZRSaVgELS35OEDTeh3mrvMBvmAkc5rPlhxQ0jKKzKBMyU3cddvMf72Rayp9Un7ojJ1hJ2v8ydS12w)