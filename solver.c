/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:29:20 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/23 10:12:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

t_etro	tetro_maker(char *str, int index, int i)
{
	t_etro	tetro;
	int		sqr_x;
	int		sqr_y;
	int		k;
	char	c;

	sqr_y = 0;
	sqr_x = 0;
	c = 'A';
	k = 0;
	tetro.letter = c + i;
	while (str[index] != '\0' )
	{
		if (str[index] == '#')
		{
			tetro.coord[k++] = sqr_x;
			tetro.coord[k++] = sqr_y;
		}
		sqr_x++;
		if (str[index] == '\n')
		{
			sqr_y++;
			sqr_x = 0;
		}
		str++;
		if ((str[index] == '\n' && str[index + 1] == '\n')
			|| (str[index] == '\n' && str[index + 1] == '\0'))
			return (tetro);
	}
	return (tetro);
}

char	**solver(t_etro *tetro, int index)
{
	char	**sqr;
	int		i_index;
	int		sidelen;
	int		check;

	sidelen = starting_sqr(index, tetro);
	i_index = 0;
	sqr = newmap(sidelen);
	check = 0;
	while (i_index < index)
	{
		check = check_collision(sqr, tetro[i_index].coord, sidelen);
		if (check == -1)
		{
			i_index--;
			if (i_index == 0)
			{
				sidelen++;
				sqr = newmap(sidelen);
				check_start(tetro[i_index].coord);
			}
			else
			{
				remove_prev_tetro(tetro[i_index].coord, sqr);
				move_x(tetro[i_index].coord, &sidelen);
			}
		}
		if (check != 4 && check != -1)
			move_x(tetro[i_index].coord, &sidelen);
		if (check == 4)
		{
			wrsq(sqr, tetro[i_index].coord, tetro[i_index].letter);
			i_index++;
		}
	}
	tetro->sidelen = sidelen;
	return (sqr);
}

void	wrsq(char **sqr, int *coord, char letter)
{
	int	index;

	index = 0;
	while (index != 8)
	{
		sqr[coord[index + 1]][coord[index]] = letter;
		index += 2;
	}
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

int	temp_start(int *coord)
{
	int	i;
	int	x;
	int	start_x;

	x = coord[0];
	i = 0;
	start_x = 0;
	while (i < 6)
	{
		if (x > coord[i + 2])
			x = start_x;
		i += 2;
	}
	return (start_x);
}

void	move_x(int *coord, int *sidelen)
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
		if (coord[index] > *sidelen - 1)
		{
			if (move_y(coord, sidelen) == 0)
				//check_start(coord);
			return ;
		}
		index += 2;
	}
}

int	move_y(int *coord, int *sidelen)
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
		//printf("%d\n", coord[index + 1]);
		index += 2;
	}
	index = 0;
	if (coord[index + 1] > *sidelen - 1
		|| coord[index + 3] > *sidelen - 1
		|| coord[index + 5] > *sidelen - 1
		|| coord[index + 7] > *sidelen - 1)
		return (0);
	return (1);
}

int starting_sqr(int index, t_etro *tetro)
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

void	check_start(int *coord)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = coord[0];
	y = coord[1];
	if (x == 0 && y == 0)
		return ;
	while (i < 6)
	{
		if (x > coord[i + 2])
			x = coord[i + 2];
		if (y > coord[i + 3])
			y = coord[i + 3];
		i += 2;
	}
	i = 0;
	while (i < 8)
	{
		coord[i] = coord[i] - x;
		coord[i + 1] = coord[i + 1] - y;
		i += 2;
	}
	//return (coord);
}

int	check_collision(char **sqr, int *tetro, int sidelen)
{
	int	index;
	int	space;
	int	dots;

	space = 0;
	index = 0;
	dots = 0;
	while (index != 8)
	{
		if (tetro[index + 1] >= sidelen || tetro[index] >= sidelen)
		{
			check_start(tetro);
			return (-1);
		}
		if (sqr[tetro[index + 1]][tetro[index]] == '.')
			space++;
		index += 2;
	}
	return (space);
}

char	**newmap(int sidelen)
{
	char	**sqr;
	int		index;

	index = 0;
	sqr = (char **)malloc(sizeof(char *) * sidelen);
	if (!sqr)
		return (NULL);
	while (index < sidelen)
	{
		sqr[index] = (char *)malloc(sizeof(char ) * sidelen);
		if (!sqr[index])
			return (NULL);
		ft_memset(sqr[index], '.', sidelen);
		index++;
	}
	return (sqr);
}

void	print_answer(char **solution, int sidelen)
{
	int	i;

	i = 0;
	while (i < sidelen)
		ft_putendl(solution[i++]);
}

void	*solution(char *argv)
{
	int		fd;
	char	map[BUF_MAX];
	int		read_bytes;
	t_etro	tetromino[26];
	int		i;
	int		index;
	char 	**solution;

	index = 0;
	i = 0;
	read_bytes = 0;
	fd = 0;
	fd = open(argv, fd);
	if (fd < 0)
		print_error();
	read_bytes = read(fd, map, BUF_MAX);
	map[read_bytes] = '\0';
	while (map[index] != '\0')
	{
		tetromino[i] = tetro_maker(map, index, i);
		check_start(tetromino[i].coord);
		index = index + 21;
		i++;
	}
	solution = solver(tetromino, i);
	print_answer(solution, tetromino->sidelen);
	return (NULL);
}
