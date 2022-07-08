# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baura <baura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/10 16:31:33 by baura             #+#    #+#              #
#    Updated: 2022/07/08 16:21:58 by baura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	 = so_long

NAME_B 	 = so_long_bonus

LIB 	 = libft/libft.a

SRCS 	 = 	so_long.c		so_long_utils.c		init.c	\
			map_check.c		map_transform.c		window.c \
			moves.c			moves_check.c

SRCS_B 	 = 	bonus/so_long_bonus.c	\
			bonus/so_long_utils_bonus.c	\
			bonus/init_bonus.c	\
			bonus/map_transform_bonus.c	\
			bonus/map_check_bonus.c	\
			bonus/window_bonus.c	\
			bonus/moves_bonus.c	\
			bonus/moves_check_bonus.c	\
			bonus/animation_bonus.c	\
			bonus/animation_2_bonus.c

OBJS 	 = $(SRCS:%.c=%.o)
OBJS_B 	 = $(SRCS_B:%.c=%.o)

HEADER 	 = so_long.h
HEADER_B = bonus/so_long_bonus.h
FLAGS 	 = -Wall -Wextra -Werror
LFLAGS 	 = -L libft/ -lft -Lmlx -lmlx -framework OpenGL -framework AppKit
CC 		 = gcc
RM 		 = rm -f

.PHONY 	: all clean fclean re

all		:	$(NAME)

$(NAME) :	$(OBJS) $(HEADER) $(LIB)
			@make -C mlx/
			$(CC) $(FLAGS) $(LFLAGS) $(OBJS) -o $(NAME)

bonus 	:	$(NAME_B)

$(NAME_B) :	$(OBJS_B) $(HEADER_B) $(LIB)
			@make -C mlx/
			$(CC) $(FLAGS) $(LFLAGS) $(OBJS_B) -o $(NAME_B)
		
%.o : %.c
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(LIB) 	: 
	@make -C libft/

clean : 
	$(RM) $(OBJS) $(OBJ_B)
	@make clean -C libft/
	@make clean -C mlx/
	$(RM) bonus/*.o

fclean : clean
	$(RM) $(NAME) $(NAME_B)
	@make fclean -C libft/

norm :
	norminette libft/*.c libft/*.h
	norminette bonus/*
	norminette $(SRCS) $(HEADER)

re: fclean all
