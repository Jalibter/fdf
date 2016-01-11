# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 13:45:18 by ldubos            #+#    #+#              #
#    Updated: 2016/01/11 09:12:33 by ldubos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	   draw.c \
	   get_next_line.c \
	  ft_sqrt.c 

all:
	cd libft; make; cd ..; gcc -o fdf $(SRCS) -L minilibx/ -lmlx -L libft/ -lft -framework OpenGL -framework AppKit

clean:
	cd libft; make clean; cd ..; rm fdf

fclean: clean
	cd libft; make fclean; cd ..

re:	fclean all
