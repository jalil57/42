/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversedir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:00:43 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 17:00:44 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dir	*ft_reversedir(t_dir **dir)
{
	t_dir	*tmp;
	t_dir	*stock;
	t_dir	*ret;

	tmp = *dir;
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
