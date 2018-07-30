/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:08:06 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/23 15:49:25 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (char *)malloc(len + 1 * sizeof(char));
	if (!new || !s)
		return (NULL);
	while (i < len)
	{
		new[i] = s[(size_t)start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
