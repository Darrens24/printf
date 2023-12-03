# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 17:50:06 by eleleux           #+#    #+#              #
#    Updated: 2023/06/08 12:14:56 by eleleux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = data_bonus.c \
		flags_bonus.c \
		libft_bonus.c \
		parsing_bonus.c \
		printers_bonus.c \
		printf.c \
		utils_bonus.c \
		norm.c \
		another_norm.c \
		putarg.c \

NAME = libftprintf.a

all : $(NAME)

OBJ = $(SRC:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I ./ -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

bonus : re

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus
