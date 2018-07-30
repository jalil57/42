/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:32:21 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/28 12:49:45 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpush(char *str, char c, size_t index)
{
	char	*new;

	if ((int)index < 0 || !c)
		return (str);
	if (index > ft_strlen(str))
		index = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	if (!c)
		return NULL;
	ft_strncpy(new, str, index);
	new[index] = c;
	ft_strcpy(new + index + 1, str + index);
	ft_strdel(&str);
	return (new);
}
