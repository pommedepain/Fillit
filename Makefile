# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 13:07:43 by psentilh          #+#    #+#              #
#    Updated: 2018/11/28 13:37:51 by psentilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SHELL = /bin/zsh

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRCS = 

DIR_OBJS = objs/

OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))

HEADERS = -I fillit.h


all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Creating $(NAME)..."

$(DIR_OBJS)%.o: %.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADERS)
	@echo "Compiling $<..."

clean:
	@bin/rm -rf $(DIR_OBJS)
	@echo "Cleaning $(DIR_OBJS)..."

fclean: clean
	@bin/mr -rf $(NAME)
	@echo "Cleaning $(NAME)..."

re: fclean all

.PHONY: all clean fclean re
