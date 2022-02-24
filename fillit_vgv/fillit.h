/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:40:00 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/24 13:06:20 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_MAX 1000
# define TRUE 1
# define FALSE 0
# define VALID 1
# define INVALID 0
# define FIT 4
# define OUT_OF_BOUNDS -1
# define MAX_RB 545

# include "./libft/includes/libft.h"
# include <fcntl.h>

typedef struct s_tetro
{
	int		coord[8];
	char	letter;
	char	**solution;
	int		sidelen;
	//char	**square;
	int		t_amount;
}				t_etro;

// typedef struct s_answer
// {
// 	char	**solution;
// 	int		sidelen;
// }				t_answer;

int		linecount(char *map);
int		check_minos(char *piece);
char	*four_times_four(char *map, int index);
int		map_validation(char *file);
int		check_hashs_and_newlines(char *piece);
char	*tetro_file(char *file);

void	print_error(void);
void	print_usage(void);
//void	map_err(int valid_map);

void	*solution(char *argv);
char	**newmap(int sidelen);
void	check_start(int *coordinate);
int		check_coll(char **sqr, int *tetro, int sidelen);
int		starting_sqr(int index, t_etro *tetro);
//int		*save_tetro(int *tetromino);
//int		temp_start(int *coord);
void	move_on_x_axis(int *coord, int sidelen);
void	move_on_y_axis(int *coord);
void	remove_prev_tetro(int *coord, char **sqr);
void	place_tetro(char **sqr, int *coord, char letter);
char	**solver(t_etro *tetro);
void	move_prev_tetro_or_expand(t_etro *tetro, int i);
t_etro	tetro_maker(char *str);

void	print_answer(char **solution, int sidelen);
t_etro	*prepare_struct(char *filename);
void	set_other_values(t_etro *temp, int t_amount);
int		count_minimum_sidelen(int tetromino_amount);
void	fu_valgrind(t_etro *tetromino);
#endif
