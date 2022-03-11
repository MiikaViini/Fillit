/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions_two.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:41:13 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/28 12:26:13 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_tetro(char **sqr, int *coord, char letter)
{
	int	index;

	index = 0;
	while (index != 8)
	{
		sqr[coord[index + 1]][coord[index]] = letter;
		index += 2;
	}
}
