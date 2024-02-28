---
layout: post
title: php main page 메인페이지
category: web
tags: php
---

# php main page 메인페이지

## 메인 페이지용 PHP
```php
<style type="text/css">
	img{
		width:300px;
	}
</style>
										
<?php

	$dbc = mysqli_connect('localhost', 'root', '', 'media_programming_2', '3306') or die('Error connecting to MySQL server.');
	//데이터 베이스 접속

	$query = "SELECT * FROM `content`";
	//쿼리문
	echo $query."<br />";

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
	   echo "<td><img src='".$row[4]."' /></td>";
	   echo "<td><img src='".$row[5]."' /></td>";
	   echo "<td>".$row[6]."</td>";
	   echo "<td>".$row[7]."</td>";
	   echo "</tr>";
	}
	echo "</table>";
?>
```
		            					
## JOIN을 이용한 데이터 연결
* site_main.php

```php
$query = 
"SELECT
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
    `content`.category2_code=`category2`.code";
```
			
## 검색 form 추가
* site_main.php

```php
<form method="GET" action="site_main.php">
	<input type="text" name="search_value" />
	<input type="submit" value="search" />
</form>
```
			
## 쿼리문 수정
* site_main.php

```php
$query = 	
"SELECT
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
    AND
    `content`.content LIKE '%".$_GET['search_value']."%'";
```

## 쿼리문 수정 (제목 검색도 포함하기)
* site_main.php

```php
$query = 	
"SELECT
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
    AND
                            (
    `content`.content LIKE '%".$_GET['search_value']."%'
                            OR
                            `content`.name LIKE '%".$_GET['search_value']."%')";
```

## 출력 순서

```php
ORDER BY `content`.id ASC;
```

## undefined 에러 벗어나기

* site_main.php
  
```php
if(!isset($_GET['search_value'])){
		$_GET['search_value'] = "";
	}
```

---

## 조건 필터링
### 필터링용 form 

```php
<form method="GET" action="site_main.php" id="if_form"></form>
<table id="if_table">
	<tr>
		<th>제조사</th>
										
<?php

	$dbc = mysqli_connect('localhost', 'root', '', 'media_programming_2', '3306') or die('Error connecting to MySQL server.');
	//데이터 베이스 접속
	$category1_query = "SELECT id,code,content FROM `category1`";
	//쿼리문
	$category1_result = mysqli_query($dbc, $category1_query) or die ('Error querying database');

	$category2_query = "SELECT id,code,content FROM `category2`";
	//쿼리문
	$category2_result = mysqli_query($dbc, $category2_query) or die ('Error querying database');
?>

										
<?php

	while($category1_row=mysqli_fetch_row($category1_result)){
		echo "<td>";
		echo "<input form='if_form' type='checkbox' name='category1_check[]'";
		//*
		echo " value='".$category1_row[1]."'/>".$category1_row[2];
		echo "</td>";
	}
?>
	</tr>
	<tr>
		<th>타입</th>
										
<?php

	while($category2_row=mysqli_fetch_row($category2_result)){
		echo "<td>";
		echo "<input form='if_form' type='checkbox' name='category2_check[]'";
		//*
		echo " value='".$category2_row[1]."'/>".$category2_row[2];
		echo "</td>";
	}
?>
	</tr>
</table>
<input type="submit" form="if_form" value="조건 적용"/>
```
		            					
### 채크 기능 추가 

```php
<form method="GET" action="site_main.php" id="if_form"></form>
<table id="if_table">
	<tr>
		<th>
			제조사
		</th>
										
<?php

	$c1_counter = 0; //*
	while($category1_row=mysqli_fetch_row($category1_result)){
		echo "<td>";
		echo "<input form='if_form' type='checkbox' name='category1_check[]'";
		if(isset($_GET['category1_check'])){
			if(in_array($category1_row[1], $_GET['category1_check'])){
				echo "checked='checked'";
			}
		}//*
		echo " value='".$category1_row[1]."'/>".$category1_row[2];
		echo "</td>";
		$c1_counter++; //*
	}
?>
	</tr>
	<tr>
		<th>
			타입
		</th>
										
<?php

	$c2_counter = 0; //*
	while($category2_row=mysqli_fetch_row($category2_result)){
		echo "<td>";
		echo "<input form='if_form' type='checkbox' name='category2_check[]'";
		if(isset($_GET['category2_check'])){
			if(in_array($category2_row[1], $_GET['category2_check'])){
				echo "checked='checked'";
			}
		}//*
		echo " value='".$category2_row[1]."'/>".$category2_row[2];
		echo "</td>";
		$c2_counter++; //*
	}
?>
	</tr>
</table>
<input type="submit" form="if_form" value="조건 적용"/>
```
		            					
### 쿼리추가 

```php
$if_query = "";
	if(isset($_GET['category1_check'])){
		echo "****";
		$if_query = $if_query." AND (";
		for($i=0; $i<count($_GET['category1_check']); $i++){
			$if_query = $if_query."`category1`.code = '".$_GET['category1_check'][$i]."'";
			$if_query = $if_query." OR ";
		}
		$if_query = substr($if_query, 0, -3);
		$if_query = $if_query.")";
	}
	$query = $query.$if_query;

	$if_query = "";
	if(isset($_GET['category2_check'])){
		echo "****";
		$if_query = $if_query." AND (";
		for($i=0; $i<count($_GET['category2_check']); $i++){
			$if_query = $if_query."`category2`.code = '".$_GET['category2_check'][$i]."'";
			$if_query = $if_query." OR ";
		}
		$if_query = substr($if_query, 0, -3);
		$if_query = $if_query.")";
	}
	$query = $query.$if_query;
```

## 가격순 정렬
* 정렬용 form 

```php
<form method="GET" action="site_main.php" id="sort_form"></form>
<table id="sort_table">
	<tr>
		<th>정렬방식</th>
	</tr>
	<tr>
		<td>
			낮은가격부터
			<input type="radio" name="money_sort" value="ASC" form="sort_form"
<?php if (isset($_GET['money_sort']) && $_GET['money_sort']=="ASC") echo "checked='checked'";?>		
			/> <!--오름차순-->
		</td>
		<td>
			높은가격부터
			<input type="radio" name="money_sort" value="DESC" form="sort_form"
<?php if (isset($_GET['money_sort']) && $_GET['money_sort']=="DESC") echo "checked='checked'";?>
			/> <!--내림차순-->
		</td>
		<td>
			<input type="submit" value="sort" form="sort_form"/>
		</td>
	</tr>
</table>
```
		            					
## 쿼리문 추가 

```php
$sort_query = "";
if(isset($_GET['money_sort'])){
	$sort_query = $sort_query."ORDER BY ";
	switch ($_GET['money_sort']) {
		case 'DESC':
			$sort_query = $sort_query."price DESC;";
		break;

		case 'ASC':
			$sort_query = $sort_query."price ASC;";
		break;
		
		default:
			# code...
		break;
	}
}
$query = $query.$sort_query;
```
