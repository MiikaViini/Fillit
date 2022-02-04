/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:29:20 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/04 15:08:57 by mviinika         ###   ########.fr       */
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
	int		x;
	int		y;

	sidelen = 4;
	i = 0;
	tetro_i = 0;
	square = newmap(sidelen);
	x = 0;
	y = 0;
	if (!square)
		return (0);
	newtetro = (int *)malloc(sizeof(int) * 8);
	newtetro = check_start(tetromino[0]);
	while (0 < index)
	{
		if (check_collision(square, newtetro) == 0)
		{
			printf("empty you can try to put it here");
		}
		while (tetro_i < 8)
		{
			square[newtetro[tetro_i + 1 + y]][newtetro[tetro_i + x]] = 'A';
			tetro_i = tetro_i + 2;
		}
		index--;
		i++;
		tetro_i = 0;
		//newtetro = check_start(tetromino[i]);
	}
	i = 0;
	while (i < sidelen)
	{
		printf("%s\n",square[i]);
		i++;
	}
	return (1);
}

int	*check_start(int *tetromino)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = tetromino[0];
	y = tetromino[1];
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

int	check_collision(char **square, int *tetromino)
{
	int	index;
	int	*fresh;
	int res;

	index = 0;
	fresh = check_start(tetromino);
	res = 0;
	if (square[fresh[index + 1]][fresh[index]] == '.')
	{
		while (square[fresh[index + 1]][fresh[index]] == '.' && index < 8)
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
	k = place_tetros(tetromino, i);
	//exit(1);
	//i = 0;
	//if (place_tetros(tetromino[i]) == 1)
	//	printf("success");
	return (NULL);
}
