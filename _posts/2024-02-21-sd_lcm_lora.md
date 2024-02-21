---
layout: post
title: lcm lora 초고속
category: stable-diffusion
tags: 
---

* 참고자료: https://www.internetmap.kr/entry/LCM-LoRA-very-fast-stable-diffusion
* sd1.5 : https://huggingface.co/latent-consistency/lcm-lora-sdv1-5/blob/main/pytorch_lora_weights.safetensors
* ComfyUI/models/lora에 파일 옮기기

![image](https://github.com/gunug/gunug.github.io/assets/52345276/0721819a-8311-4b10-86bd-4c1d51e15e59)

* steps - 일반적으로 20~25 정도로 설정하지만, LCM에서는 4~8 단계 정도면 충분합니다.
* CFG - 일반적으로 7을 사용하지만, LCM에서는 2 이하로 낮은 밗으로 설정합니다.
* Sampler-name - lcm 으로 설정합니다.
* Scheduler - 스케줄러도 sgm_uniform으로 설정해야 한답니다.

