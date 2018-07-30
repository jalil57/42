/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:31:00 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 12:46:48 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char	*getenv_var(char *var, t_list *envr)
{
	t_list		*tmp;

	tmp = envr;
	while (tmp)
	{
		if (ft_strncmp(tmp->content, var, ft_index(tmp->content, '=')) == 0)
			return (ft_strchr(tmp->content, '=') + 1);
		tmp = tmp->next;
	}
	return (NULL);
}

t_list	*init_envr(char **env)
{
	int			i;
	t_list		*tmp;
	t_list		*envr;

	i = ft_tablen(env) - 1;
	if (!(envr = (t_list *)malloc(sizeof(t_list))))
		exit(0);
	envr->content = ft_strdup(env[i]);
	envr->next = NULL;
	i--;
	while (i >= 0)
	{
		if (!(tmp = (t_list *)malloc(sizeof(t_list))))
			exit(0);
		tmp->content = ft_strdup(env[i]);
		ft_lstadd(&envr, tmp);
		i--;
	}
	return (envr);
}
