---
layout: post
title: php import 데이터 들여오기
category: web
tags: php
---

 xml 
* xml_import.php
  
```php
<?php
$curl = curl_init();
$timeout = 5;
$url = 'http://localhost/test_page/xml_php.php';
//localhost로부터 시작하는 full url을 입력하지 않으면 에러나더라
//$url = 'api.saramin.co.kr/job-search';
//http://api.saramin.co.kr/job-search
echo $url;

curl_setopt($curl, CURLOPT_URL, $url);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
//CURLOPT_RETURNTRANSFER가 ture(1)일 경우 curl_exec로 바로 입력할수 있는 string형태로 반환합니다.
curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, $timeout);

$xml = curl_exec($curl);
//원래는 성공, 실패를 알리는 true, false를 반환하는 함수이나 CURLOPT_RETURNTRANSFER 옵션에 의해 값을 반환 합니다.
curl_close($curl);
$xml_object = simplexml_load_string($xml,'SimpleXMLElement', LIBXML_NOCDATA);
var_dump($xml_object);

$XML_DATA = array();
$XML_DATA = json_decode(json_encode($xml_object), true);
/*잘못된 Array 전환방식 (엘리먼트가 하나일 경우 뎁스가 하나 줄어든다)*/
foreach($xml_object as $value)
{
	$idx			= $value->idx;
	$price			= $value->price;
	$category1		= $value->category1;
	$category2		= $value->category2;
	$image1			= $value->image1;
	$image2			= $value->image2;

	echo "<table>";
	echo "<tr><th>게시물번호</th><td>".$idx."</td></tr>";
	echo "<tr><th>가격</th><td>".$price."</td></tr>";
	echo "<tr><th>분류1</th><td>".$category1."</td></tr>";
	echo "<tr><th>분류2</th><td>".$category2."</td></tr>";
	echo "<tr><th>원본이미지</th><td><img src='".$image1."'/></td></tr>";
	echo "<tr><th>썸네일이미지</th><td><img src='".$image2."'/></td></tr>";
	echo "</table>";
}
?>
<style type="text/css">
	table{
		border: solid 1px #000;
		width: 100%;
	}
	th{
		width: 20%;
	}
	img{
		width: 30%;
	}
</style>
```

# json 
* json_import.php
  
```php
<?php
$curl = curl_init();
$timeout = 5;
$url = 'http://localhost/test_page/json_php.php';
//localhost로부터 시작하는 full url을 입력하지 않으면 에러나더라
//$url = 'api.saramin.co.kr/job-search';
//http://api.saramin.co.kr/job-search
echo $url;

curl_setopt($curl, CURLOPT_URL, $url);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
//CURLOPT_RETURNTRANSFER가 ture(1)일 경우 curl_exec로 바로 입력할수 있는 string형태로 반환합니다.
curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, $timeout);

$json = curl_exec($curl);
echo($json);
//원래는 성공, 실패를 알리는 true, false를 반환하는 함수이나 CURLOPT_RETURNTRANSFER 옵션에 의해 값을 반환 합니다.

$JSON_DATA = array();
$JSON_DATA = json_decode($json, true);
//print_r($JSON_DATA);
//var_dump(sizeof($JSON_DATA));
foreach($JSON_DATA as $value)
{
	$idx			= $value["idx"];
	$price			= $value["price"];
	$category1		= $value["category1"];
	$category2		= $value["category2"];
	$image1			= urldecode($value["image1"]);
	$image2			= urldecode($value["image2"]);

	echo "<table>";
	echo "<tr><th>게시물번호</th><td>".$idx."</td></tr>";
	echo "<tr><th>가격</th><td>".$price."</td></tr>";
	echo "<tr><th>분류1</th><td>".$category1."</td></tr>";
	echo "<tr><th>분류2</th><td>".$category2."</td></tr>";
	echo "<tr><th>원본이미지</th><td><img src='".$image1."'' target='_blank'>더보기</a></td></tr>";
	echo "<tr><th>썸네일이미지</th><td><img src='".$image2."'' target='_blank'>더보기</a></td></tr>";
	echo "</table>";
}
?>
<style type="text/css">
	table{
		border: solid 1px #000;
		width: 100%;
	}
	th{
		width: 20%;
	}
	img{
		width: 30%;
	}
</style>
```

# 응용 
* search_xml.php
  
```php
<form method="GET" action="search_xml.php">
	<input type="text" name="keywords" value="" />
	<input type="submit" value="입력" />
</form>
<style type="text/css">
	table,td{
		border: solid 1px #000;
	}
	table{
		width: 100%;
	}
	th{
		width: 20%;
	}
</style>
									
<?php
if(!isset($_GET['keywords'])){
	$_GET['keywords'] = "웹";
}
$keywords			= $_GET['keywords'];
$parameter			= "keywords=$keywords";

$curl = curl_init();
$timeout = 5;
$url = 'api.saramin.co.kr/job-search?keywords="'.$keywords.'"';
//$url = 'api.saramin.co.kr/job-search';
//http://api.saramin.co.kr/job-search
echo $url;

curl_setopt($curl, CURLOPT_URL, $url);
curl_setopt($curl, CURLOPT_RETURNTRANSFER, 1);
curl_setopt($curl, CURLOPT_CONNECTTIMEOUT, $timeout);

$xml = curl_exec($curl);
curl_close($curl);
$xml_object = simplexml_load_string($xml,'SimpleXMLElement', LIBXML_NOCDATA);
//var_dump($xml_object);

$XML_DATA = array();
$XML_DATA = json_decode(json_encode($xml_object), true);
/*잘못된 Array 전환방식 (엘리먼트가 하나일 경우 뎁스가 하나 줄어든다)*/
foreach($xml_object->jobs->job as $value)
{
	$id						= $value->id;
	$url					= $value->url;
	$title					= $value->position->title;
	$jobtype				= $value->position->{"job-type"};
	$company_name 			= $value->company->name;

	echo "<table>";
	echo "<tr><th>회사이름</th><td>".$company_name."</td></tr>";
	echo "<tr><th>구인제목</th><td>".$title."</td></tr>";
	echo "<tr><th>구인종류</th><td>".$jobtype."</td></tr>";
	echo "<tr><th>고유번호</th><td>".$id."</td></tr>";
	echo "<tr><th>URL링크</th><td><a href='".$url."'' target='_blank'>더보기</a></td></tr>";
	echo "</table>";
}
?>
```
