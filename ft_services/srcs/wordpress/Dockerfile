# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/12 21:30:16 by faysal            #+#    #+#              #
#    Updated: 2021/06/14 00:55:29 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine

LABEL maintainer="fbougama@student.42.fr"

RUN apk update && apk add php-fpm php7-common php7-iconv       \
    php7-json php7-gd php7-curl php7-openssl php7-xml php7-mysqli php7-pdo      \
    php7-pdo_mysql php7-soap php7-xmlrpc php7-mcrypt php7-gettext php7-ctype    \ 
    php7-dom php7 php7-phar openrc --no-cache nginx

COPY srcs /srcs

EXPOSE 5050