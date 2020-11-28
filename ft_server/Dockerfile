FROM debian:buster-slim

LABEL maintainer="fbougama@student.42.fr"

ENV AUTOINDEX="on"

RUN apt-get -y update && apt-get -y install \
#install nginx
nginx \ 
#install mariadb
mariadb-server \
#install php
php-fpm \
php-mysql \
#wordpress
php-curl \
php-gd \
php-intl \
php-mbstring \
php-soap \
php-xml \
php-xmlrpc \
php-zip \
#phpmyadmin
php-json \
php-mbstring

EXPOSE 443 80

COPY srcs ./
ENTRYPOINT [ "bash", "start.sh" ]