/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:29:20 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/28 13:51:21 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	move_prev_tetro_or_expand(t_etro *tetro, int i)
{
	if (i + 1 == 0)
	{
		ft_delar(tetro[0].solution, tetro[0].sidelen);
		tetro[0].sidelen++;
		tetro[0].solution = newmap(tetro[0].sidelen);
		check_start(tetro[i].coord);
		return ;
	}
	remove_prev_tetro(tetro[i].coord, tetro[0].solution);
	move_on_x_axis(tetro[i].coord, tetro[0].sidelen);
}

void	remove_prev_tetro(int *coord, char **sqr)
{
	int	index;

	index = 0;
	while (index != 8)
	{
		sqr[coord[index + 1]][coord[index]] = '.';
		index += 2;
	}
}

void	move_on_x_axis(int *coord, int sidelen)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		coord[index] += 1;
		index += 2;
	}
	index = 0;
	while (index < 8)
	{
		if (coord[index] > sidelen - 1)
			move_on_y_axis(coord);
		index += 2;
	}
}

void	move_on_y_axis(int *coord)
{
	int	index;
	int	x;

	x = coord[0];
	index = 0;
	while (index < 6)
	{
		if (x > coord[index + 2])
			x = coord[index + 2];
		index += 2;
	}
	index = 0;
	while (index < 8)
	{
		coord[index] = coord[index] - x;
		index += 2;
	}
	index = 0;
	while (index < 8)
	{
		coord[index + 1] += 1;
		index += 2;
	}
}

char	**solver(t_etro *tetro)
{
	int		i;
	int		check;

	i = 0;
	tetro[0].solution = newmap(tetro[0].sidelen);
	check = 0;
	while (i < tetro[0].t_amount)
	{
		check = check_coll(tetro[0].solution, tetro[i].coord, tetro[0].sidelen);
		if (check == OUT_OF_BOUNDS)
		{
			i--;
			move_prev_tetro_or_expand(tetro, i);
			if (i == -1)
				i++;
		}
		if (check != FIT && check != OUT_OF_BOUNDS)
			move_on_x_axis(tetro[i].coord, tetro[0].sidelen);
		if (check == FIT)
		{
			place_tetro(tetro[0].solution, tetro[i].coord, tetro[i].letter);
			i++;
		}
	}
	return (tetro[0].solution);
}
