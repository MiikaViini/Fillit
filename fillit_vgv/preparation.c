/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:01:47 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/23 20:34:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	count_minimum_sidelen(int tetromino_amount)
{
	int	sqroot_rounded_up;

	sqroot_rounded_up = 0;
	while (!(sqroot_rounded_up * sqroot_rounded_up >= tetromino_amount * 4))
		++sqroot_rounded_up;
	return (sqroot_rounded_up);
}

/* Optional sidelen counter, counts if the length of
** tetrominos if t_amount is less than 3
/*
/*int starting_sqr(int index, t_etro *tetro)
{
	int	hash_count;
	int	sidelen;
	int	t_index;
	int	c_index;

	sidelen = 2;
	hash_count = index * 4;
	t_index = 0;
	c_index = 0;
	while (sidelen * sidelen < hash_count)
		sidelen++;
	while (t_index < index && index < 3)
	{
		while (c_index < 8)
		{
			if (tetro[t_index].coord[c_index] >= sidelen - 1)
				sidelen = tetro[t_index].coord[c_index] + 1;
			if (tetro[t_index].coord[c_index + 1] >= sidelen - 1)
				sidelen = tetro[t_index].coord[c_index + 1] + 1;
			c_index += 2;
		}
		c_index = 0;
		t_index++;
	}
	return (sidelen);
}*/

void	set_other_values(t_etro *temp, int t_amount)
{
	int	min_sidelen;
	int	index;

	index = 0;
	min_sidelen = count_minimum_sidelen(t_amount);
	while (temp[index])
	{
	temp->sidelen = min_sidelen;
	temp->solution = NULL;
	temp->square = NULL;
	temp->letter = 'A' + index;
	++index;
	}
}

t_etro	*prepare_struct(char *filename)
{
	t_etro	*temp;
	int		index;
	char	tetrominos_file[BUF_MAX];
	int		r_value;
	int		fd;

	index = 0;
	temp = (t_etro *)ft_memalloc(sizeof(t_etro) * 27);
	fd = open(filename, fd);
	r_value = read(fd, tetrominos_file, BUF_MAX);
	if (fd < 0 || !temp || r_value < 0)
		print_error();
	close(fd);
	map[r_value] = '\0';
	while (*tetrominos_file)
	{
		temp[index] = tetro_maker(tetrominos_file);
		check_start(temp[index].coord);
		tetrominos_file += 21;
		++index;
	}
	set_other_values(temp, index);
	return (temp);
}

t_etro	tetro_maker(char *str, int index)
{
	t_etro	tetro;
	int		sqr_x;
	int		sqr_y;
	int		k;

	sqr_y = 0;
	sqr_x = 0;
	k = 0;
	while ((str[index] != '\n' || str[index + 1] != '\n')
		&& (str[index] != '\n' || str[index + 1] != '\0'))
	{
		if (str[index] == '#')
		{
			tetro.coord[k++] = sqr_x++;
			tetro.coord[k++] = sqr_y;
		}
		if (str[index] == '\n')
		{
			sqr_y++;
			sqr_x = 0;
		}
		str++;
	}
	return (tetro);
}

// if ((str[index] == '\n' && str[index + 1] == '\n')
		// 	|| (str[index] == '\n' && str[index + 1] == '\0'))
		// 	return (tetro);
