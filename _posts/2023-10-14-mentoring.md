---
layout: post
title: mentoring 멘토링
category: etc
tags:
---

1시간
2023-10-14 20:00 ~ 23:20
3시간 30분

비용지급.

# 랜덤 포탈 조정
* 룸마다 3개, 총 46개 /2 = 23개 쌍
* 중복없이 랜덤으로 연결되도록 코드
* 룸 15*3, 보스방 1

# 피격 숫자 뜨지 않는 오류
* enemy_hited_figure
* setactive false하고 awake 기능을 기대함
* 비활성화 일때는 awake동작안함
* dont destroy에 등록되지 못하고 파괴된 상태
* missing referance exception

# 플레이어 사망시 입력 불가능
```c#
if (current_hp <= 0 && isDead == false)
{
    animator.SetTrigger("Player_death");
    playercontroller.player_death();
    isDead = true;
}
```

# 빌리지 신 재방문시 캐릭터 겹침
# 플레이어 체력 사망 설정
* 체력만 볼것이 아닌
* 사망여부를 변수로 기록했어야 한다

# 보스 몬스터 움직임

* Awake에서 getComponent를 하다가 컴퍼넌트가 존재하지 않으면 스크립트 자체가 자동으로 disable됨

* 깃주소 : https://github.com/HBNU-SWUNIV/come-capstone23-gdt/tree/main

---

2023-10-26 20:00 ~ 22:38
2시간 30분

# 몬스터 AI 움직임
* EnemyMove.cs 파일내에 잡몹의 움직임에 대한 소스코드가 구현되어 있지 않습니다.
* Attack1,2,3 에 대한 SetTrigger만 있으니 걷는것에 대한 animatior.SetTrigger도 구현되어야 합니다.

## 몬스터가 공중에 뜹니다.
* RigiedBody로 인한 물리 움직임이 문제가 될 것입니다.

## 보스 몹 움직임
* 조건문 검사 : if안에 들어간 조건문을 Debug.Log하여 조건이 달성 되었는지를 우선 판별해야 합니다.
* CompareTag가 실패했을 경우 gameObject.tag를 직접 찍어서 확인할 수 있다.
* Debug.DrawRay(); //레이케스트를 시각적으로 표시해주는 디버그 도구
* 레이케스트 - 10은 수치가 너무 많으니 더 조금 움직여야 합니다.
* Vector2.left * raycast distance;
* flip이 아닌 방향에 따른 right 설정이 되어야 합니다.
* tag에 현재상태를 기록하는 방식이 아닌 변수에 기록하는 방식으로 바뀌는 것이 좋습니다.

* advanced polygon collider
* 콜라이더 동적 생성

* 보스의 위치가 맞지 않는것은 원점이 맞지 않아서. 어긋나 있기때문
* 보스의 위치 보정을 위해서 GameObject를 하나 추가하여 자식객체로 등록하는 것을 추천합니다.

# 포탈 연결

# 멘토링
* 11월 29일 - 수정가능

