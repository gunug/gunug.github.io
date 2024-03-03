---
layout: post
title: php readdir 디렉토리 파일 불러오기
category: web
tags: php
---

# php readdir 디렉토리 파일 불러오기

```php
<?php
if ($handle = opendir('./thumbnail/')) {
    /* This is the correct way to loop over the directory. */
    while (false !== ($entry = readdir($handle))) {
        if ($entry != '.' && $entry != '..'){
            if(strchr($entry, ".jpg") == true){ //$entry변수에 .jpg라는 문자가 있는지 확인
                echo "<br /><div>파일명 : $entry</div><br />";
                echo "<div><img src='./thumbnail/$entry' /></div>";
            }
        }
    }
    closedir($handle);
}
?>
```

---

# 정렬
```php
while(false !== ($f = readdir($fp))) {
    $files[] = $f;
}
sort($files);
```

---

# 적용 결과
* 역순정렬은 rsort();
  
```php
<?php
if ($handle = opendir('./thumbnail/')) {
    /* This is the correct way to loop over the directory. */
    while (false !== ($entry = readdir($handle))) {
        $files[] = $entry;
    }
    rsort($files);
    for ($i=0; $i<count($files); $i++){
        $entry = $files[$i];
        if ($entry != '.' && $entry != '..'){
            if(strchr($entry, ".jpg") == true){ //$entry변수에 .jpg라는 문자가 있는지 확인
                echo "<br /><div>파일명 : $entry</div><br />";
                echo "<div><img src='./thumbnail/$entry' /></div>";
            }
        }
    }
    closedir($handle);
}
?>
```