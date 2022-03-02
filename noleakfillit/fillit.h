/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 13:41:59 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/02 15:56:23 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SUCCESS 1
# define FAIL 0
# define VALID 1
# define INVALID 0
# define MAX_TETROS 26
# define MAX_GRID_SIZE 225
# define MAX_RB 550

# include <string.h>
# include "./libft/libft.h"
# include <fcntl.h>

typedef struct s_tetro
{
	int			t_amount;
	int			*coords[MAX_TETROS + 1];
	char		square[MAX_GRID_SIZE];
	size_t		sidelen;
	char		answer[MAX_GRID_SIZE];
	int			current_tetro;
}			t_tetro;

void		free_all(t_tetro *values);
void		adjust_coords_to_sidelen(t_tetro *values);
void		expand_square(t_tetro *values);
void		convert_tetro_coords_to_sidelen(t_tetro *values);
size_t		check_for_square(t_tetro *values);
size_t		count_min_sidelen(t_tetro *values);
int			*get_coordinates(char *tetromino);
t_tetro		*prepare_values(char *filename);
void		recursive_solver(t_tetro *values);
int			collision_and_print(t_tetro *values, int index);
void		print_tetro(t_tetro *values, int index);
void		undo_last_tetromino(t_tetro *values);
void		tetro_validation(char *file);
void		check_charecters_and_linecount(char *tetromino);
void		check_adjacency(char *tetromino);
void		check_hashs_and_newlines(char *tetromino);
void		check_validity(char *file);
void		put_error(void);
void		put_usage(void);
#endif
