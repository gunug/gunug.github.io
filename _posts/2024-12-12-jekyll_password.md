---
layout: post
title: jekyll 비공개 페이지
category: blog
tags: 
---

# jekyll 비공개 페이지
* <https://github.com/lilykonings/jekyll-password-protect?tab=readme-ov-file>

```
gulp.task('firewall:encrypt', () => {
  return gulp.src('_protected/*.*')
    .pipe(encrypt('password'))
    .pipe(gulp.dest('_posts'));
});
```

* _protected폴더의 모든 파일을 _post에 암호화 하여 출력
* 기본설정을 변경하고 싶으면 해당 내용을 고치면 됨