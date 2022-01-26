/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:06 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/26 10:05:39 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#define BUF_MAX 1000
#define VALID 1
#define INVALID 0

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
		if (map[index] != '#' || map[index] != '.')
			return (INVALID);
		index++;
	}
	if (count % 4 != 0 || count == 0)
		return (INVALID);
	return (VALID);
}

int	map_validation(int fd)
{
	char	map[BUF_MAX];
	int		res;
	int		index;

	index = 0;
	res = read(fd, map, BUF_MAX);
	if (res < 0)
		return (INVALID);
	map[res] = '\0';
	if (map[res - 2] != '\n')
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

int	main(int argc, char **argv)
{
	int		fd;
	int		valid_map;

	fd = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <file>");
		exit(1);
	}
	fd = open(argv[1], fd);
	if (fd < 0)
	{
		ft_putendl("error");
		exit(1);
	}
	valid_map = map_validation(fd);
	if (!valid_map)
		ft_putendl("error");
	if (valid_map)
		ft_putendl("success");
	return (0);
}
