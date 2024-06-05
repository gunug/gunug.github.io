---
layout: post
title: Let's Encrypt HTTPS를 위한 인증서 발급, 갱신
category: web
tags: encrypt
---

# Let's Encrypt HTTPS를 위한 인증서 발급, 갱신
## 인증서 발급
* 참고링크 : https://softone.tistory.com/64
* 무료이나 유료인증서와 다르게 3개월 단위로 갱신하여야 함
* 도메인이 mail.korea.co.kr로 가정하고 제공된 내용

## Apache Conf 설정
* httpd.conf에 ServarAdmin, ServerName, DocumentRoot 확인 및 설정
* 가상호스트 설정

### SSL 접속 도메인 설정 
* /etc/apache2/sites-available/default-ssl.confoneth
* <https://gist.github.com/devlim/5b7e09ba17f2ee2abcfcd80d69cb19eb>
  
```xml
<IfModule mod_ssl.c>
	<VirtualHost _default_:443>
		ServerAdmin webmaster@localhost
		DocumentRoot /var/www/html
		ErrorLog ${APACHE_LOG_DIR}/error.log
		CustomLog ${APACHE_LOG_DIR}/access.log combined
		SSLEngine on
		SSLCertificateFile	/etc/ssl/certs/ssl-cert-snakeoil.pem
		SSLCertificateKeyFile /etc/ssl/private/ssl-cert-snakeoil.key

		<FilesMatch "\.(cgi|shtml|phtml|php)$">
				SSLOptions +StdEnvVars
		</FilesMatch>
		<Directory /usr/lib/cgi-bin>
				SSLOptions +StdEnvVars
		</Directory>
	</VirtualHost>
</IfModule>
```

---

### SSL 설정 활성화
* ```$ sudo a2ensite default-ssl.conf```
* ```$ sudo service apache2 reload```

```Invalid command 'SSLEngine', perhaps misspelled or defined by a module not included in the server configuration```
* SSLEngine이 설치되어 있지 않음
* 참고링크 : https://zetawiki.com/wiki/%EC%9A%B0%EB%B6%84%ED%88%AC_%EC%95%84%ED%8C%8C%EC%B9%98_SSLEngine_%EB%AA%A8%EB%93%88_%ED%99%9C%EC%84%B1%ED%99%94
* a2query -m ssl 모듈확인
* a2enmod ssl 모듈활성화
---

### 리로드 실패
* logs 폴더가 기본폴더가 아님, 생성해야함
* ```$ sudo mkdir /etc/apache2/logs```
* ```$ sudo apache2ctl configtest``` 컨피그 파일에 오류가있는지 테스트해서 알려줌, 내 경우는 오타 때문
* SSLCertificateFile, SSLCertificateKeyFile 경로에 파일이 존재하지 않는다고 나옴 (아마도 예제대로 입력한 문제)
  
## Certbot 설치 및 인증서 생성
### yum 설치가 처음일때
* yum이 설치되어 있지 않을 경우 선행
* [참고사이트](https://m.blog.naver.com/keepbang/221771186484)
* ```apt install yum``` yum 설치
* ```yum repolist all``` yum 저장소 목록 표시 : 여기서 0이라면 다음을 수행

```c++
[base]
name=CentOS-$releasever - Base
baseurl=http://ftp.daum.net/centos/7/os/$basearch/
gpgcheck=1
gpgkey=http://ftp.daum.net/centos/RPM-GPG-KEY-CentOS-7

[updates]
name=CentOS-$releasever - Updates
baseurl=http://ftp.daum.net/centos/7/updates/$basearch/
gpgcheck=1
gpgkey=http://ftp.daum.net/centos/RPM-GPG-KEY-CentOS-7

[extras]
name=CentOS-$releasever - Extras
baseurl=http://ftp.daum.net/centos/7/extras/$basearch/
gpgcheck=1
gpgkey=http://ftp.daum.net/centos/RPM-GPG-KEY-CentOS-7

[centosplus]
name=CentOS-$releasever - Plus
baseurl=http://ftp.daum.net/centos/7/centosplus/$basearch/
gpgcheck=1
gpgkey=http://ftp.daum.net/centos/RPM-GPG-KEY-CentOS-7
```
* 위 내용을 https://onethelab.com/file/repo/daum.repo에 업로드 하였음
* ```wget "https://onethelab.com/file/repo/daum.repo"```로 다운받기 (위치는 etc/yum/repo.d/)
* ```yum upgrade```

### 효과가 있는지 모르지만 시도했던 것들
* ```apt install yum-utils```
* ```yum-config-manager --enable epel-release```


### let's encrypt 설치
* 참고링크 : <https://blog.jiniworld.me/137>
#### epel-release 설치
* ```yum inatall epel-release```
* ```yum repolist```
#### certbot 설치
* ```yum install certbot python2-certbot-apache```
* ```certbot --apache -d 도메인이름```
## HTTPS 443 port 방화벽 해제
## 인증서 자동갱신 설정

---

## 인증서 자동갱신
* 참고링크 : https://softone.tistory.com/65

---

# apt로 인증서 발급받기
* 위의 yum 방식으로 하다가 kernel panic 되어서 yum대신 apt로
* 참고링크 : https://serverspace.io/support/help/how-to-get-lets-encrypt-ssl-on-ubuntu/

* ufw allow 80
* ufw allow 443

* apt install letsencrypt
* systemctl status certbot.timer 봇이 동작하고 있는지 확인

* 다음 명령어의 'domain-name.com'는 당신의 도메인명입니다.
* ```sudo certbot certonly --standalone --agree-tos --preferred-challenges http -d domain-name.com```
* 80 포트를 이용중이라 진행할수 없다고 하여 service apache2 stop 아파치 서버 스탑

* apt install python3-certbot-apache
* sudo certbot --apache --agree-tos --preferred-challenges http -d domain-name.com
* Certbot이 SSL 인증서를 설치함

---

## 와일드카드 SSL 인증서 암호화
* sudo certbot certonly --manual --agree-tos --preferred-challenges dns -d domain-name.com -d *.domain-name.com

---


<img src="https://image.onethelab.com/resized/1709615455.jpg" />

---

# 인증서 갱신
* 참고링크 : <https://softone.tistory.com/65>
* ```certbot renew --dry-run``` 인증서 활성화 여부 확인
* ```certbot renew``` 인증서 갱신하기
* ```certbot certificates``` 만료일 확인하기

* ```crontab -l``` 현재 설정된 crontab 내용출력
* ```crontab -e``` 내용입력, 저장방법은 vi와 동일 콜론(:)입력후 wq 입력

* ```0 3 * * * /usr/bin/certbot renew --renew-hook="systemctl restart httpd"``` 새벽 3시에 갱신하고 아파치 서버 재시작

# 인증서 갱신 간단한 절차
* ```service apache2 stop``` 아파치 서버 종료
* ```certbot renew``` 인증서 갱신
* ```service apache2 start``` 아파치 서버 시작