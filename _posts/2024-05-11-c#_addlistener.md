---
layout: post
title: c# addlistener
category: c#
tags:
---

# c# addlistener


```c#
okButton.onClick.AddListener(OnOkButtonClicked);
okButton.onClick.AddListener(() => OnOkButtonClicked());
```
* 위의경우는 매개변수를 전달(pass addition parameters)하거나 추가기능(execute addition code)을 호출할 수 없고, 아래의 경우는 가능하다.

## pass addition parameters
```c#
string additionalParameter = "Additional Info";

okButton.onClick.AddListener(() => 
{
    OnOkButtonClicked(additionalParameter);
});
```

## execute addition code
```c#
okButton.onClick.AddListener(() => 
{
    Debug.Log("OK button was clicked");
    OnOkButtonClicked();
});
```