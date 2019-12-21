# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/11 14:25:15 by fbougama          #+#    #+#              #
#    Updated: 2019/12/21 18:31:45 by fbougama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	src/manage_conv.c src/cs_parse.c src/ft_printf.c \
		src/extract_cs.c src/ft_dispatche.c src/ft_write_c.c \
		src/ft_write_s.c src/ft_write_p.c src/ft_putnbr_base.c \
		src/ft_write_id.c

SRCS_BONUS = 

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
	$(RM) *.o src/*.o

fclean	: clean
	$(RM) $(NAME)

re : fclean all

.PHONY	: all clean fclean re bonus