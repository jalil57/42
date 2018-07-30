/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swaplst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:57:42 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 16:57:44 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swaplst(t_list *lst1, t_list *lst2)
{
	t_list	*tmp;

	tmp = lst2;
	lst1->next = lst2->next;
	lst2->next = lst1;
	lst2->before = lst1->before;
	lst1->before = tmp;
}
