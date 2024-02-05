---
layout: post
title: tinyduino 타이니두이노
category: arduino
tags: arduino
---

<iframe width="560" height="315" src="https://www.youtube.com/embed/4qeOos7Mm8c?si=ocQof5veAsdki2ba" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" allowfullscreen></iframe>

* LED dot matrix data sheet url : [http://tiny-circuits.com/wp-content/uploads/2014/04/ASD2413_Rev1.pdf](http://tiny-circuits.com/wp-content/uploads/2014/04/ASD2413_Rev1.pdf)
* Charliplexing.h, Fingure.h download at [http://tiny-circuits.com/wp-content/uploads/2014/05/LoLShield.zip](http://tiny-circuits.com/wp-content/uploads/2014/05/LoLShield.zip)

```c
#include "Charliplexing.h"
#include "Figure.h"

void setup(){
    LedSign::Init();
}

const uint8_t GRID_HEIGHT = 6;
const uint8_t GRID_WIDTH = 9;
const int CHAR_NUM = 3;
int grid[CHAR_NUM][GRID_HEIGHT][GRID_WIDTH] = 
{ 
    {
        {1,1,1,0,1,1,1,0,0},
        {1,0,1,0,1,0,0,0,0},
        {1,1,1,0,1,1,1,0,0},
        {1,0,1,0,0,0,1,0,0},
        {1,1,1,0,1,1,1,0,0},
        {0,0,0,0,0,0,0,0,0}
    },

    {
        {0,0,1,1,1,1,1,0,0},
        {0,1,0,0,0,0,0,1,0},
        {1,0,0,1,0,1,0,0,1},
        {1,0,0,0,0,0,0,0,1},
        {0,1,0,0,0,0,0,1,0},
        {0,0,1,1,1,1,1,0,0}
    },

    {
        {0,0,0,0,0,0,0,0,0},
        {0,0,1,1,0,1,1,0,0},
        {0,0,1,1,0,1,1,0,0},
        {0,0,1,1,0,1,1,0,0},
        {1,0,0,0,0,0,0,0,1},
        {0,1,1,1,1,1,1,1,0}
    }
};

void loop(){
    for(int c=0; c<CHAR_NUM; c++){
        for(int y=0; y<GRID_HEIGHT; y++){
            for(int x=0; x<GRID_WIDTH; x++){
                LedSign::Set(y,GRID_WIDTH-x-1,grid[c][y][x]);
                delay(5);
            }
        }
        delay(200);
    }
}
```