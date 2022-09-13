/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:27:20 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/13 12:01:51 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int	argc, char	**argv)
{
	int			fd;
	int			line;
	t_mlx_data	*mlx_data;
	//int			i;

	mlx_data = malloc(sizeof(t_mlx_data));
	if (!mlx_data)
		return (1);
	if (args_error_handler(argc, argv))
		return (1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write (2, "No maps\n", 9);
		return (1);
	}
	line = 0;
	mlx_data->map = put_gnl(fd, line);
	// i = 0;
	// while(mlx_data->map[i])
	// {
	// 	printf("%s", mlx_data->map[i]);
	// 	i++;
	// }
	mlx_data->mlx_width = ft_strlen_so_long(mlx_data->map[0]);
	while (mlx_data->map[mlx_data->mlx_hight])
		mlx_data->mlx_hight++;
	//printf("%zu", mlx_data->mlx_width);

	// printf("hight; %zu", mlx_data->mlx_hight);
	// printf("width; %zu", mlx_data->mlx_width);
	if (map_error_handler(mlx_data->map))
		return (1);
	
	init_mlx_map(mlx_data);
	//mlx_loop(mlx_data->mlx);
	return (0);
}

	// ft_bzero(&mlx_data, sizeof(t_mlx_data));