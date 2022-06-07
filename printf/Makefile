# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baura <baura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/12 17:50:57 by baura             #+#    #+#              #
#    Updated: 2021/11/16 19:16:50 by baura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST =	ft_printf.c		ft_putchar.c	ft_putstr.c		ft_putnbr.c		ft_un_nbr.c\
		ft_pointer.c	ft_dec_to_hex.c	ft_dec_to_up_hex.c

OBJ = $(LIST:%.c=%.o)

HEADER = ft_printf.h
FLAGS = -Wall -Wextra -Werror -I$(HEADER)
CC = gcc
RM = rm -f

.PHONY : all clean fclean re

all :	$(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean : 
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re: fclean all
