---
layout: post
title: Unity Shader 유니티 쉐이더
category: unity3d
tags: shader
---

# Unity Shader 유니티 쉐이더
* 참고자료 : https://www.youtube.com/watch?v=KnueAgpUL3Y
* 정점 위치나 픽셀 색깔을 계산하는 함수

<img src="https://image.onethelab.com/resized/1709783508.jpg" />

<img src="https://image.onethelab.com/resized/1709783688.jpg" />
Rnaderer.material.SetInt로 접근해서 고치면 오브젝트별 쉐이더 값이 변경됨
Material.SetInt로 접근해서 고치면 메테리얼 자체를 수정한것이 되어 같은 메테리얼을 사용중인 모든 오브젝트에 적용됨
<img src="https://image.onethelab.com/resized/1709783740.jpg" />

* https://ambientcg.com/ cc0 저작권 텍스쳐들 (상업적 용도 사용 및 수정 배포가능)
* LOD: Level of detail

---

## 쉐이더
<img src="https://image.onethelab.com/resized/1709783769.jpg" />
<img src="https://image.onethelab.com/resized/1709783784.jpg" />

## 에러상황
* scene color 노드를 추가하고 PBR Master 속성을 바꿔도 투명이 되지 않는 분들은 URP 셋팅 에셋 파일 General > Opaque Texture 체크를 하시면 됩니다.