---
layout: post
title: Comfyui 에러들
category: AI
tags: 
---

# Comfyui 에러들
## custom_nodes
### ComfyUI-VideoHelperSuite
#### opencv 설치
* venv 활성화 : (터미널에서) ```F:\StabilityMatrix\Packages\ComfyUI\venv\Scripts\activate```
* 성공시 : (venv) F:\StabilityMatrix\Packages\ComfyUI>
* 비활성화 : ```deactivate```
* ```pip install opencv-python``` opencv 설치하기
#### imageio_ffmpeg 설치
* ```pip install imageio-ffmpeg```
  
### ComfyUI-LatentSync-Node
#### omegaconf 설치
* ```pip install antlr4-python3-runtime==4.9.3```
* venv 활성화 : (터미널에서) ```F:\StabilityMatrix\Packages\ComfyUI\venv\Scripts\activate```
* ```pip install omegaconf```
* https://pypi.org/project/antlr4-python3-runtime/4.9.3/#files 에서

### ComfyUI-LatentSyncWrapper
* https://github.com/ShmuelRonen/ComfyUI-LatentSyncWrapper
* custom_node 폴더에 ```git clone https://github.com/ShmuelRonen/ComfyUI-LatentSyncWrapper```

## 랜더링중 ffmpeg not found 에러
* https://ffmpeg.org/download.html
* 빌드 버전을 다운로드후 압축풀고 위치를 옮김
* bin 폴더 경로(예: C:\ffmpeg\bin)를 Path에 추가
* 제어판 → 시스템 → 고급 시스템 설정 → 환경 변수 → Path에 FFmpeg의 bin 폴더 경로를 추가.
* CMD(명령 프롬프트)에서 ```ffmpeg -version```입력 시 버전 정보 나오면 정상!