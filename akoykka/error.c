/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:42:07 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/07 16:01:03 by mviinika         ###   ########.fr       */
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
	if (valid_map == FAIL)
	{
		ft_putendl("error");
		exit(1);
	}
}

