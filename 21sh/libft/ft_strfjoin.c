/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:27:33 by jtaibi            #+#    #+#             */
/*   Updated: 2018/04/01 19:57:42 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strfjoin(char *s1, char *s2, int free)
{
	char	*n;

	if (s1 == NULL && s2)
		return (ft_strdup(s2));
	else if (s1 && s2 == NULL)
		return (ft_strdup(s1));
	if (!s1 && !s2)
		return (NULL);
	if (!(n = (char *)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	ft_strcpy(n, s1);
	ft_strcpy((n + ft_strlen(s1)), s2);
	if (free == 1 || free == 3)
		ft_memdel((void *)&s1);
	if (free == 2 || free == 3)
		ft_memdel((void *)&s2);
	return (n);
}
