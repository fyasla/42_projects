# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/22 22:15:56 by faysal            #+#    #+#              #
#    Updated: 2021/09/23 00:32:39 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =       pipex

NAME_BONUS      =

SRCS            = src/pipex_utils.c src/main.c

SRCS_BONUS      =

%.o:    %.c
		$(CC) $(CFLAGS) -o $@ -c $<

OBJS    =       $(SRCS:%.c=%.o)

OBJS_BONUS      =       $(SRCS_BONUS:%.c=%.o)

CC              =       gcc

CFLAGS  =       -Wall -Werror -Wextra

RM              =       rm -f

LIBFT   =       libft.a

all             :       $(NAME)

$(NAME) :       $(OBJS) $(LIBFT)
					$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT)

bonus   :        

$(LIBFT)        :
		cd libft && make bonus && make clean && mv libft.a ..

clean   :
		$(RM) *.o */*.o $(LIBFT)

fclean  :       clean
		$(RM) $(NAME) $(NAME_BONUS)

re              :       fclean all

.PHONY  :       all clean fclean re bonus