/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:18:23 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/21 12:23:03 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s++ == '\0')
			return (NULL);
	}
	return ((char *)s);
}
