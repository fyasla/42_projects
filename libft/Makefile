# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 15:32:20 by fbougama          #+#    #+#              #
#    Updated: 2019/10/12 16:23:40 by fbougama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = split

SRC = ft_split.c split_main.c

all : $(NAME)

$(NAME) :
	gcc -o $(NAME) $(SRC)

clean :
	/bin/rm -f *.o

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all