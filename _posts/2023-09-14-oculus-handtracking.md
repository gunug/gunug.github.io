---
layout: post
title: oculus hand tracking 오큘러스 핸드 트래킹
category: vr
tags: vr oculus
---
* [공식문서](https://developer.oculus.com/documentation/unity/unity-isdk-hand-pose-detection/#shape-recognition)
* Pose Use Sample 에서 Poses(ActiveStateSelector)를 등록
* Shape Recognizer Active State 컴퍼넌트에 Shapes(ShapeRecognizer)를 등록하여 특정 손모양을 검사가능
    * curl : 두 관절을 모두 접음
    * flexion : 손바닥쪽 관절만 접음
    * abduction : 손가락과 손가락 사이를 벌림
    * opposition : 손가락과 손가락을 맞닿음
* Transform Recognizer Active State 컴퍼넌트에 Transform Feature Configs에 손방향을 추가할 수 있음
