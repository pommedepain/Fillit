# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 13:07:43 by psentilh          #+#    #+#              #
#    Updated: 2019/01/10 18:38:47 by cfauvell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SHELL = /bin/zsh

LIB= ./libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS =	main.c\
		parsing.c\
		sort_file.1.c\
		sort_file.2.c\
		sort_file.3.c\
		backtracking.c\
		grid.c\
		free_tetri.c\

OBJS = $(patsubst %.c, %.o, $(SRCS))

HEADERS = -I fillit.h


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(HEADERS) -c $(SRCS) 
	@echo "Compiling in progress $<..."
	@$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "making $(OBJS) disapear"

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
