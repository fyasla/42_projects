#!/bin/bash

echo "running start.sh ..."

#Autoindex
if [ $AUTOINDEX = "on" ]
then
        mv /nginx-conf/localhost_on /nginx-conf/localhost
		rm /nginx-conf/localhost_off
elif [ $AUTOINDEX = "off" ]
then
        mv /nginx-conf/localhost_off /nginx-conf/localhost
		rm /nginx-conf/localhost_on
else
	echo "A wrong value of AUTOINDEX has been given, it has been set to off"
fi

#nginx config
mv /localhost /var/www/
cd /var/www/localhost
tar -zxvf latest.tar.gz
rm latest.tar.gz
mv /wp-config.php /var/www/localhost/wordpress
tar -zxvf phpMyAdmin.tar.gz
rm phpMyAdmin.tar.gz
mv /var/www/localhost/phpMyAdmin-4.9.0.1-all-languages/ /var/www/localhost/phpMyAdmin
mv /config.inc.php /var/www/localhost/phpMyAdmin
mv /nginx-conf/localhost /etc/nginx/sites-available
ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
rm /etc/nginx/sites-enabled/default /etc/nginx/sites-available/default
echo "nginx config done"

#mysql config
service mysql start
echo "CREATE DATABASE wordpress DEFAULT CHARACTER SET utf8 COLLATE utf8_unicode_ci;" | mysql
echo "GRANT ALL ON wordpress.* TO 'wordpressuser'@'localhost' IDENTIFIED BY 'password';" | mysql
echo "FLUSH PRIVILEGES;" | mysql
echo "exit" | mysql
cd /
mysql wordpress -u root < wordpress.sql
echo "mysql config done"

#SSL
cd /ssl
./mkcert -install
./mkcert localhost 127.0.0.1

echo "SSL certificate and key created"

chown -R www-data:www-data /var/www/localhost

#launch services
service nginx restart
/etc/init.d/php7.3-fpm start

echo "FINISHED ! You can visit : https://localhost"

echo "The autoindex is ${AUTOINDEX}"

#To avoid container stopping
tail -f /dev/null