/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:31:58 by jtaibi            #+#    #+#             */
/*   Updated: 2018/06/27 21:18:11 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

void	not_found(char *cmd)
{
	ft_putstr("minishell: command not found '");
	ft_putstr(cmd);
	ft_putlstr("'");
}

void	get_signal(int ret)
{
	if (ret == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, get_signal);
	}
}

void	getmain_signal(int ret)
{
	if (ret == SIGINT)
	{
		ft_putchar('\n');
		signal(SIGINT, getmain_signal);
	}
}
