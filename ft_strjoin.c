/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:47:26 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/21 12:23:10 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*fresh;

	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	fresh = ft_strnew(len);
	if (!fresh)
		return (NULL);
	while (s1 && *s1 != '\0')
		*fresh++ = *s1++;
	while (s2 && *s2 != '\0')
		*fresh++ = *s2++;
	*fresh = '\0';
	return (fresh - len);
}
