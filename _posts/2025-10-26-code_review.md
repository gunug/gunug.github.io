---
layout: post
title: code review 코드리뷰
category: coding
tags:
---

# 코드리뷰를 하는 이유
## “과정 중심” 포트폴리오 강화
* 디자인 포트폴리오가 결과 중심이라면,
* 코드리뷰는 사고의 흐름(문제 → 시도 → 수정) 을 보여주는 근거가 됩니다.
→ “이 학생은 코드를 ‘그냥 썼다’가 아니라, 설계하고 디버깅하며 개선했다”는 걸 증명합니다.

## 논리적 커뮤니케이션 훈련
* 코드리뷰는 디자인 피드백처럼
* “왜 이렇게 구현했는가?”, “이 방법의 장단점은?” 을 설명하는 연습이 됩니다.
→ 협업 프로젝트나 면접에서 자기 코드 설명 능력을 키우는 데 직접적으로 도움 됩니다.

## 디자인 감각 + 기술적 완성도 연결
* 디자인 전공 학생이 종종 “감각은 좋은데 구현이 불안정하다”는 평가를 받습니다.
* 리뷰를 통해 코드의 구조, 성능, 유지보수성, 애니메이션 타이밍 등을 잡아주면
* 디자인과 기술 사이의 균형 감각을 키울 수 있습니다.

## 실제 개발자 협업 대비
* 현업에서는 git, issue tracking, 코드리뷰 문화에 익숙해야 합니다.
* 학생들이 리뷰를 통해 피드백을 주고받는 경험은 팀 프로젝트 협업 능력으로 직결됩니다.

---

# 코드리뷰의 목적
* 문제 해결 과정과 논리적 사고를 드러내는 것
* 디자인 의도와 코드 구현의 일관성을 점검하는 것
* 가독성·유지보수성·확장성을 학습하는 것
* 협업 및 피드백 커뮤니케이션 능력을 기르는 것

## 코드리뷰 기준 (가이드라인)
1. 코드 구조 (Structure)
* 파일, 함수, 변수의 역할이 명확하게 분리되어 있는가?
* 불필요한 중복 코드가 없는가?
* 로직이 단계적으로 읽히는가?

2. 가독성 (Readability)
* 들여쓰기, 네이밍, 주석이 일관성 있는가?
* 다른 사람이 봐도 흐름을 파악할 수 있는가?
* 코드 스타일(언어별 컨벤션)을 따르고 있는가?

3. 기능 구현 정확성 (Functionality)
* 코드가 의도한 대로 작동하는가?
* 인터랙션이나 애니메이션이 정확히 트리거되는가?
* 오류나 버그가 최소화되어 있는가?

4. 디자인 일관성 (Design Consistency)
* 디자인 시안 또는 의도와 코드 결과물이 일치하는가?
* 색상, 모션, 타이밍 등 디자인적 요소가 구현 단계에서 왜곡되지 않았는가?
* 코드 수정이 디자인 품질에 영향을 주지 않았는가?

5. 효율성과 확장성 (Efficiency & Scalability)
* 불필요하게 복잡한 로직은 없는가?
* 반복되는 코드는 함수화되어 있는가?
* 향후 수정/추가가 쉽게 설계되어 있는가?

6. 창의적 시도 및 실험성 (Creativity)
* 기존 방식을 그대로 복제한 것이 아닌가?
* 새로운 시도(인터랙션, 애니메이션, 데이터 활용 등)가 있는가?
* 기술이 디자인적 표현을 확장시키는 방향으로 쓰였는가?

7. 커뮤니케이션 및 피드백 반영 (Communication)
* 코드리뷰에서 받은 피드백을 얼마나 반영했는가?
* 개선 과정을 명확히 기록했는가?
* 타인의 리뷰에 대한 응답이나 설명이 논리적인가?

---

# 코드리뷰 예시
* “과정 중심 회고형(Reflection Style)” — 가장 권장
* 적합 대상: 디자인 중심 학생 / 사고 과정 강조형 포트폴리오

* 구현과정, 코드예시, 문제와 해결, 배운점, 작동방식 요약 등을 작성합니다.

### 구현 과정
사용자의 스크롤에 따라 배경색이 변화하는 인터랙션을 만들고 싶었습니다.  
처음에는 `window.scrollY` 값을 직접 색상에 매핑했지만, 변화가 너무 급격했습니다.  
그래서 `map()` 함수를 사용해 스크롤 범위를 색상 값으로 부드럽게 보정했습니다.

### 코드 예시
```js
const scrollProgress = window.scrollY / document.body.scrollHeight;
const bgColor = `hsl(${scrollProgress * 360}, 80%, 60%)`;
document.body.style.backgroundColor = bgColor;
```
### 문제와 해결
* 문제: 스크롤 시 색상 변화가 갑자기 튀는 느낌
* 해결: easing 함수를 적용하여 색상 변화 완화
* 결과: 인터랙션의 감정적 연결성이 높아짐

### 배운 점
* 단순한 코드 구현이 아니라 “감각적 전환의 타이밍”이 UX의 일부임을 깨달았습니다.

```js
// 스크롤 진행 비율 계산
const scrollProgress = window.scrollY / (document.body.scrollHeight - window.innerHeight);

// Easing 함수 정의 (easeInOutCubic 예시)
function easeInOutCubic(t) {
  return t < 0.5
    ? 4 * t * t * t
    : 1 - Math.pow(-2 * t + 2, 3) / 2;
}

// Easing 적용
const easedProgress = easeInOutCubic(scrollProgress);

// 색상 계산 (HSL 사용)
const bgColor = `hsl(${easedProgress * 360}, 80%, 60%)`;

// 배경색 적용
document.body.style.backgroundColor = bgColor;
```

### 작동 방식 요약
* scrollProgress는 0~1 사이의 선형 값.
* easeInOutCubic()으로 완화된 곡선을 적용하면 스크롤 초반엔 변화가 느리고 중간 구간은 빠르고 끝부분은 다시 완만해집니다.
* 그 결과 색상 변화가 부드럽고 자연스러운 시각적 리듬을 가집니다.

### 다른 이징 함수 예시들
* 원하는 느낌에 따라 바꿀 수 있습니다.

| 함수 이름 | 코드 | 효과 |
|------------|------|------|
| **easeOutQuad** | ```js\nt => 1 - (1 - t) * (1 - t)\n``` | 초반 빠르고 끝 완만 |
| **easeInQuad** | ```js\nt => t * t\n``` | 초반 느리고 점점 빨라짐 |
| **easeInOutSine** | ```js\nt => -(Math.cos(Math.PI * t) - 1) / 2\n``` | 매우 자연스러운 S자 곡선 |
| **easeInOutCubic** | ```js\nfunction easeInOutCubic(t) {\n  return t < 0.5\n    ? 4 * t * t * t\n    : 1 - Math.pow(-2 * t + 2, 3) / 2;\n}\n``` | 부드럽고 안정적인 색상 전환에 적합 |

### 사용 예시

```js
const scrollProgress = window.scrollY / (document.body.scrollHeight - window.innerHeight);
const easedProgress = easeInOutCubic(scrollProgress);
const bgColor = `hsl(${easedProgress * 360}, 80%, 60%)`;
document.body.style.backgroundColor = bgColor;
```

---

# 코드리뷰 결론

* 코드리뷰는 **자신이 프로젝트를 얼마나 이해하고 구현했는지를 보여주는 과정**입니다.  
* 단순히 작동하는 코드를 제출하는 것이 아니라, **왜 이렇게 작성했는지**를 설명함으로써 사고의 깊이를 드러냅니다.  
* 어떤 기능을 ‘이해하지 못한 채 사용했다면’, 이를 복습하고 스스로 정리하는 기회로 삼으세요.  
* 모든 코드를 완벽히 설명할 필요는 없습니다.  
  **자신이 이해한 범위 안에서, 얼마나 논리적으로 사고하고 개선했는지를 표현하는 것**이 가장 중요합니다.  
* 즉, 코드리뷰는 **결과보다 과정**, **정답보다 사고력**을 보여주는 공간입니다.
