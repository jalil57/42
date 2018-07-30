/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 12:14:46 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 12:21:45 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdelone(char *str, size_t index)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (str);
	ft_strncpy(new, str, index);
	ft_strcpy(new + index, str + index + 1);
	ft_strdel(&str);
	return (new);
}
