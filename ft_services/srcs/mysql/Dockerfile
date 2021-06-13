# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:48:35 by faysal            #+#    #+#              #
#    Updated: 2021/06/13 15:41:39 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine

LABEL maintainer="fbougama@student.42.fr"

RUN apk update && apk add openrc --no-cache mysql mysql-client

COPY srcs /srcs

EXPOSE 3306

ENTRYPOINT sh srcs/entrypoint.sh