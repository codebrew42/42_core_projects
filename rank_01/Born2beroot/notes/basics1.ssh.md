## install
```
su - 
apt install openssh-server
vim /etc/ssh/sshd_config
#Port 22 → Port 4242 (edit)
#PermitRootLogin prohibit-password → PermitRootLogin no(edit)
systemctl restart ssh
systemctl status ssh
hostname -I (check: ip of vm)
```
## next step
```
login to VM
setting : adapter 1, adapter 2 (bridged adapter + physical network interface: eno1, wlan0)
ssh jiepark@127.0.0.1
→ permission denied
→ vim /etc/ssh/sshd_config
: PasswordAuthentification yes
: PermitRootLogin yes
→ sudo passwd -S jiepark //check account status
//jiepark P 2024-07-03 0 99999 7 -1
→ sudo ufw status
//status: inactive = desirable
→ sudo ufw status //no firewall blocking SSH connection

```

## check enp0s3 ip in VM
```
su - 
ip addr show
//enp0s3 inet : 10.0.2.15/24 brd 10.0.2.255

```


### hostname -I → Guest IP for Port forwarding rules
```
10.0.2.15
```

after checking, power off VM, tools → network
```
c4b2c6% ifconfig
docker0: flags=4099<UP,BROADCAST,MULTICAST>  mtu 1500
        inet 172.17.0.1  netmask 255.255.0.0  broadcast 172.17.255.255
        ether 02:42:1c:d1:bd:fb  txqueuelen 0  (Ethernet)
        RX packets 0  bytes 0 (0.0 B)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 0  bytes 0 (0.0 B)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0

eno2: flags=4163<UP,BROADCAST,RUNNING,MULTICAST>  mtu 1500
        inet 10.15.102.6  netmask 255.255.0.0  broadcast 10.15.255.255
        inet6 fe80::928d:6eff:fe60:d308  prefixlen 64  scopeid 0x20<link>
        ether 90:8d:6e:60:d3:08  txqueuelen 1000  (Ethernet)
        RX packets 611425  bytes 571369738 (571.3 MB)
        RX errors 0  dropped 5  overruns 0  frame 0
        TX packets 1430383  bytes 1936249048 (1.9 GB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
        device interrupt 20  memory 0xe4400000-e4420000  

lo: flags=73<UP,LOOPBACK,RUNNING>  mtu 65536
        inet 127.0.0.1  netmask 255.0.0.0
        inet6 ::1  prefixlen 128  scopeid 0x10<host>
        loop  txqueuelen 1000  (Local Loopback)
        RX packets 4069  bytes 410281 (410.2 KB)
        RX errors 0  dropped 0  overruns 0  frame 0
        TX packets 4069  bytes 410281 (410.2 KB)
        TX errors 0  dropped 0 overruns 0  carrier 0  collisions 0
```
- **explanation by chatgpt**
	- The output displays information about the network interfaces on a Unix-like system. There are three different network interfaces listed: `docker0`, `eno2`, and `lo`. Each serves a distinct purpose:
	1. **docker0**:
	   - **Type**: Virtual network interface created by Docker.
	   - **Purpose**: Acts as a bridge for Docker containers to communicate with each other and the host machine. It *assigns private IP addresses from a private subnet* (in this case, 172.17.0.1/16).
	   - **Details**:
	     - `inet` shows the IPv4 address: 172.17.0.1.
	     - `netmask` is 255.255.0.0, indicating a /16 subnet.
	     - `ether` shows the MAC address: 02:42:1c:d1:bd:fb.
	     - No traffic has passed through this interface as RX and TX packets and bytes are all zero.
	
	2. **eno2**:
	   - **Type**: Physical Ethernet network interface.
	   - **Purpose**: Connects the machine to a physical network. This interface is used for general network communication.
	   - **Details**:
	     - `inet` shows the IPv4 address: 10.15.102.6.
	     - `netmask` is 255.255.0.0, indicating a /16 subnet.
	     - `inet6` shows the IPv6 address: fe80::928d:6eff:fe60:d308.
	     - `ether` shows the MAC address: 90:8d:6e:60:d3:08.
	     - The interface is active, as indicated by the number of RX and TX packets and bytes (571.3 MB received, 1.9 GB transmitted).
	
	3. **lo (Loopback interface)**:
	   - **Type**: Logical network interface.
	   - **Purpose**: Used for internal communication within the host. Any traffic sent to this interface is looped back to the same machine.
	   - **Details**:
	     - `inet` shows the IPv4 address: 127.0.0.1.
	     - `netmask` is 255.0.0.0, indicating a /8 subnet.
	     - `inet6` shows the IPv6 address: ::1.
	     - No MAC address is associated with this interface as it's purely virtual.
	     - The interface has traffic, indicating some local processes are communicating over the loopback interface (410.2 KB both received and transmitted).
	
	### Summary:
	- **docker0** is a virtual interface used by Docker for container networking.
	- **eno2** is a physical network interface used for regular network communication.
	- **lo** is the loopback interface for internal communication within the host system. 

## when setting the host ip for port forwarding setup
### localhost (127.0.0.1)
- if u want t o access the VM locally from the host machine, you can use 127.0.0.1 as the Host IP
- 127.0.0.1 = std IPv4 adr for the loopback interface
- used for...
	- self communication
		- allow system to send/receive network traffic to itself
		- by establishing an IP connection to the same machine or computer that is used by the end-user.
		- useful for testing and development purposes
	- not reachable externally
		- this adr is not routable on the internet or across other networks.
		- only accessible from the local machine
![[Pasted image 20240705171311.png]]
### loopback interface
- allows a computer to communicate with itself over a network protocol
### host machine's network IP
- if u want to acces the VM from other devices on the same network as the host machine, you should use the IP adr assigned to the host machine on that network
- ifconfig(linux/mac), ipconfig(window)
### host's public IP
- if u want to access VM from the internet, you might need to use the public IP adr of the host machine. ensure that the network setup (router coonfig.) allow for this kind of access