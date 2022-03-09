/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:59:26 by mviinika          #+#    #+#             */
/*   Updated: 2022/03/08 13:41:56 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	check_charecters_and_linecount(char *tetromino)
{
	int	c_count;
	int	line_count;
	int	i;

	i = 0;
	c_count = 0;
	line_count = 0;
	while (tetromino[i])
	{
		while (tetromino[i] == '.' || tetromino[i] == '#')
		{
			c_count++;
			i++;
		}
		c_count++;
		if (c_count == 5 && tetromino[i] == '\n')
			line_count++;
		i++;
		c_count = 0;
	}
	if (line_count != 4)
		put_error();
}

void	check_adjacency(char *tetromino)
{
	int	i;
	int	edges;

	i = 0;
	edges = 0;
	while (tetromino[i] != '\0')
	{
		if ((tetromino[i] == '#' && tetromino[i + 1] == '#')
			|| (i >= 1 && tetromino[i] == '#' && tetromino[i - 1] == '#'))
			edges++;
		if ((tetromino[i] == '#' && tetromino[i + 1] == '#')
			&& (i >= 1 && tetromino[i] == '#' && tetromino[i - 1] == '#'))
			edges++;
		if ((i <= 14 && tetromino[i] == '#' && tetromino[i + 5] == '#')
			|| (i >= 4 && tetromino[i] == '#' && tetromino[i - 5] == '#'))
			edges++;
		if ((i <= 14 && tetromino[i] == '#' && tetromino[i + 5] == '#')
			&& (i >= 4 && tetromino[i] == '#' && tetromino[i - 5] == '#'))
			edges++;
		i++;
	}
	if (edges != 6 && edges != 8)
		put_error();
}

void	check_hashs(char *tetromino)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	if (tetromino[0] != '.' && tetromino[0] != '#')
		put_error();
	while (tetromino[i])
	{
		if (tetromino[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		put_error();
}

void	tetro_validation(char *tetromino)
{
	check_adjacency(tetromino);
	check_hashs(tetromino);
	check_charecters_and_linecount(tetromino);
}

void	check_validity(char *filename)
{
	char	buf[22];
	int		r_value;
	int		fd;

	check_file(filename);
	fd = open(filename, O_RDONLY);
	ft_memset(buf, '\0', 22);
	r_value = (int)read(fd, buf, 21);
	if (r_value < 19)
		put_error();
	while (r_value >= 20)
	{
		tetro_validation(buf);
		r_value = (int)read(fd, buf, 21);
	}
	if (r_value != 0)
		put_error();
	close(fd);
}
