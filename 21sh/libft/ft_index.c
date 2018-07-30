/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:09:13 by jtaibi            #+#    #+#             */
/*   Updated: 2018/03/24 13:48:48 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_index(const char *str, char c)
{
	int index;

	index = 0;
	while (str[index] && str[index] != c)
		index++;
	return (index);
}
