/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:03:57 by akoykka           #+#    #+#             */
/*   Updated: 2022/03/07 19:45:58 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_error(void)
{
	ft_putstr_fd("error\n", 2);
	exit(1);
}

void	put_usage(void)
{
	ft_putstr_fd("usage: ./fillit <file>\n", 2);
	exit(1);
}
