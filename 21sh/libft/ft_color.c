/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:52:30 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 14:29:49 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_color(char *str, char *color)
{
	int				i;
	static char		*colors[9] = {"black", "red", "green", "yellow", "blue",
		"lred", "lblue", "lgreen", "lcyan"};
	static char		*codes[9] = {"30m", "31m", "32m;", "33m", "34m", "91m",
		"94m", "92m", "96m"};

	i = 0;
	while (i < 7 && ft_strcmp(colors[i], color) != 0)
		i++;
	ft_putstr("\033[");
	ft_putstr(codes[i]);
	ft_putstr(str);
	ft_putstr("\033[39m");
	return (ft_strlen(str));
}
