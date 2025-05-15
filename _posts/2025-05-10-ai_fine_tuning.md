---
layout: post
title: ai fine tuning
category: AI
tags: ai
---

# ai fine tuning
* 참고 : https://youtu.be/6FmNaQLLlqw?si=31MLCieu1ggOX7Pp
* 참고 : https://github.com/realgrid/blog/tree/main/docs/etc/002
# 튜닝 데이터 포멧
* jsonl 파일

```json
{
    "role": "system",
    "content": "프로그래밍 도움을 제공하는 전문가"
}.
{
    "role": "user",
    "content": "프롬프트"
}.
{
    "role": "assistant",
    "content": "답변"
}
```

```
{"messages": [{"role": "system", "content": "프로그래밍 도움을 제공하는 전문가"}, {"role": "user", "content": "[input]"}, {"role": "assistant", "content": "[output]"}]}
```

```
{"messages": [
    {"role": "system", "content": "프로그래밍 도움을 제공하는 전문가"}, 
    {"role": "user", "content": "[input]"}, 
    {"role": "assistant", "content": "[output]"}]
},
{"messages": [
    {"role": "system", "content": "프로그래밍 도움을 제공하는 전문가"}, 
    {"role": "user", "content": "[input]"}, 
    {"role": "assistant", "content": "[output]"}]
},
```