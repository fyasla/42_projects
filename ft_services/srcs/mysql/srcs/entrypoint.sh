#!/bin/sh

#Update mysql configuration
rm -rf /etc/my.conf.d /etc/my.conf
mv /srcs/my.cnf /etc/my.conf
mv /srcs/my.cnf.d /etc/my.cnf.D

#Start mysql
openrc
touch /run/openrc/softlevel
rc-service mariadb setup
rc-service mariadb start

#Crate Wordpress db
# mysql << EOF 
# CREATE DATABASE IF NOT EXISTS $WP_DB_NAME;
# CREATE USER '$WP_USER'@'%' IDENTIFIED BY '$PASSWORD';
# GRANT ALL ON $WP_DB_NAME.* TO '$WP_USER'@'%' IDENTIFIED BY '$PASSWORD' WITH GRANT OPTION;
# FLUSH PRIVILEGES;
# EOF