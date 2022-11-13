/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:43:26 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/11 22:15:13 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	mlx_image_init(t_mlx_data *mlx_data)
{
	int	size;

	size = WINSIZE;
	mlx_data->wall_image = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/wall-_1_.xpm", &size, &size);
	mlx_data->space_image = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/white-_1_.xpm", &size, &size);
	mlx_data->player_image = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/lucas-_3__3.xpm", &size, &size);
	mlx_data->collection_image = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/ball-_1_.xpm", &size, &size);
	mlx_data->exit_image = mlx_xpm_file_to_image(mlx_data->mlx,
			"./images/exit1.xpm", &size, &size);
}

static void	put_inside_map_utils(t_mlx_data *mlx_data, int x, int y)
{
	if (mlx_data->map[y][x] == '0')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
			mlx_data->space_image, WINSIZE * x, WINSIZE * y);
	if (mlx_data->map[y][x] == '1')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
			mlx_data->wall_image, WINSIZE * x, WINSIZE * y);
	if (mlx_data->map[y][x] == 'P')
	{
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
			mlx_data->player_image, WINSIZE * x, WINSIZE * y);
		mlx_data->player_x = x;
		mlx_data->player_y = y;
	}
	if (mlx_data->map[y][x] == 'E')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
			mlx_data->exit_image, WINSIZE * x, WINSIZE * y);
	if (mlx_data->map[y][x] == 'C')
		mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win,
			mlx_data->collection_image, WINSIZE * x, WINSIZE * y);
}

static int	put_inside_map(t_mlx_data *mlx_data)
{
	int	y;
	int	x;

	y = 0;
	while (mlx_data->map[y])
	{
		x = 0;
		while (mlx_data->map[y][x] != '\0')
		{
			put_inside_map_utils(mlx_data, x, y);
			if (mlx_data->map[y][x] == '\n')
				break ;
			x++;
		}
		y++;
	}
	return (0);
}

int	init_mlx_map(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return (1);
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, WINSIZE
			* mlx_data->mlx_width, WINSIZE * mlx_data->mlx_hight, "so_long");
	mlx_image_init(mlx_data);
	mlx_loop_hook(mlx_data->mlx, put_inside_map, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, move_maps, mlx_data);
	mlx_hook(mlx_data->mlx_win, 17, 1L << 2, destroy_mlx, mlx_data);
	mlx_loop(mlx_data->mlx);
	return (0);
}
