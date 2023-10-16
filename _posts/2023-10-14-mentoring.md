2023-10-14 20:00 ~ 23:20

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