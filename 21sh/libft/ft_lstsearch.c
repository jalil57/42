/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsearch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 21:42:41 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/28 21:44:17 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstsearch(t_list *list, char *content)
{
	t_list		*tmp;

	tmp = list;
	while (tmp->next)
	{
		if (tmp->content == content)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
