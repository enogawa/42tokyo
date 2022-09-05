/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:27:20 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/01 23:16:35 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int	argc, char	**argv)
{
	int		fd;
	int		line;
	char	**map;

	if (args_error_handler(argc, argv))
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write (2, "No maps\n", 9);
		return (1);
	}
	line = 0;
	map = put_gnl(fd, line);
	// i = 0;
	// while (map[i])
	// {
	// 	printf("map; %s", map[i]);
	// 	i++;
	// }
	// printf("\n");
	if (map_error_handler(map))
		return (0);
	system("leaks so_long");
	return (0);
}
