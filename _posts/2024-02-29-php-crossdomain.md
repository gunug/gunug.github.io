---
layout: post
title: php crossdomain 크로스 도메인 문제
category: web
tags: php
---

# php crossdomain 크로스 도메인 문제
* 크로스 도메인 보안때문에 데이터가 읽어지지 않는 사례 발생시
* PHP를 통하여 특정 사이트의 내용을 그대로 내 도메인에서 출력하여 이용
  
```php
<?php

$url = 'http://wizard2.sbs.co.kr/w3/podcast/V0000328482.xml';
$URL_parsed = parse_url($url);
$host = $URL_parsed["host"]; 
$port = $URL_parsed["port"]; 
if ($port==0) $port = 80; 
$path = $URL_parsed["path"]; 
if ($URL_parsed["query"] != "") $path .= "?".$URL_parsed["query"]; 

$fp = fsockopen($host, $port, $errno, $errstr, 30);
$out = "GET $path HTTP/1.0\r\nHost: $host\r\n\r\n"; 

if (!$fp) {
    echo "$errstr ($errno)<br />\n";
} else {
    fputs($fp, $out); 
    $body = false; 
        while (!feof($fp)) { 
                $s = fgets($fp, 128); 
                if ( $body ) $in .= $s; 
                if ( $s == "\r\n" ) $body = true; 
        }
        fclose($fp); 
        echo $in; 
}
?>
```
