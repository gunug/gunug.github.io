---
layout: post
title: z축 이송식 LED 전광판
category: review
tags: arduino
---

# z축 이송식 LED 전광판
<iframe width="560" height="315" src="https://www.youtube.com/embed/g4myrmBBYw4?si=7Ruuib_Do9wXXYev" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>


# 부품 
## 컨트롤러 보드 
* 아두이노 우노 호환보드 R3 6900원 : https://www.devicemart.co.kr/goods/view?no=1245596
* 아두이노 나노 호환보드 7200원 : https://www.devicemart.co.kr/goods/view?no=1265700
 아두이노 쉴드 
* 스크류 쉴드 8400원 : https://www.devicemart.co.kr/goods/view?no=1383272

## LCD 모듈 
* LCD 모듈 2600원 : https://www.devicemart.co.kr/goods/view?no=1327456

## IC 
* 75hc597 : https://www.devicemart.co.kr/goods/view?no=178
* 16핀 IC 소켓 : https://www.devicemart.co.kr/goods/view?no=2800

---

# 구동전압 계산 
* 아두이노 하나를 5v 100mA라고 보았을때. 0.5W * 1500 = 750W 최소 750W급 전원 공급장치를 써야함. (아두이노 보드 전용)
* 5V에서 750W급은 150A ㄷㄷㄷㄷ
* 500mA로 계산시 5배 되어 밑에 있는 SMPS가격이 5배로 상승함
* 인터넷 검색시 25만 ~ 40만 사이에 5V 150A (750W) SMPS를 구입할 수 있음. (https://www.jenomall.com/goods/goods_view.php?goodsNo=1000004190&inflow=naver&NaPm=ct%3Djqrprf3s%7Cci%3D2705cc3be4c215c90def5864c67b4b024249c732%7Ctr%3Dslsl%7Csn%3D235511%7Chk%3D1aaf62a059a91242dbfe9ba17652cb774a2cbe41)
* 10개씩 끊으면 5V 15A (75W) 4만~7만 : http://item.gmarket.co.kr/DetailView/Item.asp?goodscode=1324298840&GoodsSale=Y&jaehuid=200001169&NaPm=ct%3Djqrpvkso%7Cci%3D3601aff9e83933fdfbe20a7a955bea17efa0067f%7Ctr%3Dslsl%7Csn%3D24%7Chk%3Dd2872afe02004c016401d38160ec6b02936d14ff
* 1500개 시 15개(60만) 500개 시 5개 (20만) 예상
* 5V 500mA(0.5A) 2.5W 를 100개 단위로 묶으면 250W SMPS로 구동 가능함

# PCB 제작 
* 2층 160mm * 160mm 100판 = 35만
* 1500개 시 30 * 15 = 35만 * 15 = 525만
* 500개 시 30 * 5 = 35만 * 5 = 175만
* 2층 160mm * 160mm 4판 = 7만 (61500원)
* 2층 160mm * 160mm 10판 = 7만 (68090원)

# 케이블 제작 
* 2*10, 2*8, 2*7 > 20,16,14핀 제작가능
* 커넥터 선정 : https://www.devicemart.co.kr/goods/catalog?code=000900020001

---

# 스텝모터 
## 모터 스펙보기 
* http://hongik-mad.com/tboard/board/view.php?no_id=93&b_id=b8&keyword=&start=0&category
 드라이버 쉴드 
 쉴드형 
* 16000원 : http://vctec.co.kr/product/detail.html?product_no=5261&cate_no=204&display_group=1
* 같은거 2600원 : https://www.devicemart.co.kr/goods/view?no=1278922
* 사용법 : https://learn.adafruit.com/adafruit-motor-shield?view=all
* 사용법2 : http://playground.arduino.cc/Main/AdafruitMotorShield 
 연결형 
* 3000원 : https://www.devicemart.co.kr/goods/view?no=1327606
* https://www.geek-workshop.com/forum.php?mod=viewthread&tid=8746&highlight=EasyDriver

## 유니폴라 바이폴라 
* https://kocoafab.cc/tutorial/view/226
* 스텝모터는 구동 방식에 있어서,유니폴라(unipolar)방식과 바이폴라(bipolar)방식으로 분류되는데요,
* 유니폴라 방식은 모터의 권선(코일)에 흐르는 전류가 항상 한쪽 방향으로만 흐르는 구동 방식이고,
* 바이폴라 방식은 모터의 권선(코일)에 흐르는 전류의 방향이 바뀌는 구동 방식입니다.
 2상 스텝모터 
* 이때 고정자의 위치와 개수에 따라 상(Phase)가 정해지게 됩니다.
* 일반적인 2상 스텝의 경우에는 십자 모양으로 
* 4개가 하나의 상을 이루고 45도 회전하여
* 총 2가지의 상태를 지니게 됩니다.

## 스텝모터 스팩예시 
* https://kocoafab.cc/tutorial/view/226
* 정격전압- Rated Voltage : 12V
* 정격전류 -Rated Current : 0.33A
* 3.96W

---

# 여러대 아두이노 동시제어 
* https://kocoafab.cc/tutorial/view/452
* usb to uart : https://www.devicemart.co.kr/goods/view?no=29152

# ID 구별 
* 2^11 = 2048 로
* 점퍼스위치 11개로 2048가지 구별 가능
* 10스텝 로터리 스위치 4개로 구별 가능
* https://www.devicemart.co.kr/goods/view?no=12974
* 1개당 vcc1핀 4개 핀을 사용하니까. 4*4 = 16개 핀으로 10000가지 변수 구별 가능
[[파일:SDR10.jpg | 500px ]]
[[파일:2진화10진 2진화16진.jpg | 500px]]
* 16개 핀 쉬프트 레지스터 1개당 8핀. 16 / 8 = 2개의 쉬프트 레지스터
* array 저항 9pin 10KOhm : https://www.devicemart.co.kr/goods/view?no=1290
