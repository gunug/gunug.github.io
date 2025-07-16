---
layout: post
title: google login 구글 로그인
category: web
tags: 
---

# Google Login
## 참고자료 
* <https://notspoon.tistory.com/45>
* <https://notspoon.tistory.com/46>
* <https://notspoon.tistory.com/47>

---

# Google Developer 설정
* <https://console.cloud.google.com/>

## 프로젝트 생성
* 좌측 상단에 프로젝트 명이 적혀있는 콤보박스 클릭
* 새 프로젝트, 이름 입력후 확인하여 새 프로젝트 생성

## OAuth 동의
### OAuth 동의 화면
* 검색창에 ```oauth``` 입력 'OAuth 동의화면' 선택
* User Type 외부 선택 후 만들기 클릭
* 필수정보 입력

### 범위
* '범위 추가 또는 삭제' 버튼 클릭
* 최상단 3개 항복 선택 후 업데이트 클릭
* 저장 후 계속 클릭

### 테스트 사용자
* google 로그인 테스트를 위한 계정 추가 (누구나 사용하기 위해선 별도 애플리케이션 심사 필요)

## 사용자 인증 정보
* '사용자 인증정보 만들기' 선택
* OAuth 클라이언트 ID 만들기
* 애플리케이션 유형 > 웹 애플리케이션
* 승인된 Javascript 원본 : 구글 로그인을 사용할 홈페이지 주소 입력
* 승인된 리디렉션 URI 항목에 구글 로그인 후 Redirect할 주소 입력
* 클라이언트 ID와 보안 비밀번호가 표시됨

# 개발 환경 설정
# 초기화 및 로그인 구현하기

---

# 구글 로그인
1. 구글 Cloud Console 접속
    * 사이트 접속: Google Cloud Console<https://console.cloud.google.com/>
    * 구글 계정으로 로그인
2. 새 프로젝트 생성
    * 상단의 '프로젝트 선택' 또는 펼침(▼)을 클릭
    * '새 프로젝트' 클릭
    * 프로젝트 이름 입력
    * 필요하면 조직/위치 설정
    * '만들기' 클릭 (잠시 기다리면 우측 상단에 알림에 '프로젝트가 생성되었습니다' 표시됨)
3. OAuth 동의 화면 설정
    * 좌측 메뉴에서 “API 및 서비스” > “OAuth 동의 화면” 클릭
    * “외부(External)” 또는 “내부(Internal)” 중 선택
    * 대부분 웹 서비스는 “외부” 선택
    * 앱 정보 작성 (앱 이름, 사용자 이메일, 개발자 이메일 등)
    * “저장 후 계속” 진행
    * (필수) 범위(Scope)는 기본 이메일 등만 제공 시 추가로 건드릴 필요 없음 (“저장 후 계속”)
    * 테스트 사용자 이메일(테스트 단계에서는 본인 및 테스트할 구글 계정 추가)
    * “저장 후 계속” 또는 “완료”
4. 사용자 인증 정보(클라이언트 ID 및 시크릿) 발급
    * 좌측 메뉴에서 “API 및 서비스” > “사용자 인증 정보” 클릭 
    * 상단 “사용자 인증 정보 만들기” 클릭 > “OAuth 클라이언트 ID”선택
    * “애플리케이션 유형” 선택(대부분 “웹 애플리케이션”)
    * 이름 입력(예: My Web App)
    * 승인된 리디렉션 URI 추가
    * 예: https://yourdomain.com/oauth2callback (로컬 개발 시 http://localhost:3000/auth/google/callback 등)
    * “만들기” 클릭
    * 팝업 창에 클라이언트 ID/클라이언트 시크릿이 표시됨.
    * 이 정보는 복사해서 저장해두세요!
    * 필요하면 “JSON 다운로드”버튼으로 파일로 저장 가능

1. (필요시) 추가 API 활성화
    * 만약 Google Drive 등 특정 API를 쓰려면
    * 좌측 “API 라이브러리”에서 원하는 Google API를 선택하고
    * “사용” 버튼을 눌러 활성화

## 정리
* 프로젝트 생성 → OAuth 동의화면 설정 → 사용자 인증 정보(OAuth 클라이언트 ID/시크릿) 발급의 절차를 따릅니다.
* 발급된 클라이언트 ID와 시크릿을 예시처럼 로그인 구현 코드에 사용합니다.
* 테스트 사용자 등록을 안 하면 실제 로그인 인증 동작 시 오류가 나니 본인/테스트 계정 등록 필수입니다(배포 후 검증이 끝난 뒤엔 인증 앱 게시를 요청하세요).

---

# composer 설치
```
apt install composer
composer require google/apiclient
```

## index.php
```php
<?php
require_once __DIR__.'/vendor/autoload.php';

session_start();

$client = new Google_Client();
$client->setClientId('YOUR_CLIENT_ID');        // 발급받은 값
$client->setClientSecret('YOUR_CLIENT_SECRET');// 발급받은 값
$client->setRedirectUri('http://localhost/callback.php');  // 리디렉트 URI
$client->addScope('email');
$client->addScope('profile');

// 로그인 URL 생성
$loginUrl = $client->createAuthUrl();
?>

<a href="<?= htmlspecialchars($loginUrl) ?>">구글로 로그인하기</a>
```

## callback.php
```php
<?php
require_once __DIR__.'/vendor/autoload.php';

session_start();

$client = new Google_Client();
$client->setClientId('YOUR_CLIENT_ID');         // 동일하게
$client->setClientSecret('YOUR_CLIENT_SECRET'); // 동일하게
$client->setRedirectUri('http://localhost/callback.php');

if (isset($_GET['code'])) {
    $token = $client->fetchAccessTokenWithAuthCode($_GET['code']);
    $client->setAccessToken($token);

    // 사용자 정보 가져오기
    $oauth2 = new Google_Service_Oauth2($client);
    $userInfo = $oauth2->userinfo->get();

    $google_sub = $userInfo->id;       // Google unique id (sub)
    $google_email = $userInfo->email;  // Email
    $name = $userInfo->name;           // User name
    $picture = $userInfo->picture;     // Profile picture url

    // DB 연결 예시 (mysqli 사용)
    $mysqli = new mysqli('localhost', 'dbuser', 'dbpass', 'dbname');
    if ($mysqli->connect_error) die('DB 접속 실패: ' . $mysqli->connect_error);

    // 이미 가입된 사용자 확인
    $stmt = $mysqli->prepare('SELECT id FROM google_users WHERE google_sub = ?');
    $stmt->bind_param('s', $google_sub);
    $stmt->execute();
    $stmt->store_result();

    if ($stmt->num_rows == 0) {
        // 신규 회원가입
        $insert = $mysqli->prepare('
            INSERT INTO google_users (google_sub, email, name, picture, created_at, last_login_at)
            VALUES (?, ?, ?, ?, NOW(), NOW())
        ');
        $insert->bind_param('ssss', $google_sub, $google_email, $name, $picture);
        $insert->execute();
        $user_id = $insert->insert_id;
    } else {
        // 이미 가입, 정보/최종로그인 업데이트
        $update = $mysqli->prepare('
            UPDATE google_users SET email=?, name=?, picture=?, last_login_at=NOW()
            WHERE google_sub=?
        ');
        $update->bind_param('ssss', $google_email, $name, $picture, $google_sub);
        $update->execute();
        $stmt->bind_result($user_id);
        $stmt->fetch();
    }
    $stmt->close();

    // 세션 로그인 처리
    $_SESSION['user_id'] = $user_id;
    $_SESSION['google_sub'] = $google_sub;
    $_SESSION['email'] = $google_email;

    echo "로그인 성공! <br><a href='main.php'>메인으로</a>";
} else {
    echo "유효하지 않은 접근입니다.";
}
```

## 아이디, 시크릿
* YOUR_CLIENT_ID, YOUR_CLIENT_SECRET
* API 및 서비스 > 사용자 인증 정보

```php
<?php
define('CLIENT_ID', '여기에 본인 클라이언트ID');
define('CLIENT_SECRET', '여기에 본인 시크릿');
?>
```

```php
<?php
require '경로/config.php'; // 비밀번호 설정 파일을 포함합니다.
$YOUR_CLIENT_ID = CLIENT_ID;        // 발급받은 값
$YOUR_CLIENT_SECRET = CLIENT_SECRET; // 발급받은 값
?>
```
외부에 define 되어잇는 정보를 가져옴


## 에러 디버깅
```php
<?php
ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);
?>
```

---

# 각종에러

## 퍼미션에러
```
chmod -R 755 vendor 또는 chown -R www-data:www-data vendor
```

```
Fatal error: Uncaught Error: Class "mysqli" not found in /home/onethelab/test/callback.php:39 Stack trace: #0 {main} thrown in /home/onethelab/test/callback.php on line 39
```

```
sudo apt-get update
sudo apt-get install php-mysqli
```

```
sudo systemctl restart apache2
또는 sudo service apache2 restart
```

---

```
Fatal error: Uncaught mysqli_sql_exception: Access denied for user 'root'@'localhost' in /home/onethelab/test/callback.php:39 Stack trace: #0 /home/onethelab/test/callback.php(39): mysqli->__construct() #1 {main} thrown in /home/onethelab/test/callback.php on line 39
```

* root 접근이 안되거나 패스워드 틀림. 신규 사용자 생성이 권장

```
CREATE USER 'myuser'@'localhost' IDENTIFIED BY 'my_pw_1234';
GRANT ALL PRIVILEGES ON login_tutorial.* TO 'myuser'@'localhost';
FLUSH PRIVILEGES;
```
* 위 예시를 그대로 사용하지 말것. myuser와 my_pw_1234변경요망

* 사용자 삭제

```
DROP USER 'myuser'@'localhost', 'myuser'@'%';
FLUSH PRIVILEGES;
```

---

```
DESCRIBE google_users;
```
* 테이블 구조 확인

---

```
SELECT * FROM google_users;
SELECT * FROM google_users LIMIT 10;
SELECT id, google_sub, email FROM google_users;
SELECT * FROM google_users ORDER BY id DESC LIMIT 5;
```
* 테이블 내용확인

---

# 구글 로그인 디자인 가이드라인
* <https://developers.google.com/identity/branding-guidelines>

```
<a href="google_login.php" style="text-decoration:none;">
  <div style="display:inline-flex;align-items:center;
              border:1px solid #d9d9d9;border-radius:4px;
              background:#fff;color:#444;padding:8px 16px;
              font-weight:500;box-shadow:1px 2px 3px #eee;transition:box-shadow .2s;">
    <img src="https://developers.google.com/identity/images/g-logo.png"
         alt="Google Logo" style="width:20px;height:20px;margin-right:8px;">
    <span>구글 계정으로 로그인</span>
  </div>
</a>
```