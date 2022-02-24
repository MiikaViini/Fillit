/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:49:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/08 08:47:44 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			valid_map;
	t_tetromino	*values;

	error(argc, 1);
	valid_map = map_validation(argv[1]);
	map_err(valid_map);
	values = prepare_struct(argv[1]);
	while (values->answer == NULL)
	{
		values->square = makesquare(values->square, values->sidelen);
		recursive_solver(values);
		++values->sidelen;
	}
	print_solution(values);
	free_struct(values);
	return (0);
}
