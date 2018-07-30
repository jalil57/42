/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 12:52:00 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/28 12:55:34 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_straddend(char *str, char c)
{
	char	*new;

	if (!str || !c)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	ft_strcpy(new, str);
	new[ft_strlen(str)] = c;
	ft_strdel(&str);
	return (new);
}
