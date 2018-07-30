/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_setenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:32:49 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 12:47:53 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

t_list	*lstaddend(t_list **envr, char *content)
{
	t_list		*tmp;

	tmp = *envr;
	while (tmp->next)
		tmp = tmp->next;
	if (!(tmp->next = (t_list *)malloc(sizeof(t_list))))
		return (*envr);
	tmp = tmp->next;
	tmp->content = content;
	tmp->next = NULL;
	return (*envr);
}

void	cmd_setenv(char *line, t_list **envr)
{
	char	*name;
	char	*value;
	char	*env;

	if (!line || !(ft_strchr(line, '=')))
	{
		ft_putlstr("usage: setenv KEY=value");
		return ;
	}
	name = ft_strsub(strzap(line), 0, ft_index(line, '='));
	if (name[ft_strlen(name) - 1] == '=')
		name[ft_strlen(name) - 1] = '\0';
	ft_strtoupper(name);
	if (getenv_var(name, *envr))
	{
		ft_strdel(&name);
		return ;
	}
	value = ft_strsub(line, ft_index(line, '='), ft_strlen(line));
	env = ft_strfjoin(name, value, 3);
	*envr = lstaddend(envr, env);
}

void	cmd_unsetenv(char *line, t_list **envr)
{
	t_list		*del;
	t_list		*tmp;
	char		*name;

	name = ft_strsub(strzap(line), 0, ft_index(line, '='));
	ft_strtoupper(name);
	if (!getenv_var(name, *envr))
	{
		ft_strdel(&name);
		return ;
	}
	tmp = *envr;
	del = tmp;
	while (!ft_strstart(name, tmp->content))
	{
		del = tmp;
		tmp = tmp->next;
	}
	del->next = tmp->next;
	if (tmp)
	{
		ft_freestr(tmp->content);
		free(tmp);
	}
	ft_strdel(&name);
}

void	cmd_env(t_list *envr)
{
	t_list		*tmp;

	tmp = envr;
	while (tmp)
	{
		ft_putlstr(tmp->content);
		tmp = tmp->next;
	}
}
