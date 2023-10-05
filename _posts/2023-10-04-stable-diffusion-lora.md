---
layout: post
title: Stable diffusion lora 스테이블 디퓨젼 로라
category: stable-diffusion
tags: ai
---

# LoRA(Low-rank Adaptation)

* [참고링크](https://www.hayo.com/article/64107dacb847f9412b5a257f)

## 이미지 자료 준비
1. 이미지구하기
1. 512 * 512로 자르기 (768 * 768 시도)
1. Train > Preprocess Image
1. 소스 디렉터리 입력
1. 데스티네이션 디렉터리 입력
1. Create flipped copies 체크
1. Use BLIP for caption : 실사를 위한
1. Use deepbooru for caption : 애니메이션 캐릭터를 위한
1. Preprocess 클릭후 몇 분간 기다리기
* 이후 데스티네이션 디렉토리에 각 그림과 단어 txt가 포함됨
* 태그를 자동 생성해주는 기능으로 수동태그는 직접 넣어야 할수도

---

# LoRA Easy Training Scripts
* LoRA Easy Training Scripts는 Linux와 Windows에서 모두 사용할 수 있는 Python 프로그램입니다. 다음은 Linux를 예로 들어 설명합니다.

## 설치
* [LoRA_Easy_Training_Scripts](https://github.com/derrian-distro/LoRA_Easy_Training_Scripts)

```markdown
git clone https://github.com/derrian-distro/LoRA_Easy_Training_Scripts
cd LoRA_Easy_Training_Scripts
install.bat
```