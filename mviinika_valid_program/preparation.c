/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:01:47 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/28 12:25:03 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	set_other_values(t_etro *temp, int t_amount)
{
	int	min_sidelen;
	int	index;

	index = 0;
	temp[0].sidelen = 0;
	min_sidelen = starting_sqr(t_amount, temp);
	while (index < t_amount)
	{
		temp[index].sidelen = min_sidelen;
		temp[index].solution = NULL;
		temp[index].letter = 'A' + index;
		++index;
	}
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
		&& str[index + 1] != '\0' && k != 8)
	{
		if (str[index] == '#')
		{
			tetro.coord[k] = 0;
			tetro.coord[k++] = sqr_x;
			tetro.coord[k++] = sqr_y;
		}
		sqr_x++;
		if (str[index++] == '\n')
		{
			sqr_y++;
			sqr_x = 0;
		}
	}
	return (tetro);
}

int	starting_sqr(int t_amount, t_etro *tetro)
{
	int	hash_count;
	int	t_index;
	int	c_index;

	hash_count = t_amount * 4;
	t_index = 0;
	c_index = 0;
	while (tetro[0].sidelen * tetro[0].sidelen < hash_count)
		tetro[0].sidelen++;
	while (t_index < t_amount && t_amount < 3)
	{
		while (c_index < 8)
		{
			if (tetro[t_index].coord[c_index] >= tetro[0].sidelen - 1)
				tetro[0].sidelen = tetro[t_index].coord[c_index] + 1;
			if (tetro[t_index].coord[c_index + 1] >= tetro[0].sidelen - 1)
				tetro[0].sidelen = tetro[t_index].coord[c_index + 1] + 1;
			c_index += 2;
		}
		c_index = 0;
		t_index++;
	}
	return (tetro[0].sidelen);
}

char	*read_and_buf(char *file)
{
	int		r_value;
	int		fd;
	char	*buf;

	fd = 0;
	buf = ft_strnew(MAX_RB);
	fd = open(file, fd);
	r_value = read(fd, buf, MAX_RB);
	if (fd < 0 || !buf || r_value < 0)
		print_error();
	close(fd);
	return (buf);
}

t_etro	*prepare_struct(char *filename)
{
	t_etro	*temp;
	int		index;
	char	*tetrominos_buffer;
	int		i;

	i = 0;
	index = 0;
	temp = (t_etro *)malloc(sizeof(t_etro) * 27);
	tetrominos_buffer = read_and_buf(filename);
	while (tetrominos_buffer[i] != '\0')
	{
		temp[index] = tetro_maker(tetrominos_buffer, i);
		check_start(temp[index++].coord);
		i += 21;
	}
	free(tetrominos_buffer);
	temp[0].t_amount = index;
	set_other_values(temp, index);
	return (temp);
}
