---
layout: post
title: frustum 절두체
category: portfolio
tags: unity3d consulting
teaser: https://image.onethelab.com/thumbnail/1728743317.jpg
---

|프로젝트 이름|발주처|주소|기간|담당업무|
|:--|:--|:--|:--|:--|
|Unity3d window projection|Toleap Consulting AB|Toleap Consulting AB Hemmansvägen 11 SE 784 37 Borlänge Sweden|17일|소스코드 작성, 기술문서 작성|

---


<iframe width="560" height="315" src="https://www.youtube.com/embed/XTvBnYTXNK0?si=Elapt9kQ8WtnS6qh" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1728743758.jpg" />

# frustum
* 절두체 예제를 보고 스웨덴에서 들어온 의뢰
* 온전히 작동하는 소스코드 및 기술문서 7페이지 작성하여 발송

# 결과
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1728744098.jpg" />
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1728744064.jpg" />

---

# 재의뢰
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1732196653.jpg" />

```
Unity3D에서 사용하던 `Matrix4x4.Frustum` 기능을 Unreal Engine에서 구현하려면, 비슷한 기능을 제공하는 Unreal의 클래스를 찾아야 합니다. Unreal Engine에서는 이러한 목적을 위한 매트릭스 변환 기능이 주로 FMatrix 또는 FTransform 클래스와 관련이 있습니다. 이를 검색하기 위해 다음과 같은 키워드를 사용할 수 있습니다:

1. "Unreal Engine frustum matrix"
2. "Unreal Engine FMatrix perspective projection"
3. "Unreal Engine create frustum matrix"
4. "Unreal Engine custom projection matrix"
5. "Unreal Engine projection matrix example"

이런 검색어를 사용하면 Unreal Engine에서 커스텀 프러스텀 매트릭스를 생성하는 방법과 관련된 문서, 튜토리얼, 또는 포럼 스레드를 찾을 수 있을 것입니다. Unreal Engine의 공식 문서나 커뮤니티 포럼(예: Unreal Engine forums, Stack Overflow)에서 관련 정보를 찾는 것도 좋은 방법입니다.
```

```
Unreal Engine에서 투영 행렬(projection matrix)을 다룰 때는 `FMatrix` 클래스와 관련된 기능들을 사용하게 됩니다. 투영 행렬은 3D 공간의 좌표를 2D 화면 공간으로 변환하는 데 중요한 역할을 하며, 특히 카메라의 시야각 및 종횡비에 기반해 설정됩니다.

`FMatrix`는 Unreal Engine에서 행렬 연산을 처리하는 클래스 중 하나로, 이 클래스의 여러 기능을 사용하여 커스텀 투영 행렬을 만들거나 조작할 수 있습니다. 예를 들어, 다양한 변환 행렬을 구성하는 데 필요한 함수들이 포함되어 있습니다.

**Unreal에서의 기본적인 투영 행렬 설정 방법**:

1. **FMatrix::Identity**: 기본 단위 행렬로 시작하여 수동으로 값을 설정하는 방법.

2. **UGameplayStatics** 등과 같은 유틸리티를 통해 카메라 설정에서 직접 가져오는 방법.

3. **FMinimalViewInfo**와 같은 구조체를 사용하여 카메라 관련 설정을 저장하고 초기화할 수 있습니다. 그리고 이 설정을 통해 자동으로 투영 행렬을 생성할 수도 있습니다.

**검색할 키워드 예시**:
- "Unreal Engine FMatrix projection matrix"
- "Unreal Engine custom camera projection"
- "Unreal Engine setup perspective matrix"
- "FMatrix perspective example Unreal Engine"

이 검색어들은 Unreal Engine에서 투영 행렬을 설정하거나 수정하는 방법을 찾는 데 도움이 될 것입니다. Unreal 엔진의 문서나 튜토리얼 블로그, 개발자 포럼 등을 통해 좀 더 구체적인 예제나 응용방법을 찾아볼 수 있습니다.
```

---

* 참고 영상 : <https://youtu.be/6QCgtk4MpJ8?si=7_keYdgHekzgqg8N>
* 참고 영상 : <https://youtu.be/qMJRqwgEyqo?si=lohr-UtqidvyhkA7>

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1732693094.jpg" />

---

* test : <https://www.youtube.com/watch?app=desktop&v=F28NKqG7ce8&t=738s>
 
---

# unreal frustum
<iframe width="560" height="315" src="https://www.youtube.com/embed/dASp_DkgJRs?si=Db4nDX-sN0a_1ylD" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

# godot frustum
<iframe width="560" height="315" src="https://www.youtube.com/embed/juPy5aKiy50?si=AgX98_1XyJsXj2V3" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

---

* unity3d, unrel, godot 세가지 버전으로 frustum 샘플제작, 납품 완료