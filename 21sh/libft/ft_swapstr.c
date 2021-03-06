/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:57:33 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 16:57:34 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_swapstr(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_strdup(s1);
	free(s1);
	s1 = ft_strdup(s2);
	free(s2);
	s2 = ft_strdup(tmp);
	free(tmp);
}
