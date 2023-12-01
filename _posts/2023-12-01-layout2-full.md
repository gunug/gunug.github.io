---
layout: post
title: layout2 레이아웃2
category: subpage
tags: 
---

<!DOCTYPE html>
<html>
    <head>
        <title>layout2</title>
        <meta charset="utf-8" />
        <style>
            #wrap{
                min-width : 1000px;
                
                margin: 0px auto;
            }
            header{
                display: flex;
                justify-content: space-between;
                background-color:rgb(10, 202, 125);
                color: white;
                padding: 10px 50px;
            }
            header ul{
                list-style: none;
                display: flex;
            }
            header li{
                flex-grow:1;
                padding: 0px 10px; /*간격 띄우기*/
            }
            header h1{
                margin: 4px 0px;
            }
            header h1 span{
                color: rgb(211, 211, 6);
            }
            #main_visual{
                background-image: url("main_visual.png");
                padding: 100px;
                color: white;
                text-align: center;
                background-size: 100px auto;
                background-repeat: no-repeat;
                background-color: black;
                background-position: 50% 50%;
                background-size: contain; /* 담기도록 */
                background-size: cover; /* 씌워지도록 */
            }
            #main_visual h2{
                font-size: 40px;
                letter-spacing: 20px;
                margin: 0px;
            }
            #main_visual p{
                margin: 0px;
            }
            .button{
                background-color: rgb(173, 173, 0);
                display: inline-block;
                padding: 5px 30px;
                color: black;
                margin-top: 100px;
            }
            section{
                text-align: center;
            }
            section h3{
                color: rgb(3, 151, 77);
                font-size: 30px;
            }
            #content1{
                padding: 80px;
            }
            #content1 ul{
                display: flex;
                list-style: none;
                padding: 0px;
                margin-top: 100px;
            }
            #content1 li{
                flex:1;
                border-right: solid 1px gray;
                padding: 50px;
            }
            #content1 li:last-child{
                border: none;
            }
            #content1 dd{
                margin: 0px;
            }
            #content2 ul{
                display: flex;
                flex-direction: row;
                flex-wrap: wrap; 
                /* 유연-줄바꿈 : 줄바꿈 하기 */
                list-style: none;
                padding: 0px;
                margin-top: 100px;
            }
            #content2 li{
                width: 25%; /* 넓이를 1/4로 */
                /* 들어갈 수 있는 공간을 100%로 봤을때 */
            }
            #content2 li img{
                width: 100%; /* 들어갈 수 있는 공간의 100% */
                display: block; 
            }
        </style>
    </head>
    <body>
        <div id="wrap">
            <header>
                <h1>MY<span>FOLIO</span></h1>
                <ul>
                    <li>HOME</li>
                    <li>ABOUT ME</li>
                    <li>SERVICE</li>
                    <li>MY WORK</li>
                    <li>CONTACT ME</li>
                </ul>
            </header>
            <div id="main_visual">
                <p>Lorem ipsum dolor sit iusmod tempor</p>
                <h2>incididunt bore</h2>
                <p>Orem ipsum dolor sit amet, consectetur</p>
                
                <div class="button">KNOW MORE</div>
            </div>
            <section id="content1">
                <h3>ABOUT ME</h3>
                <p>
                    abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg
                    abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg
                    abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg
                    abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg abcdefg
                </p>
                <ul>
                    <li>
                        <img src="icon1.png" />
                        <dl>
                            <dt>Title goes here</dt>
                            <dd>
                                onsectetur adipisicing elit, sedo eiusmod tempor 
                                incidi et dolorerserss eerhfre mag.
                            </dd>
                        </dl>
                    </li>
                    <li>
                        <img src="icon2.png" />
                        <dl>
                            <dt>Title goes here</dt>
                            <dd>
                                onsectetur adipisicing elit, sedo eiusmod tempor 
                                incidi et dolorerserss eerhfre mag.
                            </dd>
                        </dl>
                    </li>
                    <li>
                        <img src="icon3.png" />
                        <dl>
                            <dt>Title goes here</dt>
                            <dd>
                                onsectetur adipisicing elit, sedo eiusmod tempor 
                                incidi et dolorerserss eerhfre mag.
                            </dd>
                        </dl>
                    </li>
                    <li>
                        <img src="icon4.png" />
                        <dl>
                            <dt>Title goes here</dt>
                            <dd>
                                onsectetur adipisicing elit, sedo eiusmod tempor 
                                incidi et dolorerserss eerhfre mag.
                            </dd>
                        </dl>
                    </li>
                </ul>
            </section>
            <section id="content2">
                <h3>MY WORK</h3>
                <p>
                    Lorem ipsum dolor sit amet, consectetur adipisicing elit, 
                    sed do eiusmod tempor <br /> incididunt ut labore et dolore magna 
                    aliqua.
                </p>
                <ul>
                    <li><img src="work1.png" /></li>
                    <li><img src="work2.png" /></li>
                    <li><img src="work3.png" /></li>
                    <li><img src="work4.png" /></li>
                    <li><img src="work5.png" /></li>
                    <li><img src="work6.png" /></li>
                    <li><img src="work7.png" /></li>
                    <li><img src="work8.png" /></li>
                </ul>
            </section>
        </div>
    </body>
</html>
