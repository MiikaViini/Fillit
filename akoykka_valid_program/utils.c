/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 23:02:38 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/08 08:48:11 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_struct(t_tetromino *values)
{
	int	i;

	i = 0;
	while (values->tetrominos[i])
	{
		ft_strdel(&(values->tetrominos[i]));
		++i;
	}
	free(values->tetrominos);
	free(values->answer);
	free(values->square);
	free(values);
	values = NULL;
}

int	convert_to_square_size(int distance, int sidelen)
{
	int	converted_len;

	if (distance > 1)
	{
		converted_len = distance + (sidelen - 4);
		return (converted_len);
	}
	return (distance);
}

void	undo_last_tetromino(char *square, int letter)
{
	while (*square)
	{
		if (*square == letter)
			*square = '.';
		++square;
	}
}

void	print_solution(t_tetromino *values)
{
	int	print;
	int	print1;

	print = 0;
	while (values->answer[print])
	{
		print1 = values->sidelen - 1;
		while (print1--)
		{
			ft_putchar(values->answer[print]);
			++print;
		}
		ft_putchar('\n');
	}
}
