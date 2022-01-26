/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 13:47:42 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/21 20:06:49 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"

void	ft_putendl(char const *s)
{
	if(!s)
		return ;
	write(1, s, ft_strlen(s));
	write(1, "\n", 1);
}
