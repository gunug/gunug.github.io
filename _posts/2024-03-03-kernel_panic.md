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
* http://coffeenix.net/board_view.php?cata_code=109&bd_code=1697&bpage=
  
---

* 읽어봄직한 자료 : https://velog.io/@markyang92/boot-loader-grub

---

# vultr에서 제공하는 kernal panic 관련 자료
* https://docs.vultr.com/recovering-from-a-kernel-panic-using-a-custom-iso
* https://docs.vultr.com/troubleshoot-your-vps-with-bootable-isos

1. 스냅샷을 떠놓는다
2. Server Infomation > Settings > custom ISO > SystemRescue x64 > Attach ISO and Reboot
   1. Boot SystemRescue default option - apt 명령을 사용할 수 없었음.
   2. installed operation system - 부팅이 아닌 뭔가 다른 화면이 나옴.
   3. copy image to ram - apt 명령을 사용할 수 없었음.
* https://help.ubuntu.com/community/Boot-Repair

```

sudo apt install apt
sudo apt-get install software-properties-common

locate apt-get
```

```
sudo add-apt-repository ppa:yannubuntu/boot-repair && sudo apt update
sudo apt install -y boot-repair && boot-repair
```

1. Server Infomation > Settings > custom ISO > Remove ISO

---

## 우분투에서 yum을 사용하려 하였습니다.
* https://raspberrytips.com/use-yum-on-ubuntu/
* 시스템을 손상시킬수 있다고 하네..
* https://www.redhat.com/sysadmin/linux-kernel-panic
* cd /boot
* uname -r
* 5.15.43-1-lts 결과
* dracut -f /boot/initramfs-5.15.43-1-lts.img 5.15.43-1-lts - dracut 명령을 사용할 수 없었음

---

# 여러가지 명령어
* ```fdisk -l``` boot가 들어있는 경로명 확인
* lsblk -o PATH,FSTYPE,MOUNTPOINT 경로명
* 타입이 일단 ext4로 나옴
* 디스크 이름은 /dev/vda1

---
## /boot/grub/grub.cfg
* ```cat /boot/grub/grub.cfg``` 명령으로 파일내용 열람 가능

---

## 리눅스 부팅과정
* https://mapoo.net/os/oslinux/%EB%A6%AC%EB%88%85%EC%8A%A4-%EB%B6%80%ED%8C%85-%EA%B3%BC%EC%A0%95%EA%B3%BC-%EC%BB%A4%EB%84%90-%ED%8C%A8%EB%8B%89-%EC%A1%B0%EC%B9%98%EC%9A%94%EB%A0%B9/

1. 전원 ON
1. BIOS 프로그램 실행
  - CPU, MEMORY, VGA 같은 하드웨어에 대한 진단 테스트(POST) - 이상 발생시 비프 음을 내며 멈춤
  - POST(Power On Self Test)과정이 이상없이 수행되면 부트디바이스의 MBR(하드 디스크의 첫 섹터,크기는 512 byte)에서 부트로더를 로딩
1. 부트로더가 실행되면 레드햇계열에서는 보통 다음과 같은 메시지가 출력되며 GRUB(GRUB이 부트로더이다)이 실행됨
1. GRUB은 커널이미지를 메모리에 로드
1. Booting Red Hat Enterprise Linux Server (2.6.18-8.el5) in 5 seconds…
1. 커널에 의한 초기화
1. 드라이버의 적재 (이 과정은 dmesg명령이나 /var/log/dmesg 파일에서 다음의 내용 확인가능)
  - 커널버전 표시
  - 램 용량 표시
  - CPU관련 정보 표시
  - SELinux 상태 표시
  - Kernel command line 명령 확인
  - 램디스크 할당 (initramfs)
  - 하드드라이브와 파티션 확인
  - 네트워크 카드 확인
  - 파일시스템 활성화
  - 스왑 활성화
1. 커널과 드라이버가 로드된 다음에는 /sbin/init 프로세스가 부팅 과정을 마무리
  - /sbin/init à /etc/inittab
  - /etc/rc.d/rc.sysinit
  - 각 런 레벨 서비스 스크립트
  - /etc/rc.local
  - 로그인 프롬프트
