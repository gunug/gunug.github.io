---
layout: post
title: media wiki 미디어 위키
category: etc
tags: 
---

# media wiki 미디어 위키

## 로고 변경하기 
* LocalSetting.php 수정
* 내용중 $wgLogo = "$wgScriptPath/resource/assets/wiki.png"; 부분 찾기
* 자신이 만든 로고파일을 해당 패스에 업로드 하고 패스명 바꾸기

## 사용자 권한 조정 
[[특수기능:사용자권한]]에서 권한별 능력 확인
* 권한 그룹 추가 

```php
$wgGroupPermissions['guest']['read'] = true;
$wgGroupPermissions['guest']['edit'] = false;
$wgGroupPermissions['guest']['createaccount'] = false;

$wgGroupPermissions['wonderaction']['read'] = true;
$wgGroupPermissions['wonderaction']['edit'] = true;
$wgGroupPermissions['wonderaction']['createaccount'] = false;
```

## LocalSettings.php 셋팅 
* 외부 이미지 허용 : ```$wgAllowExternalImages = true;```
* 이미지 태그 허용 : ```$wgAllowImageTag = true;```

## 업로드 파일 확장자 추가등록 
* LocalSettings.php를 수정
  
```php
$wgFileExtensions[] = 'zip';
$wgFileExtensions[] = 'doc';
$wgFileExtensions[] = 'xls';
$wgFileExtensions[] = 'pdf';
$wgFileExtensions[] = 'mp3';
$wgFileExtensions[] = 'svg';
$wgFileExtensions[] = 'ino';
```
* images폴더의 권한은 읽기쓰기를 모드 해주어야 파일이 정상적으로 업로드 됩니다.

## 업로드 최대용량 변경 
* 먼저 서버쪽 셋팅을 변경해 주어야 한다. [[튜토리얼: 클라우드 서비스 이용하기]]참고
* 30M인 경우 30*1024*1024 = 31641870
* 20M인 경우 20*1024*1024 = 20971520

```php
$wgUploadSizeWarning = 20971520;
$wgMaxUploadSize = 20971520;
```

## 외부링크 새창으로 열기 
```php
$wgExternalLinkTarget = '_blank';
```

## 성능향상 
* LocalSettings.php에 추가
  
```php
 #USER CUSTOM ADDED - by GUNUG
 $wgMainCacheType = CACHE_ACCEL;
 $wgCacheDirectory = "$IP/cache";
 $wgFileCacheDirectory="$IP/cache";
 $wgEnableSidebarCache=true;
 $wgUseFileCache=true;
 $wgDisableCounters = true;
 $wgJobRunRate = 0.01;
```

* html페이지로 굽은 형태인데 CSS가 바로바로 적용이 안되여 일단 사용하지 않습니다.

---

## 기능 및 형태 변경 
### CSS 설정 
* [[미디어위키:Common.css]]
* 해당 페이지에서 내용을 변경한 후. 저장, 전체새로고침 Ctrl + Shift + R을 하면됨.
* class = mw-highlight에 border를 추가함

## 편집창 내용추가 
[https://ko.wikipedia.org/wiki/%EB%AF%B8%EB%94%94%EC%96%B4%EC%9C%84%ED%82%A4:Edittools 위키백과의 미디어위키:Edittools 내용]을 [[미디어위키:Edittools]]에 복붙
* CharInsert 확장기능을 설치 (구형 위키라 적용 안되어 되돌려 놓음)

## media query viewport
```html
<meta name="viewport" content="width=device-width, initial-scale=1">
```
* 확장기능 Extension 설치하기 
* 마크언어 클릭입력 Extension:CharInsert 
* [https://www.mediawiki.org/wiki/Extension:CharInsert Extension:CharInsert]
* 띄어쓰기는 syntaxhighlight lang="html" inline <nowiki> </nowiki> /syntaxhighlight 로 입력해 주어야함. 안그러면 끊김

## 소스코드하이라이터 SyntaxHighlight 
* [https://www.mediawiki.org/wiki/Extension:SyntaxHighlight Extension:SyntaxHighlight]
  
```php
require_once "$IP/extensions/SyntaxHighlight_GeSHi/SyntaxHighlight_GeSHi.php";
wfLoadExtension( 'SyntaxHighlight_GeSHi' );
```
* 2020-09-06. 에러를 일으켜서 일단 막아둠

## 에디터 확장 Extension:WikiEditor 
* [https://www.mediawiki.org/wiki/Extension:WikiEditor Extension:WikiEditor]
* 파일 내려받아 설치 후 다음을 입력
  
```php
wfLoadExtension( 'WikiEditor' );
# Enables use of WikiEditor by default but still allows users to disable it in preferences
$wgDefaultUserOptions['usebetatoolbar'] = 1;
# Enables link and table wizards by default but still allows users to disable them in preferences
$wgDefaultUserOptions['usebetatoolbar-cgd'] = 1;
# Displays the Preview and Changes tabs
$wgDefaultUserOptions['wikieditor-preview'] = 1;
# Displays the Publish and Cancel buttons on the top right side
$wgDefaultUserOptions['wikieditor-publish'] = 1;
```

## 모바일 지원하기 
```php
wfLoadExtension( 'MobileFrontend' );
$wgMFAutodetectMobileView = true;
$wgMFDefaultSkinClass = 'SkinGreyStuff'; // use Timeless skin
```
* 스킨에서 자동으로 지원하여 모바일 지원이 필요없게 됨 - 주석처리 되었습니다.

## PrivatePageProtection 
* 권한그룹 추가 
  
```php
$wgGroupPermissions['*']['createaccount'] = false;
$wgGroupPermissions['*']['edit'] = false;

$wgGroupPermissions['guest']['read'] = true;
$wgGroupPermissions['guest']['edit'] = false;
$wgGroupPermissions['guest']['createaccount'] = false;

$wgGroupPermissions['wonderaction']['read'] = true;
$wgGroupPermissions['wonderaction']['edit'] = true;
$wgGroupPermissions['wonderaction']['createaccount'] = false;
```
## extension 설치 
* [https://www.mediawiki.org/wiki/Extension:PrivatePageProtection Extension:PrivatePageProtection]
* 페이지내에서 다음을 변경하여 작성 {{#allow-groups:sysop}}
* 메뉴얼에는 두그룹 이상을 추가할 수 있다고 나와있지만 에러남, 한그룹만 추가하시길

---

## 사용자 등록하기 
* http://45.32.49.113/wiki/index.php/특수:계정만들기 특수:계정만들기
* wonderaction과 guest가 있음

## 권한변경하기 
* http://45.32.49.113/wiki/index.php?title=특수:권한조정 특수:권한조정
* tech그룹이 없어서 tech문서를 못보는 상황 발생하여 다음을 localsetting에 추가하고 특수권한 tech를 할당함
  
```php
$wgGroupPermissions['tech']['read'] = true;
$wgGroupPermissions['tech']['edit'] = false;
$wgGroupPermissions['tech']['createaccount'] = false;
```

---

## 유튜브 동영상 첨부 
* Extentions:youtube
  
```php
require_once "$IP/extensions/YouTube/YouTube.class.php";
wfLoadExtension( 'YouTube' );

<youtube>동영상구분번호</youtube>
```

---

## 지도 첨부 
* http://45.32.49.113/phpmyadmin/ 를 참고하여 제작됨
* cd extensions
* git clone https://gerrit.wikimedia.org/r/p/mediawiki/extensions/Kartographer
* cd Kartographer
* git submodule update --init
* LocalSettings.php에 다음을 추가 wfLoadExtension( 'Kartographer' );
* 지도 아이콘은 [https://www.mediawiki.org/wiki/Maps/Icons#/map/0 지도아이콘] 참고
* 구글맵에서 위도와 경도를 찾아서 표시 할 수 있음.
  * 구글맵에서 위치 검색후 마우스 오른쪽 클릭 '이 지역이 궁금한가요' 선택
  * 위도 경도가 표시되는데 이 두가지 값을 서로 바꿔서 넣어야 제대로 나옴
* 사용 예시는 [[리뷰: 도쿄]]를 활용
  
```html
<mapframe text="도쿄 도 東京都 Tokyo" width=100% height=350 zoom=13 longitude=139.695251 latitude=35.684174>
{
  "type": "Feature",
  "geometry": { "type": "Point", "coordinates": [139.695251,  35.684174] },
  "properties": {
    "title": "[[wikipedia:Tokyo|Tokyo]]",
    "description": "[[File:Giant_Mirror_at_the_Exploratorium.jpeg|200px]]",
    "marker-symbol": "city",
    "marker-size": "large",
    "marker-color": "0050d0"
  }
}
</mapframe>
```

## 스킨바꾸기 
* 링크주소 : https://www.mediawiki.org/wiki/Skin:GreyStuff
* LocalSetting.php 변경
```php
$wgDefaultSkin = "GreyStuff";

require_once "$IP/skins/GreyStuff/GreyStuff.php";
wfLoadSkin( 'GreyStuff' );
```

## 추가 확장기능 리뷰 사이트 
* http://blog.naver.com/PostView.nhn?blogId=alkydes&logNo=220907922093&categoryNo=82&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=postView

## 숨기기 펼치기 
* 출처:https://librewiki.net/wiki/%EB%8F%84%EC%9B%80%EB%A7%90:%EC%9C%84%ED%82%A4_%EB%AC%B8%EB%B2%95
<div class="mw-collapsible mw-collapsed">
스포일러 주의
<div class="mw-collapsible-content">
사실 그녀의 정체는 위키 페어리인 척하는 위키모이였다.
</div>
</div>
