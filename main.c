/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:06 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/28 11:28:00 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	error(int argc, int fd)
{
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit <file>");
		exit(1);
	}
	if (fd < 0)
	{
		ft_putendl("error");
		exit(1);
	}
}

void	map_err(int valid_map)
{
	if (valid_map == FALSE)
	{
		ft_putendl("error");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	int		valid_map;

	error(argc, 1);
	valid_map = map_validation(argv[1]);
	map_err(valid_map);
	solution(argv[1]);
	return (0);
}
