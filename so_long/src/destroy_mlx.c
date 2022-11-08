/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 19:39:29 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:43:52 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_mlx(t_mlx_data *mlx_data)
{
	int	x;

	mlx_destroy_image(mlx_data->mlx, mlx_data->wall_image);
	mlx_destroy_image(mlx_data->mlx, mlx_data->space_image);
	mlx_destroy_image(mlx_data->mlx, mlx_data->player_image);
	mlx_destroy_image(mlx_data->mlx, mlx_data->exit_image);
	mlx_destroy_image(mlx_data->mlx, mlx_data->collection_image);
	x = 0;
	while (mlx_data->map[x])
	{
		free(mlx_data->map[x]);
		x++;
	}
	free(mlx_data->map);
	exit(0);
}
