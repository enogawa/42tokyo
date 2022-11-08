/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_gnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 19:39:05 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/01 19:39:06 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**put_gnl(int fd, int line)
{
	char	**map;
	char	*tmp;

	tmp = get_next_line(fd);
	if (!tmp)
	{
		map = malloc(sizeof(char **) * (line + 1));
		map[line] = NULL;
		return (map);
	}
	else
	{
		map = put_gnl(fd, line + 1);
		map[line] = tmp;
		return (map);
	}
}
