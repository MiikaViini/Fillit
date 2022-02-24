/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:06 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/24 14:10:01 by mviinika         ###   ########.fr       */
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
	while (map[index] != '\0')
	{
		piece = four_times_four(map, index);
		if (check_minos(piece) == INVALID
			|| check_hashs_and_newlines(piece) == INVALID
			|| linecount(piece) == INVALID)
			return (INVALID);
		index = index + 21;
		ft_strdel(&piece);
	}
	return (VALID);
}

int	main(int argc, char **argv)
{
	t_etro	*nimi;
	char	**answer;

	if (argc != 2)
		print_usage();
	//if (map_validation(argv[1]) == INVALID)
	//	print_error();
	nimi = prepare_struct(argv[1]);
	answer = solver(nimi);
	print_answer(answer, nimi[0].sidelen);
	//fu_valgrind(nimi);
	return (0);
}
/*

void print_usage(void)
{
ft_putendl("usage: ./fillit <file>");
exit(1);
}

void print_error(void)
{
ft_putendl("error");
exit(1);
}

int	main(int argc, char **argv)
{
	t_etro *nimi
	if (argc != 2)
		print_usage()
	if(check_map(argv[1]) == INVALID)
		print_error()
	t_etro = save_tetrominos(argv + structi)
	solve_fillit(t_etro mini);
	print_solved_square(struckti jossa vastaus)
	return (0);
}
*/
