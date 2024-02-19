---
layout: post
title: mysql query 질의문
category: web
tags: mysql
---

# mysql query 질의문

 테이블 생성하기 
```sql
CREATE TABLE `sample_data` (week varchar(15),line_number varchar(15),line_type varchar(15),station_name varchar(15),station_number varchar(15),time_5 varchar(15),time_6 varchar(15),time_7 varchar(15),time_8 varchar(15),time_9 varchar(15),time_10 varchar(15),time_11 varchar(15),time_12 varchar(15),time_13 varchar(15),time_14 varchar(15),time_15 varchar(15),time_16 varchar(15),time_17 varchar(15),time_18 varchar(15),time_19 varchar(15),time_20 varchar(15),time_21 varchar(15),time_22 varchar(15),time_23 varchar(15),time_0 varchar(15),null_1 varchar(15), null_2 varchar(15), null_3 varchar(15), null_4 varchar(15));
```

 실습용 데이터 
* 데이터 출처 - 공공데이터 : <www.data.go.kr>
* '지하철 혼잡도' 검색
* <a href="/file/csv/2015_metro_euc-kr.csv">2015_metro_euc-kr.csv</a>
* <a href="/file/csv/2015_metro_utf-8.csv">2015_metro_utf-8.csv</a>
* <a href="/file/sql/sample_data.sql">sample_data.sql</a>
```다운받은 데이터를 sql에 적용하는 부분이 누락되었습니다```

---

# 연습문제 

> 
* 역번 219번은 무슨 역일까요? 
```sql
SELECT station_name FROM `sample_data` WHERE station_number = 219;
```
```sql
+--------------+
| station_name |
+--------------+
| 삼성         |
| 삼성         |
| 삼성         |
| 삼성         |
| 삼성         |
| 삼성         |
+--------------+
```

>
* 오전 10시에 가장 혼잡한 역 이름과, 역번은 무엇일까요? 
```sql
SELECT station_name, station_number, time_10 FROM `sample_data` ORDER BY cast(time_10 as integer) DESC LIMIT 10;
```
```sql
+--------------+----------------+---------+
| station_name | station_number | time_10 |
+--------------+----------------+---------+
| 방배         | 225            | 94      |
| 사당(2)      | 226            | 94      |
| 서초         | 224            | 93      |
| 남태령       | 434            | 92      |
| 사당(4)      | 433            | 92      |
| 사당(2)      | 226            | 87      |
| 낙성대       | 227            | 87      |
| 남태령       | 434            | 87      |
| 교대(2)      | 223            | 86      |
| 방배         | 225            | 85      |
+--------------+----------------+---------+
```

>
* 하루종일 가장 혼잡한 역의 이름과 역번, 혼잡도를 표시 하세요
```sql
SELECT week 요일표시, line_type 회선, station_name 역명, station_number 역번, (time_5+ time_6+ time_7+ time_8+ time_9+ time_10+ time_11+ time_12+ time_13+ time_14+ time_15+ time_16+ time_17+ time_18+ time_19+ time_20+ time_21+ time_22+ time_23+ time_0) 전체혼잡도 FROM `sample_data` ORDER BY cast((time_5+ time_6+ time_7+ time_8+ time_9+ time_10+ time_11+ time_12+ time_13+ time_14+ time_15+ time_16+ time_17+ time_18+ time_19+ time_20+ time_21+ time_0) as integer) DESC LIMIT 10;
```
```sql
+----------+------+---------+------+------------+
| 요일표시 | 회선 | 역명    | 역번 | 전체혼잡도 |
+----------+------+---------+------+------------+
| 평일     | 외선 | 사당(2) | 226  |       1368 |
| 평일     | 외선 | 방배    | 225  |       1359 |
| 평일     | 외선 | 서초    | 224  |       1348 |
| 평일     | 외선 | 낙성대  | 227  |       1305 |
| 평일     | 내선 | 방배    | 225  |       1303 |
| 평일     | 내선 | 서초    | 224  |       1290 |
| 평일     | 내선 | 교대(2) | 223  |       1285 |
| 토요일   | 상선 | 남태령  | 434  |       1284 |
| 토요일   | 하선 | 혜화    | 420  |       1271 |
| 평일     | 외선 | 교대(2) | 223  |       1257 |
+----------+------+---------+------+------------+
```

>
* '평일' '상선' '사당(4)' '오전10'의 혼잡도는? 
```sql
SELECT time_10 FROM `sample_data` WHERE week='평일' AND line_type='상선' AND station_name = '사당(4)';
```
```sql
+---------+
| time_10 |
+---------+
| 42      |
+---------+
```

>
* '오후6'의 혼잡도가 50이상인 역은 몇개나 되나요? 
```sql
SELECT COUNT(*) FROM `sample_data` WHERE time_18>=50;
```
```sql
+----------+
| COUNT(*) |
+----------+
|      388 |
+----------+
```

>
* '평일' '오후6'에 가장 한산한 역 10곳은? 
```sql
SELECT station_name, time_18 FROM `sample_data` WHERE week='평일' ORDER BY cast(time_18 as integer) ASC LIMIT 10;
```
```sql
+--------------+---------+
| station_name | time_18 |
+--------------+---------+
| 신도림(지선) | 0       |
| 오금(3)      | 0       |
| 성수(지선)   | 0       |
| 신설동(지선) | 0       |
| 당고개       | 0       |
| 성수(2)      | 0       |
| 성수E        | 0       |
| 까치산(지선) | 0       |
| 당고개       | 3       |
| 상계         | 7       |
+--------------+---------+
```

>
* 오전 11시의 혼잡도는 평균 몇인가요? 
```sql
SELECT AVG(time_11) FROM `sample_data`;
```
```sql
+-------------------+
| AVG(time_11)      |
+-------------------+
| 37.61610738255033 |
+-------------------+
```
---

# 심화과정 
나의 데이터 기준으로 문제를 풀어봅시다
평균 ```AVG()```, 합산 ```SUM()```, 계수 ```COUNT()```

* 상품중 가장 비싼 10가지는?
* 상품의 가격을 모두 합치면 총액은?
* (category_1,code 0001)의 상품 수는?
* (category_1,code 0001)의 상품의 가격 총액은?
* (category_1)의 갯수는?