/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:54:09 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/01 14:58:07 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	undo_last_tetromino(t_tetro *values)
{
	char	*square;

	square = values->square;
	while (*square)
	{
		if (*square == values->current_tetro + 'A')
			*square = '.';
		++square;
	}
}

int	collision_and_print(t_tetro *values, int index)
{
	int	second;
	int	third;
	int	fourth;

	fourth = (values->coords)[values->current_tetro][2];
	third = (values->coords)[values->current_tetro][1];
	second = (values->coords)[values->current_tetro][0];
	if (values->square [index + second] == '.'
		&& values->square [index + second + third] == '.'
		&& values->square [index + second + third + fourth] == '.')
	{
		values->square [index] = 'A' + values->current_tetro;
		values->square [index + second] = 'A' + values->current_tetro;
		values->square [index + second + third] = 'A' + values->current_tetro;
		values->square [index + second + third + fourth] = 'A' + values->current_tetro;
		return (SUCCESS);
	}
	return(FAIL);
}

void	recursive_solver(t_tetro *values)
{
	int	i;

	i = 0;
	if (values->current_tetro == values->t_amount)
		ft_strcpy(values->answer, values->square);
	while (values->square[i] && !*(values->answer))
	{
		if ((values->square)[i] == '.'
			&& collision_and_print(values, i) == SUCCESS)
		{
			++values->current_tetro;
			recursive_solver(values);
			--values->current_tetro;
			undo_last_tetromino(values);
		}
		++i;
	}
}
