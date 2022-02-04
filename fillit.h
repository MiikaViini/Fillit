/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 09:40:00 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/04 14:22:06 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUF_MAX 1000
# define TRUE 1
# define FALSE 0
# define VALID 1
# define INVALID 0

# include "./libft/includes/libft.h"
# include <fcntl.h>

int		linecount(char *map);
int		check_minos(char *piece);
char	*four_times_four(char *map, int index);
int		map_validation(char *file);
void	error(int argc, int fd);
void	map_err(int valid_map);
void	*solution(char *argv);
char	**newmap(int sidelen);
int		*check_start(int *tetromino);
int		check_collision(char **square, int *tetromino);

#endif
