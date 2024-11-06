---
layout: post
title: unity export package 패키지 내보내기
category: unity
tags: 
---

# 협업시 주의 사항
## folder 생성
* export package, import package 과정에서 폴더명이 같거나 파일명이 같으면 모두 덮어씌워집니다.
* 파일을 잘 저장하였어도 덮어씌워져 유실될 수 있으니 폴더명, 파일명이 겹치지 않도록 하는 것이 중요합니다.

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730905993.jpg" />
* project창 빈공간 우클릭 Create > Folder
* 개인식별자(이름의 이니셜, 닉네임)를 추가한 폴더명을 입력(예 gunhee_폴더명)
* 이후 개인 작업물은 모두 이 폴더 안에 집어넣도록 합니다.

## scene 생성
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730907639.jpg" />
* 개인폴더에 만드는 scene은 어떠한 이름이라도 괜찮습니다.


# unity export package 패키지 내보내기

## Select Dependencies 의존성 선택
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730907824.jpg" />
* Project창에 있는 scene위에서 마우스 우클릭
* Select Dependancies 선택

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730907966.jpg" />
* 관련있는 모든 자산(assets)이 선택(select)됨

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730908030.jpg" />
* 관련 자산이 모두 선택된 상태로 마우스 우클릭
* export package

<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1730908160.jpg" />
* include Dependancies (의존성 포함하기) 체크 해제
* export 버튼 클릭

---

# import package
* 친구로 부터 전달 받은 unitypackage 더블클릭 (또는 Project창에 드래그 드랍)
* import 버튼 클릭
* 폴더 안에 scene을 더블클릭으로 열고 복사(ctrl+c), 붙여넣기(ctrl+v) 방식으로 옮겨오기