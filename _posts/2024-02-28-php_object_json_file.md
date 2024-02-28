---
layout: post
title: php object json file
category: web
tags: php
---

# php object json file
## Object 

```php
  <?php
    $obj = (object) [
    'var1' => 'value_1',
    'var2' => 50,
    ];

    echo $obj->var1;
  ?>
```

## JSON 
```php
<?php
$myObj->name = "John";
$myObj->age = 30;
$myObj->city = "New York";

$myJSON = json_encode($myObj);

echo $myJSON;
?>
```

## file 
* fopen(const char* filename, const char* mode);
* r:읽기형식, w:쓰기, a:덧붙이기
* 참고: https://modoocode.com/58
  
```php
$value_txt = "test string data";
$file_url = "file.txt";   
$data_file = fopen(file_url, "w");  
fwrite($data_file, $value_txt);  
fclose($data_file);
```
---

## Object -> json -> file 
```php
$obj->min = 0;
$obj->max = 100;
$json = json_encode($obj);
$file_url = "file.txt";
$data_file = fopen($file_url, "w");
fwrite($data_file, $json);  
fclose($data_file);
```
---

## file -> json -> Object 
```php
$file_url = "file.txt";
$data_file2 = fopen($file_url, "r") or die("Unable to open file!");
$json2 = fread($data_file2,filesize($file_url));
fclose($data_file2);
$obj2 = json_decode($json2);
echo $obj2->min;
echo $obj2->max;
```
