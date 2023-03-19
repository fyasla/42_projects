#!/bin/sh

mv /srcs/nginx.conf /etc/nginx/nginx.conf

adduser -D -g 'www' www && \
mkdir /www && \
mv /srcs/index.html /www/index.html && \
chown -R www:www /var/lib/nginx && \
chown -R www:www /www && \
mkdir -p /run/nginx

nginx -g 'daemon off;'