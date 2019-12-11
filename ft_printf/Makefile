# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 14:25:15 by fbougama          #+#    #+#              #
#    Updated: 2019/12/11 14:27:46 by fbougama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = #

SRCS = #

SRCS_BONUS = #

OBJS = $(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all		: $(NAME)

$(NAME)	: $(OBJS)
	ar rcs $(NAME) $(OBJS) 

%.o:	%.c
		@$(CC) $(FLAGS) -o $@ -c $<

bonus : $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

clean	:
	$(RM) *.o

fclean	: clean
	$(RM) $(NAME)

re : fclean all

.PHONY	: all clean fclean re bonus