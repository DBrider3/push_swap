# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcho <dcho@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/14 18:06:38 by dcho              #+#    #+#              #
#    Updated: 2021/06/01 20:12:08 by dcho             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
# CFLAGS = -I ./includes -I ./libft
CFLAGS = -Wall -Wextra -Werror -I ./includes -I ./libft

LDFLAGS = -L $(LIBFT_DIR)

RM = rm -f

NAME = push_swap
NAME_B = checker

SRC =	main.c			\
		error.c			\
		quick_sort.c	\
		node.c			\
		double_list.c	\
		gnl/get_next_line_utils.c	\
		gnl/get_next_line.c			\
		lib_a.c						\
		lib_b.c						\
		push_swap.c					\
		a_to_b.c					\
		b_to_a.c					\
		sort_three.c				\
		pivot.c						\
		init.c						\
		free.c

SRCS_B = ./bonus/srcs/main_bonus.c			\
		./bonus/srcs/error_bonus.c			\
		./bonus/srcs/quick_sort_bonus.c	\
		./bonus/srcs/node_bonus.c			\
		./bonus/srcs/double_list_bonus.c	\
		./bonus/srcs/gnl/get_next_line_bonus.c			\
		./bonus/srcs/gnl/get_next_line_utils_bonus.c		\
		./bonus/srcs/lib_main_bonus.c						\
		./bonus/srcs/lib_a_bonus.c						\
		./bonus/srcs/lib_b_bonus.c						\
		./bonus/srcs/push_swap_bonus.c					\
		./bonus/srcs/a_to_b_bonus.c					\
		./bonus/srcs/b_to_a_bonus.c					\
		./bonus/srcs/sort_three_bonus.c				\
		./bonus/srcs/pivot_bonus.c						\
		./bonus/srcs/init_bonus.c						\
		./bonus/srcs/free_bonus.c

SRC_DIR = ./srcs/
SRCS = $(addprefix $(SRC_DIR),$(SRC))

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

LIBFT_DIR = ./libft/

all : $(NAME)

$(NAME) : $(OBJS)
		@make -C $(LIBFT_DIR) all
		$(CC) $(CFLAGS) $^ \
		$(LDFLAGS) -lft \
		-o $@

%.o : $(SRC_DIR)/%.c
		$(CC) $(CFLAGS) -o $@ -c $<

clean:
		$(RM) $(OBJS) $(OBJS_B)
		@make -C $(LIBFT_DIR) clean

fclean: clean
		$(RM) $(NAME)
		$(RM) $(NAME_B)
		@make -C $(LIBFT_DIR) fclean

re : fclean all

bonus : $(NAME_B)

$(NAME_B) : $(OBJS_B)
		@make -C $(LIBFT_DIR) all
		$(CC) $(CFLAGS) $^ \
		$(LDFLAGS) -lft \
		-o $@

.PHONY : all clean fclean re

