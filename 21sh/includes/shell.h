/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 15:36:05 by jtaibi            #+#    #+#             */
/*   Updated: 2018/07/25 07:59:59 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H
# include "../libft/libft.h"
# include <termcap.h>
# include <termios.h>
# include <term.h>
# include <curses.h>
# include <stdint.h>

# define SHIFTL (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59\
		&& buf[4] == 50 && buf[5] == 68)
# define SHIFTR (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59\
		&& buf[4] == 50 && buf[5] == 67)
# define SHIFTUP (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59\
		&& buf[4] == 50 && buf[5] == 65)
# define SHIFTDWN (buf[0] == 27 && buf[1] == 91 && buf[2] == 49 && buf[3] == 59\
		&& buf[4] == 50 && buf[5] == 66)
# define CTRLL (buf[0] == 12)
# define CTRLP (buf[0] == 16)
# define ENTER ((buf[0] == 10 && buf[1] == 0 )|| (buf[0] == 13 && buf[1] == 0))
# define SPACE	(buf[0] == 32 && buf[1] == 0)
# define SUPP	(buf[0] == 127)
# define DEL	(buf[0] == 27 && buf[1] == 91 && buf[2] == 51 && buf[3] == 126)
# define HOME	(buf[0] == 27 && buf[1] == 91 && buf[2] == 72)
# define END	(buf[0] == 27 && buf[1] == 91 && buf[2] == 70)
# define UP		(buf[0] == 27 && buf[1] == 91 && buf[2] == 53 && buf[3] == 126)
# define DOWN	(buf[0] == 27 && buf[1] == 91 && buf[2] == 54 && buf[3] == 126)
# define HAUT	(buf[0] == 27 && buf[1] == 91 && buf[2] == 65)
# define BAS	(buf[0] == 27 && buf[1] == 91 && buf[2] == 66)
# define LEFT	(buf[0] == 27 && buf[1] == 91 && buf[2] == 68)
# define RIGHT	(buf[0] == 27 && buf[1] == 91 && buf[2] == 67)
# define MULTIUP (buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 65)
# define MULTIDO (buf[0] == 27 && buf[1] == 27 && buf[2] == 91 && buf[3] == 66)
# define TAB	(buf[0] == 9)

typedef struct		s_term
{
	struct termios	term;
	struct termios	old;
	char			*name;
	char			*prompt;
	char			*stack;
	int				fd;

	char			*tc_left;
	char			*tc_right;
	char			*tc_up;
	char			*tc_do;

	int				icpy;
	char			*copy;

	int				x;
	int				y;
}					t_term;

void	get_line(char **line);
t_list	*g_envr;

t_list	*init_envr(char **env);
int		isexec(char *path);
int		exec_builtins(char *cmd, char *line, char **arg, t_list *envr);
char	*getenv_var(char *var, t_list *envr);
char	*modifenv_var(char *var, char *modif);
char	*strzap(char *str);
char	**parsing(char *line);
void	not_found(char *cmd);
char	*putprompt(void);
void	execution(char *path, char **arg, t_list *envr);
void	cmd_cd(char **arg, t_list *envr);
void	cmd_echo(char *arg, char *line, t_list *envr);
void	cmd_setenv(char *line, t_list **envr);
void	cmd_unsetenv(char *line, t_list **envr);
void	cmd_env(t_list *envr);
void	get_signal(int ret);
void	getmain_signal(int ret);
void	addoldpwd();
void	setoldpwd(t_list *envr);

#endif
