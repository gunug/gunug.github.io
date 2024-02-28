---
layout: post
title: unity file name 파일명
category: unity3d
tags: c#
---

# unity file name 파일명

## 소스코드
* 출처 : https://oneday0012.tistory.com/162

```c++
public String convertFilename(String orgnStr) {
    String restrictChars = "|\\\\?*<\":>/";
    String regExpr = "[" + restrictChars + "]+";

    // 파일명으로 사용 불가능한 특수문자 제거
    String tmpStr = orgnStr.replaceAll(regExpr, "");

    // 공백문자 "_"로 치환
    return tmpStr.replaceAll("[ ]", "_");
}
```

## for Unity

```c#
    public String convertFilename(String orgnStr)
    {
        // 파일명으로 사용 불가능한 특수문자 제거
        System.Text.RegularExpressions.Regex regex = new System.Text.RegularExpressions.Regex("[|\\\\?*<\":>/]");
        string output = regex.Replace(orgnStr, "");
        string output2 = output.Replace(" ", "_");

        // 공백문자 "_"로 치환
        return output2;
    }
```
