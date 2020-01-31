# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/31 17:43:33 by fbougama          #+#    #+#              #
#    Updated: 2020/01/31 18:09:10 by fbougama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 14:25:15 by fbougama          #+#    #+#              #
#    Updated: 2019/12/21 23:39:42 by fbougama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	parsing_test

LIBS		=	libftprintf.a

SRCS 		=	../src/parsing/parse_1.c ../src/parsing/parse_2.c \
				../src/parsing/parsing_utils.c ../src/parsing/parsing_utils2.c \
				../src/parsing/parsing_utils3.c ../src/parsing/initiate_scene.c \
				../src/parsing/map_parse.c ../src/parsing/get_next_line_utils.c \
				../tests/src/parsing_display.c \
				../src/parsing/get_next_line.c ../tests/src/parsing_test.c

OBJS		=	$(SRCS:%.c=%.o)

CC			=	gcc

CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBS)
			@$(CC) -o $(NAME) $(OBJS) $(LIBS)

$(LIBS)	:
	cd ../libs/ft_printf && make && make clean && mv $(LIBS) ../../tests

%.o				:	%.c
					$(CC) $(FLAGS) -o $@ -c $<

clean	:
			$(RM) $(OBJS) $(LIBS)

fclean	: 	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re