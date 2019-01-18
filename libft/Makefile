# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/08 12:31:47 by psentilh          #+#    #+#              #
#    Updated: 2019/01/18 14:04:35 by psentilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= libft.a

SHELL= /bin/zsh


# Compilation
CC= gcc

DEBUG= no
ifeq ($(DEBUG), yes)
	CFLAGS= -Wall -Werror -Wextra -g
else
	CFLAGS= -Wall -Werror -Wextra
endif


# Sources
SRCS= 	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strdup.c\
		ft_strcpy.c\
		ft_strncpy.c\
		ft_strcat.c\
		ft_strncat.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strstr.c\
		ft_strnstr.c\
		ft_strcmp.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_memalloc.c\
		ft_memdel.c\
		ft_strnew.c\
		ft_strdel.c\
		ft_strclr.c\
		ft_striter.c\
		ft_striteri.c\
		ft_strmap.c\
		ft_strmapi.c\
		ft_strequ.c\
		ft_strnequ.c\
		ft_strsub.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_strsplit.c\
		ft_word_count.c\
		ft_letter_count.c\
		ft_tab_filling.c\
		ft_itoa.c\
		ft_digit_len.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putendl.c\
		ft_putnbr.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_lstnew.c\
		ft_lstdelone.c\
		ft_lstdel.c\
		ft_lstadd.c\
		ft_lstiter.c\
		ft_lstmap.c\
		get_next_line.c\
		ft_print_words_tables.c\
		ft_tabdel.c\

DIR_OBJS= objs/

OBJS= $(patsubst %.c,$(DIR_OBJS)%.o,$(SRCS))


# Others
HEADERS= -I .


all: $(NAME)
ifeq ($(DEBUG), yes)
	@echo "*** DEBUG MODE ACTIVATED ***"
endif

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "Creating $(NAME)..."

$(DIR_OBJS)%.o: %.c
	@mkdir -p $(DIR_OBJS)
	@$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)
	@echo "Compiling $<..."

clean: 
	@/bin/rm -rf $(DIR_OBJS)
	@echo "Cleaning $(DIR_OBJS) ..."

fclean: clean
	@/bin/rm -rf $(NAME)
	@echo "Cleaning $(NAME)..."

re: fclean all

.PHONY: re all clean fclean
