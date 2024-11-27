# step 1. getting ready
## 1-0.download sudo
1. download iso
2. on VM:  login → install & reboot sudo
```	
su
apt install sudo
sudo reboot
```
2. check if sudo have been installed correctly
		1. switch to root user → sudo -V or sudo -V > file.txt (create file.txt with the result, in case its too large)
```
 sudo version 1.9.13p3
 sudoers policy plugin ver 1.9.13p3
 sudoers file grammar ver 50
 sudoers I/O pligin
 sudoers audit plugin ...
 ```

## 1-1.manage users
1. in the root user : sudo adduser jiepark
```
the user 'jiepark' already exists (if it exists) → step 2
if jiepark is not in the sudoers file → login as root user
```
2. (step 2) login as a root user →  sudo visudo (might not neccessary)
```
#user privilege specification
root ALL=(ALL:ALL) ALL

# allow members of group sudo to execute any commend
%sudo  ALL=(ALL:ALL) ALL
jiepark ALL=(ALL) NOPASSWD:ALL //not to ask passwd
```
3. create a group, add jiepark to sudo and user42, check
```
sudo addgroup user42 

sudo adduser jiepark sudo //include the user 
sudo adduser jiepark user42 

 getent group user42
  getent group sudo
```
### gid (group)
- group identifier

## 1-2. Installing and configuring SSH
### steps

```
sudo apt update
sudo apt install openssh-server //2.
sudo service ssh status //3
```
-  //2. install main tool for remote access with the SSH protocol, using OpenSSH
- //3. install was ok? check

## 1-3. download additional apps
- download vim : sudo apt install vim

## 1-4. edit file two config-docu
- vim /etc/ssh/sshd_config
```
Port 4242
PermitRootLogin no
```
- vim /etc/ssh/ssh_config
```
Port 4242 //in the middle
PermitRootLogin no
```
## 1-5. restart : sudo service ssh restart → sudo service ssh status
```
listening to port 4242 //check
:: port 4242 //check
```

## step 2. install and configure UFW
### ufw
- firewall uses command for setting up iptables using a small nbr of easy command
- iptable 
	- user-space utility prog allowing a system administrator to configure IP packet filter rules of Linux kernel firewall, implemented as diff netfilter modules.
	- must be executed bz user root
	- installed as /usr/sbin/iptables and its man pages
	  or /sbin/iptables
### steps 2-1. download
```
sudo apt install ufw
sudo ufw enable //show us the firewall is active
sudo ufw allow 4242 //allow firewall to accept connections on 4242 port
sudo ufw status (numbered) //check everything
```


## step 3. set up sudo policies && strong passwd policy
### 3-1. edit config
- cd ~
- touch /etc/sudoers.d/sudo_config
- mkdir /var/log/sudo  //each commands need to be logged (input/output)
- nano /etc/sudoers.d/sudo_config : type
```
Defaults passwd_tries=3
...
Defautls...
```


### 3-2. password policy set-up
- nano /etc/login.defs
```
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2

```
- sudo apt install libpam-pwquality //new package 
- nano /etc/pam.d/common-password
```
retry=3 minlen=10 ucredit=-1 dcredit=-1 lcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root

```
### 3-3. passwd history check
- sudo chage -l jiepark
- sudo chage -l root
 ```
min, max days btw passwd change : still default 
```
- //we create these users before we create the passwd policy
- so change:
   sudo chage -M 30 root
    sudo chage -m 2 root
   sudo chage -l root
- maybe with jiepark too
## step 4. connect via ssh
### 4-1. port setting
- close the machine 
- go to settings : port 4242 - 4242

### 4-2. if error: changing host port : 4242→4243
lsof ui : 4242
curl localhost:4242
//can see some words: ftpkg-srv%
→ can see the port is already being used, but cannot inspect (lsof ui)
→ anyway we should use another host port1

assignment want us to use internal side(guest port) of 4242
external side(host port) is egal

### 4-3. connect via ssh
open VM and then login, and then try SSH on the terminal
```
ssh jiepark@localhost -p 4242
```

