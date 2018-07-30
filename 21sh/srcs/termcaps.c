/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termcaps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 07:46:59 by jtaibi            #+#    #+#             */
/*   Updated: 2018/07/25 08:48:18 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/shell.h"

t_term		*init_term(void)
{
	t_term		*term;

	if (!(term = (t_term *)malloc(sizeof(t_term))))
		exit(-1);
	term->name = getenv("TERM");
	tgetent(NULL, term->name);
	tcgetattr(0, &term->old);
	tcgetattr(0, &term->term);
	term->term.c_lflag = (ICANON | ECHO);
	term->term.c_cc[VMIN] = 1;
	term->term.c_cc[VTIME] = 100;
	if (!isatty(STDERR_FILENO) ||
			!(term->fd = open(ttyname(STDERR_FILENO), O_RDWR)))
		exit(-1);
	if (tcsetattr(0, TCSANOW, &term->term) == -1)
		exit(-1);
	return (term);
}

void	get_line(char **line)
{
	char		buf[8];
	t_term		*term;

	if (!(term = init_term()))
		exit(-1);
	term->stack = ft_strnew(0);
	while (read(STDERR_FILENO, buf, 8) > 0 && buf[0] == '\n')
	{
		if (RIGHT)
			exit(0);
		else if (LEFT)
			exit(0);
		else
			ft_putchar_fd(buf[0], term->fd);
	}
	*line = term->stack;
}
