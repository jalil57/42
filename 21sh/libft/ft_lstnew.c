/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:56:41 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/29 15:16:15 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if ((new = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (!content)
	{
		new->content = NULL;
		new->size = 0;
	}
	else
	{
		if ((new->content = malloc(sizeof(content))) == NULL)
			return (NULL);
		new->size = content_size;
		ft_memcpy(new->content, content, new->size);
	}
	new->next = NULL;
	new->before = NULL;
	return (new);
}
