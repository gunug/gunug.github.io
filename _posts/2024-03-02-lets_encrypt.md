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
### SSL 설정 활성화
* ```$ sudo a2ensite default-ssl.conf```
* ```$ sudo service apache2 reload```

### 리로드 실패
* logs 폴더가 기본폴더가 아님, 생성해야함
* ```$ sudo mkdir /etc/apache2/logs```
* ```$ sudo apache2ctl congigtest``` 컨피그 파일에 오류가있는지 테스트해서 알려줌, 내 경우는 오타 때문
* SSLCertificateFile, SSLCertificateKeyFile 경로에 파일이 존재하지 않는다고 나옴 (아마도 예제대로 입력한 문제)
  
## Certbot 설치 및 인증서 생성
### yum 설치가 처음일때
* yum이 설치되어 있지 않을 경우 선행
* [참고사이트](https://lieadaon.tistory.com/entry/Linux-yum-%EB%AA%85%EB%A0%B9%EC%96%B4-%EC%82%AC%EC%9A%A9-%EC%8B%9C-%EB%9C%A8%EB%8A%94-repolist-all-repolist-0-there-are-no-enabled-repos-%EC%97%90%EB%9F%AC-%ED%95%B4%EA%B2%B0)
* ```apt install yum``` yum 설치
* ```yum repolist all``` yum 저장소 목록 표시 : 여기서 0이라면 다음을 수행
* ```apt install yum-utils```
* ```yum-config-manager --enable epel-release```
* ```sudo yum inatall epel-release```

### let's encrypt 설치
* ```yum install letencrypt -y```
## HTTPS 443 port 방화벽 해제
## 인증서 자동갱신 설정

---

## 인증서 자동갱신
* 참고링크 : https://softone.tistory.com/65