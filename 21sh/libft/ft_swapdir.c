/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:57:55 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 16:57:56 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapdir(t_dir *d1, t_dir *d2)
{
	t_dir	*tmp;
	t_dir	*tmp2;

	tmp = d2->next;
	tmp2 = d2->before;
	d2->next = d1->next;
	d2->before = d1->before;
	d1->next = tmp;
	d1->before = tmp2;
	d1->next->before = d1;
	if (d1->before)
		d1->before->next = d1;
	d2->next->before = d2;
	if (d2->before)
		d2->before->next = d2;
}
