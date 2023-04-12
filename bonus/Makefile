# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 10:47:09 by eleleux           #+#    #+#              #
#    Updated: 2023/04/11 11:15:43 by eleleux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = printf.c \
		data_bonus.c \
		flags_bonus.c \
		libft_bonus.c \
		main.c \
		parsing_bonus.c \
		printers_bonus.c \
		utils_bonus.c \

NAME = printf

all : $(NAME)

OBJ = $(SRC:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I ./ -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus
