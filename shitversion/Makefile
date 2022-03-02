# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 10:30:12 by mviinika          #+#    #+#              #
#    Updated: 2022/03/02 14:43:03 by mviinika         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
	solver.c \
	validation.c \
	error_handling.c\
	prep.c \

NAME = fillit

CC = clang

FLAGS = -g -Wall -Werror -Wextra
 
INCLUDES = -I . -I libft -L libft -lft

all: $(NAME)

$(NAME):
		make -C libft/ fclean && make -C libft/
		$(CC) $(FLAGS) $(SRCS) $(INCLUDES) -o $(NAME)
clean:
		@make clean -C libft
		@rm -f $(OBJS)

fclean: clean
		@make fclean -C libft
		@rm -f $(NAME)

re: fclean all
