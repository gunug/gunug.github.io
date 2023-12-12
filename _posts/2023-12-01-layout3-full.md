---
layout: post
title: layout3 레이아웃3
category: subpage
tags: 
---

```html
<!DOCTYPE html>
<html>
    <head>
        <title>layout3</title>
        <meta charset="utf-8" />
        <style>
            #wrap{
                min-width: 1000px;
                max-width: 1920px;
                margin: 0px auto;
            }
            body{
                background-image: url("background.png");
            }
            header h1{
                font-size: 50px;
            }
            header ul{
                display: flex;
                list-style: none;
                padding: 0px;
                font-size: 12px;
            }
            header li{
                padding:0px;
                padding-right: 20px;
            }
            .short_line{
                width: 30px;
                border-top: solid 1px black;
            }
            #content{
                display: flex;
                flex-direction: row;
                flex-wrap: wrap;
                justify-content: center;
            }
            .content_card{
                width: 310px;
                background-color: white;
                box-shadow: 2px 2px 2px gray;
                /* 가로위치 세로위치 번짐정도 그림자색상*/
                margin: 20px;
            }
            .category{
                position: absolute; /* 위치지정 : 절대적인*/
                /* top bottom left right */
                left: 0px;
                bottom: 0px;
                background-color: black;
                color: white;
                padding: 5px 15px;
            }
            .content_card>div:first-child{
                position: relative;
                /* relative 부모는 absolute 자식의 기준이 된다*/
            }
            .content_card img{
                display: block;
            }
            .content_card>div:last-child{
                padding: 20px;
            }
            .content_card h2{
                margin-top: 0px;    
            }
            .content_card>div>div:nth-child(2){
                color: gray;
            }
            .long_line{
                width: 250px;
                border-top: dotted 1px gray;
                margin: 10px 0px;
            }
            .content_card p{
                margin: 0px;
            }
            footer ul{
                display: flex;
                list-style: none;
                padding: 0px;
            }
            footer li{
                padding-right: 20px; 
            }
        </style>
    </head>
    <body>
        <div id="wrap">
            <header>
                <h1>Gridly.</h1>
                <div class="short_line"></div>
                <ul>
                    <li>home</li>
                    <li>digital designs</li>
                    <li>web designs</li>
                    <li>branding/identity</li>
                </ul>
                <div class="short_line"></div>
            </header>
            <div id="content">
                <section class="content_card">
                    <div>
                        <img src="card1.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card2.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card3.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card4.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card5.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card6.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card7.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card8.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card9.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card10.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
                <section class="content_card">
                    <div>
                        <img src="card11.png"/>
                        <div class="category">photosho, design</div>
                    </div>
                    <div>
                        <h2>Dulux Colour Awards</h2>
                        <div>2023.12.01</div>
                        <div class="long_line"></div>
                        <p>
                            abcdefg abcd efg abcde fg abc defg abc defg
                            abcdefg abcd efg abcd efg abcdefg abcd efg
                            abc defg abc defg abcdefg abcdefg abcdefg
                        </p>
                        <div class="long_line"></div>
                        <div>Read on</div>
                    </div>
                </section>
            </div>
            <footer>
                <div class="short_line"></div>
                <ul>
                    <li><img src="icon1.png" /></li>
                    <li><img src="icon2.png" /></li>
                    <li><img src="icon3.png" /></li>
                    <li><img src="icon4.png" /></li>
                </ul>
                <div class="short_line"></div>
                <p>copyright</p>
            </footer>
        </div>
    </body>
</html>
```
