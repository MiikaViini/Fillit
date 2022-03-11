/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:26 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/28 15:32:34 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Counts lines, if there is 4 + linefeed, its a good line.
** Returns 1(true) if linecount equals to 4.*/
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

/* Chops one tetromino from the file, allocates memory for it
** and returns piece if allocation succeeded */
char	*four_times_four(char *map, int index)
{
	char	*piece;
	int		piece_index;

	piece_index = 0;
	piece = ft_strnew(21);
	if (map[index] == '\n')
		index++;
	while (map[index] != '\0')
	{
		piece[piece_index++] = map[index++];
		if (piece_index == 20)
			return (piece);
	}
	return (NULL);
}

/* Counts hashtags and \n from one tetromino
** and treat it as valid if count of these two equals 8
*/
int	check_hashs_and_newlines(char *piece)
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

/* Opens, reads and copies a file for validation
*/
char	*tetro_file(char *file)
{
	char	*buf;
	char	*tetros;
	int		read_bytes;
	int		file_descriptor;

	file_descriptor = 0;
	tetros = NULL;
	buf = ft_strnew(MAX_RB);
	file_descriptor = open(file, file_descriptor);
	if (file_descriptor < 0)
		print_error();
	read_bytes = read(file_descriptor, buf, MAX_RB);
	if (read_bytes < 20 || read_bytes > MAX_RB)
		print_error();
	tetros = ft_strndup(buf, read_bytes);
	if (tetros[read_bytes] == '\0' && tetros[read_bytes - 2] == '\n')
		print_error();
	close(file_descriptor);
	free(buf);
	return (tetros);
}
