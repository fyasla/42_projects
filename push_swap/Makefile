# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 12:50:16 by fbougama          #+#    #+#              #
#    Updated: 2021/08/13 16:13:29 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_BONUS	=	checker

SRCS	=	srcs/check_input.c srcs/double_list.c srcs/main.c \
			srcs/stacks_instructions.c 

SRCS_BONUS	= srcs/check_input.c srcs/double_list.c \
			srcs/stacks_instructions.c srcs/instructions_parse.c srcs/checker.c

OBJS	=	$(SRCS:%.c=%.o)

OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

RM		=	rm -f

LIB		=	libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIB)
		$(CC) -o $(NAME) $(CFLAGS)  $(OBJS) $(LIB)

bonus	:	 $(OBJS_BONUS) $(LIB)
	$(CC) -o $(NAME_BONUS) $(CFLAGS) $(OBJS_BONUS) $(LIB)

$(LIB)	:
	cd libft && make bonus && make clean && mv libft.a .. 

%.o		:	%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean	:
	$(RM) *.o */*.o $(LIB)

fclean	:	clean
	$(RM) $(NAME) $(NAME_BONUS)

re		:	fclean all

.PHONY	:	all clean fclean re bonus