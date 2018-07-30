/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:33:08 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 12:47:34 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

static char		*get_options(char **arg)
{
	int		i;
	int		i2;
	char	*options;

	i = 1;
	options = ft_strdup("  ");
	while (arg[i])
	{
		if (arg[i][0] == '-' && (i2 = 1) == 1)
		{
			while (arg[i][i2])
			{
				if (arg[i][i2] == 'L')
					options[0] = 'L';
				if (arg[i][i2] == 'P')
					options[1] = 'P';
				i2++;
			}
		}
		i++;
	}
	return (options);
}

void			setoldpwd(t_list *envr)
{
	t_list	*tmp;
	char	*old;
	char	cwd[257];

	tmp = envr;
	getcwd(cwd, 256);
	old = ft_strjoin("OLDPWD=", cwd);
	while (tmp->next && !ft_strstart("OLDPWD=", tmp->content))
		tmp = tmp->next;
	if (ft_strstart("OLDPWD=", tmp->content))
	{
		ft_freestr(tmp->content);
		tmp->content = ft_strdup(old);
	}
	ft_freestr(old);
}

char			*changetield(char *path, t_list *envr)
{
	char	*new;

	if (!path)
		return (NULL);
	if (path[0] != '~')
		return (path);
	if (!(new = ft_strjoin(getenv_var("HOME", envr), (path + 1))))
		return (path);
	ft_strdel(&path);
	return (new);
}

void			changedir(char *path, t_list *envr)
{
	if (ft_strequ(getenv_var("PWD", envr), "/") && ft_strequ(path, ".."))
		return ;
	setoldpwd(envr);
	if (!path)
		path = ft_strdup(getenv_var("HOME", envr));
	if ((chdir(path)) == -1)
	{
		if (access(path, F_OK) == -1)
			ft_putstr("no such file or directory: ");
		else if (access(path, R_OK) == -1)
			ft_putstr("permission denied: ");
		else
			ft_putstr("not a directory: ");
		ft_putlstr(path);
	}
	ft_freestr(path);
}

void			cmd_cd(char **arg, t_list *envr)
{
	int		i;
	char	*options;

	if (arg[1])
		arg[1] = changetield(arg[1], envr);
	if ((i = 1) == 1 && !arg[2] && ft_strequ(arg[1], "-"))
	{
		ft_putlstr(getenv_var("OLDPWD", envr));
		changedir(ft_strdup(getenv_var("OLDPWD", envr)), envr);
		return ;
	}
	options = get_options(arg);
	while (arg[i] && arg[i][0] == '-' && arg[i][1])
		i++;
	if (arg[i] && arg[i + 1])
	{
		ft_putstr("cd: not in pwd: ");
		ft_putlstr(arg[i]);
	}
	else if (arg[i] && !ft_strequ(arg[i], "."))
		changedir(ft_strdup(arg[i]), envr);
	else
		changedir(NULL, envr);
	ft_freestr(options);
}
