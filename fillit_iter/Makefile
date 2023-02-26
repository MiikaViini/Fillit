# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 10:30:12 by mviinika          #+#    #+#              #
#    Updated: 2023/02/26 19:46:50 by mviinika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	solver.c \
	validation.c \
	error.c \
	preparation.c \
	helper_functions_two.c \
	helper_functions.c

NAME = fillit

CC = gcc

FLAGS = -Wall -Werror -Wextra -g

INCLUDES = libft/libft.a

all: $(NAME)

$(NAME):
		@make -C libft/ fclean && make -C libft/
		$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)
clean:
		@make clean -C libft
		@rm -f $(OBJS)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all

