# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 12:50:16 by fbougama          #+#    #+#              #
#    Updated: 2021/08/29 20:21:07 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_BONUS	=	checker

SRCS_COM	=	srcs/check_input.c srcs/double_list.c \
			srcs/stacks_instructions.c srcs/sort.c srcs/checker_utils.c \
			srcs/instructions_parse.c srcs/stack_transfo.c srcs/sort_utils.c srcs/sort_utils2.c \
			srcs/free_args.c
			
SRCS		= $(SRCS_COM) srcs/main.c

SRCS_BONUS	= $(SRCS_COM) srcs/checker.c

OBJS	=	$(SRCS:%.c=%.o)

OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

CC		=	gcc

CFLAGS	=	-Wall -Werror -Wextra

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