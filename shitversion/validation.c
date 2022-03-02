/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:26 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/02 14:56:41 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* Counts lines, if there is 4 + linefeed, its a good line.
** Returns 1(true) if linecount equals to 4.*/
void	linecount(char *piece)
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
	if (line_count != 4)
		put_error();
}

/* Checks tetrminos if they are aligned right, +1 checks if there
** is next to it on the right -1 does the same thing on left,
** +5 and -5 checks if there is block below or above.
*/
void	check_minos(char *piece)
{
	int	index;
	int	edges;

	index = 0;
	edges = 0;
	if (!piece)
		put_error();
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
	if (edges != 6 && edges != 8)
		put_error();
}

/* Chops one tetromino from the file, allocates memory for it
** and returns piece if allocation succeeded */
// char	*four_times_four(char *all_tetros, int index)
// {
// 	char	piece[20 + 1];
// 	int		piece_index;

// 	piece_index = 0;
// 	//piece = ft_strnew(21);
// 	while (all_tetros[index] != '\0')
// 	{
// 		piece[piece_index++] = all_tetros[index++];
// 			return (piece);
// 	}
// 	return (NULL);
// }

/* Counts hashtags and \n from one tetromino
** and treat it as valid if count of these two equals 8
*/
void	check_hashs_and_newlines(char *piece)
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
		index++;
	}
	if (count != 4)
		put_error();
}

void	tetro_validation(char *tetromino)
{
	check_minos(tetromino);
	check_hashs_and_newlines(tetromino);
	linecount(tetromino);
}

/* 
Opens, reads and copies a file for validation
*/
void	check_validity(char *file)
{
	char	buf[22];
	int		r_value;
	int		file_descriptor;

	file_descriptor = 0;
	file_descriptor = open(file, file_descriptor);
	ft_memset(buf, '\0', 22);
	r_value = (int)read(file_descriptor, buf, 21);
	if (r_value < 20 || r_value > MAX_RB)
		put_error();
	while (r_value == 21)
	{
		tetro_validation(buf);
		r_value = (int)read(file_descriptor, buf, 21);
		if (r_value != 0 && r_value != 21)
			put_error();
	}
	close(file_descriptor);
}
