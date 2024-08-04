---
layout: post
title: OpenAI API key 환경변수 등록
category: subpage
tags: 
---

# OpenAI API key 환경변수 등록

* 환경변수는 컴퓨터 자체에 기록하는 변수 입니다.
* 외부에서 값에 접근 할 수 없어 안전하게 값을 저장하고 사용할 수 있습니다.

* window + R 단축키 입력
 
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722754630.jpg" />

* 실행창에 cmd 입력 후 확인 클릭
* 윈도우 > 시작메뉴 > cmd(터미널) - 방법으로 실행해도 동일

* ```setx OPENAI_API_KEY 키값``` 환경변수로 키 등록
* ```echo %OPENAI_API_KEY%``` 등록된 키 보기 (터미널을 다시 실행해야 변경된 키값을 볼 수 있습니다)
* <https://help.openai.com/en/articles/5112595-best-practices-for-api-key-safety>{:target="_blank"} 환경변수를 이용한 키설정 참고

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1722754961.jpg" />