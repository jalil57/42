/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:31:23 by jtaibi            #+#    #+#             */
/*   Updated: 2018/07/25 07:46:43 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

char	*putprompt(void)
{
	char	*prompt;
	char	cwd[4096];

	prompt = ft_strnew(0);
	getcwd(cwd, 4096);
	if (!ft_strrchr(cwd, '/') || ft_strequ(cwd, getenv_var("HOME", g_envr)))
		prompt = ft_strfjoin(prompt, "~", 1);
	else if (ft_strlen(ft_strrchr(cwd, '/')) > 1)
		prompt = ft_strfjoin(prompt, ft_strrchr(cwd, '/') + 1, 1);
	else
		ft_color("/", "lblue");
	prompt = ft_strfjoin(prompt, "->", 1);
	return (prompt);
}

char	*searchpath(char *cmd, t_list *envr)
{
	char	*bin;
	char	*path;

	path = getenv_var("PATH", envr);
	while (path)
	{
		bin = ft_strfjoin(ft_strsub(path, 0, ft_index(path, ':')), "/", 1);
		bin = ft_strfjoin(bin, cmd, 1);
		if (isexec(bin))
			return (bin);
		ft_freestr(bin);
		path = ft_strchr(path, ':') ? ft_strchr(path, ':') + 1 : NULL;
	}
	return (NULL);
}

void	get_cmd(char *lin, int len, t_list *envr)
{
	char			*exec;
	char			**arg;
	char			*cmd;
	char			*line;

	line = ft_strsub(lin, 0, len);
	cmd = ft_strsub(line, 0, ft_index(line, ' '));
	if (ft_strequ(cmd, "exit"))
		exit(0);
	if (!(arg = parsing(line)))
		return ;
	if (exec_builtins(cmd, line, arg, envr))
		;
	else if (isexec(cmd))
		execution(cmd, arg, envr);
	else if ((exec = searchpath(cmd, envr)))
	{
		execution(exec, arg, envr);
		ft_freestr(exec);
	}
	else
		not_found(cmd);
	ft_freetab(arg);
	ft_strdel(&cmd);
}

void	get_cmds(char **cmds, t_list *envr)
{
	int		i;

	i = 0;
	while (cmds[i])
	{
		if (ft_strlen(strzap(cmds[i])))
			get_cmd(strzap(cmds[i]), ft_strlen(cmds[i]),
					envr);
		i++;
	}
}

int		main(int ac, char **av, char **env)
{
	t_list	*envr;
	char	**cmds;
	char	*line;

	if (ac == 0 || !av[0])
		return (0);
	envr = init_envr(env);
	g_envr = envr;
	setoldpwd(envr);
	while (1)
	{
		signal(SIGINT, getmain_signal);
		ft_putstr(putprompt());
		get_line(&line);
		if (ft_strlen(strzap(line)) > 0 &&
				(cmds = ft_strsplit(strzap(line), ';')))
		{
			get_cmds(cmds, envr);
			ft_freetab(cmds);
		}
		ft_strdel(&line);
	}
	return (0);
}
