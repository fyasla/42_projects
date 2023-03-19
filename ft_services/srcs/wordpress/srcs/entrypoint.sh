#!/bin/sh

#nginx setup
adduser -D -g 'www' www && \
mkdir /www && \
mv /srcs/index.html /www/index.html && \
chown -R www:www /var/lib/nginx && \
mkdir -p /run/nginx


#install wp
wget http://wordpress.org/latest.tar.gz
tar -xzvf latest.tar.gz
rm latest.tar.gz
mv wordpress /www/
chown -R www:www /www 

rm /etc/nginx/nginx.conf
mv /srcs/nginx.conf /etc/nginx/nginx.conf

openrc
touch /run/openrc/softlevel