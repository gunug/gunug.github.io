---
layout: post
title: c# code
category: c#
tags:
---

# c# code

# 추상 클래스 abstract
```c#
public abstract class Expression{
    public abstract void SaySomething();
}
public class Constant : Expression{
    public override void SaySomething()
    {
        Console.WriteLine("hello!");
    }
}
```

---

# 접근 제한자 accessor
```c#
public class accessor{
    public int value1; //액세스가 제한되지 않음
    private int value2; //이 클래스로만 액세스가 제한됨
    protected int value3; // 이 클래스 또는 이 클래스에서 파생된 클래스로만 액세스가 제한됨
    internal int value4; // 액세스가 현제 어셈블리(.exe또는 .dll)로 제한됨
    protected internal int value5; //액세스가 이 클래스, 이클래스에서 파생된 클래스 또는 동일한 어셈블리 내의 클래스로만 제한됨
    private protected int value6; //액세스가 이클래스 또는 동일한 어셈블리내의 이 형식에서 파생된 클래스로만 제한됨

    public static readonly int value7; //읽기전용 정적변수

    public void etc(){
        value1 = 0;
        value2 = 0;
        Console.WriteLine(value2); //콘솔찍기 전에는 필드가 사용되지 않았습니다 warning뜨고 이거 있으니 안뜨는것 무엇
        value3 = 0;
        value4 = 0;
        value5 = 0;
        value6 = 0;
    }
    public static void etc_static(){
        int get_value = value7;
    }
}
```

---

# 배열 array
```c#
public static class array_example{
    public static void array_sample(){
        int[] a1 = new int[10];
        int[,] a2 = new int[10,20];
        int[,,] a3 = new int[1,2,3];

        int[][] a4 = new int[3][];
        a4[0] = new int[3];
        a4[1] = new int[3];
        a4[2] = new int[3];

        int[] a5 = new int[]{1,2,3};
        int[] a6 = {1,2,3};

        foreach (int item in a6){
            Console.WriteLine("item:"+item);
        }
    }
}
```

---

# closure
```c#
public static class closure{

    public static void start_sample(){
        for(int i=0; i<5; i++){
            Console.WriteLine(i);
        }
    }

    public static void lambda_sample(){
        var b = () => {
            Console.WriteLine("test");
            return "test";
        };
        Console.WriteLine(b);
        
        for(int i=0; i<5; i++){
            Console.WriteLine(i);
            Func<int> a = () => { 
                Console.WriteLine("lambda:"+i);
                return i;
            };
            Console.WriteLine("lambda_return:"+a);
        }
    }

    public static void sample(){
        test1();
    }
    public static void test1(){
        for(int i=0; i<3; i++){
            test2(()=>{return 1;});
        }
    }
    public static void test2(Func<int> f){
        Console.WriteLine(f);
    }
}
```

---

# delegate
```c#
using System.IO;
namespace root{
    public class delegate_sample{
        public void init(){
            // Instantiate the delegate.
            Del d1 = DelegateMethod; //유형이 맞으면 대리자 등록
            Del d2 = DelegateMethod2;
            Del handler = d1 + d2; //대리자를 덧셈으로 추가 가능
            handler += d2; //가산식 적용가능
            // 뺄셈이나 감산식 적용가능

            // Call the delegate.
            handler("delegate sample activate!");

            MethodWithCallback(0,1,handler); //대리자를 메서드에 전달하여 콜백용으로 사용

            int invocationCount = handler.GetInvocationList().GetLength(0); //대리자에 포함된 메서드 숫자 알아내기
            Console.WriteLine("invocationCount:"+invocationCount);
        }

        public void CallBackFunction(){
            Console.WriteLine("call back function activate!");
        }

        public delegate void Del(string message); //대리자 선언

        public static void DelegateMethod(string message){
            Console.WriteLine(message);
        }
        public static void DelegateMethod2(string message){
            Console.WriteLine("is from 2 :"+message);
        }

        public static void MethodWithCallback(int param1, int param2, Del callback)
        {
            callback("The number is: " + (param1 + param2).ToString());
        }
    }
}
```

---

# event
```c#
public class MyList2<T>
{
    const int DefaultCapacity = 4;

    T[] _items;
    int _count;
    public int Count => _count;

    public MyList2(int capacity = DefaultCapacity)
    {
        _items = new T[capacity];
    }

    public int Capacity
    {
        get =>  _items.Length;
        set
        {
            if (value < _count) value = _count;
            if (value != _items.Length)
            {
                T[] newItems = new T[value];
                Array.Copy(_items, 0, newItems, 0, _count);
                _items = newItems;
            }
        }
    }

    public T this[int index]
    {
        get => _items[index];
        set
        {
            _items[index] = value;
            OnChanged();
        }
    }
    public void Add(T item)
    {
        if (_count == Capacity) Capacity = _count * 2;
        _items[_count] = item;
        _count++;
        OnChanged();
    }
    protected virtual void OnChanged() => Changed?.Invoke(this, EventArgs.Empty);

    public override bool Equals(object other) =>
    Equals(this, other as MyList2<T>);

    static bool Equals(MyList2<T> a, MyList2<T> b)
    {
        if (Object.ReferenceEquals(a, null)) return Object.ReferenceEquals(b, null);
        if (Object.ReferenceEquals(b, null) || a._count != b._count)
            return false;
        for (int i = 0; i < a._count; i++)
        {
            if (!object.Equals(a._items[i], b._items[i]))
            {
                return false;
            }
        }
        return true;
    }

    public event EventHandler Changed;

    public static bool operator ==(MyList2<T> a, MyList2<T> b) =>
        Equals(a, b);

    public static bool operator !=(MyList2<T> a, MyList2<T> b) =>
        !Equals(a, b);
}

class EventExample
{
    static int s_changeCount;
    
    static void ListChanged(object sender, EventArgs e)
    {
        s_changeCount++;
    }
    
    public static void Usage()
    {
        var names = new MyList2<string>();
        names.Changed += new EventHandler(ListChanged);
        names.Add("Liz");
        names.Add("Martha");
        names.Add("Beth");
        Console.WriteLine(s_changeCount); // "3"
    }
}
```

---

# generic
```c#
namespace root{
    public class generic_sample{
        public static void ShowText<T>(T t1, T t2){
            Console.WriteLine (t1+":"+t2);
        }
        public static void CallShow(){
            ShowText(1.2f, 1.3f);
            ShowText(3,5);
            ShowText("A","B");
        }
    }

    public class generic_class<T>{
        
        //static T test;
        public generic_class(T i1, T i2){
            
        }
    }
}
```

---

# get set
```c#
public static class get_set{
    public static int return_value;
    public static int get_set_test{
        get => return_value;
        set {
            return_value = value;
            Console.WriteLine("set");
        }
    }
}
```

---

# indexer
```c#
public class MyList<T>
{
    const int DefaultCapacity = 4;

    T[] _items;
    int _count;
    public int Count => _count;

    public MyList(int capacity = DefaultCapacity)
    {
        _items = new T[capacity];
    }

    public int Capacity
    {
        get =>  _items.Length;
        set
        {
            if (value < _count) value = _count;
            if (value != _items.Length)
            {
                T[] newItems = new T[value];
                Array.Copy(_items, 0, newItems, 0, _count);
                _items = newItems;
            }
        }
    }

    public T this[int index]
    {
        get => _items[index];
        set
        {
            _items[index] = value;
            OnChanged();
        }
    }
    public void Add(T item)
    {
        if (_count == Capacity) Capacity = _count * 2;
        _items[_count] = item;
        _count++;
        OnChanged();
    }
    protected virtual void OnChanged() => Changed?.Invoke(this, EventArgs.Empty);

    public override bool Equals(object other) =>
    Equals(this, other as MyList<T>);

    static bool Equals(MyList<T> a, MyList<T> b)
    {
        if (Object.ReferenceEquals(a, null)) return Object.ReferenceEquals(b, null);
        if (Object.ReferenceEquals(b, null) || a._count != b._count)
            return false;
        for (int i = 0; i < a._count; i++)
        {
            if (!object.Equals(a._items[i], b._items[i]))
            {
                return false;
            }
        }
        return true;
    }

    public event EventHandler Changed;

    public static bool operator ==(MyList<T> a, MyList<T> b) =>
        Equals(a, b);

    public static bool operator !=(MyList<T> a, MyList<T> b) =>
        !Equals(a, b);
}

public class main_class{
    public void _example(){
        MyList<string> names = new();
        names.Add("Liz");
        names.Add("Martha");
        names.Add("Beth");
        for (int i = 0; i < names.Count; i++)
        {
            string s = names[i];
            names[i] = s.ToUpper();
        }
    }
}
```

---

# lambda
```c#
public static class lambda{
    public static int lambda_value = 0;
    public static void lambda_example(){
        // Expression lambdas
        var a = (string s) => int.Parse(s);
        // Statement lambdas
        var b = (string s) => { 
            int d = int.Parse(s); 
            return d;
        };

        var c = (int s) => {
            s++;
        };
    }

    public delegate int lambda_dele(int a);
    public static lambda_dele e = (int a) =>{
        Console.WriteLine(a);
        return 1+3;
    };
    public static void start_lambda(){
        e += (int a) => 4*5;
        e += (int a) => 6*7;
        Console.WriteLine(e(10));
    }
}
```

---

# overload
```c#
class OverloadingExample
{
    static void F() => Console.WriteLine("F()");
    static void F(object x) => Console.WriteLine("F(object)");
    static void F(int x) => Console.WriteLine("F(int)");
    static void F(double x) => Console.WriteLine("F(double)");
    static void F<T>(T x) => Console.WriteLine($"F<T>(T), T is {typeof(T)}");            
    static void F(double x, double y) => Console.WriteLine("F(double, double)");
    
    public static void UsageExample()
    {
        F();            // Invokes F()
        F(1);           // Invokes F(int)
        F(1.0);         // Invokes F(double)
        F("abc");       // Invokes F<T>(T), T is System.String
        F((double)1);   // Invokes F(double)
        F((object)1);   // Invokes F(object)
        F<int>(1);      // Invokes F<T>(T), T is System.Int32
        F(1, 1);        // Invokes F(double, double)
    }
}
```

---

# struct
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

---

# virtual
```c#
class Parent
{
  // 프로퍼티도 virtual 키워드 사용할 수 있습니다.
  public virtual string Str { get; set; }
  
  // 가상 메서드로 선언합니다.
  public virtual void show() 
  {
    Console.WriteLine("Parent의 show() 메서드");
  }
}

class Child : Parent
{
  // 프로퍼티도 재정의할 수 있습니다.
  public override string Str { get; set; }
  
  // show() 메서드를 재정의합니다.
  public override void show()
  {
    Console.WriteLine("Parent 클래스의 show() 메서드 오버로드");
  }
}

///
/*
오버로딩(Overloading)
매개변수와 반환 타입이 다르지만, 메서드 이름이 동일합니다.

오버라이딩(Overriding)
상위 클래스의 메서드를 하위 클래스에서 재정의합니다. 

오버로딩과 오버라이딩의 가장 큰 차이점은 오버로딩은 컴파일 시간에 작동하는 반면, 
오버라이딩은 런타임에 작동한다는 것입니다. virtual 키워드는 런타임에 실행되므로 메서드 오버라이딩 개념을 따릅니다.
*/
```