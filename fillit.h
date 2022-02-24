/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:40:00 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/22 16:36:39 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_MAX 1000
# define TRUE 1
# define FALSE 0
# define VALID 1
# define INVALID 0

# include "./libft/includes/libft.h"
# include <fcntl.h>

typedef struct s_tetro
{
	int		coord[8];
	char	letter;
	int		sidelen;
}				t_etro;


int		linecount(char *map);
int		check_minos(char *piece);
char	*four_times_four(char *map, int index);
int		map_validation(char *file);
void	error(int argc, int fd);
void	map_err(int valid_map);
void	*solution(char *argv);
char	**newmap(int sidelen);
void	check_start(int *coordinate);
int		check_collision(char **sqr, int *tetro, int sidelen);
int		starting_sqr(int index, t_etro *tetro);
int		*save_tetro(int *tetromino);
int		temp_start(int *coord);
void	move_x(int *coord, int *sidelen);
int		move_y(int *coord, int *sidelen);
void	remove_prev_tetro(int *coord, char **sqr);
void	wrsq(char **sqr, int *coord, char letter);
char	**solver(t_etro *tetro, int index);
void	print_answer(char **solution, int sidelen);
#endif
