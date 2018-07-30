/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put2str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 21:56:53 by jtaibi            #+#    #+#             */
/*   Updated: 2018/04/01 16:32:43 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put2str(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		ft_putlstr(tab[i]);
		i++;
	}
}