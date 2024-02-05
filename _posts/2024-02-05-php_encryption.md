---
layout: post
title: php encryption 암호화
category: web
tags: php
---

# php encryption 암호화

## 암호(password) 
* 단순 텍스트(plain text)
* 단방향 해시 함수(one-way hash function)의 다이제스트(digest)
 단방향 해시 함수(one-way hash function)의 다이제스트(digest) 
* 다이제스트(digest) : 소화 시키다 소화 되다
* 단방향 해시 함수는 수학적인 연산을 통해 원본 메시지를 변환하여 암호화된 메시지인 다이제스트를 생성한다.
* 단방향성 : 원본을 알면 암호화된 다이제스트를 구하기 쉽지만, 다이제스트로는 원본 메시지를 추론할 수 없어야 한다.
* 쇄도 avalanche 효과 : 평문 또는 키값을 조금만 변경시켜도 암호문에는 매우 큰 변화가 생기는 것, 패스워드 원본을 추론하기 어렵게 만드는 중요한 요소.

![image](https://github.com/gunug/gunug.github.io/assets/52345276/76c01ace-b519-43ee-9bbb-204691cb26a6)


---


* 단방향 해시함수의 예 : MD5 http://md5encryption.org/index.html

## 단방향 해시 함수의 단점 
## 인식 가능성(recognizability) 
* 동일한 원본 패스워드가 동일한 다이제스트를 갖는다면, 공격자가 전처리(pre-computing)된 다이제스트를 가능한 많이 확보한 다음 이를 탈취한 다이제스트와 비교해 원본 패스워드를 찾아낼 수 있다. 이와같은 다이제스트 목록을 레인보우 테이블 (rainbow table)이라 하고, 이와같은 공격방식을 레인보우 공격(rainbow attack)이라고 한다. 또한 다른 사용자라도 패스워드가 같으면 다이제스트가 같으므로 한꺼번에 정보가 탈취될 수 있다.
## 속도(speed) 
* 해시 함수는 암호학에서 사용되지만 원래 패스워드를 저장하기 위해 설계된 것이 아닌 짧은 시간에 데이터를 검색하기 위해 설계된 것이다. 해시 함수의 빠른 처리속도로 인하여. 공격자는 매우 빠른 속도로 임의의 문자열의 다이제스트와 해킹할 대상의 다이제스트를 비교할 수 있다.(MD5를 사용한 경우 일반적인 장비를 이용하여 1초당 56억 개의 다이제스트를 대입할 수 있다) 이런 방식으로 패스워드를 추측하면 패스워드가 충분히 길거나 복잡하지 않은 경우에는 그리 긴 시간이 걸리지 않는다. 그리고 대부분 사용자의 패스워드는 길거나 복잡하지 않다.

## 단방향 해시 함수 보완하기 
## 솔팅(salting) 
* 솔트(salt)는 단방향 해시 함수에서 다이제스트를 생성할 때 추가되는 바이트 단위의 임의의 문자열이다. 
* 원본 메시지에 문자열(솔트, salt)을 추가하여 다이제스트를 생성하는 것을 솔팅(salting)이라 한다.
## 키 스트레칭(key stretching) 
* 원본 패스워드의 다이제스트를 생성 후, 이를 이용하여 다시 다이제스트를 생성한다. 
* 이렇게 생성된 다이제스트는 동일 횟수만큼 시도해야 일치여부를 판단할 수 있다. 이를 키 스트레칭 이라 한다.
## 암호용도로 사용하면 안되는 알고리즘 
* MySQL의 password() 함수, crypt(), md5(), sha1(), MD5, SHA-1, SHA-256, SHA-512 등의 해시 함수
* 이는 메세지의 인증과 무결성 체크를 하기위한 알고리즘으로 암호화를 하기위해 사용하면 안된다.

---

## 암호용으로 사용할 수 있는 알고리즘 
### PBKDF2 
* 가장 많이 사용되는 key derivation function은 PBKDF2(Password-Based Key Derivation Function)이다.
* 해시 함수의 컨테이너인 PBKDF2는 솔트를 적용한 후 해시 함수의 반복 횟수(키스트래칭)를 임의로 선택할 수 있다. 
* PBKDF2는 아주 가볍고 구현하기 쉬우며, SHA와 같이 검증된 해시 함수만을 사용한다. 
* PBKDF2의 기본 파라미터는 다음과 같은 5개 파라미터다.
  
```php
    DIGEST = PBKDF2(PRF, Password, Salt, c, DLen)
```
* PRF: 난수(예: HMAC)
* Password: 패스워드
* Salt: 암호학 솔트
* c: 원하는 iteration 반복 수
* DLen: 원하는 다이제스트 길이

### scrypt 
* scrypt는 PBKDF2와 유사한 adaptive key derivation function이며 Colin Percival이 2012년 9월 17일 설계했다.
* scrypt는 다이제스트를 생성할 때 메모리 오버헤드를 갖도록 설계되어, 억지 기법 공격(brute-force attack)을 시도할 때 병렬화 처리가 매우 어렵다.
* 따라서 PBKDF2보다 안전하다고 평가되며 미래에 bcrypt에 비해 더 경쟁력이 있다고 여겨진다. 
* scrypt는 보안에 아주 민감한 사용자들을 위한 백업 솔루션을 제공하는 Tarsnap에서도 사용하고 있다. 
* scrypt는 여러 프로그래밍 언어의 라이브러리로 제공받을 수 있다. 
* scrypt의 파라미터는 다음과 같은 6개 파라미터다.
  
```php
    DIGEST = scrypt(Password, Salt, N, r, p, DLen)
```
* Password: 패스워드
* Salt: 암호학 솔트
* N: CPU 비용
* r: 메모리 비용
* p: 병렬화(parallelization)
* DLen: 원하는 다이제스트 길이


## bcrypt 
* bcrypt는 애초부터 패스워드 저장을 목적으로 설계되었다. 
* Niels Provos와 David Mazières가 1999년 발표했고 현재까지 사용되는 가장 강력한 해시 메커니즘 중 하나이다. 
* bcrypt는 보안에 집착하기로 유명한 OpenBSD에서 기본 암호 인증 메커니즘으로 사용되고 있고 미래에 PBKDF2보다 더 경쟁력이 있다고 여겨진다. 
* bcrypt에서 "work factor" 인자는 하나의 해시 다이제스트를 생성하는 데 얼마만큼의 처리 과정을 수행할지 결정한다. 
* "work factor"를 조정하는 것만으로 간단하게 시스템의 보안성을 높일 수 있다. 
* 다만 PBKDF2나 scrypt와는 달리 bcrypt는 입력 값으로 72 bytes character를 사용해야 하는 제약이 있다.

---

# PHP에 bcrypt 사용
* 원본출처 : http://dolgo.net/PHP/lecture/18
* PHP 버전 5.3 이상부터는 bcrypt 해시 기술이 기본적으로 내장되어 있다.

## bcrypt 사용가능여부 확인
```php
<?php
if (defined("CRYPT_BLOWFISH") && CRYPT_BLOWFISH)
    echo "CRYPT_BLOWFISH is enabled!";
else
    echo "CRYPT_BLOWFISH is not available";
?>
```

## bcrypt 사용 
```php
<?php
$salt = '$2a$07$R.gJb2U2N.FmZ4hPp1y2CN$';
$passwd = crypt("password", $salt);
?>
```

## 암호화 방법, 확인 방법
```php
<?php
$hash = password_hash($password, PASSWORD_DEFAULT);	//여기서 반환되는 $hash 값을 DB에 저장해 두었다가 아래에서 확인하는 데 씁니다.

if (password_verify($password, $hash)) { // 비밀번호가 맞음 } else { // 비밀번호가 틀림 }
?>
```

---

# bcrypt 연습 
* password_test.php
  
```php
<?php
	if (!defined('PASSWORD_BCRYPT')) {
	    define('PASSWORD_BCRYPT', 1);
	    define('PASSWORD_DEFAULT', PASSWORD_BCRYPT);
	}

	$password = "my_password";
	$hash = password_hash($password, PASSWORD_DEFAULT); 
	//여기서 반환하는 $hash 값을 DB에 저장해 두었다가 아래에서 확인하는 데 씁니다.

	echo "패스워드 해시:";
	var_dump(PASSWORD_DEFAULT);
	echo "<br/>";
	echo "패스워드:".$password."<br/>";
	echo "<br/>";
	echo "다이제스트:".$hash."<br/>";
	if (password_verify($password, $hash)) { 
		// 비밀번호가 맞음
		echo "비밀번호가 일치합니다. <br/>";
	} else { 
		// 비밀번호가 틀림 
		echo "비밀번호가 일치하지 않습니다. <br/>";
	} //다이제스트 결과는 매번 다른 결과가 나옵니다. 나중에 다이제스트와 원본 패스워드를 판별 해주는 함수를 통하여 판별 결과를 받습니다.
	echo "<br/>";
	echo "서버에 저장될 다이제스트:"."\$2y\$10\$LZsyxoKndzYUWlf7e0QmFOwMcXmLyb7H9sUM/97bFa2y0TsW4mcK6"."<br/>";
	if (password_verify($password, "\$2y\$10\$LZsyxoKndzYUWlf7e0QmFOwMcXmLyb7H9sUM/97bFa2y0TsW4mcK6")) { 
		// 비밀번호가 맞음
		echo "작성한 비밀번호가 일치합니다. <br/>";
	} else { 
		// 비밀번호가 틀림 
		echo "작성한 비밀번호가 일치하지 않습니다. <br/>";
	}
?>
```
