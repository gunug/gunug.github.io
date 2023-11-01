---
layout: post
title: serial communication 시리얼 통신
category: etc
tags:
---

# serial communication 시리얼 통신
* RS232, RS485, RS422

## RS485
* 노이즈에 강함
* 멀티드랍
* RE485 포트가 있는 카드를 컴퓨터에 설치하거나 usd 젠더를 통하여 usb연결도 가능함
* 토큰링
* RS485 장비가 데이터를 릴레이 하는게 가능
* 트위스트 페어 (rx, tx를 교차) 하요 1km 떨어져도 통신가능

## acknowledge

* 통신 성공 인증 절차
* 수신한 측에서 수신완료 신호를 보냄으로서 통신을 완료

* 시리얼 데이터누락, 디바이스 다운에 대한 대쳐가 가능해짐