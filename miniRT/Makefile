# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faysal <faysal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/12 15:32:20 by fbougama          #+#    #+#              #
#    Updated: 2020/06/26 17:17:37 by faysal           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	miniRT

LIBS				=	libftprintf.a

SRCS_PARSING		=	src/parsing/get_next_line_utils.c src/parsing/get_next_line.c libftprintf.a \
						src/parsing/initiate_scene.c src/parsing/map_parse.c \
						src/parsing/parse_1.c src/parsing/parse_2.c \
						src/parsing/parsing_utils.c src/parsing/parsing_utils2.c src/parsing/parsing_utils3.c \
						src/parsing/parsing_utils4.c

SRCS				=	$(SRCS_PARSING) \
						src/base/draw.c src/base/pixel.c src/base/collision.c \
						src/base/collision2.c src/base/collision3.c \
						src/base/colors.c src/base/normal.c src/base/events.c\
						src/math_utils/vectors.c src/math_utils/vectors2.c src/math_utils/converts.c \
						src/math_utils/trinome.c src/math_utils/rotations.c \
						src/main.c src/save/save_main.c


SRCS_BONUS 			= 

OBJS				=	$(SRCS:%.c=%.o)

OBJS_BONUS			=	$(SRCS_BONUS:%.c=%.o)


CC					=	cc -I /usr/local/include

CFLAGS				=	-Wall -Werror -Wextra

RM					=	rm -f
				
all				:	$(NAME)
	@echo "Project built"

$(NAME)			:	$(SRCS) $(LIBS)
	@echo "Building..."
	@clang -Wall -Werror -Wextra -I /usr/local/include -g -L /usr/local/lib $(SRCS) $(LIBS) -o \
	$(NAME) -lX11 -lXext -lm -lmlx

mac				:	$(OBJS) $(LIBS)
	@$(CC) $(OBJS) $(LIBS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit \
	&& mv a.out minirt_mac

$(LIBS)			:
	@cd libs/ft_printf && make && make clean && mv $(LIBS) ../..	

%.o				:	%.c
	@$(CC) $(FLAGS) -o $@ -c $<

parsing_test	:
	cd tests && make && mv parsing_test ..

bonus 			:	$(OBJS) $(OBJS_BONUS)
	$(CC) -o $(NAME) $(OBJS) $(OBJS_BONUS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

clean			:
	@$(RM) $(OBJS) $(OBJS_BONUS) $(LIBS) \
	&& cd tests && make clean
	@echo "clean !"

fclean			:	clean
	@$(RM) $(NAME) parsing_test minirt_mac bitmapImage.bmp
	@echo "REALLY clean !"

re				:	fclean all

.PHONY			:	all clean fclean re bonus libftprintf.a parsing_test