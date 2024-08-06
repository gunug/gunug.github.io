---
layout: post
title: Image Generation 이미지 생성
category: AI
tags: 
---

* 출처 : https://github.com/OkGoDoIt/OpenAI-API-dotnet?tab=readme-ov-file#images

## images

```c#
async Task<ImageResult> CreateImageAsync(ImageGenerationRequest request);

// for example
var result = await api.ImageGenerations.CreateImageAsync(new ImageGenerationRequest("A drawing of a computer writing a test", 1, ImageSize._512));
// or
var result = await api.ImageGenerations.CreateImageAsync("A drawing of a computer writing a test");

Console.WriteLine(result.Data[0].Url);
```

---

## DALL-E

```c#
async Task<ImageResult> CreateImageAsync(ImageGenerationRequest request);

// for example
var result = await api.ImageGenerations.CreateImageAsync(new ImageGenerationRequest("A drawing of a computer writing a test", OpenAI_API.Models.Model.DALLE3, ImageSize._1024x1792, "hd"));
// or
var result = await api.ImageGenerations.CreateImageAsync("A drawing of a computer writing a test", OpenAI_API.Models.Model.DALLE3);

Console.WriteLine(result.Data[0].Url);
```

* For DALL-E 3, only 1024x1024, 1024x1792, or 1792x1024 is allowed.