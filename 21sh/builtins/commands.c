/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:32:28 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/26 17:36:01 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char	*strzap(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return ((str + i));
}

void	execution(char *path, char **arg, t_list *envr)
{
	char	**env;
	pid_t	pid;

	pid = fork();
	if (!(env = ft_lsttab(envr)))
		exit(0);
	signal(SIGINT, get_signal);
	if (pid < 0)
		ft_putlstr("Fork failed");
	else if (pid == 0)
	{
		if (execve(path, arg, env) == -1)
		{
			ft_freetab(env);
			exit(0);
		}
	}
	ft_freetab(env);
	wait(&pid);
}

int		isexec(char *path)
{
	int				file;
	struct stat		*tmp;

	file = open(path, O_RDONLY);
	if (file > 0)
		close(file);
	else
		return (0);
	if (!(tmp = (struct stat *)malloc(sizeof(struct stat))))
		return (-1);
	lstat(path, tmp);
	if (ft_ftype(tmp->st_mode) != 'd' && (tmp->st_mode &
		S_IXUSR || tmp->st_mode & S_IXGRP || tmp->st_mode & S_IXOTH))
	{
		free(tmp);
		return (1);
	}
	free(tmp);
	return (0);
}

int		exec_builtins(char *cmd, char *line, char **arg, t_list *envr)
{
	if (ft_strequ(cmd, "cd"))
		cmd_cd(arg, envr);
	else if (ft_strequ(cmd, "echo"))
		cmd_echo(arg[1], ft_strchr(line, ' '), envr);
	else if (ft_strequ(cmd, "setenv"))
		cmd_setenv(ft_strchr(line, ' '), &envr);
	else if (ft_strequ(cmd, "unsetenv"))
		cmd_unsetenv(ft_strchr(line, ' '), &envr);
	else if (ft_strequ(cmd, "env"))
		cmd_env(envr);
	else
		return (0);
	return (1);
}
