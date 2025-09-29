---
layout: post
title: Unity Assets store 유니티 에셋 스토어
category: unity3d
tags:
---

#  Unity Assets store 유니티 에셋 스토어
* <https://assetstore.unity.com/ko-KR/> 에셋 스토어 접속 주소

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759178235.jpg" />
* 검색창에 찾고 싶은 단어를 입력
* 카테고리의 3D를 선택하면 모델 파일만 별도로 확인가능
* 가격 선택란에서 Free를 선택하면 무료 에셋만 표시가능
* <b style="color:red">수업에서는 무료 에셋만 사용합니다. (퀄리티를 위해 비용을 들이고, 들인 비용에 따라 학점을 받는상황 방지)</b>

---

# 랜더 파이프라인 지원

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759178978.jpg" />
* Overview에 Render pipeline compatibility가 명시되어 있는 경우
* 각 랜더 파이프라인이 호환 가능(Compatible)한지 확인하여 다운로드하면 문제가 없습니다.
* Render pipeline compatibility가 명시되지 않은 경우는 직접 다운로드하여 확인해보는 방법밖에 없습니다.


# 다운로드 후 모델위치
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759187226.jpg" />
* 폴더를 열어보면 대부분 prefabs 폴더를 발견할 수 있습니다.
* 이를 Scene으로 드래그 드랍하여 모델을 불러옵니다.

---

# 쉐이더 변경
* 참고링크 : <https://blog.terresquall.com/2023/12/how-to-convert-your-assets-between-the-different-render-pipelines-built-in-urp-hdrp-in-unity/>

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759187392.jpg" />
* 모델을 선택한 후 Inspector 창 제일 하단 material 부분 우클릭 > Select Material 선택하여 material 위치로 이동

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759187503.jpg" />
* material을 선택 후 inspector창 상단 shader를 standard로 변경
* 대부분의 경우 Universal Render pipeline으로 만들어진 모델을 Built-in으로 변경가능 하지만. 이 방법으로 변경이 안된다면 사용할수 없는 모델입니다.

---

# 자동변경 복구
* Asset store에서 모델을 다운로드 받아서 사용하다가 자동으로 render pipeline이 변경되면 잘 보이던 모델이 분홍색(error shader)으로 보일 수 있습니다.
* 자동으로 Built-in render pipeline이 Universal Render pipeline으로 변경되었을때 되돌리는법
  
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759181615.jpg" />
* Menu > Edit > Project Settings

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1759181781.jpg" />
* Project Settings > Graphics > Scriptable Render Settings 우측 동그라미 버튼 선택
* Select Render Pipeline Asset 창에서 None 선택