/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 20:54:59 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/30 22:05:32 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		lstlen(t_list *list)
{
	t_list	*tmp;
	int		len;

	tmp = list;
	len = 0;
	while (tmp)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

char			**ft_lsttab(t_list *list)
{
	t_list	*tmp;
	int		i;
	char	**new;

	tmp = list;
	if (!(new = (char **)malloc(sizeof(char *) * lstlen(list) + 1)))
		return (NULL);
	i = 0;
	while (tmp)
	{
		new[i] = ft_strdup(tmp->content);
		i++;
		tmp = tmp->next;
	}
	new[i] = NULL;
	return (new);
}
