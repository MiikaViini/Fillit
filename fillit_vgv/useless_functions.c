/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useless_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 20:34:55 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/23 20:35:58 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*save_tetro(int *tetromino)
{
	int	*current_tetro;
	int	index;

	if (!tetromino)
		return (0);
	index = 0;
	current_tetro = (int *)malloc(sizeof(int) * 8);
	if (!current_tetro)
		return (0);
	while (index < 8)
	{
		current_tetro[index] = tetromino[index];
		index++;
	}
	return (current_tetro);
}

int	temp_start(int *coord)
{
	int	i;
	int	x;
	int	start_x;

	x = coord[0];
	i = 0;
	start_x = 0;
	while (i < 6)
	{
		if (x > coord[i + 2])
			x = start_x;
		i += 2;
	}
	return (start_x);
}
