/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:39:23 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/01 15:42:49 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Counts lines, if there is 4 + linefeed, its a good line.
** Returns 1(true) if linecount modulo 4 equals to 0.*/
int	linecount(char *map)
{
	int	c_count;
	int	line_count;
	int	index;

	index = 0;
	c_count = 0;
	line_count = 0;
	while (map[index] != '\0')
	{
		while (map[index] != '\n')
		{
			c_count++;
			index++;
		}
		c_count++;
		if ((c_count % 5 == 0 && map[index] == '\n')
			|| (c_count % 5 == 0 && map[index] == '\0'))
			line_count++;
		index++;
		c_count = 0;
	}
	return (line_count % 4 == 0 && line_count <= 104);
}

/* Checks tetrminos if they are aligned right, +1 checks if there
** is next to it on the right -1 does the same thing on left,
** +5 and -5 checks if there is block below or above.
*/
int	check_minos(char *piece)
{
	int	index;
	int	connect;

	index = 0;
	connect = 0;
	if (!piece)
		return (0);
	while (piece[index] != '\0')
	{
		if ((piece[index] == '#' && piece[index + 1] == '#')
			|| (piece[index] == '#' && piece[index - 1] == '#'))
			connect++;
		if ((piece[index] == '#' && piece[index + 1] == '#')
			&& (piece[index] == '#' && piece[index - 1] == '#'))
			connect++;
		if ((piece[index] == '#' && piece[index + 5] == '#')
			|| (piece[index] == '#' && piece[index - 5] == '#'))
			connect++;
		if ((piece[index] == '#' && piece[index + 5] == '#')
			&& (piece[index] == '#' && piece[index - 5] == '#'))
			connect++;
		index++;
	}
	free(piece);
	return (connect == 6 || connect == 8);
}

char	*four_times_four(char *map, int index)
{
	char	*piece;
	int		piece_index;

	piece_index = 0;
	piece = ft_strnew(21);
	while (map[index] != '\0')
	{
		piece[piece_index++] = map[index++];
		if ((map[index] == '\n' && map[index + 1] == '\n')
			|| (map[index] == '\n' && map[index + 1] == '\0'))
			return (piece);
	}
	return (NULL);
}

int	check_map(char *map)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (map[index] != '\0')
	{
		if (map[index] == '#')
			count++;
		index++;
	}
	if (count % 4 != 0 || count == 0)
		return (INVALID);
	return (VALID);
}

int	map_validation(char *file)
{
	char	map[BUF_MAX];
	int		res;
	int		index;
	int		fd;

	fd = 0;
	fd = open(file, fd);
	error(2, fd);
	index = 0;
	res = read(fd, map, BUF_MAX);
	if (res < 0)
		return (INVALID);
	map[res] = '\0';
	if (map[res - 2] != '\n' || check_map(map) == INVALID)
		return (INVALID);
	close(fd);
	while (map[index] != '\0')
	{
		if (check_minos(four_times_four(map, index)) == 0 || !linecount(map))
			return (INVALID);
		index = index + 21;
	}
	return (VALID);
}
