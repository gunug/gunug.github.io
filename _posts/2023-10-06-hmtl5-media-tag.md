---
layout: post
title: html5 media tag 미디어 태그
category: web
tags: kaywon web
---

# html5 media tag 미디어 태그

## canvas
* canvas는 기본적으로 300px * 150px의 사이즈를 가지고 있습니다. CSS로 이를 조정할 경우 비율이나 크기가 틀어질 수 있습니다.

```html
  <style type="text/css">
      #myCanvas{
          height: 300px;
          width: 300px;
      }
  </style>
  <canvas id="myCanvas"></canvas>
  
  <script>
    var canvas = document.getElementById("myCanvas"); //myCanvas라는 이름의 canvas element를 받아옵니다.
    var ctx = canvas.getContext("2d"); //2D canvas를 생성합니다.
    ctx.fillStyle = "#FF0000"; //색을 지정합니다.
    
    ctx.fillRect(25, 25, 100, 100); //채움 사각형
    ctx.clearRect(45, 45, 60, 60); //사각형태로 지우기
    ctx.strokeRect(50, 50, 50, 50); //윤곽 사각형
    
    ctx.fillStyle = "#000000";
    ctx.beginPath(); //선그리기 시작
    ctx.moveTo(65, 75); //펜 들어 움직이기
    ctx.lineTo(90, 95); //선 그으며 움직이기
    ctx.lineTo(90, 55);
    ctx.fill(); //내부 채우기
    
    ctx.beginPath();
    ctx.arc(225, 75, 50, 0, Math.PI * 2, true); // Outer circle 
    ctx.moveTo(260, 75);
    ctx.arc(225, 75, 35, 0, Math.PI, false);  // Mouth (clockwise)
    ctx.moveTo(215, 65);
    ctx.arc(210, 65, 5, 0, Math.PI * 2, true);  // Left eye
    ctx.moveTo(245, 65);
    ctx.arc(240, 65, 5, 0, Math.PI * 2, true);  // Right eye
    ctx.stroke();
  </script>
```

## audio
* 샘플 : [https://file-examples.com/index.php/sample-audio-files/](https://file-examples.com/index.php/sample-audio-files/)
* mp3, ogg, wav같은 소리파일 재생용 tag

```html
  <audio controls autoplay> <!-- autoplay : 자동재생 -->
  <audio controls>
    <source src="horse.ogg" type="audio/ogg">
    <source src="horse.mp3" type="audio/mpeg">
    Your browser does not support the audio element.
  </audio>
```
* 업데이트된 내용은 https://www.w3schools.com/tags/tag_audio.asp 에서 확인

## mime type
* MP3 : audio/mpeg
* OGG : audio/ogg
* WAV : audio/wav

## 크롬 자동재생 문제
* audio troubleshooting : http://html5doctor.com/multimedia-troubleshooting/
* chrome에서 autoplay가 되지 않음 : https://stackoverflow.com/questions/50490304/audio-autoplay-not-working-in-chrome
* Google Chrome에서 정책이 변경되어 muted 되어 있지 않은 동영상은 자동재생 되지 않음

```html
  <head>
    <script>
      window.onload = function() {
        var context = new AudioContext();
      }
    </script>
  </head>
  Than this will work as you want:
  
  <audio autoplay>
        <source src="hal_9000_sorry_dave.mp3">
  </audio>
```
## video
* 샘플 : https://file-examples.com/index.php/sample-video-files/
* mp4, webm, ogg 등의 비디오 파일 재생용 tag

```html
  <video width="320" height="240" controls>
    <source src="movie.mp4" type="video/mp4">
    <source src="movie.ogg" type="video/ogg">
    Your browser does not support the video tag.
  </video>

```
## 지원 확장자 및 코덱
* MP4 = MPEG 4 files with H264 video codec and AAC audio codec
* WebM = WebM files with VP8 video codec and Vorbis audio codec
* Ogg = Ogg files with Theora video codec and Vorbis audio codec

* 업데이트된 내용은 https://www.w3schools.com/tags/tag_video.asp 에서 확인

## mime type
* MP4 : video/mp4
* WebM : video/webm
* Ogg : video/ogg

## track
```html
  <video width="320" height="240" controls>
    <source src="forrest_gump.mp4" type="video/mp4">
    <source src="forrest_gump.ogg" type="video/ogg">
    <track src="subtitles_en.vtt" kind="subtitles" srclang="en" label="English">
    <track src="subtitles_no.vtt" kind="subtitles" srclang="no" label="Norwegian">
  </video>
```
*동영상 및 오디오 자료출처 : https://www.sample-videos.com/
