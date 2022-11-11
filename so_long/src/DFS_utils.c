/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DFS_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 17:57:42 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/11 19:39:47 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**dup_map(char **map, t_mlx_data	*mlx_data)
{
	int		y;
	char	**dup;

	y = 0;
	dup = (char **)malloc(sizeof(char *) * mlx_data->mlx_hight + 1);
	while (map[y])
	{
		dup[y] = ft_strdup(map[y]);
		y++;
	}
	dup[y] = NULL;
	return (dup);
}

char	**dfs_map_error_utils(char **dfs_map, int y, int x)
{
	if (dfs_map[y - 1][x] != '1' && dfs_map[y - 1][x] != 'M')
	{
		dfs_map[y - 1][x] = 'M';
		dfs_map_error_utils(dfs_map, y - 1, x);
	}
	if (dfs_map[y + 1][x] != '1' && dfs_map[y + 1][x] != 'M')
	{
		dfs_map[y + 1][x] = 'M';
		dfs_map_error_utils(dfs_map, y + 1, x);
	}
	if (dfs_map[y][x - 1] != '1' && dfs_map[y][x - 1] != 'M')
	{
		dfs_map[y][x - 1] = 'M';
		dfs_map_error_utils(dfs_map, y, x - 1);
	}
	if (dfs_map[y][x + 1] != '1' && dfs_map[y][x + 1] != 'M')
	{
		dfs_map[y][x + 1] = 'M';
		dfs_map_error_utils(dfs_map, y, x + 1);
	}
	return (dfs_map);
}

char	**dfs_map_error(char **dfs_map)
{
	int	y;
	int	x;

	y = 0;
	while (dfs_map[y])
	{
		x = 0;
		while (dfs_map[y][x])
		{
			if (dfs_map[y][x] == 'P')
				return (dfs_map_error_utils(dfs_map, y, x));
			x++;
		}
		y++;
	}
	return (NULL);
}

int	check_e_c(char **dfs_map, int c)
{
	int	y;

	y = 0;
	while (dfs_map[y])
	{
		if (ft_strchr(dfs_map[y], c))
		{
			write(2, "You can't get goal with this map", 33);
			return (1);
		}
		y++;
	}
	return (0);
}
