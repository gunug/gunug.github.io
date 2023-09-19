---
layout: post
title: A* Pathfinding Project Pro
category: unity-asset
tags: asset
---

# A* Pathfinding Project Pro
* 에셋스토어 : [A* Pathfinding Project Pro](https://assetstore.unity.com/packages/tools/behavior-ai/a-pathfinding-project-pro-87744)
* [document](https://arongranberg.com/astar/docs/getstarted.html)

---

# NavMesh
* [참고](https://wergia.tistory.com/224)

* Window > AI > Navigation
* 바닥이 될 객체들은 inspector에서 static 체크
* Navigation창 > object > navigation Static 체크를 해도 동일하게 NavMesh를 생성
* Navigation창 > bake > bake 선택하여 NavMesh 베이크

---

# 세팅하기
* 이 앱에서는 NavMesh가 아닌 PathFinder를 사용하는것 같다.
* A*, Bot, Target, Camera를 옮기기
* A*선택 inspector창 > Pathfinder > RacastGraph
* Center와 Size를 조절하여 Pathfinder를 그릴 영역 설정
* Graph Display의 Scan을 선택하여 Pathfinder 그리기
* 이후 Play하면 예제와 동일 하게 다른 Scene에서도 사용가능
* Navmesh Cut 컴퍼넌트를 사용하면 다이나믹 패스파인더 변경이 가능