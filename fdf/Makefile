# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohortal- <ohortal-@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/27 12:33:36 by ohortal-          #+#    #+#              #
#    Updated: 2023/11/05 13:18:33 by ohortal-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCE = fdf.c events.c draw.c read_file.c utils.c

OBJS = $(SOURCE:.c=.o)

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -MMD

INCLUDE = -Ifdf.h ./libft/libft.a ./minilibx_macos/libmlx.a -framework OpenGL -framework AppKit

NAME = fdf

DEPS= $(OBJS:.o=.d)

%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all: $(NAME)

-include $(DEPS)
$(NAME): $(OBJS)
	@make -C ./libft
	@make -C ./minilibx_macos
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) -o $(NAME)

clean :
	make -sC ./libft clean
	make -sC ./minilibx_macos clean``
	@$(RM) $(OBJS) $(DEPS)

fclean: clean
	@$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
