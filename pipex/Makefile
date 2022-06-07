# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baura <baura@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/27 12:47:38 by baura             #+#    #+#              #
#    Updated: 2022/03/03 20:08:34 by baura            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = 	ft_strlen.c		ft_strnstr.c	ft_substr.c		ft_strjoin.c	ft_split.c\
		pipex.c			pipex_utils.c

# LIST_B = 	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c	ft_lstlast.c	ft_lstadd_back.c\
			ft_lstdelone.c	ft_lstclear.c		ft_lstiter.c	ft_lstmap.c

OBJS = $(SRCS:%.c=%.o)
#OBJ_B = $(LIST_B:%.c=%.o)

HEADER = pipex.h
FLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -f

.PHONY : all clean fclean re bonus

all	:		$(NAME)

$(NAME) :	$(OBJS) $(HEADER)
			$(CC) $(FLAGS) $(OBJS) -o $(NAME)
			
%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

#bonus :
#@make OBJ="$(OBJ_B)" all

clean : 
	$(RM) $(OBJS) 
#$(OBJ_B)

fclean : clean
	$(RM) $(NAME)

re: fclean all
