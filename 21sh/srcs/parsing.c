/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:56:01 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 12:46:54 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char	*get_word(char *str)
{
	int		len;

	len = 0;
	while (str[len] && !ft_isspace(str[len]))
		len++;
	return (ft_strsub(str, 0, len));
}

int		nbwords(char *line)
{
	int		i;
	int		nb;

	nb = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i])
			nb++;
		while (line[i] && !ft_isspace(line[i]))
			i++;
	}
	return (nb);
}

char	**parsing(char *line)
{
	char	**pars;
	int		p;
	int		i;

	if (!(pars = (char **)malloc(sizeof(char *) * nbwords(line) + 1)))
		return (NULL);
	i = 0;
	p = 0;
	while (line[i])
	{
		while (line[i] && ft_isspace(line[i]))
			i++;
		if (line[i])
		{
			pars[p] = get_word((line + i));
			p++;
		}
		while (line[i] && !ft_isspace(line[i]))
			i++;
	}
	pars[p] = NULL;
	ft_strdel(&line);
	return (pars);
}
