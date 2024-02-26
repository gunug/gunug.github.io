---
layout: post
title: Google play store  구글 플레이 스토어
category: etc
tags: 
---

# Google play store  구글 플레이 스토어

* 2017.02.13 작성
## 구글 개발자 등록 
* 구글에 새 계정 생성하기
* 구글 플레이접속 [https://play.google.com/store 구글 플레이 스토어]
* 하단에 개발자 버튼이 있다 [http://developer.android.com/ 구글 개발자 페이지]
* 개발자 페이지 우측에 ... Links에 Google Play Developer Console
* 개발자 계약절차 (25$)
* 구글 월렛 가입 및 결제 절차 (지출 및 앱 수익관련 관리툴)
* '유료 앱 또는 인앱 상풍을 생성할 계획이라면 판매자 계정을 생성해야 합니다.' 진행 (안할 경우 무료앱만 출시 할 수 있음)

* 전화번호 입력시 010-1111-1111이라면 +82-10-1111-1111으로 입력해 줘야함 <br />
* 판매자 계정 생성시, 사업자 번호와 서비스 유형등을 선택하게 되어 있는데 <br />
* 월 2500만 이하는 간이 과세자, 이상은 일반과세자로 신청해야 한다.

# 광고추가 
## 애드몹(AdMob) 계정 등록 및 광고 생성 
* [http://admob.co.kr 애드몹 페이지]
* AdMob에 가입하기 5단계 입력절차 진행
* 메뉴의 '수익 올리기' 버튼 클릭, 새로운 광고 생성
* '앱 검색' 또는 '앱 직접추가' 방식으로 앱 선택
* 광고 형식 '배너:부분광고' , '삽입:전면광고'로 나뉜다
* 발급받은 '광고 단위 ID' 관리 주의

#  광고 앱에 등록하기 
* [http://leanbranch.urigit.com/ GitHub 이용방법 학습하기]
* GitHub에서 Google Mobile Ads Unity Plugin v2.2.1를 찾는다
* Plugin(package 형태)를 내려받은뒤 unity에 import
* Google_play_services/libproject/google_play_services.lib를 Unity의 Project로 복사 (안드로이드 SDK가 설치된 폴더의 sdk/extras/google/에서 찾을 수 있음)

# 전면광고 소스코드 작성하기 (Unity) 
```c#
using GoogleMobileAds.Api;

public class FrontBannerAd : MonoBehaviour{
  private InterstitialAd inter Ad;
  private string appId = "ca-app-pub-1234567890/1234567890";

  void Awake(){
    interAd = new InterstitialAd(appId);
    AdRequest request = new AdRequest.Builder().build();
    interAd.LoadAd(request);
  }
  void InterAdShow(){
    if(interAd.IsLoaded()){
      interAd.Show();
    }
  }  
}
```

---

# 배너광고 소스코드 작성하기 (Unity) 
```c#
using GoogleMobileAds.Api;

public class BannderAD : MonoBehaviour{
  private BannderView banner;
  private string appId = "ca-app-pub-1234567890/1234567890";

  void Awake(){
    banner = new BannerView(appId, Adsize.Banner, AdPosition.Top);
    AdRequest request = new AdRequest.Builder().build();
    banner.LoadAd(request);
  }
  void BannerAdShow(){
    banner.Show();
  }  
}
```

---

# 출시 하기 
## Unity Build setting 변경 
* 바로 파일을 올리면 APK 업로드 실패 화면이 나옴
* build settinf > Player Setting 선택
* Publishing Settings 의 Create New Keystore 선택
* Browse Keystore에 Keystore password, Confirm password 입력
* Alias Unsigned (debug)를 Create a new key로 변경
* Create a new Key 선택 후 다음을 입력
* Alias: 생성될 키의 별칭
* Password: 패스워드
* Confirm: 패스워드 확인
* Validity (Years): 인증서 유효기간
* First And LastName: 이름
* Organizational Unit: 조직 단위
* Organization: 조직 (회사)
* City or Locality: 도시
* State or Province: 지역
* Country Code (XX): 국가번호

---

# 구글 마켓에 등록 
* 새 어플리케이션 추가
* 프로덕션으로 첫 번째 APK 업로드 버튼 선택
* APK업로드 후 스토어 등록정보 및 나머지 추가 정보 입력후 '앱 게시' 버튼 선택
