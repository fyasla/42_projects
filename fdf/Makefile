# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/21 12:50:16 by fbougama          #+#    #+#              #
#    Updated: 2021/09/02 11:57:35 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	fdf

NAME_BONUS	=	
			
SRCS		= src/parsing.c src/plot_line.c src/conv_to_iso.c \
				src/resize.c src/main.c

SRCS_BONUS	=

%.o:	%.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

OBJS	=	$(SRCS:%.c=%.o)

OBJS_BONUS	=	$(SRCS_BONUS:%.c=%.o)

CC		=	gcc -g

CFLAGS	=	-Wall -Werror -Wextra

RM		=	rm -f

LIBFT	=	libft.a

all		:	$(NAME)

$(NAME)	:	$(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) -I /usr/local/include -g -L /usr/local/lib $(SRCS) $(LIBFT) -o \
        $(NAME) -lX11 -lXext -lm -lmlx


bonus	:	 

$(LIBFT)	:
	cd lib/libft && make bonus && make clean && mv libft.a ../.. 

mlx		:
	git clone https://github.com/42Paris/minilibx-linux.git \
	&& cd minilibx-linux && make && cd .. \
	&& sudo cp -r minilibx-linux/man/man1 /usr/local/man/ \
	&& sudo cp minilibx-linux/libmlx.a /usr/local/lib/ \
	&& sudo cp minilibx-linux/mlx.h /usr/local/include/ \
	&& rm -rf minilibx-linux

clean	:
	$(RM) *.o */*.o $(LIBFT)

fclean	:	clean
	$(RM) $(NAME) $(NAME_BONUS)

re		:	fclean all

.PHONY	:	all clean fclean re bonus