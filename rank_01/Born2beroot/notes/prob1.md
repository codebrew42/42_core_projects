# case 1.  kex_exchange_identification: connection closed by remote host / connection closed by 127.0.0.1 port 4242

## 배울 것
- 127.0.0.1의 의미
- 포트포워딩은 뭘 하나
- 포트는 무엇?
- 호스트? 게[스트?]
- the fact that "ftpkg server (type psauxww|grep ftpkg) runs on localhost:4242"

## 체크 할 것
- (vm을 대상으로 ssh하는 상황이라면)
- : 호스트 pc의 ssh서버가 몇 번 포트에 열려있는지 확인
- 내가 설정한 vm안의 424포트가 열려있나? 
- 그 포트에 뭐가 돌아가고 있나?
- vm에 sshd가 켜져 잇는지 확인
- sshd_conf 파일 설정에 포트가 명시되어 있는지 확인
- 방화벽이나 selinux 설정 확인 (설정이 어려우면 관련 서비스 모두 비활시키고 테스트)
- hosts.allow hosts.deny 파일 설정 확인
- 보안 서비스 설치되어 있는지 확인
- check network connectivity
- verify ssh client config
- verify ssh server config
- try a diff encryption algorithm

### check network connectivity
```
ping localhost
ping 127.0.0.1
```

### check firewall settings
```
sudo iptables -L -n
sudo iptables -A INPUT -p tcp --dport 4242 -j ACCEPT //if neccessary
```

### rm known_hosts
```
cd cd .ssh/ 
rm -r known_hosts
```



## 중요
- 호스트 pc의 4242포트가 사용중인지 아닌지는 vm의 ssh서버가 4242포트로 열려있고 그에 접속하는데는 상관이 없다

## 가능한 해결책
### 1. using bridge adapter and VMs Ip
- instead of NAT with forwarding
### 2. using another port 

### 3. .ssh 디렉토리에서 .known_hosts ? 날리기