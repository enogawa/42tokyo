#include "so_long.h"

void	mlx_image_init(t_mlx_data	*mlx_data)
{
	int size = WINSIZE;
	mlx_data->wall_image = mlx_xpm_file_to_image(mlx_data->mlx, "./images/wall1.xpm", &size, &size);
	mlx_data->space_image = mlx_xpm_file_to_image(mlx_data->mlx, "./images/empty1.xpm", &size, &size);
	mlx_data->player_image = mlx_xpm_file_to_image(mlx_data->mlx, "./images/player1_down.xpm", &size, &size);
	mlx_data->collection_image = mlx_xpm_file_to_image(mlx_data->mlx, "./images/item1.xpm", &size, &size);
	mlx_data->exit_image = mlx_xpm_file_to_image(mlx_data->mlx, "./images/exit1.xpm", &size, &size);
}

int put_inside_map(t_mlx_data	*mlx_data)
{
	int	y;
	int x;

	x = 0;
	while (mlx_data->map[x])
	{
		y = 0;
		while (mlx_data->map[x][y] != '\0')
		{
			if (mlx_data->map[x][y] == '0')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->space_image, WINSIZE * y, WINSIZE * x);//put_empty
			if (mlx_data->map[x][y] == '1')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->wall_image, WINSIZE * y, WINSIZE * x);//put_wall
			if (mlx_data->map[x][y] == 'P')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->player_image, WINSIZE * y, WINSIZE * x);//put_player
			if (mlx_data->map[x][y] == 'E')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->exit_image, WINSIZE * y, WINSIZE * x);//put_exit
			if (mlx_data->map[x][y] == 'C')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->collection_image, WINSIZE * y, WINSIZE * x);//put_collectible
			if (mlx_data->map[x][y] == '\n')
				break ;
			y++;
		}
		x++;
	}
	return (0);
}
void	init_mlx_map(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	if (!mlx_data->mlx)
		return ;
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, WINSIZE * mlx_data->mlx_width, WINSIZE * mlx_data->mlx_hight, "so_long");
	mlx_image_init(mlx_data);

	put_inside_map(mlx_data);
	mlx_loop_hook(mlx_data->mlx, put_inside_map, mlx_data);
	mlx_hook(mlx_data->mlx_win, 2, 1L << 0, move_maps, mlx_data);
	mlx_hook(mlx_data->mlx_win, 17, 1L << 2, destroy_mlx, mlx_data);
	mlx_loop(mlx_data->mlx);
}
