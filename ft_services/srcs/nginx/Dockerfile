# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 20:37:51 by faysal            #+#    #+#              #
#    Updated: 2021/06/12 21:30:09 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine

LABEL maintainer="fbougama@student.42.fr"

RUN apk update && apk add openrc --no-cache nginx

COPY srcs /srcs

ENTRYPOINT sh /srcs/entrypoint.sh

EXPOSE 80 443 22