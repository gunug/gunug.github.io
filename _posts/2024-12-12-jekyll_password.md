---
layout: post
title: jekyll 비공개 페이지
category: blog
tags: 
---

# jekyll 비공개 페이지
* <https://github.com/lilykonings/jekyll-password-protect?tab=readme-ov-file>
<div style="color:red">gulp 설치 에러로 해당 기능을 사용할 수 없습니다</div>

---

```javascript
gulp.task('encrypt', () => {
  return gulp.src('SRC-FOLDER')
    .pipe(encrypt('PASSWORD'))
    .pipe(gulp.dest('DEST-FOLDER'));
});
```
* 아래의 encrypt gulp 작업은 SRC-FOLDER에 있는 각 파일을 PASSWORD로 암호화하여 DEST-FOLDER에 출력합니다. 사이트 구조에 따라 이러한 설정을 gulpfile.js에서 변경하세요.
  
---

```javascript
gulp.task('firewall:encrypt', () => {
  return gulp.src('_protected/*.*')
    .pipe(encrypt('password'))
    .pipe(gulp.dest('_posts'));
});
```

* _protected폴더의 모든 파일을 _post에 암호화 하여 출력
* 기본설정을 변경하고 싶으면 해당 내용을 고치면 됨

---

# Protect Posts
* 포스트를 암호화하려면, 지정된 SRC-FOLDER에 해당 포스트를 저장하고 gulp를 실행하기만 하면 됩니다.
* "gulp를 실행한다"는 것은 Gulp라는 도구를 사용하여 특정 작업(task)을 수행하는 것을 의미합니다. Gulp는 웹 개발에서 자동화 작업을 관리하는 빌드 시스템 도구로, 예를 들어 파일을 압축하거나, 이미지를 최적화하거나, SASS 파일을 CSS로 변환하는 등의 작업을 자동으로 처리할 수 있도록 도와줍니다.
* Gulp를 실행한다는 것은 터미널(커맨드 라인)에서 `gulp` 명령어를 입력하여 설정 파일(gulpfile.js)에 정의된 작업들을 수행하는 과정을 말합니다. 이 경우, 파일 암호화 작업이 정의되어 있으므로, SRC-FOLDER에 있는 파일들을 PASSWORD로 암호화하여 DEST-FOLDER로 옮기는 작업을 진행하게 됩니다.

## glup설치
1. **Node.js 설치**: Gulp는 Node.js 환경에서 동작하기 때문에, 우선 Node.js가 설치되어 있어야 합니다. Node.js를 설치하면 npm(Node Package Manager)도 함께 설치됩니다.
2. **전역으로 Gulp CLI 설치**:
   ```bash
   npm install --global gulp-cli
   ```
   이 명령어는 Gulp의 커맨드 라인 인터페이스(CLI)를 전역적으로 설치하여, 어느 디렉토리에서나 `gulp` 명령어를 사용할 수 있게 합니다.
3. **프로젝트에서 Gulp를 설치**:
   프로젝트 루트 디렉토리에서 아래 명령어를 실행하여 Gulp를 설치합니다.
   ```bash
   npm install --save-dev gulp
   ```
   이 명령은 프로젝트의 `package.json` 파일에 Gulp를 개발 의존성으로 추가합니다.
4. **gulpfile.js 설정**:
   프로젝트 루트에 `gulpfile.js`라는 파일을 생성하고, 여기서 수행할 작업들을 정의합니다.
이제 터미널에서 `gulp`를 입력하여 설정된 작업을 실행할 수 있습니다. Gulp CLI가 전역적으로 설치되어 있으므로, 각 Gulp 작업에 따라 필요한 플러그인들도 함께 설치하고 설정해야 할 수 있습니다.

---

# glup 공식 설치 가이드
* <https://gulpjs.com/docs/en/getting-started/quick-start/>

## 설치에러
* ReferenceError: primordials is not defined
* gulp 버전이 너무 낮거나, node 버전이 너무 높음
* 참고링크 : <https://velog.io/@khy731/gulp-%EC%97%90%EB%9F%AC-ReferenceError-primordials-is-not-defined-in-node>
* NVM (Node Version Manager) : <https://github.com/coreybutler/nvm-windows/releases>
* 
* ```nvm install v11.15.0``` 원하는 버전의 노드 설치
* ```nvm use 11.15.0``` 원하느 버전의 노드 사용

---

* ```npm uninstall -g gulp``` 설치제거
* ```npm install -g "gulpjs/gulp.git#4.0"``` 4.0설치

---

# 설치에러
```
npm i gulp gulp-sass node-sass --save-dev
```