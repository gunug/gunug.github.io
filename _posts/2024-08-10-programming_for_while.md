---
layout: post
title: programming for while 반복문
category: coding
tags: 
---

# programming for while 반복문

```c#
//(초기값;조건식;증감식)
for(int i=0; i<10; i++){
Console.WriteLine(i);
}

int i=0;
if(i<10){

}
i++;
// i += 1;
// i = i + 1;
```

---

```c#
int i = 0;
while(i<10){
    Console.WriteLine(i);
    i++;
}
```

---

```c#
int[] scores = {90,80,50,30,40,20};
for(int i=0; i<6; i++){
    Console.WriteLine(scores[i]);
}
```