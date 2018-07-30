/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverselst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:00:53 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 17:00:54 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_reverselst(t_list **lst)
{
	t_list	*tmp;
	t_list	*stock;
	t_list	*ret;

	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	ret = tmp;
	while (tmp->before)
	{
		stock = tmp->before;
		tmp->before = tmp->next;
		tmp->next = stock;
		tmp = stock;
	}
	return (ret);
}
