/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 17:33:58 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/29 15:17:33 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *first;
	t_list *tmp;

	tmp = f(lst);
	if ((new = ft_lstnew(tmp->content, tmp->size)) == NULL)
		return (NULL);
	first = new;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if ((new->next = ft_lstnew(tmp->content, tmp->size)) == NULL)
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (first);
}
