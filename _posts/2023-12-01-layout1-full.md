---
layout: post
title: layout1 레이아웃1
category: subpage
tags: 
---


```html
<!DOCTYPE html>
<html>
    <head>
        <title>layout1</title>
        <meta charset="utf-8" />
        <style>
            #wrap ul{}
            #wrap>header>ul{}
            #wrap{
                min-width: 1000px;
                max-width: 1920px;
                margin: 0px auto;
            }
            header ul{
                list-style: none;
                display: flex;
                padding: 0px;
            }
            header li{
                padding: 0px 10px; /* 상하 좌우 */
                border-right: solid 1px gray;
            }
            header li:last-child{
                border: none;
            }
            header{
                display: flex;
                justify-content: space-between;
                padding: 5px 50px;
            }
            header h1{
                margin: 0px;
            }
            header img{
                display: block;
            }
            header>div>img{
                margin: 15px 0px; 
            }
            nav ul{
                list-style: none;
                display: flex;
            }
            nav li{
                padding: 0px 10px;
            }
            nav {
                display: flex;
                justify-content: space-between;
                background-color: lightgray;
                padding: 5px 50px;
            }
            nav h2{
                margin: 9px 0px;
            }
            #content>section>div{
                display: flex;
                justify-content: center;
            }
            #content dt{
                font-weight: bold;
            }
            #content dd{
                margin: 0px;
            }
            .container{
                margin: 0px 10px;
            }
            #content>section:nth-child(1){background-color: #98f;}
            #content>section:nth-child(2){background-color: #5d9;}
            #content>section:nth-child(3){background-color: #f76;}
            #content>section:nth-child(4){background-color: #ec5;}
            h3{
                margin: 0px;
                padding-bottom: 40px;
                color: white;
                font-weight: normal;
            }
            section{
                padding: 50px;
            }
            footer ul{
                list-style: none;
                display: flex;
                padding : 0px;
            }
            footer ul li{
                padding: 0px 5px;
            }
            footer div:first-child li{
                border-right: solid 1px lightgray;
            }
            footer div:first-child li:last-child{
                border: none;
            }
            footer{
                display: flex;
                justify-content: space-between;
                background-color: #333;
                color: white;
                padding: 50px;
            }
        </style>
    </head>
    <body>
        <div id="wrap">
            <header>
                <h1><img src="logo.png" /></h1>
                <ul>
                    <li>ABOUT</li>
                    <li>SERVICES</li>
                    <li>WORK</li>
                    <li>BLOG</li>
                    <li>CONTACT US</li>
                </ul>
                <div><img src="zoom.png" /></div>
            </header>
            <nav>
                <h2>See Our Works</h2>
                <ul>
                    <li>web designs</li>
                    <li>icons</li>
                    <li>web designs</li>
                    <li>web designs</li>
                </ul>
                <div></div>
            </nav>
            <div id="content">
                <section>
                    <h3>Web Design</h3>
                    <div>
                        <div class="container">
                            <img src="img1.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                        <div class="container">
                            <img src="img2.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                    </div>
                </section>
                <section>
                    <h3>Web Design</h3>
                    <div>
                        <div class="container">
                            <img src="img3.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                        <div class="container">
                            <img src="img4.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                    </div>
                </section>
                <section>
                    <h3>Web Design</h3>
                    <div>
                        <div class="container">
                            <img src="img5.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                        <div class="container">
                            <img src="img6.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                    </div>
                </section>
                <section>
                    <h3>Web Design</h3>
                    <div>
                        <div class="container">
                            <img src="img7.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                        <div class="container">
                            <img src="img8.png" />
                            <dl>
                                <dt>프로젝트 제목</dt>
                                <dd>프로젝트 내용</dd>
                            </dl>
                        </div>
                    </div>
                </section>
            </div>
            <footer>
                <div>
                    <ul>
                        <li>home</li>
                        <li>about</li>
                        <li>services</li>
                        <li>work</li>
                        <li>blog</li>
                        <li>contact us</li>
                    </ul>
                    <p>copyright</p>
                    <p>discription</p>
                </div>
                <div>
                    <ul>
                        <li><img src="icon1.png"/></li>
                        <li><img src="icon2.png"/></li>
                        <li><img src="icon3.png"/></li>
                        <li><img src="icon4.png"/></li>
                        <li><img src="icon5.png"/></li>
                        <li><img src="icon6.png"/></li>
                    </ul>
                </div>
            </footer>
        </div>
    </body>
</html>
```
