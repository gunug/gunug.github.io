---
layout: post
title: 버튼 인터랙션 실습
category: sub
tags: 
---

* 이 실습은 [Meta XR Project Setting](/vr/2024/09/05/meta_xr_start.html){:target="_blank"} 이 선행 되어야 합니다.

# 버튼 인터랙션 실습
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762177052.jpg" />
* poke example scene을 열기
* Interactables > BigRedButton > Button 선택
* Inpector 창에서 interatable Unity Event Wrapper 찾기

## 선택할 수 있는 인터랙션
* `Interactable Unity Event Wrapper`는 XR Interaction Toolkit에서 제공하는 컴포넌트로,  
* 사용자가 XR 환경에서 오브젝트(버튼 등)와 상호작용할 때 발생하는 이벤트들을 UnityEvent 형태로 노출한다.

| 이벤트 이름 | 발생 시점 | 설명 |
|--------------|------------|------|
| **When Hover()** | 인터랙터(손, 컨트롤러, 포인터 등)가 오브젝트 위에 올라왔을 때 | 마우스 오버처럼, 사용자가 오브젝트를 ‘가리키기 시작할 때’ 호출된다. |
| **When Unhover()** | 인터랙터가 오브젝트 위에서 벗어날 때 | Hover 상태가 해제될 때 (가리키던 손이나 레이가 떠날 때). |
| **When Select()** | 오브젝트를 실제로 ‘선택’했을 때 | 버튼을 누르거나 트리거를 당기는 등, 클릭/그랩 동작 시 발생한다. |
| **When Unselect()** | 선택 상태를 해제했을 때 | 버튼에서 손을 떼거나, 그랩을 놓을 때 발생한다. |
| **When Interactor View Added()** | 새로운 인터랙터가 감지되었을 때 | 새로운 손, 레이캐스트 등 상호작용 가능한 대상이 인식될 때 호출된다. |
| **When Interactor View Removed()** | 감지되던 인터랙터가 사라졌을 때 | 손이 트래킹에서 벗어나거나 레이가 끊길 때 발생한다. |
| **When Selecting Interactor View Added()** | 선택을 시도하는 인터랙터가 추가될 때 | 오브젝트를 선택하려는 인터랙터가 진입할 때 호출된다. |
| **When Selecting Interactor View Removed()** | 선택 중이던 인터랙터가 빠져나갈 때 | 선택을 시도하던 인터랙터가 중단되거나 사라질 때 발생한다. |

### 1. Interactor란?
XR Interaction Toolkit에서 **Interactor**는 “사용자의 상호작용 행위 주체”를 의미한다.  
- 예시:
  - 손으로 누를 때 → **Poke Interactor**
  - 컨트롤러로 집을 때 → **Direct Interactor**
  - 멀리서 레이로 가리킬 때 → **Ray Interactor**
  - 눈동자/시선으로 조준할 때 → **Gaze Interactor**

```csharp
void OnInteractorViewAdded(InteractorView view)
{
    var interactor = view.Interactor; // 실제 인터랙터 객체

    if (interactor is XRRayInteractor)
        Debug.Log("Ray Interactor 감지됨");
    else if (interactor is XRPokeInteractor)
        Debug.Log("Poke Interactor 감지됨");
    else if (interactor is XRGazeInteractor)
        Debug.Log("Gaze Interactor 감지됨");
}
```

---

### 요약
- **Hover / Unhover** → 포인팅(가리킴)
- **Select / Unselect** → 실제 클릭 또는 잡기(그랩)
- **Interactor View Added/Removed** → 트래킹되는 인터랙터 감지 변화
- **Selecting Interactor View Added/Removed** → 선택 상태 변화

---

# 스크립트 생성하기
* 기존 [Gemini 제미나이 실습2](/etc/2025/11/03/Gemini2.html){:target="_blank"}을 통해 만들어진 소스코드를 그대로 사용하여 다른 이벤트에 연결해 봅시다.
* ```새 스크립트 colorChanger.cs파일 생성해줘. material color를 빨강,파랑,초록 순서대로 반복되게 변경하는 public 함수 colorRotation 포함```

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762185785.jpg" />

* poke example scene에서 cube 생성

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762186356.jpg" />

* cube에 colorChanger.cs를 드래그 드랍하여 적용 (이번엔 clickEventHandler.cs는 사용하지 않습니다.)

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762186534.jpg" />

* button의 When Select의 추가(+) 버튼을 눌러 대상을 추가
* Object 란에 cube을 드래드 드랍하여 연결
* function 부분에서 colorChanger.colorRotation을 선택
* 결과적으로 '버튼을 누르(When Select)면 컬러바꾸기(colorRotation)' 기능이 동작하도록 됨.

---

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762187805.jpg" />

* 스와이프 객체를 왼손으로 스와이프(When active) 하면

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762187965.jpg" />

* DistanceGrab 객체를 멀리서 잡으면(When select)
* HandGrab 객체를 직접 잡으면(When select)

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762188610.jpg" />

* 스프레이를 분사하면(When spray)
* 스프레이를 직사하면(When stream)

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762189210.jpg" />
* 왼손으로 엄지척을 하면(When select)

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762189492.jpg" />
* Interactable Event Wrapper가 없는 경우는 Interactable이 있는 위치에서
* Add Component > 검색하여 추가
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1762189597.jpg" />
* Interactable을 드래그 하여 Interactable Event Wrapper에 연결

---