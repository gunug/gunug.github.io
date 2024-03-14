---
layout: post
title: Crest Water System HDRP (Ocean, Rivers & Lakes)
category: unity-asset
tags: unity3d assets
---

# Crest Water System HDRP (Ocean, Rivers & Lakes)
*https://assetstore.unity.com/packages/tools/particles-effects/crest-water-system-hdrp-ocean-rivers-lakes-164158

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1709795492.jpg" />



* buoyancy 부력

* Crest Ocean Renderer 컴퍼넌트
  * 비활성화 시 물이 렌더 되지 않음
  * Sim Setting Dynamic Waves
  * Sim Setting Clip Surface
* Crest Shape FFT
  * 활성화 시 파도가 렌더됨
* Crest Water Body
* Crest Register Clip Surface Input

---

* https://www.youtube.com/@WaveHarmonic/videos

<iframe width="560" height="315" src="https://www.youtube.com/embed/FE6l39Lt3js?si=Dd-FD0lxB9LiP_7t" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>


---

<iframe width="560" height="315" src="https://www.youtube.com/embed/Y7ny8pKzWMk?si=OES_8XiABd1s8iop" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

## Crest Ocean Renderer
* Simulation Params > Sim Setting Aimated Wave > Create assets
* Attenuation in shallows(얕은 곳의 감쇠) : 물가 파도치는양을 조절
* Simulation Params > Sim Settings Foam > Create assets (거품관련 세팅)
* Crest Ocean Depth Cache > Update Saved Cache File 클릭하면 지면 업데이트
  
## Crest Simple Floating Object
* 떠다니는 물체
  
## Register Clip Suface Input (Script)
* 물 자르기(clip)
* Crest Ocean Renderer에서 Create Clip Surface Data의 옵션을 켜야함
* MeshRenderer > Materials > ClipSurfaceRemoveArea 메테리얼을 선택 하면 Mesh 만큼 물이 클립핑됨
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1709957199.jpg" />

## Crest Underwater Renderer
* 물속 랜더링, 옆면 경계를 만들고 물을 클립핑 하는 역할도 함
* Mode - Volume으로 설정해야 하기 설정이 활성화됨
* volume geometry에 Mesh Filter를 등록하여 클립핑 영역을 설정


---

* Window > Crest > Crests Water body
* 