/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freelst1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:53:31 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 16:53:35 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freelst1(t_list **lst)
{
	t_list	*tmp;

	tmp = *lst;
	if (tmp->content)
		free(tmp->content);
	*lst = tmp->next;
	free(tmp);
}
