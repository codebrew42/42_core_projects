==for eval==

# what makes computer computer?
- OS
- CPU RAM Storage
- GPU NIC

# virtual machine
## basic
- put the computer in your computer
- free, anyone can do it
- only way to use Hypervisor
## ==purpose of using VM==
- to hack : using vm + vpn
- learn other operating sys
- break and build a new one
### ==How it works==


# ==.vdi file==
## def
- virtual disk image
	- file represents a virtual hard disk drive
	- used by VMs (oracle VM virtualbox)

# Hypervisor
## type 1
- installed straight onto the hardware
## type 2

# steps
- booting, keep pressing F12
- cpu config

## To use Linux Debian on Mac
- use a ver. of Debian compatible with the ARM architecture (ARM64, AArch64)
- so, u need Debian ARM64 Netinst ISO

### m1 chip
- based on ARM architecture
- so the std 64-bit AMD64 images won't work

## linux debian vs ubuntu 
### linux debian
- established: 1993
- focuses on free software, open-source principles
- known for its stability and robustness
- package management
	- uses APT package management system with '.deb' packaged
### ubuntu
- established: 2004, based on Debian
- user-friendly, accessible to all users
- regular releases every six months
- package management
	- also uses APT and '.deb', but has its own repositories

### hypervisor
- software
- virtualise the actual physical resources, mediate this with the VMs, in the middle
- can ctrl the hardware, so it offers virtual hardware and have diverse function in VMs

## ==operating system for server : centos vs debian==
### centos 
- for companies, uses RHEL(Red Hat Enterprise Linux)
### debian
- for individuals

## ==Debian : aptitude vs apt== (both for *package management*)
### apt (advanced packaging tool)
- command-line tool for handling package management
- package ctr tool for installing software prog-s
- free
- low level but flexible
- if progs- have conflits → -auto-remove ... option needed
### aptitude
- have *more functions* than apt
- high level package ctrl manager
- terminal based package manager 
- offering interactive interface for package management tasks (install, rm, ubgrads)

## ==debian: APPArmor==
- linux security module implemented in Debian to enforce MAC (mandatory access ctrl) policies
- restricting prog's actions to enhance security
- limiting privileges(sudo...) based on rules
- designed to complement traditional UNIX permissions

## basic commands

### systemctl restart ssh
- def: restart SSH service to apply changes
### systemctl status ssh
- def: check the SSH service is runnin without errors
### sudo ufw status 
- ensure that port 4242 is open and not blocked bz firewall on the virtual machine
- res : 
### su - ⇔ exit
- def : swtich to the root user → and then prompted by it
```sh
su -
fdisk -l
exit
```

### fdisk
- fdisk -l
- fdisk -l /dev/sda
- fdisk -lu /dev/sda
- fdisk -ls /dev/sda

### check partition (=list all block devices): lsblk
![[Pasted image 20240703171005.png]]
- bootloader is installed on sda1 as the assignment wants

### fine tuned command 1 : lsblk -o NAME,FSTYPE,SIZE,MOUNTPOINT
![[Pasted image 20240703173259.png]]
### fine-tuned command 2 : flblk -f -m
![[Pasted image 20240703172710.png]]

### lvs : disp logical volumes
![[Pasted image 20240703173919.png]]
### vgs: show the volum groups
![[Pasted image 20240703173923.png]]
### pvs : disp physical volumes
![[Pasted image 20240703173928.png]]
### visudo
![[Pasted image 20240705163953.png]]
- add secure_path=...
- add other policies
```
Defaults authfail_message="권한 획득 실패 메세지" 
Defaults badpass_message="비밀번호 틀릴때 메세지" 
Defaults iolog_dir="/var/log/sudo/" 
Defaults log_input 
Defaults log_output 
Defaults requiretty 
Defaults passwd_tries=
```

### usermod -aG sudo jieun
- put this user 'jieun' into the sudo group

### login jieun
- login as jieun
- execute sudo
### add user jiepark42 on vm
```
sudo adduser jiepark42
cat /etc/passwd | grep jiepark42 //verify
sudo usermod -aG sudo jiepark42 //give sudo privileges
sudo systemctl restart ssh //after making any changes to ssh config
```


### flags
- m : Show info about Linux permissions
- f : List info about Linux filesystems
- l : Force list format output option
- d : Avoid printing holders. In other words just see block device/disk names
- o NAME,FSTYPE,SIZE,MOUNTPOINT : Only display selected columns as per Table 1.





## creating partitions
- at this point, you might want to create 3 partitions in tool like cfdisk 
	1. 200-500M for /boot/efi (type EFI)
	2. 2 - 4G for swap (type SWAP)
	3. balance for / (type Linux Filesystem)

## prob

- chage -l new_jiepark
- → permission denied

## DHCP
dynamic Host Configuration Protocol

- Automatically assign IP adr and TCP/IP protocol's setting
## ip
### public ip
- unique
### private ip
- non-unique
- can be used on other private networks
- window terminal: ipconfig ⇔ mac : ifconfig
	- internal private IPv4 adr
- whatismyipaddress.com
	- ipv6
	- ipv4

# what to do step by step
