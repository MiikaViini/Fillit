/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:59:19 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/08 08:47:09 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetromino	*prepare_struct(char *filename)
{
	t_tetromino	*values;
	int			tetromino_amount;

	values = (t_tetromino *)malloc(sizeof(t_tetromino));
	values->tetrominos = (char **)ft_memalloc(sizeof(char *) * (26 + 1));
	if (!values || !values->tetrominos)
		exit(1);
	tetromino_amount = count_and_save_tetrominos(filename, values->tetrominos);
	values->sidelen = count_minimum_sidelen(tetromino_amount);
	values->answer = NULL;
	values->square = NULL;
	values->letter = 'A';
	return (values);
}

int	count_minimum_sidelen(int tetromino_amount)
{
	int	sqroot_rounded_up;

	sqroot_rounded_up = 0;
	while (!(sqroot_rounded_up * sqroot_rounded_up >= tetromino_amount * 4))
		++sqroot_rounded_up;
	return (sqroot_rounded_up);
}

char	*makesquare(char *square, int sidelen)
{
	free(square);
	square = (char *)ft_memalloc(sidelen * sidelen + sidelen + 1);
	if (!square)
		exit(1);
	ft_memset(square, '.', sidelen * sidelen);
	return (square);
}

int	count_and_save_tetrominos(char *filename, char **tetrominos)
{
	ssize_t		r_value;
	char		buf[21 + 1];
	int			amount_of_tetrominos;
	int			fd;

	fd = open(filename, O_RDONLY);
	amount_of_tetrominos = 0;
	ft_memset(buf, '\0', 22);
	r_value = read(fd, &buf, 21);
	while (r_value)
	{
		*tetrominos = (char *)ft_memalloc(16 + 4 + 1);
		copy_except(*tetrominos, buf, '\n');
		++tetrominos;
		++amount_of_tetrominos;
		r_value = read(fd, &buf, 21);
	}
	close(fd);
	return (amount_of_tetrominos);
}

void	copy_except(char *dest, char *src, int c)
{
	while (*src)
	{
		if (*src != c)
		{
			*dest = *src;
			dest++;
		}
	src++;
	}
	return ;
}
