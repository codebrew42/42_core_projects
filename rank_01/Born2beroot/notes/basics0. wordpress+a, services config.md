
# lighttpd
- web server designed to be fast, secure, flexible...
- optimizes env, it consumes less CPU, RAM...
- download
```
sudo apt install lighttpd
```
- allow connections through port 80
```
sudo ufw allow 80
sudo ufw status //check
```
- add port in Network-setting, Port
# wordpress
- download wget and zip first
```
sudo apt install wget zip
```
	- wget : for downloading files from the web
- cd /var/www/
- download latest ver of wrodpress → unzip → rename → give permission
```
sudo wget https://en-gb.wordpress.org/latest-en_GB.zip
sudo unzip latest-en_GB.zip
sudo mv html/ html_old
sudo mv wordpress/ html
sudo chmod -R 755 html
```

# mariadb
- download
```
sudo apt install mariadb-server
```
- use a script provided by mariadb-server package to restrict access to the server and rm unused accounts
```
sudo mysql_secure_installation
```
- check : access mariadb
```su
mariadb

//can see, u r accessing mariadb
```

- create database for Wordpress 
```
CREATE DATABASE wp_database;

//wp_database: 아무이름임
//output) query OK, 1 row affected

```
- → show database
```
SHOW DAATABASES;
```
- create a user inside the database 
  → bind the new user to our database 
  → update permissions for the changes to take affect 
```
CREATE USER 'pingoo'@'localhost' IDENTIFIED BY '12345';
//output) query OK, 0 rows affected

GRANT ALL PRIVILEGES ON wp_database.* TO 'pingoo'@'localhost';
//output) query OK, 0 rows affected

FLUSH PRIVILEGES;
//output) query OK, 0 rows affected
```
- then exit
```
exit
```
# php
- php
	- progr- language to develop dynamic web app and interactive websites
	- PHP runs on the server side
- install necessary packages
```
sudo apt install php-cgi php-mysql
```
# wordpress config
```
cd /var/www/html

cp wp-config-sample.php wp-config.php

nano wp-config.php
```

- change content
	- name of database: 'DB_NAME', 'wp_database'
	- database username: 'DB_USER', 'pingoo'
	- database passwd: 'DB_PASSWORD', '12345'
- enable fastcgi-php module in Lighttpd to improve speed and performance of web app on the server → update apply change
```
sudo lighty-enable-mod fastcgi-php

sudo service lighttpd force-reload
//shows nothing
```

# wordpress 접속
```terminal
ssh jiepark@localhost -p 2424
```

```web
localhost:8080
localhost:8080/wp-admin
```
