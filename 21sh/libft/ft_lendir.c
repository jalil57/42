/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lendir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:45:17 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 17:01:52 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lendir(char *path, int err, int cache)
{
	struct dirent	*dir_ent;
	DIR				*dir;
	int				len_dir;

	len_dir = 0;
	if (!(dir = opendir(path)) && err != 0)
		ft_erno(path);
	while ((dir_ent = readdir(dir)) != NULL)
	{
		if (cache == 0 && dir_ent->d_name[0] == '.')
			;
		else
			len_dir++;
	}
	free(dir_ent);
	closedir(dir);
	return (len_dir);
}
