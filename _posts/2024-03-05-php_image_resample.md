---
layout: post
title: php image resample 이미지 크기변경 화질
category: web
tags: php
---

# php image resample 이미지 크기변경 화질
* 참고링크 : https://stackoverflow.com/questions/3617272/php-gd-bad-quality-on-resize


## imagesetinterpolation
* https://www.php.net/manual/en/function.imagesetinterpolation.php
* 다운샘플링 의 경우 IMG_SINC 알고리즘을 사용하는 것이 더 선명한 결과를 제공하는 경향이 있습니다.
* 업샘플링의 경우 IMG_BICUBIC_FIXED, IMG_GENERALIZED_CUBIC 및 IMG_QUADRATIC이 더 나은 결과를 제공할 수 있습니다.

## imagecopyresampled
* https://www.php.net/manual/en/function.imagecopyresampled.php

---

## interpolation 보간
```
IMG_BELL: Bell filter.
IMG_BESSEL: Bessel filter.
IMG_BICUBIC: Bicubic interpolation.
IMG_BICUBIC_FIXED: Fixed point implementation of the bicubic interpolation.
IMG_BILINEAR_FIXED: Fixed point implementation of the bilinear interpolation (default (also on image creation)).
IMG_BLACKMAN: Blackman window function.
IMG_BOX: Box blur filter.
IMG_BSPLINE: Spline interpolation.
IMG_CATMULLROM: Cubic Hermite spline interpolation.
IMG_GAUSSIAN: Gaussian function.
IMG_GENERALIZED_CUBIC: Generalized cubic spline fractal interpolation.
IMG_HERMITE: Hermite interpolation.
IMG_HAMMING: Hamming filter.
IMG_HANNING: Hanning filter.
IMG_MITCHELL: Mitchell filter.
IMG_POWER: Power interpolation.
IMG_QUADRATIC: Inverse quadratic interpolation.
IMG_SINC: Sinc function.
IMG_NEAREST_NEIGHBOUR: Nearest neighbour interpolation.
IMG_WEIGHTED4: Weighting filter.
IMG_TRIANGLE: Triangle interpolation.
```

---

## 사용법
```
	$dimg = imagecreatetruecolor($nw, $nh);
	//imagesetinterpolation($dimg, IMG_SINC);
	imagesetinterpolation($dimg, IMG_BILINEAR_FIXED);
```
* 이미지 생성 이후에 샘플링 방법을 명시하면됨

---

*이미지 테스트

<img src=198.13.61.223/resized/1709612717.jpg />

<img src=http://198.13.61.223/resized/1709612717.jpg />

![image](http://198.13.61.223/thumbnail/1709612717.jpg)

<img src="http://198.13.61.223/resized/1709612717.jpg" />

<img src="http://198.13.61.223/resized/1709612717.jpg" />
