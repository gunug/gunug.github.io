---
layout: post
title: C# struct 구조체
category: c#
tags: c#
---

# C# struct 구조체
* 참고링크 : https://docs.microsoft.com/ko-kr/dotnet/csharp/language-reference/builtin-types/struct?source=recommendations
  
```c#
public struct Coords
{
    public Coords(double x, double y)
    {
        X = x;
        Y = y;
    }

    public double X { get; }
    public double Y { get; }

    public override string ToString() => $"({X}, {Y})";
}
```