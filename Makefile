# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eleleux <eleleux@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 17:50:06 by eleleux           #+#    #+#              #
#    Updated: 2023/04/12 13:19:06 by eleleux          ###   ########.fr        #
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

SRCBONUS = ./bonus/data_bonus.c \
			./bonus/flags_bonus.c \
			./bonus/libft_bonus.c \
			./bonus/parsing_bonus.c \
			./bonus/printers_bonus.c \
			./bonus/printf.c \
			./bonus/utils_bonus.c \


NAME = libftprintf.a

all : $(NAME)

OBJ = $(SRC:.c=.o)

OBJBONUS = $(SRCBONUS:.c=.o)

ifdef MAKEBONUS
	OBJ = $(OBJBONUS)
endif

.c.o :
	$(CC) $(CFLAGS) -I ./ -c $< -o ${<:.c=.o}

$(NAME) : $(OBJ)
	ar rcs $@ $(OBJ)

bonus :
	@make MAKEBONUS=1 all

clean :
	rm -f $(OBJ) $(OBJBONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean bonus
