---
layout: post
title: 2023년 2학기 웹 퍼블리싱
category: education
tags: kaywon education
---

# 2023년 2학기 웹 퍼블리싱

# 1주차

* [2023년도 학과 수칙 및 수업진행 방식](/subpage/2023/09/07/education-rule.html){:target="_blank"}
* [오리엔테이션](/subpage/2023/09/07/webpublishing-week1.html){:target="_blank"}

---

# 2주차

## 이론

* [www 월드 와이드 웹](/web/2023/09/15/www.html)
* [HTML HyperText Markup Language](/web/2023/09/15/hypertext-markup-language.html)

## 실습

* [HTML](/web/2023/08/22/html.html)
* [HTML tag](/web/2023/09/14/html-tag.html)

---

# 3주차
* 사전진단평가
* 지하철 이용증빙(교통카드 사용내역)
* 지하철 지급 증빙서류(지연 확인서)
* 이미지 파일로 메일(gunug@naver.com)발송, 반학번이름 필히 기제
* 전자출결에서 9월 15일 지각 -> 출석 신청 (4개 전부다 신청해야 합니다)
* 다음 수업일(10월 6일) 일괄 승인 할 예정 입니다.

## 이론
* [웹 표준](/web/2023/09/21/web-standards.html)
* [웹 접근성](/web/2023/09/21/web-accessibility.html)

## 실습
* [HTML tag](/web/2023/09/14/html-tag.html)

---

# 4주차
* 추석연휴로 인한 공강

---

# 5주차
* 전자출결 수정

## 이론
* [크로스 브라우징](/web/2023/10/05/web_cross_browsing.html)
* [XHTML](/web/2023/10/05/xhtml.html)

## 실습
* [HTML tag](/web/2023/09/14/html-tag.html)
* [form tag 양식 태그](/web/2023/09/25/html_form_tag.html)
* [HTML5 Media tag](/web/2023/10/06/hmtl5-media-tag.html)

---

# 8주차 - 중간평가
* [중간평가 유의사항](/subpage/2023/10/06/2023-2-middle-test.html)

```html
<!DOCTYPE html> <!-- 문서유형 -->
<html>
    <head> <!-- 머릿말 -->
        <title>0000의 홈페이지</title>
        <meta charset="utf-8" /> <!-- utf-8, euc-kr -->
        <meta name="keywords" content="웹퍼블리싱, 계원, html, css" />
    </head>
    <body> <!-- 본문 -->
        <a href="sub.html" target="_blank">서브페이지</a> <!-- 서브페이지 이동 -->
        <a href="http://www.naver.com">네이버</a>
        <a href="https://cafe.naver.com/kwdmd" target="_blank">계원디미디카페</a>

        <img width="100px" height="auto" src="https://upload.wikimedia.org/wikipedia/commons/1/18/Dog_Breeds.jpg" />
        <img width="100px" height="auto" src="image/Dog_Breeds.jpg" />

        <a href="http://www.naver.com"><img width="100px" height="auto" src="image/Dog_Breeds.jpg" /></a>

        <시작태그>
        </종료태그>
        <독립형태그 />
        
        <시작태그 속성="값">내용</종료태그>
        <독립형태그 속성="값" />
        
        <!-- h1 ~ h6 -->
        <hr />
        <h1>대한민국</h1>
            아시아의 한 국가이다
            <h2>서울특별시</h2>
                <h3>영등포구</h3>
            <h2>경기도</h2>
                <h3>의왕시</h3>
                <h3>안양시</h3>
        <hr />
        <h1>미국</h1>
        <h1>일본</h1>

        <p>
            단어가 모여서 문장, 문장이 모여서 문단
            한가지 주제를 가지고 있는 문장의 집합
        </p>
        
        HTML은         띄여쓰기, 
        <br /> 줄바꿈을 무시한다

        <hr />

        <strong>강한 강조</strong>
        <em>강조</em>
        <!-- 의미를 부여함 (사용 권장) -->

        <b>굵은 글씨</b>
        <i>기울임 (이텔릭체)</i>
        <!-- 모양을 부여함 (사용 비권장)-->

        <ins>추가 글</ins>
        <del>삭제 글</del>
        <!-- 의미를 부여 -->

        <u>밑 줄</u>
        <strike>가운데 줄</strike>
        <!-- 모양을 부여 -->

        윗첨자<sup>추가되는 설명을 위에 표시</sup>
        아랫첨자<sub>추가되는 설명을 아래에 표시</sub>

        <ul>
            <li>리스트1</li>
            <li>리스트2</li>
            <li>리스트2</li>
        </ul>
        <ol>
            <li>리스트1</li>
            <li>리스트2</li>
            <li>리스트2</li>
        </ol>
        <dl>
            <dt>용어</dt>
            <dd>용어에 대한 설명</dd>
            <dt>HTML</dt>
            <dd>Hyper Text Markup Language</dd>
        </dl>

        <style>
            th, td{
                border: solid 1px black;
            }
        </style>
        <table summary="table 기초">
            <caption>테이블 기초</caption>
            <tr> <!-- row 행 줄-->
                <th scope="col" rowspan="2">제목1</th> <!-- table header-->
                <th scope="col" colspan="2">제목2</th> <!-- colum 열 칸 -->
                <th scope="col">제목3</th>
            </tr>
            <tr>
                <td>내용1</td>
                <td>내용2</td>
                <td>내용3</td>
            </tr>
            <thead>표제목</thead>
            <tbody>표본문</tbody>
            <tfoot>표끝</tfoot>
        </table>

        <div>블록(block)형 구획 나누기</div>
        <span>인라인(inline)형 구획 나누기</span>
        <!-- 의미 없이 사용하기 좋은 태그 -->

        <form>
            <label for="name_1">아이디</label>
            <input name="name_1" type="text" placeholder="-기호없이 숫자만 입력" />
            <input type="password" />

            <input type="radio" name="p1" checked/>사과
            <input type="radio" name="p1" />배
            <input type="radio" name="p1" />딸기
            
            <input type="checkbox" />가을
            <input type="checkbox" />겨울
            <input type="checkbox" />봄

            <select> <!-- select box, combo box-->
                <option>네이버</option>
                <option>구글</option>
                <option>계원</option>
            </select>

            <textarea rows="10" cols="60">내용</textarea>

            <input onclick="alert('버튼클릭');" type="button" value="버튼입니다" />
            <button>
                <strong>
                    <del>
                        버튼입니다
                    </del>
                </strong>
            </button>

            <input type="submit" value="제출" />
        </form>
    </body>
</html>

```
