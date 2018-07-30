/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:32:57 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 12:47:45 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void			putline(char *line, int *i, t_list *envr)
{
	char	*var;

	while (line[*i] && ft_isascii(line[*i]) && line[*i] != '"')
	{
		if (line[*i] == '$' && ft_isalnum(line[*i + 1]) &&
				(var = ft_strsub(line, *i + 1, ' ')))
		{
			ft_putstr(getenv_var(var, envr));
			while (line[*i] && line[*i] != ' ' && line[*i] != '\t')
				*i += 1;
			if (line[*i] && line[*i + 1])
				ft_putchar(' ');
			ft_freestr(var);
			break ;
		}
		else if (line[*i] && line[*i] != ' ' && line[*i] != '\t')
			ft_putchar(line[*i]);
		else if (line[*i])
		{
			ft_putchar(' ');
			break ;
		}
		*i += 1;
	}
}

void			cmd_echo(char *arg, char *line, t_list *envr)
{
	int		i;

	if (!line)
		return ;
	if ((i = 1) && arg && arg[0] == '-' && arg[1] == 'n' && !arg[2])
		i = 4;
	while (line[i])
	{
		if (line[i] == '"')
		{
			ft_putnstr((line + i + 1), ft_index(line + i + 1, '"'));
			i += ft_index(line + i + 1, '"') + 1;
		}
		while (line[i] && (line[i] == ' ' || line[i] == '\t'))
			i++;
		putline(line, &i, envr);
	}
	if (!(arg[0] == '-' && arg[1] == 'n' && !arg[2]))
		ft_putchar('\n');
}
