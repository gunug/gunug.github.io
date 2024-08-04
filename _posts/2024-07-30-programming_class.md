---
layout: post
title: programming class 클래스
category: coding
tags: 
---

# class

* 클래스는 변수나 함수의 집합
* 클래스는 생성자를 통해서 객체가 됨

```c#
using System;
					
public class Program
{	
	public static void Main()
	{
		People p1 = new People();
	}
}
public class People
{
	public int a = 15;
}
```

---

# static

```c#
using System;
			
public class Program
{	
	
	public static void Main()
	{
		People p1 = new People();
		People p2 = new People();
		p1.name = "홍길동";
		p2.name = "김철수";
		Console.WriteLine(People.p_name);
	}
}
public class People
{
	public static string p_name="test";
	public string name;
	public int age = 15;
	public void hello(){
		Console.WriteLine("hello 나는"+name+":"+age+"살이다");
	}
}	
```
---
# virtual
```c#
public class Animal
{
   public virtual void Speak()
   {
        Console.WriteLine("Nothing!");
   }
}
 
public class Dog : Animal
{
    public override void Speak()
    {
        Console.WriteLine("멍멍!");
    }
}
 
Dog temp = new Dog();
temp.Speak();//멍멍!
```
---
# abstract
```c#
public abstract class Animal
{
    public abstract void Speak();
    
}
 
public class Dog : Animal
{
    public override void Speak()
    {
        Console.WriteLine("멍멍!");
    }
}
 
  Dog temp = new Dog();
  temp.Speak();//멍멍!
```

---

# interface
```c#
public interface Animal
{
    void Speak();
 
    string Name
    {
        get;
        set;
    }
  
}
 
class Dog : Animal
{
    private string name;
 
    public void Speak()
    {
        Console.WriteLine(name + "->멍멍!");
    }
 
    public string Name
    {
        get
        {
            return name;
        }
        set
        {
            name = value;
        }
    }
}
 
Dog temp = new Dog();
temp.Name = "흰둥이";
temp.Speak(); //흰둥이->멍멍!
```

---

# override

```c#
public override void Setup(string name){
	// 기반 클래스의 Setup 메소드 호출
	base.Setup(name);

	//추가내용 작성
}
```