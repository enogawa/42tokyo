/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:57:43 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/26 13:41:37 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_collections(t_mlx_data *mlx_data)
{
	size_t	x;
	size_t	y;

	x = 0;
	while (mlx_data->map[x])
	{
		y = 0;
		while (mlx_data->map[x][y])
		{
			if (mlx_data->map[x][y] == 'C')
			{
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

static void	make_it_finished(t_mlx_data *mlx_data)
{
	mlx_data->steps++;
	ft_printf("walked %d stepps\n", mlx_data->steps);
	ft_printf("FINISHED!!\n");
	destroy_mlx(mlx_data);
}

static void	move_p(t_mlx_data *mlx_data, int y, int x)
{
	if (mlx_data->map[mlx_data->player_y + y][mlx_data->player_x + x] != '1')
	{
		if (mlx_data->map[mlx_data->player_y + y][mlx_data->player_x
			+ x] != 'E')
		{
			mlx_data->map[mlx_data->player_y][mlx_data->player_x] = '0';
			mlx_data->map[mlx_data->player_y + y][mlx_data->player_x + x] = 'P';
			mlx_data->steps++;
			ft_printf("walked %d stepps\n", mlx_data->steps);
			mlx_data->player_x += x;
			mlx_data->player_y += y;
		}
		else
		{
			if (check_collections(mlx_data) == 0)
				make_it_finished(mlx_data);
		}
	}
}

int	move_maps(int key_num, t_mlx_data *mlx_data)
{
	// printf("%d\n", key_num);
	if (key_num == ESC_KEY)
		destroy_mlx(mlx_data);
	if (key_num == 'w')
		move_p(mlx_data, -1, 0);
	if (key_num == 'd')
		move_p(mlx_data, 0, 1);
	if (key_num == 'a')
		move_p(mlx_data, 0, -1);
	if (key_num == 's')
		move_p(mlx_data, 1, 0);
	return (0);
}
