/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 11:32:12 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/02 14:48:15 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	free_all(t_tetro *values)
{
	int	i;

	i = 0;
	while ((values->coords)[i])
	{
		free((values->coords)[i]);
		++i;
	}
	free(values);
}

void	adjust_coords_to_sidelen(t_tetro *values)
{
	int	tetromino_i;
	int	coord_i;

	tetromino_i = 0;
	while ((values->coords)[tetromino_i])
	{
		coord_i = 0; 
		while (coord_i < 3)
		{
			if ((values->coords)[tetromino_i][coord_i] != 1)
				++(values->coords)[tetromino_i][coord_i];
			++coord_i;
		}
	++tetromino_i;
	}
}

void	expand_square(t_tetro *values)
{
	size_t			sidelen;
	unsigned long	newline_index;

	sidelen = values->sidelen;
	newline_index = sidelen - 1;
	ft_memset(values->square, '\0', MAX_GRID_SIZE);
	ft_memset(values->square, '.', (sidelen) * (sidelen - 1));
	while (sidelen--)
	{
		(values->square)[newline_index] = '\n';
		newline_index += values->sidelen;
	}
}

int	main(int argc, char **argv)
{
	t_tetro	*values;

	if (argc != 2)
		put_usage();
	check_validity(argv[1]);
	values = prepare_values(argv[1]);
	while (!*(values->answer))
	{
		expand_square(values);
		recursive_solver(values);
		++values->sidelen;
		adjust_coords_to_sidelen(values);
	}
	ft_putstr(values->answer);
	free_all(values);
	return (0);
}
