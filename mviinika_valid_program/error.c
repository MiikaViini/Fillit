/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 19:55:50 by mviinika          #+#    #+#             */
/*   Updated: 2022/02/23 20:44:31 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_usage(void)
{
	ft_putendl("usage: ./fillit <file>");
	exit(1);
}

void	print_error(void)
{
	ft_putendl("error");
	exit(1);
}
