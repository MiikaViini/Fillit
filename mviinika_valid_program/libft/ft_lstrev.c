/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviinika <mviinika@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:07:24 by mviinika          #+#    #+#             */
/*   Updated: 2022/01/04 14:16:06 by mviinika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*prv;
	t_list	*next;
	t_list	*curr;

	curr = *alst;
	prv = NULL;
	while (curr)
	{
		next = curr->next;
		curr->next = prv;
		prv = curr;
		curr = next;
	}
	*alst = prv;
}
