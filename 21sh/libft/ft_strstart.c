/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:57:11 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 16:57:13 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstart(char *start, char *str)
{
	int		i;

	i = 0;
	while (str[i] && start[i] && str[i] == start[i])
		i++;
	if (i == (int)ft_strlen(start))
		return (1);
	return (0);
}
