---
layout: post
title: Ubontu Kernel panic 우분투 커널 패닉
category: server
tags: 
---


# Ubontu Kernel panic 우분투 커널 패닉

* https://cloud.google.com/compute/docs/troubleshooting/kernel-panic?hl=ko
* end Kernel panic - not syncing: Attemped to kill init! exit

---

## 발생원인
* 커널에 해당하는 initramfs 파일과 관련된 항목은 grub.cfg 파일에 존재하지 않습니다.
* initramfs 파일은 커널 설치 중에 /boot 디렉터리에 생성되지 않습니다.
* initramfs 파일이 부분적으로 생성되거나 손상되었습니다.

---

* 참고링크 : https://askubuntu.com/questions/898449/kernel-panic-and-unable-to-boot-ubuntu-16-04-after-updating
* 시스템을 완전히 끄십시오. 
* 시스템을 다시 켜십시오.
* 시스템 제조 로고 또는 부팅 메시지 직후 Shift를 눌러 Grub 옵션으로 이동합니다. 또는 전원 버튼으로 시스템을 강제 종료하고 다시 켜면 Grub 메뉴가 나타납니다.
* Ubuntu의 고급 옵션을 선택하십시오.
* 시스템에 설치된 커널 목록과 함께 선택 메뉴가 나타나야 합니다. 최신 커널의 버전 번호(일반적으로 첫 번째 커널)를 기록해 두십시오. 이전 커널의 복구 옵션(일반적으로 첫 번째 커널보다 버전 번호가 낮은 커널)을 선택하십시오. 네 번째 네 번째 옵션).
* 다른 옵션 목록이 나타나야 합니다. root를 선택합니다. 루트 쉘 옵션으로 드롭합니다. 루트 계정 비밀번호를 설정한 경우 여기에 해당 비밀번호를 입력하고 그렇지 않으면 Enter를 누릅니다.
* 다음 명령을 실행합니다.

```
mount -o remount,rw /
mkinitramfs -o /boot/initrd.img-{kerner_version}-generic {kernel_version}-generic
update-grub
```
* 여기서 {Kernel_version}은 5단계(문제가 있는 커널, 최근 설치된 커널)에서 기록한 커널 버전 번호입니다.
* 시스템을 재부팅하면 모든 준비가 완료되어 작업을 계속할 수 있습니다. 도움이 되길 바랍니다.
* root 억세스를 선택하라는데 선택창 없이 부팅중 kernel panic으로 이어짐

---

## Grub
* 참고링크: https://blog.neonkid.xyz/225
* ```grub> set```

### 수동부팅
* ```grub> ls ```
* ```grub> ls (hd0,gpt1)/boot``` 해당 파티션에 부트용 커널 이미지들이 들어있는지 확인
* ```grub> set root=(hd0,gpt1)``` 커널 이미지가 있다면 루트를 변경
* ```grub> linux /boot/vmlinuz root=/dev/nvme0n1p1``` 리눅스의 커널 이미지 경로를 linux 명령어로 넣어주고, 최상위 마운트 경로가 있는  dev경로 입력
* 만약 경로가 잘못되면 리눅스가 제대로 부팅되지 않고, busybox가 실행됨
* ```grub> initrd /boot/initrd.img``` 리욱스 실제 루트 파일 시스템 마운트를 위하여, 초기 마운트 파일 시스템 이미지 경로를 정해줌
* ```grub> boot``` 시스템 부팅

---

### 커멘드 입력중 오류가 있어서 다른 버전
* insmod linux
* linux /vmlinuz root=/dev/sda2
* initrd /initrd.img
* boot
  
### 수행결과
* Begin: Running /script/local-block ... mdadm: CREATE group disk not found\
* no arrays found in config file or automatically
* BusyBox v1.22.1
* 이거 나온거 보니 리눅스가 부팅되지 않고 busybox가 실행된 상황인듯
* /dev/sda2 does not exist.


---

# BusyBox
* 참고링크 : https://velog.io/@reveloper-1311/%EC%9A%B0%EB%B6%84%ED%88%AC-%EB%B6%80%ED%8C%85%EC%97%90%EB%9F%AC-initramfs
* Busybox: 우분투 복구모드로 간단한 명령어로 OS의 불량이나 오류 부분을 고칠 수 있다.
* initramfs: 명령어를 입력할 수 있는 프롬프트
* reboot(전체 시스템 재부팅), exit(busybox 재시도) 명령어 등으로 재부팅


* linux /vmlinuz root=/dev/ram0
* initrd /boot/initrd.img-4.4.0-62-generic

---

## Kernel panic - not syncing: Attempted to kill init!
* https://mapoo.net/os/oslinux/kernel-panic-not-syncing-attempted-to-kill-init/
* 읽어봄직한 자료 : https://velog.io/@markyang92/boot-loader-grub
* https://conory.com/blog/43204
  
---

## /boot/grub/grub.cfg
* ```cat /boot/grub/grub.cfg``` 명령으로 파일내용 열람 가능
