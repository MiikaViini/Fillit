/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:01:47 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/24 14:25:33 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int	count_minimum_sidelen(int tetromino_amount)
// {
// 	int	sqroot_rounded_up;

// 	sqroot_rounded_up = 0;
// 	while (!(sqroot_rounded_up * sqroot_rounded_up >= tetromino_amount * 4))
// 		++sqroot_rounded_up;
// 	return (sqroot_rounded_up);
// }

void	set_other_values(t_etro *temp, int t_amount)
{
	int	min_sidelen;
	int	index;

	index = 0;
	min_sidelen = starting_sqr(t_amount, temp);
	while (index < t_amount)
	{
		temp[index].sidelen = min_sidelen;
		temp[index].solution = NULL;
		temp[index].letter = 'A' + index;
		++index;
	}
}

t_etro	*prepare_struct(char *filename)
{
	t_etro	*temp;
	int		index;
	char	*tetrominos_buffer;
	int		r_value;
	int		fd;

	fd = 0;
	index = 0;
	temp = (t_etro *)ft_memalloc(sizeof(t_etro) * 27);
	tetrominos_buffer = ft_strnew(550);
	fd = open(filename, fd);
	r_value = read(fd, tetrominos_buffer, 550);
	if (fd < 0 || !temp || r_value < 0)
		print_error();
	close(fd);
	while (*tetrominos_buffer)
	{
		temp[index] = tetro_maker(tetrominos_buffer);
		check_start(temp[index].coord);
		tetrominos_buffer = tetrominos_buffer + 21;
		++index;
	}
	temp[0].t_amount = index;
	set_other_values(temp, index);
	return (temp);
}

t_etro	tetro_maker(char *str)
{
	t_etro	tetro;
	int		sqr_x;
	int		sqr_y;
	int		k;

	sqr_y = 0;
	sqr_x = 0;
	k = 0;
	while ((*str != '\n' || *(str + 1) != '\n')
		&& *(str + 1) != '\0')
	{
		if (*str == '#')
		{
			tetro.coord[k++] = sqr_x;
			tetro.coord[k++] = sqr_y;
		}
		sqr_x++;
		if (*str == '\n')
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

/* Optional sidelen counter, counts if the length of
** tetrominos if t_amount is less than 3
*/
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
