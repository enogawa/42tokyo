/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:27:20 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/08 14:52:24 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int	argc, char	**argv)
{
	int		fd;
	int		line;
	char	**map;
	t_mlx_data	*mlx_data;

	if (args_error_handler(argc, argv))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write (2, "No maps\n", 9);
		return (1);
	}
	line = 0;
	mlx_data->map = put_gnl(fd, line);
	if (map_error_handler(mlx_data->map))
		return (0);
	init_mlx_map(mlx_data);
	//system("leaks so_long");
	return (0);
}
