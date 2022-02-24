/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:26 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/14 12:18:54 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Counts lines, if there is 4 + linefeed, its a good line.
** Returns 1(true) if linecount modulo 4 equals to 0.*/
int	linecount(char *piece)
{
	int	c_count;
	int	line_count;
	int	index;

	index = 0;
	c_count = 0;
	line_count = 0;
	while (piece[index] != '\0')
	{
		while (piece[index] == '.' || piece[index] == '#')
		{
			c_count++;
			index++;
		}
		c_count++;
		if ((c_count == 5 && piece[index] == '\n')
			|| (c_count == 5 && piece[index] == '\0'))
			line_count++;
		index++;
		c_count = 0;
	}
	return (line_count == 4);
}

/* Checks tetrminos if they are aligned right, +1 checks if there
** is next to it on the right -1 does the same thing on left,
** +5 and -5 checks if there is block below or above.
*/
int	check_minos(char *piece)
{
	int	index;
	int	edges;

	index = 0;
	edges = 0;
	if (!piece)
		return (0);
	while (piece[index] != '\0')
	{
		if ((piece[index] == '#' && piece[index + 1] == '#')
			|| (index >= 1 && piece[index] == '#' && piece[index - 1] == '#'))
			edges++;
		if ((piece[index] == '#' && piece[index + 1] == '#')
			&& (index >= 1 && piece[index] == '#' && piece[index - 1] == '#'))
			edges++;
		if ((index <= 14 && piece[index] == '#' && piece[index + 5] == '#')
			|| (index >= 4 && piece[index] == '#' && piece[index - 5] == '#'))
			edges++;
		if ((index <= 14 && piece[index] == '#' && piece[index + 5] == '#')
			&& (index >= 4 && piece[index] == '#' && piece[index - 5] == '#'))
			edges++;
		index++;
	}
	return (edges == 6 || edges == 8);
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
		if (piece_index == 20)
			return (piece);
	}
	ft_strdel(&piece);
	return (NULL);
}

int	check_map(char *piece)
{
	int	count;
	int	index;

	index = 0;
	count = 0;
	if (piece[0] != '.' && piece[0] != '#')
		piece[index] = '\0';
	while (piece[index] != '\0')
	{
		if (piece[index] == '#')
			count++;
		if (piece[index] == '\n')
			count++;
		index++;
	}
	if (count == 8)
		return (VALID);
	return (INVALID);
}

int	map_validation(char *file)
{
	char	map[BUF_MAX];
	int		read_bytes;
	int		index;
	int		fd;
	char	*piece;

	fd = 0;
	fd = open(file, fd);
	error(2, fd);
	index = 0;
	read_bytes = read(fd, map, BUF_MAX);
	if (read_bytes < 20 || read_bytes > MAX_RB)
		return (INVALID);
	map[read_bytes + 1] = '\0';
	while (map[index] != '\0')
	{
		piece = four_times_four(map, index);
		if (check_minos(piece) == INVALID || check_map(piece) == INVALID
			|| linecount(piece) == INVALID || map[read_bytes - 2] == '\n')
			return (INVALID);
		index = index + 21;
		ft_strdel(&piece);
	}
	close(fd);
	return (VALID);
}
