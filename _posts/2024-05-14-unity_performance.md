---
layout: post
title: Unity Performance 최적화
category: unity3d
tags:
---

# Unity Performance 최적화

---

## 그래픽 퍼포먼스
- https://docs.unity3d.com/kr/current/Manual/OptimizingGraphicsPerformance.html
- Draw Call( DP Call ) 보통 70~100 정도가 일반적.
- 텍스쳐에서 Generate Mip Maps 활성화 하기
### LOD Group 컴포넌트를 추가하기
- 프러스텀(Frustum) 컬링 : 각 Layer별로 컬링 거리를 설정하는것이 가능, 멀리서도 보이는 오브젝트는 멀게 설정하고. 중요도가 낮은 오브젝트는 거리를 짧게 설정
- 오클루젼(Occlusion)컬링 : Window > rendering > Occlusion Culling 메뉴에서 설정 가능 (기본 설정값에서 bake를 눌러서 생성, play중에 확인 가능)
- 오클루젼 컬링 : https://docs.unity3d.com/kr/530/Manual/OcclusionCulling.html

---

- Smallest Occluder :	오 클루 젼 컬링을 수행 할 때 다른 객체를 숨기는 데 사용되는 가장 작은 객체의 크기입니다. 이 크기보다 작은 모든 오브젝트는 오브젝트에 의해 가려진 오브젝트가 절대로 제거되지 않습니다. 예를 들어 값이 5 인 경우 5 미터보다 크거나 더 넓은 모든 객체는 뒤에 숨겨진 객체가 추려 지도록합니다 (렌더링되지 않고 렌더링 시간 절약). 이 속성에 대한 좋은 값을 선택하는 것은 오 클루 젼 정확도와 오 클루 전 데이터 저장 크기 사이의 균형입니다.
- Smallest Hole :	이 값은 카메라가 보게 될 지형 간의 최소 간격을 나타냅니다. 이 값은 구멍을 통해 들어갈 수있는 물체의 직경을 나타냅니다. 장면에 카메라가 볼 수있는 균열이 매우 작 으면 가장 작은 구멍 값이 간격의 가장 좁은 치수보다 작아야합니다.

---

- Backface Threshold :	유니티의 오 클루 전은 데이터 크기 최적화를 사용하여 뒷면을 테스트하여 불필요한 세부 사항을 줄입니다. 기본값 100은 견고하며 데이터 집합에서 뒷면을 절대로 제거하지 않습니다. 값 5는 눈에 보이는 뒷면이있는 위치를 기반으로 데이터를 적극적으로 줄입니다. 일반적으로 유효한 카메라 위치는 일반적으로 많은 뒷면을 보지 못합니다 (예 : 지형의 아래쪽 뷰 또는 도달 할 수없는 단단한 물체에서의 뷰). 임계 값이 100보다 낮 으면 Unity는 데이터 세트에서이 영역을 완전히 제거하여 폐색의 데이터 크기를 줄입니다.

---

- 오브젝트 통합(Combine) : 드로우콜을 줄이기 위한 방법. Script패키지, CombineChildren 컴포넌트 제공 (통합하는 경우는 택스쳐를 하나로 합쳐서 texture atlas)를 사용
- Static Batch : Edit > project setting > player에서 설정, 움직이지 않는 오브젝트들은 static으로 설정해서, 배칭 되도록 함. static으로 설정된 게임 오브젝트에서 동일한 재질을 사용할 경우, 자동으로 통합됨. 통합되는 오브젝트를 모두 하나의 커다란 메쉬로 만들어서 따로 저장(메모리 사용량 증가)
- 쉐이더를 사용할경우에는 모바일용 쉐이더를 사용 , Mobile > VertexLit은 가장 빠른 쉐이더

---

# 물리엔진 퍼포먼스
- FixedUpdate 주기 조절 : TimeManager에서 업데이트 주기 조절. (게임에 따라 0.2초 또는 그 이상으로 수정하여도 문제 없음)
움직이지 않는 물체는 static으로 설정
- 리지드 바디가 없는 고정 충돌체를 움직이면 CPU부하 발생, 이런경우 리지드 바디를 추가하고, isKinematic 옵션 사용.
- Maximum Allowed Timestep 조정 : 시스템에 부하가 걸려 지정된 시간보다 오래 걸릴경우 물리 계산을 건너뛰는 설정
- Solver Iteration Count 조정 : 물리 관련 계산을 얼마나 정교하게 할지를 지정. (높을수록 정교함) Edit > Project Setting > Physics
- Sleep 조절 : 리지드 바디 속력이 설정된 값보다 작을 경우, 휴면상태에 들어감. Physics.Sleep() 함수를 이용하면 강제 휴면상태로 만들 수 있음
매쉬 콜라이더를 사용하지 않는다.

---

# 라이팅 퍼포먼스
- 출처: https://docs.unity3d.com/kr/530/Manual/LightPerformance.html
- 라이트맵 베이크하여 사용하기
- 라이트 렌더모드에서 important, not important 설정가능, 게임에서 중요한 동적 라이팅에만 important로 설정

---

# 퀄리티 세팅
- 출처: https://docs.unity3d.com/kr/530/Manual/class-QualitySettings.html
# 기타 최적화 방법
https://coderzero.tistory.com/entry/%EC%9C%A0%EB%8B%88%ED%8B%B0-%EC%B5%9C%EC%A0%81%ED%99%94-%EC%9C%A0%EB%8B%88%ED%8B%B0-%EC%B5%9C%EC%A0%81%ED%99%94%EC%97%90-%EB%8C%80%ED%95%9C-%EC%9D%B4%ED%95%B4