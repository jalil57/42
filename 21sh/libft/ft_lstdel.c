/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 13:41:07 by jtaibi            #+#    #+#             */
/*   Updated: 2018/07/01 19:45:52 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst)
{
	t_list *tmp;
	t_list *nxt;

	tmp = *alst;
	while (tmp)
	{
		ft_strdel(&tmp->content);
		nxt = tmp;
		free(tmp);
		tmp = nxt->next;
	}
	*alst = NULL;
}
