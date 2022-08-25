# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 12:21:27 by mmensing          #+#    #+#              #
#    Updated: 2022/08/26 00:28:12 by mmensing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap.a

CC = gcc
CFLAGS= -Wall -Werror -Wextra
HEADER= push_swap.h
RM= rm -rf

FILES= extra_funcs.c main.c rules.c delete_later_funcs.c checking.c first_sort_try.c

O_FILES= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES) $(HEADER)
	ar rcs $(NAME) $(O_FILES)
	
clean:
	$(RM) $(O_FILES)
	$(RM) a.out
	
fclean: clean
	$(RM) $(NAME)
	
re: fclean all

g:
	@gcc $(FILES) $(CFLAGS)

.PHONY: all clean fclean re