---
layout: post
title: Vuforia 뷰포리아
category: unity3d
tags: unity ar
---

# Vuforia 뷰포리아

* 참고 사이트 : http://dark0946.tistory.com/292

---

# 뷰포리아 개요 
* 스냅드래곤으로 유명한 퀄컴(Qualcomm) 社 에서 만든 증강현실(AR) 기술
## 개발자 등록 
## 회원가입 
* 뷰포리아 개발자 페이지 : https://developer.vuforia.com/
* 우상단 Register클릭
* 가입양식 적어넣기 (하단참조)
    * First name	이름	
    * Last name	성	
    * Email Address	이메일 주소	(아이디로도 사용되니 잊지 않도록 합니다)
    * Confirm Email	이메일 주소 재확인	
    * Password	암호	암호는 반드시 8자이상 1자이상 대문자/소문자 포함되어야 합니다.
    * Confirm password	패스워스 재확인	
    * Company	회사명	개인 가입자는 영문 이름으로 작성
    * Country	국가 이름	대한민국 - Korea, Republic of
    * How did you learn about Vuforia?	어떻게 뷰포리아를 알게 되었습니까?	
    * Username	사용자 이름	사이트에서 사용하게될 닉네임
    * Which development platform are you interested in?(check all that apply)	어떤 플랫폼 개발에 관심이 있습니까? (중복선택 가능)	
    * I would like to receive updates on Vuforia news and evnet	뷰포리아 업데이트, 뉴스, 이벤트관련 이메일 수신 여부	
    * Verification	인증	위에 보이는 이미지에서 진한 글자를 입력
    * i agree to the Vuforia Developer Agreement	나는 뷰포리아 개발자 약관에 동의합니다.	반드시 체크
* Register버튼을 눌러 등록을 완료한다.
## 인증메일 확인 
* 등록 완료 후 위에 입력한 이메일주소로 메일이 발송됨
* 이메일을 확인하고 이메일에 포함된 링크를 클릭하면 가입확인

---

# SDK다운로드 
* 뷰포리아 개발자 페이지 : https://developer.vuforia.com/ 접속
* download>sdk내의 'Download for Unity'클릭하여 패키지 다운로드
* 새 Unity 프로젝트를 만들고 패키지를 더블클릭하여 import
* Qualcomm Augmented Reality -> Prefabs 폴더에 뷰포리아 기본 프리팹들이 들어있음
* 이후 Key값 및 DB셋팅을 해주면, 기본기능은 코딩없이 구현 가능
 유니티 최신버전에서 기본 import 되면서 dll파일 충돌상황 발생 
* Assets\Vuforia\Scripts\Internal|\Vuforia.UnityExtensions.dll
* Assets\Vuforia\Editor\Scripts\\Vuforia.UnityExtensions.Editor.dll
* package download 부분을 건너뛰고.  playersetting XR setting 으로 해결해야 할듯

# imagetarget 
* Qualcomm Augmented Reality - Prefabs 폴더안에 있는
* ARCamera , ImageTarget 2개를 Hierarchy탭으로 드래그 드롭
* 기존에 있던 Main Camera는 삭제

# 라이센스 키 발급받기 
* 하나의 앱당 하나의 라이센스를 가져야 한다.
* imageTarget의 inspector에 imageTargetBehaviour(script) 부분
* 'no targets defined. press here for target creation' 버튼을 누르면 개발페이지 내 라이센스 메니져 탭으로 이동됨
  * 링크주소 : https://developer.vuforia.com/targetmanager/project/checkDeviceProjectsCreated?dataRequestedForUserId
* Add License Key선택
* 어플리케이션 이름을 설정하고 next를 누름
    * Starter : 무료. 워터마크 표시, Cloud 인식 제한적 트래픽 사용.
    * Classic : 유료 ( 라이센스 1개, $499 ) , 워터마크 제거 가능 (Cloud 인식 기능 사용 불가 )
    * Cloud : 유료 ( 월$99 ~$999 ) , 워터마크 제거 및 Cloud 인식 트래픽 차등.
* By clicking 'confirm' below, you acknowledge that this license key is subject to the terms and conditions of the Vuforia Developer agreement.에 체크한 후 confirm 클릭
* 다시 라이센스 창으로 돌아오면 새로 등록한 라이센스가 추가된것이 보임
* 라이센스 이름을 클릭하여 라이센스키를 전체복사 한다.
* 복사한 라이센스키를 hierachy에 있는 ARCamera를 선택하면 나오는 inspector의 QCARBehaviour(script)의 app license key에 붙여넣기 한다
  * 버전변경으로 인하여 inspector가 간소화 되었다. 'open vuforia configuration' 버튼을 클릭하여 오픈 가능
  * 버전별 오류발생 가능성 확인 : http://dark0946.tistory.com/342

# target manager 오브젝트 등록하기 
* 뷰포리아 개발자페이지 Develop>TargetManager탭에 LicenseManager와 비슷한 형식의 페이지가 준비되어 있다
* Add Database 클릭
* Database이름을 임의로 입력 후, Device로 선택하고 Create를 누름
  * Device : 기기안에 오브젝트 (이미지 or 모델링) 데이터를 담아두고, 데이터를 읽는 방식
    * 장점 : 인식 횟수 무제한.
    * 단점 : 앱 용량 증가. 새로운 Target 오브젝트를 추가할때마다 빌드를 새로 해야함.
    * Cloud : 개발자 페이지에서 셋팅한 데이터를 뷰포리아 서버와 연결하여 데이터를 읽는 방식.
    * 장점 : 오브젝트 관련 데이터를 서버와 연동하므로 앱을 가볍게 만들수 있음. 신규 Target을 추가하더라도 데이터를 서버에서 받아오므로 앱 빌드를 새로 할 필요 없음.
    * 단점 : 인식 횟수 제한. ( 트래픽을 추가하려면 비용 지불 )
* 각각의 Database에는 다수의 Target오브젝트를 갖을 수 있음
* Add Target에 Type은 Single Image로 설정
* 타겟이 될 이미지 파일을업로드

* width는 실제 이미지의 가로길이를 mm(밀리미터)단위로 입력
* 이미지를 모두 추가한 이후에 Download Dataset(All)을 클릭
* Unity Editor를 선택한 후 download 클릭
* 다운받아진 패키지를 더블클릭하여 프로젝으로 import
* imageTarget선택후 inspector에서 imageTargetBehaviour의 imageTarget에 EMPTY대신 새로만들어진 타겟을 선택한다.
* Database와 Target설정을 하고나면 하얀 네모만 있던 imageTarget부분에 이미지가 나타남
  * unity 5.5이상 imageTarget에 이미지가 나타나지 않고 흰색또는 이상하게 표시될때
  * Editor>QCAR>ImageTargetTextures>database안에 직접 업로드 한 이미지 텍스쳐를 선택 후 설정을 다음으로 변경
    * Texture Type - defult
    * Texture Shape - 2D
* 이후에 imageTarget에 하위객체로 3D모델을 올려준다.

* ARCamera선택 후 inspector창에 DataSetLoadBehaviour스크립트란에 LoadDataSet[database name] 체크
* 하단에 추가되는 Active도 체크
