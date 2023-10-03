# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 12:33:36 by ohortal-          #+#    #+#              #
#    Updated: 2023/10/03 13:59:02 by ohortal-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fdf

SRCS= events.c utils.c draw.c fdf.c read_file.c

OBJ= $(SRCS:.c=.o)

CFLAGS= -Wall -Werror -Wextra
LDFLAGS= -L./libft -L./minilibx_macos
LDLIBS= -lft -lmlx

FARMEWORKS= -framework OpenGL -framework AppKit

$(NAME): $(OBJ)
	make -sC ./libft
	make -sC ./minilibx_macos
	gcc $(CFLAGS) $(LDFLAGS) $(OBJ) $(LDLIBS) $(FRAMEWORKS) -o $(NAME)

all: $(name)

re: fclean all

clean:
	@rm -rf $(OBJ)
	@make -sC ./libft clean
	@make -sC ./minilibx_macos clean

fclean:
	@rm -rf $(NAME)

.PHONY: all clean re fclean
