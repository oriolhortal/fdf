# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 12:33:36 by ohortal-          #+#    #+#              #
#    Updated: 2023/10/17 12:52:09 by ohortal-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

CC := gcc

CFLAGS := -Wall -Wextra -Werror -Iheaders/

SOURCE := source/*.c
LIBFT := libft/*.c
LIBRARY := -Lminilibx_macos -lmlx -framework OpenGL -framework AppKit
MINILIBX := minilibx_macos/

all: 
	make -C $(MINILIBX)	
	make -C ./libft
	$(CC) $(CFLAGS) $(SOURCE) $(LIBFT) $(LIBRARY) -o $(NAME)

clean :
	make -sC ./libft clean
	make -sC ./minilibx_macos clean
	rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean re fclean
