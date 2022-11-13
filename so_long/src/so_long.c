/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:27:20 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/12 17:07:24 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	count_hight_width(t_mlx_data *mlx_data)
{
	mlx_data->mlx_width = ft_strlen_so_long(mlx_data->map[0]);
	while (mlx_data->map[mlx_data->mlx_hight])
		mlx_data->mlx_hight++;
}

static int	free_data(t_mlx_data *mlx_data, int i)
{
	int	y;

	free(mlx_data);
	y = 0;
	if (i == 1)
	{
		while (mlx_data->map[y])
		{
			free(mlx_data->map[y]);
			y++;
		}
		free(mlx_data->map);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int			fd;
	int			line;
	t_mlx_data	*mlx_data;

	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		return (1);
	mlx_data->steps = 0;
	mlx_data->mlx_hight = 0;
	if (args_error_handler(argc, argv))
		return (free_data(mlx_data, 0));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "No maps\n", 9);
		return (free_data(mlx_data, 0));
	}
	line = 0;
	mlx_data->map = put_gnl(fd, line);
	if (!mlx_data->map[0])
		return (free_data(mlx_data, 1));
	count_hight_width(mlx_data);
	if (map_error_handler(mlx_data->map, mlx_data) || init_mlx_map(mlx_data))
		return (free_data(mlx_data, 1));
	return (0);
}
// int	main(int argc, char **argv)
// l43 free gnl free data
// l48 free gnl

// static int	p_e_c_error(char **map)
// strchr p e だめ 

// int	map_error_handler(char **map, t_mlx_data	*mlx_data)
// l129 free dfs_map
// l130 free dfs_map
