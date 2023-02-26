/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:06 by mviinika          #+#    #+#             */
/*   Updated: 2023/02/26 19:49:03 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	map_validation(char *file)
{
	char	*map;
	int		index;
	char	*piece;

	index = 0;
	map = tetro_file(file);
	while (map[index + 1] != '\0')
	{
		piece = four_times_four(map, index);
		if (check_minos(piece) == INVALID
			|| check_hashs_and_newlines(piece) == INVALID
			|| linecount(piece) == INVALID)
		{
			free(map);
			free(piece);
			return (INVALID);
		}
		free(piece);
		index = index + 21;
	}
	free(map);
	return (VALID);
}

int	main(int argc, char **argv)
{
	t_etro	*name;
	char	**answer;

	if (argc != 2)
		print_usage();
	if (map_validation(argv[1]) == INVALID)
		print_error();
	name = prepare_struct(argv[1]);
	answer = solver(name);
	print_answer(answer, name[0].sidelen);
	ft_delar(answer, name[0].sidelen);
	free(name);
	return (0);
}
