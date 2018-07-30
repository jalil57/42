/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 17:01:05 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/21 14:43:05 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str2add(char **str2, char *str)
{
	int		i;
	char	**new;

	if (!(new = (char **)malloc(sizeof(char *) * ft_tablen(str2) + 2)))
		return (NULL);
	i = 0;
	while (str2[i])
	{
		new[i] = str2[i];
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	ft_memdel((void *)&str2);
	return (new);
}
