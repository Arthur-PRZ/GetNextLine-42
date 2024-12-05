# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artperez <artperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 09:13:42 by artperez          #+#    #+#              #
#    Updated: 2024/12/05 13:41:17 by artperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

CC = cc
CFLAGS = -Wall -Wextra -Werror

FCB = get_next_line_bonus.c \
	get_next_line_utils_bonus.c \

FC = get_next_line.c \
	get_next_line_utils.c \

FO = $(FC:.c=.o)

FOB = $(FCB:.c=.o)

all: $(NAME)

$(NAME): $(FO) 
	ar rcs $(NAME) $(FO)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(FOB)
	ar rcs $(NAME) $(FOB)

clean:
	rm -f $(FO)	&& rm -f $(FOB)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus