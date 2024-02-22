---
layout: post
title: unity chasing 추적하기
category: unity3d
tags: unity3d
---


# unity chasing 추적하기

* 모델 import > rig에서 Humanoid > Create From This Model 선택
* Configure에서 bone 확인후, Mucles & Settings에서 조절가능 rigging이 제대로 되었는지 확인한다. Done을 눌러 되돌아옴
* Project에서 Create > Animation controller 생성 > 더블클릭하여 오픈. Animation controller에 animation을 드래그 드롭하여 새 블럭을 만들고. 블럭 우클릭 Make Transition하여 서로 연결.
* 연결된 Transition 선택 후 Parameters에서 +선택하여 파라메터를 추가. inspector > consitions 변수 선택후 값 선택
* 지면 gameObject선택 후 inspector > Static 선택하여 Navigation Static으로 변경
* Window > Navigation 선택 하여 Navigation 창 열기 . Navigation Static으로 설정되어있는 지면이 나타남
* Bake를 눌러 Walkable 지면 표시 (하늘색으로 표현됨)
* 추적할 대상(이경우는 Player)의 tag를 Player로 설정하여 findWithTag로 찾아낼 예정

* Monster의 Component에 Nav Mesh Agent 추가

```c++
private Transform monsterTr;
private Transform playerTr;
private UnityEngine.AI.NavMeshAgent nvAgent;

// Use this for initialization
void Start () {
//몬스터의 Transform 할당
monsterTr = this.gameObject.GetComponent<Transform>();
//추적대상인 Player의 Transform 할당
playerTr = GameObject.FindWithTag(“Player”).GetComponent<Transform>();
//NavMeshAgent 컴포넌트 할당
nvAgent = this.gameObject.GetComponent<UnityEngine.AI.NavMeshAgent>();

//추적대상의 위치를 설정하면 바로 추적 시작
nvAgent.destination = playerTr.position;
}
```

* _animation.SetBool(“IsTrace”, trace);로 미리 만들어 놓은 구분자 isTrace를 변경하여
애니메이션을 전환 할 수 있다.
