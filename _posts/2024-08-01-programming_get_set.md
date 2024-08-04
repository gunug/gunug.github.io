---
layout: post
title: programming get set 읽기 쓰기
category: coding
tags: 
---

# get set

```c#
class Knight
{
    protected int hp;

    public int GetHp(){
        return hp;
    }
    public void SetHp(int hp){
        this.hp = hp;
    }
}
```
```c#
class Knight{
    public int hp
    {
        get { return hp; }
        set { hp = value; }
    }
}
```
* 사용
  
```c#
Knight hero = new Knight();
hero.hp = 100;
Console.WriteLine(hero.hp);
```
---
```c#
public int Hp { get; set; }
```