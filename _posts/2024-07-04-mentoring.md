---
layout: post
title: mentoring 멘토링
category: etc
tags: 
---

# 멘토링 2023-04-21 21:00

---

# 멘토링 유의사항

- 멘토링 내용을 무조건 따라야 하는건 아닙니다.
- 멘토링은 프로젝트에 대한 의견을 말해주고 어려운것에 대한 도움을 주는것 입니다.
- 프로젝트 진행 방향의 결정은 지도교수님과 상의하고 팀원들이 정해야 할 일입니다.
- 적극적인 요구사항이 있어야 합니다.

---

# 요청사항
- FSM, 캐릭터에 장착되는 2D 소켓, 실감나는 적 AI 제작, github에서의 다운파일의 온정성, 유니티 네비게이션
- 너무 큰 개념 (FSM)
- 모호한 단어 (실감나는)
- 사용하지 않는 단어 (2D 소켓, 온정성, 네비게이션-NaviMeshAgent?)

---

# 좋지않은 요청사항이란
- FSM 만드는 방법을 모르겠습니다. (처음부터 끝까지 알려달라는 의미, 내용이 너무 광범위함)

# 좋은 요청사항이란1
- FSM에서 000의 개념이 잘 이해가 안됩니다. (전체가 아닌 구체적인 부분을 질문)
- FSM를 다음과 같이 만들어보았는데 개선점이 있을까요? (cs파일 첨부)
- FSM을 보면 상속이나 추상클래스 가상클래스를 사용하는데 이유가 무엇인가요?
- 다음과 같은 캐릭터 2D소켓 자료를 찾았는데(링크첨부) 우리 프로젝트에 적용할 수 있을까요?

---

# 좋은 요청사항이란2

- (예시 동영상 링크첨부)다음과 같은 AI 적들을 구현하려면 어떻게 구성해야 할까요
- Github를 이용해서 프로젝트를 진행할 예정인데 유의사항은 없을까요?
- Github를 사용해서 프로젝트를 진행하다가 다음과 같은 문제가 발생하였습니다. 이유는 무엇이고 해당 문제를 해결하려면 (또 다시 발생하지 않게 하려면) 어떻게 해야 하나요?

---

# 멘토링을 효율 적으로 받기 위하여
- 멘토링을 받기위한 자료를 만들 필요는 없지만 같이 보고 이야기할만한 구체적인 사례, 예시, 소스코드는 있어야 합니다.
- 링크 주소, 동영상, 스크린샷 등이 있다면 같이보고 이야기 할 것입니다.

---

# FSM : 유한 상태 머신 (Finite State Machine)
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1720067193.jpg" />
- 유한개의 상태를 가지고 주어지는 입력에 따라 상태를 전환하거나 출력하거나 액션이 일어나게하는 장치

---

# 고박사의 유니티 노트
- FSM1 : https://youtu.be/O_NJaHpbjaI
- FSM2 : https://youtu.be/4rmf0S885X4
- FSM3 : https://youtu.be/DeJO4zOFG9E
- FSM4 : https://youtu.be/xGu-sTL73iU

---

# Dictionary
- 정보를 Key와 Value로 저장하기 위한 구조체

```c#
Dictionary<TKey,TValue>
SortedDictionary<TKey,TValue>
```
- `<Tkey, TValue>` 문법이 궁금하다면 제너릭 클래스 읽어볼것
- 제너릭 클래스 : https://learn.microsoft.com/ko-kr/dotnet/csharp/language-reference/keywords/where-generic-type-constraint

```c#
private Dictionary<string,int> player_state = new Dictionary<string,int>(){
    {"age", 20},
    {"hp", 100},
    {"max_hp",100}
}
```

---

- 상태 판단 (게임매니져, 몬스터, 플레이어의 몫)
  
```c#
private enum GameState{
    mainMenu,intro,playing,gameOver
}
public static GameState currentGameState = GameState.mainMenu;
```

---

- 상태 수행 (몬스터의 몫)
  
```c#
private void ChangeState(PlayerState newState){ //상태 변환 함수
    StopCoroutine(playerState.ToString()); //이전 상태 수행중지
    playerState = newState; //새로운 상태기록
    StartCoroutine(playerState.ToString()); //새 상태 수행시작
}
private IEnumerator Idle(){
    //상태 진입
    while(true){
        //상태 수행
        yield return null;
    }
    //상태 종료
}
private IEnumerator Attack()...
```

---

# 2D 소켓
- AnyPortrait ($49) : https://assetstore.unity.com/packages/tools/animation/anyportrait-111584
- 본과 메시의 소켓 이용방법 : https://rainyrizzle.github.io/kr/AdvancedManual/AD_Socket.html
- https://rainyrizzle.github.io/kr/AdvancedManual/AD_AttachEquipments.html

- Unity 2d bone animation : https://youtu.be/k4LkNtp9_wU

---

# NaviMeshAgent
- https://wergia.tistory.com/224

# Unity UI , UI Toolkit
- UI Toolkit download: https://unity.com/kr/features/ui-toolkit
- UI Toolkit 설명 : https://mechurak.github.io/2023-02-24_unity_ui_toolkit/
- Navagation view : https://www.youtube.com/watch?v=XymkbKQRih8

---

# 인디게임이 리소스 부하를 줄이는 법
- Brotato : https://youtu.be/-_pVPhP8CUk
- 로그라이크 장르도 인디게임사가 컨텐츠 분량은 늘리는 수단 중 하나

---

# 생각보다 긴 작업시간
## 하이하이
- 참고자료 : https://blog.naver.com/PostView.nhn?blogId=eastfever5&logNo=221928964306
- 하이 하이 : https://youtu.be/mqw4O7qrG60
- 점프, 좌우이동, 웅크리기
- 날아오는 미사일, 움직이는 플랫폼, 
- 동전먹기, 층 표시하기
- 돌맹이, 선인장, 미사일, 불꽃
- 개발자 3명이서 4~5개월
- 겉으로 쉽게 보이지 않는 세부적인 기능이 많기 때문
 
---
 
## 플래피버드
- 보도자료 : https://www.gametoc.co.kr/news/articleView.html?idxno=15120
- 2~3일
- 지나가는 파이프
- 점수 올라가기
- 탭하면 캐릭터가 올라가고, 천천히 떨어짐
- 파이브에 부딧치면 게임오버

출처 : 게임톡(https://www.gametoc.co.kr)

---

# 실제로 게임을 기획한다는 것
- 뱀파이어 서바이벌 : https://www.youtube.com/watch?v=aS7JqyHdQQA
- https://namu.wiki/w/Vampire%20Survivors/%EC%95%84%EC%9D%B4%ED%85%9C

---

# 세이브
## 데이터 직렬화 (Serialization), 역직렬화 (Deserialization)
- https://rito15.github.io/posts/unity-serialize-tree-object/
## 플레이어 프랩스 (PlayerPrefs)
- https://notyu.tistory.com/61
- https://yoonstone-games.tistory.com/43
## 파일저장, 불러오기
- https://yoonstone-games.tistory.com/43

---

# 인벤토리
- https://rito15.github.io/posts/unity-study-rpg-inventory/
- 아이템 추가(습득)
- 아이템 제거(버리기)
- 아이템 사용
- 아이템 이동
- 슬롯 하이라이트
- 아이템 툴팁
- 아이템 버리기 팝업
- 아이템 개수 나누기 팝업
- 인벤토리 빈칸 채우기
- 인벤토리 정렬
- 아이템 필터링

---

# 게임 기능 공부를 하면서 게임을 만든다는 것
- 유니티 초급기술 (23화) : https://www.youtube.com/watch?v=8Wh8LrwuXGE&list=PLC2Tit6NyVifrkxvhC2wg3hbAeuoLpMgV
- 유니티 2D 기초 (11화): https://www.youtube.com/watch?v=MrkATUUX0iU&list=PLC2Tit6NyVie46nbdEM00wFoojjRlXIcf
- 유니티 C# (25화): https://www.youtube.com/watch?v=YKiTGbPIZKQ&list=PLC2Tit6NyVicT5cCqILMWXpXVEoM9ufyH
- 하루에 하나씩만 습득한다고 해도 59일

---

# top down (4방향)
- https://www.youtube.com/watch?v=whzomFgjT50
# top down (회전)
- https://www.youtube.com/watch?v=LNLVOjbrQj4

---

# 그래서 추천하는 방식
- 참고 자료가 될만한 다른 게임을 선정할것 (기획, 기능개발, 레벨 디자인, 리소스 제작에 도움이됨)
- 주 개발내용이 아닌것은 Asset Store에서 무료버전이나 구입하여 사용할것