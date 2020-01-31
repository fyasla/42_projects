# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 10:49:58 by fbougama          #+#    #+#              #
#    Updated: 2020/01/28 16:39:07 by fbougama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbougama <fbougama@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 15:32:20 by fbougama          #+#    #+#              #
#    Updated: 2020/01/07 10:50:58 by fbougama         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY	: all clean fclean re bonus

NAME =	miniRT

LIBS = libftprintf.a

SRCS =	src/parsing/get_next_line_utils.c src/parsing/get_next_line.c \
		src/main.c

SRCS_BONUS = 

OBJS =	$(SRCS:%.c=%.o)

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

CC = cc -I /usr/local/include

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

$(LIBS) :
	cd libs/ft_printf && make && make clean && mv $(LIBS) ../..

all		: $(NAME)

$(NAME)	: $(OBJS) $(LIBS)
		$(CC) $(OBJS) $(LIBS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit \
		&& mv a.out $(NAME)
%.o:	%.c
		$(CC) $(FLAGS) -o $@ -c $<

bonus : $(OBJS) $(OBJS_BONUS)
			$(CC) $(OBJS) $(OBJS_BONUS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit \
			&& && mv a.out $(NAME)

clean	:
	$(RM) $(OBJS) $(OBJS_BONUS) $(LIBS)

fclean	: clean
	$(RM) $(NAME)

re : fclean all