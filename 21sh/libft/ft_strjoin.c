/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:27:33 by jtaibi            #+#    #+#             */
/*   Updated: 2018/03/26 21:41:04 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;

	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	else if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	if (!(n = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1))
		&& (!s1 && !s2))
		return (NULL);
	ft_strcpy(n, s1);
	ft_strcpy((n + ft_strlen(s1)), s2);
	return (n);
}
