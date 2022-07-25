# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baura <baura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 19:56:11 by baura             #+#    #+#              #
#    Updated: 2022/03/25 16:49:27 by baura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap

NAME_B 	= checker

LIB 	= libft/libft.a

SRCS 	= 	push_swap.c			push.c			swap.c			rotate.c		rev_rotate.c\
			push_swap_utils.c	check_arg.c		check_order.c	free_stack.c	create_stack.c\
			sort_index.c		index_utils.c	small_sort.c	big_sort.c		stack_info.c\
			node_info.c			compare.c

SRCS_B 	= 	push_swap_bonus.c	push.c			swap.c			rotate.c		rev_rotate.c\
			push_swap_utils.c	check_arg.c		check_order.c	free_stack.c	create_stack.c\
			sort_index.c		index_utils.c	small_sort.c	big_sort.c		stack_info.c\
			node_info.c			compare.c

OBJS 	= $(SRCS:%.c=%.o)
OBJS_B 	= $(SRCS_B:%.c=%.o)

HEADER 	= push_swap.h
FLAGS 	= -Wall -Wextra -Werror -g
LFLAGS 	= -L libft/ -lft
CC 		= gcc
RM 		= rm -f

.PHONY 	: all clean fclean re

all		:	$(NAME)

$(NAME) :	$(OBJS) $(HEADER) $(LIB)
			$(CC) $(FLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

bonus 	:	$(NAME_B)

$(NAME_B) :	$(OBJS_B) $(HEADER) $(LIB)
			$(CC) $(FLAGS) $(LFLAGS) $(OBJS_B) -o $(NAME_B)
		
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIB) 	: 
	make -C libft/
			
clean : 
	$(RM) $(OBJS) $(OBJ_B)
	@make clean -C libft/

fclean : clean
	$(RM) $(NAME) $(NAME_B)
	@make fclean -C libft/

re: fclean all
