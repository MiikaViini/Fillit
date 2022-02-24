/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:37:21 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/24 13:11:19 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// void	fu_valgrind(t_etro *tetromino)
// {
// 	t_etro	*temp;
// 	int		i;
// 	size_t	loop;

// 	loop = 27;
// 	temp = tetromino;
// 	while (loop--)
// 	{
// 		i = 0;
// 		while (tetromino[0].sidelen != i)
// 			free(temp->solution[i++]);
// 		free(tetromino->solution);
// 		i = 0;
// 		free(&temp);
// 		++temp;
// 	}
// 	free(tetromino);
// }

void	print_answer(char **solution, int sidelen)
{
	int	i;

	i = 0;
	while (i < sidelen)
		ft_putendl(solution[i++]);
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
	/*return (coord);*/
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

int	check_coll(char **sqr, int *tetro, int sidelen)
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
