
crontab
- background process manager

to configure crontab
```
sudo crontab -u root -e
```
→ add the line at the end : */10 * * * * sh /home/jiepark/monitoring.sh


after editing everything
- obtain signature!
	- steps
		- 1. shut down VM (once u turn on or modify, signature will be changed)
		- 2. go to the dir, where .vdi locates
			- /sgoinfre/Perso/jiepark... ?
		- 3. run this command to get signature
 ```
shasum Born2beroot.vdi
```
			- then, result will be added to signature.txt