/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:00:23 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 17:00:31 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcreate(size_t n, char c)
{
	int		i;
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = 0;
	while (i < (int)n)
	{
		str[i] = c;
		i++;
	}
	str[i] = '\0';
	return (str);
}
