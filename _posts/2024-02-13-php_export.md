---
layout: post
title: php export 데이터 내보내기
category: web
tags: php
---

# xml 
* xml_php.php
  
```php
<?php
	header("Content-type: text/xml");
	echo "<?xml version=\"1.0\" encoding=\"utf-8\" ?> \n";

	$dbc = mysqli_connect('localhost', 'root', '', 'media_programming_2', '3306') or die('Error connecting to MySQL server.');
	//데이터 베이스 접속
	$query = 	"SELECT
 				`content`.id,
				`content`.price,
				`category1`.content,
				`category2`.content,
				`content`.image_url,
				`content`.thumb_url,
				`content`.name,
				`content`.content 
				FROM `content`,`category1`,`category2`
				WHERE
					`content`.category1_code=`category1`.code 
					AND 
					`content`.category2_code=`category2`.code
				";

	$result = mysqli_query($dbc, $query) or die ('Error querying database');
	//쿼리문 수행하기

	mysqli_close($dbc);
	//데이터 베이스 닫기

	echo "<document>";
	while($row = mysqli_fetch_row($result)){
	   echo "<content>";
	   echo "<idx>".$row[0]."</idx>";
	   echo "<price>".$row[1]."</price>";
	   echo "<category1>".$row[2]."</category1>";
	   echo "<category2>".$row[3]."</category2>";
	   echo "<image1>".$row[4]."</image1>";
	   echo "<image2>".$row[5]."</image2>";
	   echo "<title>".$row[6]."</title>";
	   echo "<comment>".$row[7]."</comment>";
	   echo "</content>";
	}
	echo "</document>";
?>
```

* 기상청 RSS <http://www.kma.go.kr/weather/forecast/mid-term-rss3.jsp?stnId=108>
* RSS [rich site summary]

---

# json 
* json_php.php

```php
<?php
	header("Content-Type:application/json");
	$dbc = mysqli_connect('localhost', 'root', '', 'media_programming_2', '3306') or die('Error connecting to MySQL server.');
	//데이터 베이스 접속
	$query = 	"SELECT
 				`content`.id,
				`content`.price,
				`category1`.content,
				`category2`.content,
				`content`.image_url,
				`content`.thumb_url,
				`content`.name,
				`content`.content 
				FROM `content`,`category1`,`category2`
				WHERE
					`content`.category1_code=`category1`.code 
					AND 
					`content`.category2_code=`category2`.code
				";

	$result = mysqli_query($dbc, $query) or die ('Error querying database');
	//쿼리문 수행하기

	mysqli_close($dbc);
	//데이터 베이스 닫기

	$rows = array();
	//echo '{"content:"';
	echo'{';
	$result_text = "";
	$counter = 0;
	while($row = mysqli_fetch_row($result)){
		$result_text = $result_text.'"content'.$counter.'":{';
		$result_text = $result_text.'"idx":"'.$row[0].'",';
		$result_text = $result_text.'"price":"'.$row[1].'",';
		$result_text = $result_text.'"category1":"'.$row[2].'",';
		$result_text = $result_text.'"category2":"'.$row[3].'",';
		$result_text = $result_text.'"image1":"'.urlencode($row[4]).'",';
		$result_text = $result_text.'"image2":"'.urlencode($row[5]).'",';
		$result_text = $result_text.'"title":"'.$row[6].'",';
		$result_text = $result_text.'"comment":"'.$row[7].'"';
		$result_text = $result_text.'},';
		$counter++;
	}
	$result_text = substr($result_text,0,-1);
	echo $result_text;
	echo'}';
?>
```

* https://jsonlint.com/

---

# excel 
* excel_php.php
  
```php
<?php
 $today = date("Y-m-d");
 header( "Content-type: application/vnd.ms-excel" ); 
 header( "Content-Disposition: attachment; filename=". $today. ".xls"); 
 header( "Content-Description: PHP5 Generated Data" ); 
?>
<meta http-equiv="Content-Type" content="text/html; charset=utf-8">
<html>
<head>
<title></title>
</head>
<body>									
<?php
  $dbc = mysqli_connect('localhost', 'root', '', 'media_programming_2', '3306') or die('Error connecting to MySQL server.');
  //데이터 베이스 접속
  $query =  "SELECT
        `content`.id,
        `content`.price,
        `category1`.content,
        `category2`.content,
        `content`.image_url,
        `content`.thumb_url,
        `content`.name,
        `content`.content 
        FROM `content`,`category1`,`category2`
        WHERE
          `content`.category1_code=`category1`.code 
          AND 
          `content`.category2_code=`category2`.code
        ";

  $result = mysqli_query($dbc, $query) or die ('Error querying database');
  //쿼리문 수행하기

  mysqli_close($dbc);
  //데이터 베이스 닫기

  echo "<table>";
  while($row = mysqli_fetch_row($result)){
     echo "<tr>";
     echo "<td>".$row[0]."</td>";
     echo "<td>".$row[1]."</td>";
     echo "<td>".$row[2]."</td>";
     echo "<td>".$row[3]."</td>";
     echo "<td>".$row[4]."</td>";
     echo "<td>".$row[5]."</td>";
     echo "<td>".$row[6]."</td>";
     echo "<td>".$row[7]."</td>";
     echo "</tr>";
  }
  echo "</table>";
?>
</body>
</html>
```
