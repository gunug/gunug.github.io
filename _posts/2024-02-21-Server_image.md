---
layout: post
title: server image 이미지 서버 셋팅
category: etc
tags: 
---

# server image 이미지 서버 셋팅

```conf
<VirtualHost *:80>
    ServerName image.onethelab.com
    DocumentRoot /home/onethelab/public_html/image
    <Directory /home/onethelab/public_html/image>
        Require all granted
    </Directory>
</VirtualHost>
```

---

# 인증서 발급받아서 HTTPS 활성화 하기