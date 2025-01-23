# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artperez <artperez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/15 14:23:48 by artperez          #+#    #+#              #
#    Updated: 2025/01/15 13:03:36 by artperez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

BONUS = ft_lstadd_front_bonus.c \
	ft_lstnew_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstmap_bonus.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

FC = ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line_bonus.c \
	get_next_line_utils_bonus.c \
	functions.c \
	functions2.c \
	printf.c

FO = $(FC:.c=.o)

FOB = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(FO) 
	ar rcs $(NAME) $(FO)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(FOB)
	ar rcs $(NAME) $(FOB)

clean:
	rm -f $(FO) && rm -f $(FOB)

fclean: clean
	rm -rf $(NAME)

re: fclean all
