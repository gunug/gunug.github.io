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

# prompt 프롬프트
## 얼굴만
* 512*768

* positive

```markdown
1girl, realistic, masterpiece, best quality, detailed face, detailed eyes, focus on face, light smile, happy,  realistic skin,  beauty face,  pretty, korean. portrait,  upper body,  cinematic light, 
__77_face_lora__, __77_face_lora__,  __77_face_lora__, highres, (simple background:1.2), 
```

* negative

```markdown
Easynegative,  nsfw, Drawings, abstract art, cartoons, surrealist painting, conceptual drawing, graphics, low resolution, (blurry:1.3), (strabismus:1.1), (western:1.2), (full body:1.2),
(worst quality:1.3), (low quality:1.3),  collage, (makeup:0.8), nsfw, bad proportions, floral print, loli, big eyes, (watermark:1.2), letter, (abs:1.2), (hand:1.7)
```
