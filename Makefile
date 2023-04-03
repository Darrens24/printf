# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 17:50:06 by eleleux           #+#    #+#              #
#    Updated: 2023/04/02 10:35:45 by eleleux          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	  ft_putchar_fd.c \
	  ft_putnbr_base_fd.c \
	  ft_sizebase_fd.c \
	  ft_putstr_fd.c \
	  ft_strlen.c \

SRCBONUS = 


NAME = libftprintf.a

all : $(NAME)

OBJ = $(SRC:.c=.o)

.c.o :
	$(CC) $(CFLAGS) -I ./ -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus
