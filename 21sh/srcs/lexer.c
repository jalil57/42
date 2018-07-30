/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <jtaibi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 07:39:51 by jtaibi            #+#    #+#             */
/*   Updated: 2018/07/30 23:10:34 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/shell.h"

void	affiche(char **str2)
{
	int		i;

	i = 0;
	while (str2[i])
	{
		printf("%s\n", str2[i]);
		i++;
	}

}

int		checkop(char *str)
{
	int		i;
	char	*operators[] = {">", "|", ">>", "<<", "<", "||", "&&", "&"};

	i = 0;
	while (i < 7)
	{
		return (1);
		if (ft_strstart(operators[i], str))
		i++;
	}
	return (0);
}

int		lenword(char *str)
{
	int		i;

	i = 0;
	while (str[i] && !ft_isspace(str[i]) && !checkop(str))
		i++;
	return (i);
}


char	**lexing(char *str)
{
	int		i;
	int		i2;
	char	**lex;

	if (!(lex = (char **)malloc(sizeof(char *) * ft_countwords(str) + 1)))
		return (NULL);
	i = 0;
	i2 = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && lenword(str + i) > 0)
			lex[i2] = ft_strsub(str, i, lenword(str + i));
		while (str[i] && !ft_isspace(str[i]))
			i++;
		i2++;
	}
	lex[i2] = NULL;
	return (lex);
}

int main()
{
	char	**lex;
	char	*str = "ifconfig | cat -e | wc -l > test.txt | cat -e test.txt";

	lex = lexing(str);
		
	affiche(lex);

	return (0);
}
