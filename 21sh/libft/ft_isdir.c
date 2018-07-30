/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtaibi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/20 16:54:23 by jtaibi            #+#    #+#             */
/*   Updated: 2018/05/20 16:54:36 by jtaibi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdir(char *path)
{
	struct stat		*stats;

	if (!(stats = (struct stat *)malloc(sizeof(struct stat))))
		return (-1);
	lstat(path, stats);
	if (ft_ftype(stats->st_mode) == 'd')
	{
		free(stats);
		return (1);
	}
	free(stats);
	return (0);
}
