/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:41:29 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/21 20:15:36 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if(!str)
		return (-1);
	while (str[i])
		i++;
	return (i);
}
