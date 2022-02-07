/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:29:20 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/07 15:20:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	*tetro_maker(char *str, int index)
{
	int	*tetro;
	int	square_x;
	int	square_y;
	int	k;

	square_y = 0;
	square_x = 0;
	k = 0;
	tetro = (int *)malloc(sizeof(int ) * 8);
	while (str[index] != '\0' )
	{
		if (str[index] == '#')
		{
			tetro[k++] = square_x;
			tetro[k++] = square_y;
		}
		square_x++;
		if (str[index] == '\n')
		{
			square_y++;
			square_x = 0;
		}
		str++;
		if ((str[index] == '\n' && str[index + 1] == '\n')
			|| (str[index] == '\n' && str[index + 1] == '\0'))
			return (tetro);
	}
	return (0);
}

int	place_tetros(int **tetromino, int index)
{
	int		sidelen;
	int		i;
	char	**square;
	int		tetro_i;
	int		*newtetro;
	int		*current_tetro;
	int		x;
	int		y;
	int		c;

	sidelen = starting_square(index);
	i = 0;
	tetro_i = 0;
	square = newmap(sidelen);
	x = 0;
	y = 0;
	c = 'A';
	if (!square)
		return (0);
	newtetro = (int *)malloc(sizeof(int) * 8);
	newtetro = check_start(tetromino[0]);
	while (0 < index)
	{
		current_tetro = save_tetro(tetromino[i]);
		while (check_collision(square, newtetro, x, y) != 4)
		{
			square = newmap(sidelen);
			while (tetro_i < 8)
			{
				x++;
				current_tetro[tetro_i] += x;
				if (current_tetro[tetro_i] == 3)
				{
					y++;
					current_tetro[tetro_i + 1] += y;
					x = 0;
				}
				tetro_i += 2;
			}
			tetro_i = 0;
			while (tetro_i < 8)
			{
				square[current_tetro[tetro_i + 1]][current_tetro[tetro_i]] = c;
				tetro_i = tetro_i + 2;
			}
			tetro_i = 0;
		}
		while (tetro_i < 8)
		{
			square[newtetro[tetro_i + 1]][newtetro[tetro_i]] = c;
			tetro_i = tetro_i + 2;
		}
		c++;
		index--;
		if (index > 0)
			i++;
		tetro_i = 0;
		newtetro = check_start(tetromino[i]);
	}
	i = 0;
	while (i < sidelen)
	{
		printf("%s\n",square[i]);
		i++;
	}
	return (1);
}

int	starting_square(int index)
{
	int	hash_count;
	int	sidelen;

	sidelen = 2;
	hash_count = index * 4;
	while (sidelen * sidelen < hash_count)
		sidelen++;
	return (sidelen);
}

int	*save_tetro(int *tetromino)
{
	int	*current_tetro;
	int	index;

	if (!tetromino)
		return (0);
	index = 0;
	current_tetro = (int *)malloc(sizeof(int) * 8);
	if (!current_tetro)
		return (0);
	while (index < 8)
	{
		current_tetro[index] = tetromino[index];
		index++;
	}
	return (current_tetro);
}

int	*check_start(int *tetromino)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = tetromino[0];
	y = tetromino[1];
	if (x == 0 && y == 0)
		return (tetromino);
	while (i < 6)
	{
		if (x > tetromino[i + 2])
			x = tetromino[i + 2];
		if (y > tetromino[i + 3])
			y = tetromino[i + 3];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		tetromino[i] = tetromino[i] - x;
		tetromino[i + 1] = tetromino[i + 1] - y;
		i = i + 2;
	}
	return (tetromino);
}

int	check_collision(char **square, int *tetromino, int x, int y)
{
	int	index;
	int	*fresh;
	int res;

	index = 0;
	fresh = check_start(tetromino);
	res = 0;
	if (square[fresh[index + 1] + y][fresh[index] + x] == '.')
	{
		res++;
		while (square[fresh[index + 1] + y][fresh[index] + x] == '.' && index < 6)
		{
			index += 2;
			res++;
		}
	}
	return (res);
}

char	**newmap(int sidelen)
{
	char	**square;
	int		index;

	index = 0;
	square = (char **)malloc(sizeof(char *) * sidelen);
	if (!square)
		return (NULL);
	while (index < sidelen)
	{
		square[index] = (char *)malloc(sizeof(char ) * sidelen);
		if (!square[index])
			return (NULL);
		ft_memset(square[index], '.', sidelen);
		index++;
	}
	return (square);
}

void	*solution(char *argv)
{
	int		fd;
	char	map[BUF_MAX];
	int		read_bytes;
	int		*tetromino[26];
	int		i;
	int		k;
	int		s;
	int		index;

	index = 0;
	s = 0;
	k = 0;
	i = 0;
	read_bytes = 0;
	fd = 0;
	fd = open(argv, fd);
	error(2, fd);
	read_bytes = read(fd, map, BUF_MAX);
	map[read_bytes] = '\0';
	while (map[index] != '\0')
	{
		tetromino[i] = tetro_maker(map, index);
		index = index + 21;
		i++;
	}
	//i = 0;
	//while (i < 8)
	//		printf("tetromino%d", tetromino[1][i++]);
	k = place_tetros(tetromino, i);
	//exit(1);
	//i = 0;
	//if (place_tetros(tetromino[i]) == 1)
	//	printf("success");
	return (NULL);
}
