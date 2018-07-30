/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpushstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:32:11 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/27 14:38:27 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpushstr(char *str, char *str2, size_t index)
{
	char	*new;

	if ((int)index < 0 || index > ft_strlen(str2) || !str2)
		return (str);
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str) +
					ft_strlen(str2) + 2)))
		return (NULL);
	ft_strncpy(new, str, index);
	ft_strcpy(new + index, str2);
	ft_strcpy(new + index + ft_strlen(str2), str + index);
	return (new);
}
