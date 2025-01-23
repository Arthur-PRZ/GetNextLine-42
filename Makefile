# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artperez <artperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/10 10:15:26 by artperez          #+#    #+#              #
#    Updated: 2025/01/15 09:59:39 by artperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = libft/libft.a
MLX = minilibx-linix/libmlx.a
FC = src/so_long.c

FO = $(FC:.c=.o)

all: $(NAME)

$(NAME): $(FO)
	$(CC) $(CFLAGS) $(FO) -Llibft -Lminilibx-linux -lmlx -lft -lXext -lX11 -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(FO)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re