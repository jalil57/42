/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:55:37 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 16:56:12 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		not_found(char *name, char c)
{
	ft_putstr(name);
	ft_putstr(": invalid option: -- '");
	ft_putchar(c);
	ft_putstr("'\n");
	exit(0);
}

char			*ft_options(char *name, char **arg, char *list)
{
	int		i;
	int		i2;
	char	*options;

	if (!(options = ft_strcreate(ft_strlen(list), ' ')))
		return (NULL);
	i = 0;
	while (arg[i])
	{
		if (arg[i][0] && arg[i][0] == '-' && arg[i][1])
		{
			i2 = 1;
			while (arg[i][i2])
			{
				if (ft_strchr(list, arg[i][i2]))
					options[ft_index(list, arg[i][i2])] =
						list[ft_index(list, arg[i][i2])];
				else
					not_found(name, arg[i][i2]);
				i2++;
			}
		}
		i++;
	}
	return (options);
}
