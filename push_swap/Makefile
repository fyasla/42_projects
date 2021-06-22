# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 12:50:16 by fbougama          #+#    #+#              #
#    Updated: 2021/06/22 18:57:13 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	srcs/check_input.c srcs/main.c

OBJS	=	$(SRCS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIB		=	libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIB)
		$(CC) -o $(NAME) $(FLAGS)  $(OBJS) $(LIB)

$(LIB)	:
	cd libft && make bonus && make clean && mv libft.a .. 

%.o		:	%.c
	@$(CC) $(FLAGS) -o $@ -c $<

clean	:
	$(RM) *.o */*.o $(LIB)

fclean	:	clean
	$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re bonus