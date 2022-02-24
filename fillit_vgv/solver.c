/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 10:29:20 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/24 14:44:59 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	move_prev_tetro_or_expand(t_etro *tetro, int i)
{
	if (i == 0)
	{
		tetro[0].sidelen++;
		tetro[0].solution = newmap(tetro[0].sidelen);
		check_start(tetro[i].coord);
	}
	remove_prev_tetro(tetro[i].coord, tetro[0].solution);
	move_on_x_axis(tetro[i].coord, tetro[0].sidelen);
}

void	remove_prev_tetro(int *coord, char **sqr)
{
	int	index;

	index = 0;
	while (index != 8)
	{
		sqr[coord[index + 1]][coord[index]] = '.';
		index += 2;
	}
}

void	move_on_x_axis(int *coord, int sidelen)
{
	int	index;

	index = 0;
	while (index < 8)
	{
		coord[index] += 1;
		index += 2;
	}
	index = 0;
	while (index < 8)
	{
		if (coord[index] > sidelen - 1)
			move_on_y_axis(coord);
		index += 2;
	}
}

void	move_on_y_axis(int *coord)
{
	int	index;
	int	x;

	x = coord[0];
	index = 0;
	while (index < 6)
	{
		if (x > coord[index + 2])
			x = coord[index + 2];
		index += 2;
	}
	index = 0;
	while (index < 8)
	{
		coord[index] = coord[index] - x;
		index += 2;
	}
	index = 0;
	while (index < 8)
	{
		coord[index + 1] += 1;
		index += 2;
	}
}

char	**solver(t_etro *tetro)
{
	int		i;
	int		check;

	i = 0;
	tetro[0].solution = newmap(tetro[0].sidelen);
	check = 0;
	while (i < tetro[0].t_amount)
	{
		check = check_coll(tetro[0].solution, tetro[i].coord, tetro[0].sidelen);
		if (check == OUT_OF_BOUNDS)
		{
			i--;
			move_prev_tetro_or_expand(tetro, i);
		}	
		if (check != FIT && check != OUT_OF_BOUNDS)
			move_on_x_axis(tetro[i].coord, tetro[0].sidelen);
		if (check == FIT)
		{
			place_tetro(tetro[0].solution, tetro[i].coord, tetro[i].letter);
			i++;
		}
	}
	return (tetro[0].solution);
}
/*
void	solve_fillit(char *argv)
{
	int		fd;
	char	map[BUF_MAX];
	int		read_bytes;
	t_etro	tetromino[26];
	int		i;
	//int		k;
	//int		s;
	int		index;
	char 	**solution; // tehdaan struct jossa vastaus

	index = 0;
	//s = 0;
	//k = 0;
	i = 0;
	//read_bytes = 0;
	//fd = 0;
	fd = open(argv, fd);
	error(2, fd);
	read_bytes = read(fd, map, BUF_MAX);
	map[read_bytes] = '\0';
	while (map[index] != '\0')
	{
		tetromino[i] = tetro_maker(map, index, i);
		check_start(tetromino[i].coord);
		index = index + 21;
		i++;
	}
	solution = solver(tetromino, i);
	return (NULL);
}


 Checkki 2 argumenttia

// Validaattori ottaa tiedoston lukee sen ja sulkee
// Miika tekee taman (lisaa oikean validaattorin)

// palauttaa valid jos tiedosto VALID
// palauttaa invalid jos tiedosto INVALID -> EXIT




Save_tetrominos ottaa tiedoston lukee sen ja sulkee

Sylkee ulos s_tetro strucktin jossa:
on mallocoitu s_tetro tetro[26]
johon laitetettu jokaiseen 'lokeroon'
	cordinaatit (nollattuna)
	tetron letteri
**solution joka on NULL
ja sidelen joka on oikein
Atte



Solveri ottaa s_tetro
ja palauttaa voidin

printteri printtaa s_tetro strucktista vastauksen
Atte

			if (--i == 0)
			{
				square = newmap(tetro.sidelen++);
				check_start(tetro[i].coord);
			}
			remove_prev_tetro(tetro[i].coord, square);
			move_on_x_axis(tetro[i].coord);*/