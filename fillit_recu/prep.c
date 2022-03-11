/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:59:04 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/01 13:37:25 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	convert_tetro_coords_to_sidelen(t_tetro *values)
{
	int	tetromino_i;
	int	coord_i;

	tetromino_i = 0;
	while (tetromino_i < values->t_amount)
	{
		coord_i = 0;
		while (coord_i < 3)
		{
			if ((values->coords)[tetromino_i][coord_i] > 1)
				(values->coords)[tetromino_i][coord_i] += values->sidelen - 5;
			++coord_i;
		}
	++tetromino_i;
	}
}

size_t	check_for_square(t_tetro *values)
{
	if ((values->coords)[0][0] == 1
			&& (values->coords)[0][1] == 4
			&& (values->coords)[0][2] == 1)
	{
		return (3);
	}
	return (4);
}

size_t	count_min_sidelen(t_tetro *values)
{
	size_t	sqroot;

	if (values->t_amount == 1)
	{
		return (check_for_square(values));
	}
	sqroot = 0;
	while (sqroot * sqroot < (size_t)values->t_amount * 4)
		++sqroot;
	return (sqroot + 1);
}

int	*get_coordinates(char *tetromino)
{
	char		*temp;
	char		*temp2;
	int			*onetetro;
	int			i;

	i = 0;
	onetetro = (int *)ft_memalloc(sizeof(int) * 3);
	if (!onetetro)
		exit (1);
	temp = ft_strchr(tetromino, '#');
	while (i != 3)
	{
		temp2 = ft_strchr(temp + 1, '#');
		onetetro[i] = (int)(temp2 - temp);
		temp = temp2;
		++i;
	}
	return (onetetro);
}

t_tetro	*prepare_values(char *filename)
{
	int		fd;
	char	buffer[22];
	t_tetro	*values;
	int		r_value;

	values = (t_tetro *)ft_memalloc(sizeof(t_tetro));
	ft_memset(buffer, '\0', 22);
	fd = open(filename, O_RDONLY);
	r_value = read(fd, &buffer, 21);
	if (r_value == -1 || fd < 0 || !values)
		put_error();
	while (r_value > 0)
	{
		values->coords[values->t_amount] = get_coordinates(buffer);
		r_value = read(fd, &buffer, 21);
		if (r_value == -1)
			put_error();
		values->t_amount++;
	}
	close(fd);
	values->sidelen = count_min_sidelen(values);
	convert_tetro_coords_to_sidelen(values);
	ft_memset(values->answer, '\0', MAX_GRID_SIZE);
	values->current_tetro = 0;
	return (values);
}
