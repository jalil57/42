/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str2trim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 19:31:55 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/21 14:13:13 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_str2trim(char **str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (str[i])
	{
		tmp = ft_strtrim(str[i]);
		free(str[i]);
		if (ft_strlen(tmp) > 0)
			str[i] = ft_strdup(tmp);
		i++;
		free(tmp);
	}
}
