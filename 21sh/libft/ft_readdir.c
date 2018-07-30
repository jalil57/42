/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:43:53 by jtaibi            #+#    #+#             */
/*   Updated: 2018/04/01 20:40:59 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_readdir(char *path, int a)
{
	int				i;
	struct dirent	*dir_ent;
	DIR				*dir;
	char			**files;

	i = 0;
	if (!(dir = opendir(path)))
		return (NULL);
	if (!(files = (char **)malloc(sizeof(char *) * ft_lendir(path, 1, a) + 1)))
		return (NULL);
	while (dir && (dir_ent = readdir(dir)))
	{
		if (!a && dir_ent->d_name[0] == '.')
			i--;
		else
			files[i] = ft_strdup(dir_ent->d_name);
		i++;
	}
	files[i] = NULL;
	free(dir_ent);
	closedir(dir);
	return (files);
}
