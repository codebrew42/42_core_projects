
# result
``` sh monitoring.sh
1. Architecture:
2. CPU physical:
3. vCPU:
4. Memory Usage:
5. CPU load:
6. Last boot:
7. LVM use:
8. Connections TCP:
9. User log:
10. Network:
11. Sudo:
```


## 1. architecture of OS
```
uname -a (=--all)

//output: Linux jiepark42 6.1.0-22-amd64 #1 SMP PREEMPT_DYNAMIC Debian ... x86_64 GNU/Linux
```
- show the architecture of operating system
## 2. CPU physical
```
grep "physical id" /proc/cpuinfo | wc -l
```
- show info on physical cores on the system
## 3. CPU virtual
```
grep "processor" /proc/cpuinfo | wc -l
grep processor /proc/cpuinfo | wc -l //same as above
```
- nbr of virtual cores
- ### 참고. nbr of physical cores from "/proc/cpuinfo"
```
cat /proc/cpuinfo
//res: image1 below

grep "physical id" /proc/cpuinfo
//physical id : 0

grep "physical id" /proc/cpuinfo | wc -l
//output: 1
```
- cat /proc/cpuinfo
	- image1) don't need all of this res, we will get some part ![[Pasted image 20240708141155.png]]
- wc -l
	- word count : count nbr of words in the input it receives
- Q. what is the meaning of get the nbr of the line?   1개 있다는 뜻인듯..? ![[Pasted image 20240708142147.png]]

## 4. RAM total, RAM used, RAM percent
### used memory (RAM mem) - comp with 2-1
```
free -m | awk '$1 == "Mem:" {print $3}'
free --mega | awk '$1 == "Mem:" {print $3}'
//output) 219 
```

###  total memory (RAM mem) - comp with 2-2
```
free -m | awk '$1 == "Mem:" {print $2}'
free --mega | awk '$1 == "Mem:" {print $2}'
//output) 219 
```
- free, free -k
	- shows mem in kibibytes(KiB)
	- 1 KiB = 1024 bytes ![[Pasted image 20240708143726.png]]
- free m ⇔ free --mega
	- show system's mem(RAM) usage (total, used, free, shared, buff/cache, available)
	- --mega : to show mem in MB
	- results can be diff, idk why.
		- pos reason: depends on how they calculate ![[Pasted image 20240708144043.png]]
- awk
	- powerful text-processing language, used for **pattern scanning and processing**
	- it processes the input
-  '$1 == "MEM:" {print $3}'
	- awk script that processes each line of the output
	-  '$1 == "MEM:"
		- checks if the first filed (column) is "MEM:"  ("MEM" = wrong)
		- $1 = 1st column of the current line
	-  {print $3}
		- if condition is true, print the 3rd column of that line ![[Pasted image 20240708143215.png]]


# 5. DISK total, used, percent

```
df
df -m
```
- df -m
	- generates **list of all mounted filesystems and their disk usage** in MB![[Pasted image 20240708144600.png]]
		- **udev**
			- device manager for Linux curnal
			- dynamically creats/rm device node files in /dev
			- allows system to recognize and configure devices like USB driver, printer,... as they're connected or disconnected
		- **tmpfs**
			- temporary filesystem
			- stores files in virtual mem (RAM)
			- data in tmpfs is temporary and only exists in RAM, doesn't persist after a reboot
			- useful for files like in /tmp or /run
		- **dir**
			- **1. /dev**
				- contains device files in Linux and Unix-like OS
				- not regular files but represent hardware/virtual devices
				- **1-1.strage devices**
					- /dev/sda1
						- 1st partition on the 1st disk
						- trd'l disk-based filesystem mounted at the root(/)
						- ext4 filesystem in many cases, but not always
					- /dev/sda
						- 1st SCSI or SATA disk
					- /dev/sdb
						- 2nd disk
				- **1-2.terminals and consoles**
					- /dev/tty
						- cntr'lling terminal for the current process
					- /dev/tty0
						- current virtual console
				- **1-3.other devices**
					- /dev/null
						- discards all data written to it, provides end-of-file on read
					- /dev/random
						- provides random data
				- **1-4.**shared mem
					- /dev/shm
					- **shared mem** for inter-process communication
			- **2. /boot**
				- files needed to boot Linux OS
					- Kernel images
						- vmlinuz-...-generic
					- initial Ramdisk (initrd/initramfs)
						- initrd.img-...-generic
					- bootloader config files
						- grub.cf
			- **3. /run**
				- store **runtime data** used by processes since the system boot
				- used as tmpfs (temporary filesystem)
				- one of the 1st filesystems to be mounted during the boot process
				- **3-1. /run/lock**
					- store **lock files** which helps preventing concurrent access to resources
				- **3-2. /run/user**
					- subdir for each user named by their user ID(UID)
				- **3-3. /run/user/1000**
					- temp files for user with UID 1000
				- **3-4. /run/systemd**
					- used by init system (systemd) for various runtime data
				- **3-5. /run/network**
					- runtime data related to network management
				- **3-6. /run/udev**
					- used by udev(device manager) for runtime data related to device management
### 2-1. obtain memory_use
```
df
df -m //in MB
df -m | grep "/dev/" | grep -v "/boot" | awk '{memory_use += $3} END {print memory_use}'
```
- **df command**
	- disk filesystem
	- complete summary of the use of disk space ![[Pasted image 20240706182130.png]]
- **grep**
	- filters the output to include only lines contiaing "/dev/"
	- which correspond to actual disk partitions and not special pseudo filesystems
	- only physical and logical disk partitions are included
- **grep -v "/boot"**
	- "grep -v" **inverts** the match, meaning it excludes lines that contain "/boot"
	- to exclude /boot partition from the res
- **after processing all lines,** awk prints the total used space ![[Pasted image 20240706182549.png]]
### 2-2. obtain total space
```
def -m | grep "/dev/" | grep -v "/boot" | awk '{res += $2} END {printf("%.0fGb\n"), res/1024}'
```
- ![[Pasted image 20240706183259.png]]
### 2-3. percentage of used memory
```
df -m | grep "/dev/" | grep -v "/boot" | awk '{use += $3} {total += $2} END {printf ("(%d%%)\n"), use/total*100}'

10% //output
```
### 2-1 ~ 2-3. obtain : used mem , total mem, percentage of used (used/total*100)
- ![[Pasted image 20240708152231.png]]
- %.0f = %d%\% : 바꿔도 똑같음
### 3. see partitions
```
lsblk
```


# 6. CPU load
## 6-1. CPU idle time 
```
cpu_idletiem = $(vmstat 1 2 | tail -1 | awk '{print $15}')
```
### 1. vmstat 1 4
- a snapshot of system performance metrics at regular intervals (4 iterations per 1 sec)
- each line represents : snapshot at a particular moment including matrics like CPU usage, mem usage, IO activity, ...
- useful for monitoring system performances, identifying bottlenecks, troubleshooting issues ![[Pasted image 20240708153510.png]]
### 2. tail -1
- takes the last line of the output from 'vmstat' command
### 3. awk '{print $15}'
- extracts 15th field from that last line, corresponds to **the CPU idle time percentage**
### CPU idle time percentage
- portion of time the CPU spends waiting for tasks to be dispatched to it
- during this time, cpu is not performing any useful work and is effectively idle
- CPU가 작업을 기다리거나 아무 작업을 수행하지 않고 놀고 있는 시간, 즉 비활성 상태 시간의 비율
- higher CPU idle time percentage : the CPU is underutilized
- lower : higher utilization or busyness of the CPU, overloaded, potentially causing performance degradation or bottlenecks
- for example: %id = 80%
	- CPU was idle and not executing tasks approximately 80% of the time
	- only 20% of the time, cpu actively performing computations or handling tasks
- importance
	- fundamental for maintaining optimal system performance, ensuring efficient resource utilization in computing env
## 6-2. CPU usage percentage : subtract idle time from 100
```
cpu_usage= $((100 - cpu_idletime)
```
## 6-3. formatting CPU usage percentage to one decimal place
```
printf "%.1f" $cpu_usage
```


# 7. Last boot ; time of last system boot (who = info about users)
```
who -b | awk '$1 == "system" {print $3 " " $4}'

2024-07-06 18:16 //output
```
- to see **date and time of our last restart** : who -b
- who : Print information about users who are currently logged in.  
		- ![[Pasted image 20240708155811.png]]
	- flags
	       -a, --all  
	              same as -b -d --login -p -r -t -T -u  
	       -b, --boot  
	              **time of last system boot**  
	       -d, --dead  
	              print dead processes  
	       -H, --heading  
	              print line of column headings  
	       --ips  print  ips  instead  of  hostnames. with --lookup, canonicalizes  
	              based on stored IP, if available, rather than stored hostname  
	       -l, --login  
	              print system login processes  
	       --lookup  
	              attempt to canon
	              icalize hostnames via DNS  
# 8. LVM use
```
if [ $(lsblk | grep "lvm" | wc -l) -gt 0 ]; then echo yes; else echo no; fi

//meaning) if there are any LVM devices(category: TYPE) listed by 'lsblk', the output : yes, else : no
```
## 0. lsblk
![[Screenshot 2024-07-11 at 15.52.15.png]]

## 1. if [ $(...) -gt 0 ]; then ...; else ...; fi
- 띄어쓰기 조심 ![[Pasted image 20240708162745.png]]
- -gt 3 : output == no
## 2. lvm
- **def**
	- Local Volume Manager
	- allows for flexible partitioning of hard drives or other storage devices
	- it abstracts physical storage into logical volumes
- **purpose**
	- provides **way to create virtualized partitions** that can span across multiple physical disks
	- allowing for flexible storage management, resizing of volumes, and snapshots which are useful for tasks like backup and system recovery
- **components**
	- PVs: physical volumes
	- VGs: volume groups
	- LVs: logical volums
### 1-2. lsblk
- lists **info about block devices** in a tree-like format
	- **block devices**
		- def
			- type of storage device that stores data in fixed-size blocks or sectors
		- usage
			- used for persistent strage where data needs to be stored reliably and accessed efficiently
		- examples
			- HDDs, SSDs: hard drives
			- USB drivers
			- CD-ROMs
			- LVM volumes
### 1-3. $(...) : command substitution
- runs commands inside () and replace $() with their output
### 1-4. -gt 0
- checks if it is greater than 0
## lsblk, Partitioning, LVM info
- partitioning
	- sr0 : 
		- 1st optical disc drive detected by the system
		- sr : SCSI read-only
		- /dev/sr0 : entire optical drive
	- sda :
		- 1st SCSI(or SATA) disk drive in the system
		- partitions : sda1, sda2...
	  

# 9. TCP connections
```
ss -ta | grep ESTAB | wc -l
```
## res1: before ssh on VM
- grep ESTAB : shows no result ![[Pasted image 20240708190306.png]]
## res2: after ssh on VM
- grep ESTAB : shows result ![[Pasted image 20240708190312.png]]
## ss -ta
- ss : investigate sockets, check nbr of established TCP connections
- -t : only output to TCP sockets
- -a : all sockets (listening and non-listening)
## socket
- def
	- endpoint for sending/receiving data across a comp. network
	- represents communication channel btw two entities such as btw a client and server
	- allows for network communication using protocools(TCP, UDP)
- key aspects
	- IP adr: identifies the host
	- Port Nbr: identifies specific app/service on the host
## **TCP**
- def
	- transmission ctrl protocol
	- core protocol of the internet protocol suite
	- provides reliable, ordered, error-checked delivery of data btw app-s runing on hosts in a network
- key aspects
	- reliable 
		- ensures data is delivered in order
	- connection-oriented
		- requires connection to be established btw two endpoints before data transfer
	- detects errors and request retransmission
	- manages data flow → efficient transfer
- used for
	- web browsing(HTTP(s)), emails(SMTP, IMAP), FTP: file transfers, ...
### 2-3. grep ESTAB
- only include lines containing "**ESTAB**" which means "established TCP connections"
### 2-4. wc -l
- give nbr of TCP connections

# 10. user log

```
users | wc -w
// nbr of users check
```
- wc -c
	- count nbr of words in the command output ![[Pasted image 20240708191642.png]]

#  11. Network
```
ip = $(hostname -I)
mac = $(ip link | grep "link/ether" | awk '{print $2}') 
...
Network: IP $ip ($mac)
```
- ip
	- ret IP adr assigned to the host
- mac
	- ip link
		- dsp info about all network interfaces
	- "link/ether"
		- corresponds to the lines showing MAC adr
# 12. Sudo
```
cmd = $(journalctl _COMM=sudo | grep "COMMAND=" | wc -l)

//counting lines that log executed commands
```
- journalctl _COMM=sudo
	- retrieves log entries related to the sudo command from the syst journal
- grep "COMMAND="
	- filters to include only those contain the word COMMAND
- 
