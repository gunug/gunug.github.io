---
layout: post
title: php file access 파일접근
category: web
tags: 
---

# php file access 파일접근
1. "PHP exclusive file access"
2. "Restrict file access to PHP"
3. "Secure PHP file access"
4. "PHP file access control"
5. "Deny direct file access in PHP"

---

* .htaccess 등으로 파일접근을 막고 PHP에서 부름

---

# php 접근제한
1. **파일 권한 설정**: 운영체제의 파일 시스템 권한이 PHP 프로세스 사용자에게 읽기/쓰기 권한을 주지 않는 경우입니다. Unix 기반 시스템에서는 `chmod`, `chown` 명령어로 파일 권한을 설정할 수 있습니다.
2. **PHP 설정 제한**: PHP 설정에서 `open_basedir` 기능을 사용하여 PHP 스크립트가 접근할 수 있는 디렉토리를 제한할 수 있습니다. 이 경우 명시된 디렉토리 밖의 파일에 PHP가 접근할 수 없습니다.
3. **SELinux나 AppArmor 정책**: Linux 시스템에서 SELinux나 AppArmor를 사용하는 경우, 이러한 보안 모듈에 설정된 정책에 의해 PHP의 파일 접근이 제한될 수 있습니다.