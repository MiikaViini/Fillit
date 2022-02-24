/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:42:06 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/23 20:42:38 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	t_etro	*nimi;

	if (argc != 2)
		print_usage();
	if (check_map(argv[1]) == INVALID)
		print_error();
	nimi = prepare_struct(argv[1]);
	solver(nimi);
	//print_answer(**solution, sidelen);
	fu_valgrind(nimi);
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
