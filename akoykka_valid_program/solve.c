/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 11:25:05 by akoykka           #+#    #+#             */
/*   Updated: 2022/02/07 23:04:57 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_exceptions(t_tetromino *values)
{
	char	*tetromino;

	if (values->sidelen == 2)
	{
		tetromino = ft_strchr(*values->tetrominos, '#');
		if (ft_strncmp(SQUARE_PIECE, tetromino, 6) == SUCCESS)
			return (SUCCESS);
	}
	if (values->sidelen == 3)
	{
		tetromino = ft_strchr(*values->tetrominos, '#');
		if (ft_strncmp(L_PIECE, tetromino, 5) == SUCCESS
			|| ft_strncmp(L_PIECE2, tetromino, 5) == SUCCESS
			|| ft_strncmp(S_PIECE, tetromino, 5) == SUCCESS)
			return (SUCCESS);
	}
	return (FAIL);
}

int	wallcollision(t_tetromino *values)
{
	int	wall_index;

	wall_index = values->sidelen;
	while (values->square[wall_index])
	{
		if (values->square[wall_index] == values->letter
			&& values->square[wall_index - 1] == values->letter
			&& check_exceptions(values) == FAIL)
		{
			undo_last_tetromino(values->square, values->letter);
			return (FAIL);
		}
		wall_index = wall_index + values->sidelen;
	}
	return (SUCCESS);
}

int	get_distance_from_tetromino(char *block)
{
	int	distance;

	distance = 1;
	while (block[distance] != '#')
		++distance;
	return (distance);
}

int	collision(t_tetromino *values, int index)
{
	char	*block;
	int		loop;
	int		dist_to_next;

	values->square[index] = values->letter;
	block = ft_strchr(*values->tetrominos, '#');
	loop = 3;
	while (loop--)
	{
		dist_to_next = get_distance_from_tetromino(block);
		index = index + convert_to_square_size(dist_to_next, values->sidelen);
		block = block + dist_to_next;
		if (values->square[index] == '.')
			values->square[index] = values->letter;
		else
		{
			undo_last_tetromino(values->square, values->letter);
			return (FAIL);
		}
	}
	return (SUCCESS);
}

void	recursive_solver(t_tetromino *values)
{
	int	i;

	i = 0;
	if (!*(values->tetrominos))
	{
		ft_strdel(&values->answer);
		values->answer = ft_strdup(values->square);
		return ;
	}
	while (values->answer == NULL && values->square[i])
	{
		if (values->square[i] == '.'
			&& collision(values, i) == SUCCESS
			&& wallcollision(values) == SUCCESS)
		{
			++values->letter;
			++values->tetrominos;
			recursive_solver(values);
			--values->letter;
			--values->tetrominos;
			undo_last_tetromino(values->square, values->letter);
		}
		++i;
	}
}
