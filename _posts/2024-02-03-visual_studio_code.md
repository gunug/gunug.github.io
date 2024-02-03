---
layout: post
title: visual studio code 비쥬얼 스튜디오 코드 사용
category: etc
tags: vscode
---

# formatter
* 참고링크 : https://80000coding.oopy.io/bd5c80d7-92ce-4387-ae74-b6d35ad77635
* C/C++, Clang-Format 익스텐션 설치
* 커맨드 팔레트 (Ctrl+Shift+P)
* Preferences: Open User Settings (JSON)
* 아래의 코드를 추가

```markdown
// 기본 포매터를 정의합니다.
"editor.defaultFormatter": "ms-vscode.cpptools",

// 저장할 때 코드를 포매팅합니다.
"editor.formatOnSave": true,

// 코드 포매팅 스타일을 정의합니다.
"C_Cpp.clang_format_fallbackStyle": "Google",
```

* LLVM: LLVM coding standards
* Google: Google's C++ style guide
* Chromium: Chromium's style guide
* Mozilla: Mozilla's style guide
* WebKit: WebKit's style guide
* Microsoft: Microsoft's style guide
* GNU: GNU coding standards

---

* 참고링크: https://contentstoaster.tistory.com/entry/vscode-formatter-prettier
* Prettier - Code Formatter 설치
* 루트 디렉토리 .prettierrc 파일을 생성후 다음을 입력

```json
{
    "singleQuote": true, //큰따옴표 대신 작은 따옴표로
    "semi":true, //세미콜론 항상 붙이기
    "useTabs": false, //탭 대신 공백으로 들여쓰기
    "tabWidth": 2 // 공백은 두 칸씩
}
```

---

# 빈줄 지우기
* 참고링크 : https://www.inflearn.com/blogs/1442
* 찾아 바꾸기 : Ctrl+H
* 정규식 사용 클릭
* ^$\n  :  입력창에 입력
* 모두 바꾸기 클릭