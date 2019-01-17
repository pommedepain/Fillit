# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 13:07:43 by psentilh          #+#    #+#              #
#    Updated: 2019/01/17 11:42:34 by pommedepin       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = ./libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS =	main.c\
		parsing.c\
		sort_file.1.c\
		sort_file.2.c\
		sort_file.3.c\
		FUCK_BACKTRACKING.c\
		backtracking.c\
		grid.c\
		free_tetri.c\

OBJS= $(patsubst %.c,$(DIR_OBJS)%.o,$(SRCS))

DIR_OBJS= objs/

HEADERS = -I fillit.h


all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\033[31m\033[1mCreating $(NAME)...\033[0m"

$(DIR_OBJS)%.o: %.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)
	@echo "\033[34mCompiling $<...\033[0m"

clean:
	@/bin/rm -rf $(DIR_OBJS)
	@echo "\033[35mCleaning $(DIR_OBJS)...\033[0m"

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "\033[32mCleaning $(NAME)...\033[0m"

re: fclean all

.PHONY: all clean fclean re
