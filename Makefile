# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 13:45:18 by ldubos            #+#    #+#              #
#    Updated: 2016/01/11 23:12:14 by ldubos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export CC=gcc
export CFLAGS=-Wall -Wextra -Werror
NAME=fdf
SRCS_DIR=srcs/
SRCS=$(SRCS_DIR)main.c \
	 $(SRCS_DIR)get_next_line.c \
	 $(SRCS_DIR)map.c \
	 $(SRCS_DIR)draw.c
OBJS=$(SRCS:.c=.o)
	INC_DIR=-I./includes/ -I./libft/includes/
	LIB_DIR=-L./libft -lft -L./minilibx -lmlx -framework OpenGL -framework AppKit
	LIB_MAKE=libft/

all		: $(NAME)

$(NAME)	: $(OBJS)
	@cd $(LIB_MAKE) && $(MAKE)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_DIR) $(LFLAGS)
	@echo "\033[36m\033[33mmake fdf is done !\033[0m";

%.o		: %.c
	@$(CC) $(CFLAGS) $(INC_DIR) -c $< -o $@

.PHONY	: clean fclean re

clean	:
	@cd $(LIB_MAKE) && $(MAKE) $@
	@rm -f $(OBJS)
	@echo "\033[36m\033[33mclean fdf is done !\033[0m";

fclean	: clean
	@cd $(LIB_MAKE) && $(MAKE) $@
	@rm -f $(NAME)
	@echo "\033[36m\033[33mfclean fdf is done !\033[0m";

re		: fclean all
