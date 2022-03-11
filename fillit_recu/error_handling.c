/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:03:57 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/11 09:05:34 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_error(void)
{
	ft_putstr("error\n");
	exit(1);
}

void	put_usage(void)
{
	ft_putstr("usage: ./fillit <file>\n");
	exit(1);
}
