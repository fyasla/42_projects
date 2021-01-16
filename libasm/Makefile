# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/16 00:09:02 by faysal            #+#    #+#              #
#    Updated: 2021/01/16 00:34:27 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

TEST = test

SRC_TEST = main.c

SRCS = srcs/ft_strlen.s srcs/ft_strcpy.s \
	srcs/ft_strcmp.s srcs/ft_write.s \
	srcs/ft_read.s srcs/ft_strdup.s

SRCS_BONUS = 

OBJS = $(SRCS:.s=.o)

OBJS_BONUS = $(SRCS:.s=.o)

ASM = nasm

ASMFLAGS = -f elf64

CC = gcc

CCFLAGS = -Wall -Werror -Wextra

RM = rm -f

%.o : %.s
	$(ASM) $(ASMFLAGS) $<

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus : $(OBJS) $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

test :
	$(CC) $(CCFLAGS) $(SRC_TEST) $(NAME) -o $(TEST)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(TEST)

re : fclean all