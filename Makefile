# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmensing <mmensing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 12:21:27 by mmensing          #+#    #+#              #
#    Updated: 2022/10/25 16:40:15 by mmensing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap.a

CC= gcc
CFLAGS= -Wall -Werror -Wextra -g
HEADER= push_swap.h
RM= rm -rf
NAME= push_swap

LIBFT= libs/LIBFT/libft.a
LIBFT_DIR= libs/LIBFT
#DEBUG = -fsanitize=address

FILES=	funcs/RULES/a_and_b_rules.c \
		funcs/RULES/a_rules.c \
		funcs/RULES/b_rules.c \
		funcs/marie_sort.c \
		funcs/checking.c \
		funcs/perfect_pivot.c \
		funcs/extra_funcs_one.c \
		funcs/extra_funcs_two.c \
		funcs/main.c \
		funcs/some_above_a.c \
		funcs/some_under_a.c \
		funcs/some_above_b.c \
		funcs/some_under_b.c \
		funcs/quick_to_b.c \
		funcs/hc_quick_to_b.c \
		funcs/b_starts_empty.c \
		funcs/hardcode.c \
		funcs/edit_list.c \
		funcs/list_positions.c \
		funcs/list_infos.c \
		funcs/clean_up_list.c

O_FILES= $(FILES:%.c=%.o)

all: $(NAME)

$(NAME): $(O_FILES)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) $(DEBUG) $(O_FILES) -o $(NAME)

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re