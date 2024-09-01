---
layout: post
title: OpenAI API DALL-E3 달리3 이미지 생성
category: AI
tags:
---

# OpenAI API DALL-E3 달리3 이미지 생성
* 참고링크: <https://velog.io/@yeomja99/DALLE3-API-%EC%82%AC%EC%9A%A9%EB%B2%95>

## module 설치
* 기존 모듈 삭제 ```pip uninstall openai```
* pip 업그레이드 ```pip install --upgrade pip```
* 모듈 설치 ```pip install openai```

## 생성
```python
import openai 
import webbrowser
import os

# Replace YOUR_API_KEY with your OpenAI API key
client = openai.OpenAI(api_key = "API KEY")

# Call the API

# 1장 생성 시 0.03$

response = client.images.generate(
  model="dall-e-3",
  prompt="a cute cat with a hat on",
  size="1024x1024",
  quality="standard",
  n=1,
)

# Show the result that has been pushed to an url
webbrowser.open(response.data[0].url)
```

## 저장
```python
# curl 요청
url = response.data[0].url
import urllib.request
import time

img_dest = "./"
start = time.time()
urllib.request.urlretrieve(url, img_dest+"result.jpg")

end = time.time()
print(f"총 소요시간 {end-start}초")
```

---

# 내 환경에 맞게 변경
```python
import openai 
import webbrowser
import os

# Replace YOUR_API_KEY with your OpenAI API key
# api_key from envitonment variable
my_api_key = os.getenv("OPENAI_API_KEY")
client = openai.OpenAI(api_key = my_api_key)

# Call the API

# 1장 생성 시 0.03$

response = client.images.generate(
  model="dall-e-3",
  prompt="a cute cat with a hat on",
  size="1024x1024",
  quality="standard",
  n=1,
)

# Show the result that has been pushed to an url
webbrowser.open(response.data[0].url)
```

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1724992977.jpg" />