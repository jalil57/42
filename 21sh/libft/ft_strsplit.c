/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:48:28 by jtaibi            #+#    #+#             */
/*   Updated: 2018/07/29 08:35:18 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		isintab(char *str2, char c)
{
	int		i;

	i = 0;
	while (str2[i])
	{
		if (str2[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		count_words(char *s, char *c)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i])
	{
		while (s[i] && isintab(c, s[i]))
			i++;
		if (s[i])
			nb++;
		while (s[i] && !isintab(c, s[i]))
			s[i]++;
	}
	return (nb);
}

static int		count_len_word(char *s, int index, char *c)
{
	int	len;

	len = 0;
	while (s[index + len] && isintab(c, s[index + len]))
		len++;
	return (len);
}

static	char	**create_tab(char *s, char *c)
{
	char	**tab;
	int		nbmots;
	int		index;
	int		i;

	nbmots = count_words(s, c);
	if ((tab = (char **)malloc((nbmots + 1) * sizeof(char *))) == NULL)
		return (NULL);
	tab[nbmots] = NULL;
	index = 0;
	i = 0;
	while (i < nbmots)
	{
		while (s[index] && isintab(c, s[index]))
			index++;
		tab[i] = (char *)malloc(count_len_word(s, index, c) * sizeof(char));
		if (tab[i] == NULL)
			return (NULL);
		while (s[index] && isintab(c, s[index]))
			index++;
		i++;
	}
	return (tab);
}

char			**ft_strsplit(char const *s, char *c)
{
	char	**new;
	int		len;
	int		i;
	int		x;

	if (!s || (!(new = create_tab((char *)s, c))))
		return (NULL);
	i = 0;
	x = 0;
	while (new[i])
	{
		while (s[x] && isintab(c, s[x]))
			x++;
		len = count_len_word((char *)s, x, c);
		ft_strncpy(new[i], s + x, len);
		new[i][len] = '\0';
		while (s[x] && !isintab(c, s[x]))
			x++;
		i++;
	}
	return (new);
}
