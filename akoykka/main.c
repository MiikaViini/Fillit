/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:49:44 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/07 17:45:35 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	int			valid_map;
	t_tetromino	*values;
 	//Validation
	error(argc, 1);
	valid_map = map_validation(argv[1]);
	map_err(valid_map);
	//Validation ends
	//check_leaks();
	values = prepare_struct(argv[1]);
	while (values->answer == NULL)
	{
		values->square = makesquare(values->square, values->sidelen);
		recursive_solver(values);
		++values->sidelen;
	}
	print_solution(values);
	free_struct(values);
	//check_leaks();
	return (0);
}
