# 0. General instructions (O)
- signature.txt is present at the root of the repo
- identical to the ".vdi" of VM to be evaluated
- where is ".vdi" file located?
- as a precaution, copy VM for the next eval
	- ==born2beroot.vdi → born2beroot_cp.vdi(not to mess up)==
- start VM
# A. project overview(O)
- ## 1.==How VM works?==
	- you can have VM on your physical computer, as many as you want
	- can have thousands of them theorically
	- providing security, whatever damage it has, can just rm it
	- works like you are renting many computers
- ## 2. ==choich of OS in VM==
	- Linux
		- Unix-like OS developed by Linus Torvalds in 1991 as a open-source software
		- inspired by Unix
		- +: **open** resources, free, a lot of people workin on this resources, have communities
		- **numerous Linux distributions** tailored for diff purposes, preferences, ranging from desktops(Ubuntu, Fedora, Debian), servers(Red Hat Enterprise Linux, CentOs), embedded system(android)
	- Unix
		- OS developed **in 60-70s** at AT&T
		- portable, **multitasking, multi-user**
		- various standards bodies like IEEE, POSIX to maintain compatibility across diff Unix flavors
- ## 3. ==aptitude vs. apt==
	- both
		- **package managers**
			- package : progs put in computers, saving ur work
	- aptitude
		- nicer interface, more options
		- has cache?
	- apt
		- basic, low level
- ## 4. ==centOS vs. Debian==
	- centOS
		- supported by a large community
		- servers are hosted on CentOS
		- not support many diff architectures
		- **maintained for 10 years**, never changed except for security flaws or bugs new versions are released after long gap → **stable**
	- Debian
		- gets **updates** faster
		- easier GUI, desktop friendly
		- less market preference than centOS
		- **fast catching up**
		- has **more packages**
- ## 5. ==APParmor==
	- easy-to-use linux application secuirty system or module
	- protect OS and apps from ex/internal threats by enforcing good behavior and preventing app flaws from being exploited
	- allows administrator to **restrict the capabilities of a prog**
- ## 6. ==during this defence, check: if a script display info every 10 min==
	- script : on vm
	```vim
	**cd /var/spool/cron/crontabs → cat root**
	vim monitoring.sh
	ls cron*
	
	sudo service cron status
	sudo crontab -e
	```
		- in order to execute the script, use crontab
		- crontab = way to make script regularly with min/hour/day of month...
	- need to stress CPU? when CPU percentage is about 0
	```on terminal (do SSH and then)
	top 
	yes > /dev/null
	
	top -b -n 1
	top -b -n 2
	```
		- top = info about what's goin on on the computer,CPU,mem
# B. simple setup (O)
- ## 1. login to VM with passwd
- ## 2.start UFW service 
	- ufw
		- shows ports which are allowed, for webserver/fdp...
		- v6 : IPv6
	```c
	sudo ufw enable
	sudo ufw status numbered
	sudo ufw delete 3 //to delete unneccessary link
	```
	- port
		- 21 : protocol (TCP), service (FTP: File transfer protocol)
		- 8080 : protocol (TCP), service (http)
			- common alternative HTTP port for web traffic, 
			- used for HTTP Web proxies

- ## 3. check : SSH started?
- ## 4. ==check : Os is Debian or CentOS==
```c
lsb_release -a //option 1

cat /etc/os-release //option 2
```
- lsb = Linux Standard Base and Distribution info

# C. User (O)

## 1. check a user jiepark is added
```
who

id jiepark
output) uid=1002(fedor) gid=1002, 100(users), 1003(evaluating))
1002 = nbr of user
1002 ) nbr of group "user" = 100

ls -ln
ls -l

```
- list of users currently logged in

## 2. check if it's in the group sudo, user42 groups
```
getent group user42
getent group sudo
```
- see any user is added to the group
## 3. create a user and put it in a group → show one or two modified files
```
sudo adduer mario
sudo groupadd evaluating
sudo usermod -aG evaluating mario
getent group evaluating

//sudo groupdel evaluating //for rm
//sudo userdel -r jin


```
## 4. Q. advantage and disadvantage of using usergroup?
### advantage
- 1. simplified administration
	- allow admin to manage permissions for multiple users simultaneously
- 2. efficiency
	- instead of setting permissions individually, can create one group
- 3. enhanced security
	- controlled access
### disadvantage
- 1. complexity in large systems
	- in large organs, the nbr of groups can become very large
	- some systems allows "nested groups" which can complicate understanding permissions
- 2. potential for misconfiguration
	- users may be added or rm-ed from wrong groups, leading to inappropriate access wrights
## 5. Q. (1)how to set up rules requested in the subject on their VM? (password policies) (2)advantage of  it (3) + and - of its implementation

## pam = framework

```
sudo nano /etc/pam.d/common-password
sudo nano /etc/login.defs
```
### 5-1. how to set passwd policy ? config PAM
- install a package with framework
```
sudo apt-get install libpam-pwdquality
```
- config the PAM module
```
sudo nano /etc/pam.d/common-password
```
- update the line
```
password requisite pam_pwquality.so retry=3 minlen=8 dcredit=-1 ucredit=-1 ocredit=-1 lcredit=-1 
```
	-  `retry=3`: Number of attempts to enter a valid password.
    - `minlen=8`: Minimum password length.
    - `dcredit=-1`: Require at least one digit.
    - `ucredit=-1`: Require at least one uppercase letter.
    - `ocredit=-1`: Require at least one special character.
    - `lcredit=-1`: Require at least one lowercase letter.
- modify "/etc/login.defs/ to set passwd expiration policies
```
sudo nano /etc/login.defs

//content
    PASS_MAX_DAYS 90 PASS_MIN_DAYS 10 PASS_WARN_AGE 7
```
### 8-2. + of using password policy
- enhanced security
	- reduce risks of unauthrized access
- compliance 
	- helps in adhering to security std
- user accountability

**8-3. + and - of its implementation**
- advantages
	- improved security
	- meets industry std
- disadvantage
	- user frustration
	- requires administrative effort and resources
# D. Hostname and partitions (O)
## 1. check hostnames of the machine
```
hostnamectl

sudo hostname jiepark42 
```
## 2. modify the hostname(jiepark42)  & check if changed & reboot
```vm
//1.
sudo hostnamectl set-hostname mario
→ see if it's changed to 'mario42'

//2.reset to the original
sudo nano /etc/hostname
sudo nano /etc/hosts

hostnamectl 
sudo reboot
→ changed to 'jiepark42'
```
## 3. Q. how to view the partitions?
```
lsblk
```
- compare with the assignment's partition on pdf

# E. sudo (O)
### 4-1.  check if sudo is properly installed
```
su
```
### 4-2. assign new user to sudo
```
sudo adduser jin
sudo usermod -aG sudo jin
getent group sudo
```
### 4-3. Q. value and operations of using sudo?
- **value** 
	- 1. enhanced security
		- sudo allows users to perform tasks with root privileges without logging in as the root user
		- → minimizes risk of system compromise since users do not need to know root passwd (?)
	- 2. granular permissions
		- system admin can grant permissions to users, providing fine-grained ctr over user capabilities
	- 3. helps track user actions
		- → improves accountability, simplify troubleshooting
	- 4. reduces risk of mistakes
		- by requiring explicit use of sudo, it reduces chances of accidental execution of critical commands
- **operation**
	- **1. command execution**
	- example) updates package info with root privileges
		```
		sudo apt update
		```
	- **2.authentification**
	- example) this command would prompt for user's passwd
		```
		sudo apt install vim
		```
	- **3. authorization**
	- example) sudo checks '/etc/sudoers' file to verify if the user has permission to run the specified command, this command below allows to run any command as any user on any host
```/etc/sudoers
		username ALL=(ALL) ALL
```
### 4-4. verify "/var/log/sudo/" folder exists → check the contents, see a history of the commands used with sudo
```
cd /var/log/sudo
cat sudo_config


//sudo_log
cat sudo_logs
```

 
# E. Firewall : Ufw (O)
## 1. check "UFS" properly installed on VM
```
sudo ufw status

//alternative: iptables-save *just dspy
```
- res) status: active
## 1-2. Q. what is UFW, value of using it?
- **def**
	- UFS = **Uncomplicated FireWall**
	- **user-friendly** front-end for managing iptables firewall rules on Unix-like OS
	- simplifies process of config a firewall
- **purpose**
	- easy-to-use interface for config and **managing firewall**
- **what it does**
	- **allows user to enable/disable firewall**
	- **allow/deny network traffic** based on IP adr, port, protocol
	- set up firewall rules for incoming/outgoing traffic
- **value**
	- 1. **simplicity** : straitforward command-lin interface
	- 2. **ease of management** : simplify common firewall tasks such as allowing/blocking ports, enabling/disabling firewall, setting policies... 
	- 3. **security** : UFW encoruages more usres to implement and maintain effective firewall reuls, enhancing overall system security
## 1-3. list active rules in UFW, A rule must exist for port 4242
```
sudo ufw status
```
- res) status: active

## 1-4. add a new rule to open port 8080, delete this
```
sudo ufw allow 8080
sudo ufw status numbered
sudo ufw delete 5(nbr to rm)
```
- res) status: active
# F. ssh (O)
## 1. check: ssh installed?
```
jiepark@localhost -p 4243
```
## 2. Q. what's SSH? value of using it?
- ssh
	- secure shell
	- **network protocol** used for **securely accessing and managing remote systems** 
	- provicdes secure, encrypted connection btw two computers(server=remote machine, client=local machine)
- value of using SSH
	- security
		- encrypts all data transmitted including passwords, data, commands...
	- strong authentication method
		- reducing risk of unauthorized access
	- remote access
		- from anywhere with network connectivitiy

## 3. check: SSH uses only port 4242
```
cd /etc/ssh
vim sshd_config
vim ssh_config

netstat -tuln //option 1
```
- -t : TCP connection
- -u: UDP connection
- -l : only listening sockets
- -n: numerical add instead of resolving hostnames
```
ss -tuln //option 2
lsof -i -P
```
- ss = socket statistics
- isof : list open files
	- -i : list internet (IPv4, IPv6)
	- -p : show port numbers

## 4. use SSH using new user, use a key or passwd, cannot use SSH with the root user, of course.
```
mario@localhost -p 4242
```

# G. script monitoring (O)
 
 - ## 1. how the scripts works? showing the code → monitoring.ssh

- ## 2. cron?
	- cron
		- unix utility allowing tasks (cron jobs) to be executed at specified times or intervals
		- runs in the background as a daemon
	- crontab = cron table
		- file that specifies the schedule of cron jobs
		- each user has their own crontab, system has a system-wide crontab

# H. Bonus (?)
## 1. setting up partitions
## 2. setting up wordpress
## 3. free choice service : FTP? and explain (NGINX, APAChe2 prohibited)



## ssh
- 22 by default

## wall
- not just for disp
- man wall
- write a mesg to all users