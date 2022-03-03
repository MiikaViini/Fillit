/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akoykka <akoykka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 17:41:31 by akoykka           #+#    #+#             */
/*   Updated: 2021/12/07 22:06:21 by akoykka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int	i;

	i = (int)ft_strlen(s1);
	while (*s2 != '\0' && n != 0)
	{
		s1[i] = *s2;
		++i;
		++s2;
		--n;
	}
	s1[i] = '\0';
	return (s1);
}
