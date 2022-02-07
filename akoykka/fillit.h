/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:40:00 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/07 23:06:44 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdio.h>
# include "./libft/includes/libft.h"
# include <fcntl.h>

# define FAIL 1
# define SUCCESS 0
# define L_PIECE "###.#"
# define L_PIECE2 "#.###"
# define S_PIECE "##.##"
# define SQUARE_PIECE "##..##"
# define BUF_MAX 1000

typedef struct s_tetromino
{
	char			*square;
	char			**tetrominos;
	int				sidelen;
	int				letter;
	char			*answer;
}				t_tetromino;

int			linecount(char *map);
int			check_minos(char *piece);
char		*four_times_four(char *map, int index);
int			map_validation(char *file);
void		error(int argc, int fd);
void		map_err(int valid_map);
void		copy_except(char *dest, char *src, int c);
int			count_and_save_tetrominos(char *filename, char **tetrominos);
void		print_solution(t_tetromino *values);
char		*makesquare(char *square, int sidelen);
void		undo_last_tetromino(char *square, int letter);
int			check_exceptions(t_tetromino *values);
int			wallcollision(t_tetromino *values);
int			convert_to_square_size(int distance, int sidelen);
int			get_distance_from_tetromino(char *block);
int			collision(t_tetromino *values, int index);
void		recursive_solver(t_tetromino *values);
int			count_minimum_sidelen(int tetromino_amount);
t_tetromino	*prepare_struct(char *filename);
void		free_struct(t_tetromino *values);
int			connect_points(char *piece);

#endif
