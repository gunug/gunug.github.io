---
layout: post
title: Comfyui
category: AI
tags: 
---

# Stability Matrix
<img style='border:solid 1px black;' src="https://image.onethelab.com/resized/1746233800.jpg" />

---

# Comfy ui 강제종료
1) 포트 번호를 사용하는 프로세스 찾기
```netstat -ano | findstr :8188```
마지막 열에 숫자가 있는데, 이게 PID입니다. 예를 들어 12345라면 다음과 같이 사용하세요.
2) PID로 프로세스 종료
```taskkill /PID 12345 /F```

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

---

# pytorch_lightning
* Installing required package: pytorch_lightning
```
F:
cd F:\StabilityMatrix\Packages\ComfyUI
.\venv\Scripts\activate
```

```
pip install pytorch_lightning
```

---

# diffusers
* Installing required package: diffusers
```
cd F:\StabilityMatrix\Packages\ComfyUI
.\venv\Scripts\activate
```

```
pip install diffusers
```

---

# 허깅페이스 업그레이드
```
pip install --upgrade huggingface_hub
pip install --upgrade diffusers
```

```
pip install insightface
```

```
pip install insightface decord ffmpeg-python av imageio[ffmpeg] onnxruntime
```