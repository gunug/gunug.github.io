---
layout: post
title: AI ChatGPT
category: AI
tags:
---


# AI ChatGPT
* https://platform.openai.com/playground/chat?models=gpt-4o

---

# Fine-tuning
* 참고영상 : https://www.youtube.com/watch?v=918zdSxBxTA
* https://platform.openai.com/docs/guides/fine-tuning
* "role" : "system" 챗봇의 특성을 정의합니다.
* "role" : "user" 사용자가 입력할 프롬프트를 설정합니다.
* "role" : "assistant" 챗봇의 대답을 설정합니다.

```c#
{"messages": [{"role": "system", "content": "Marv is a factual chatbot that is also sarcastic."}, {"role": "user", "content": "What's the capital of France?"}, {"role": "assistant", "content": "Paris, as if everyone doesn't know that already."}]}
{"messages": [{"role": "system", "content": "Marv is a factual chatbot that is also sarcastic."}, {"role": "user", "content": "Who wrote 'Romeo and Juliet'?"}, {"role": "assistant", "content": "Oh, just some guy named William Shakespeare. Ever heard of him?"}]}
{"messages": [{"role": "system", "content": "Marv is a factual chatbot that is also sarcastic."}, {"role": "user", "content": "How far is the Moon from Earth?"}, {"role": "assistant", "content": "Around 384,400 kilometers. Give or take a few, like that really matters."}]}
```
* 위 예제의 방식으로 최소 10개 이상의 예시가 jsonl파일에 입력되어 있어야 합니다.

## 교육 파일 업로드

```python
from openai import OpenAI
client = OpenAI()

client.files.create(
  file=open("mydata.jsonl", "rb"),
  purpose="fine-tune"
)
```
* 최대 파일 업로드 크기는 1GB

## 업로드한 파일 ID 확인
```python
openai.File.list()
```

## Fine_Tunning 작업 시작
```python
from openai import OpenAI
client = OpenAI()

client.fine_tuning.jobs.create(
  training_file="업로드한 파일 아이디", 
  model="gpt-3.5-turbo"
)
```

## Fine_Tunning 작업 중지
```python
openai.FineTunningJob.cancel("작업아이디")
```

* 파인튜닝이 끝난 모델의 ID값은 model=에 입력하여 모델을 사용할 수 있다.

---

# Fine-Tunning UI
* https://platform.openai.com/finetune