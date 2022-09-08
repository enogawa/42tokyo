#include "so_long.h"

void	init_mlx_map(t_mlx_data *mlx_data)
{
	mlx_data->mlx = mlx_init();
	mlx_data->mlx_win = mlx_new_window(mlx_data->mlx, mlx_data->mlx_width, mlx_data->mlx_hight, "so_long");
	mlx_image_init(mlx_data);
	put_inside_map(mlx_data);
	
}
void	mlx_image_init(t_mlx_data	*mlx_data)
{
	mlx_data->wall_image = mlx_xpm_file_to_image(mlx_data->mlx, "", image_size, image_size);
	mlx_data->space_image = mlx_xpm_file_to_image(mlx_data->mlx, "", image_size, image_size);
	mlx_data->player_image = mlx_xpm_file_to_image(mlx_data->mlx, "", image_size, image_size);
	mlx_data->collection_image = mlx_xpm_file_to_image(mlx_data->mlx, "", image_size, image_size);
	mlx_data->exit_image = mlx_xpm_file_to_image(mlx_data->mlx, "", image_size, image_size);
}

void	put_inside_map(t_mlx_data	*mlx_data)
{
	int	y;
	int x;

	x = 0;
	y = 0;
	while (mlx_data->map[x])
	{
		while (mlx_data->map[x][y] != '\0')
		{
			if (mlx_data->map[x][y] == '0')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->space_image, x, y);//put_empty
			if (mlx_data->map[x][y] == '1')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->wall_image, x, y);//put_wall
			if (mlx_data->map[x][y] == 'P')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->player_image, x, y);//put_player
			if (mlx_data->map[x][y] == 'E')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->exit_image, x, y);//put_exit
			if (mlx_data->map[x][y] == 'C')
				mlx_put_image_to_window(mlx_data->mlx, mlx_data->mlx_win, mlx_data->collection_image, x, y);//put_collectible
			if (mlx_data->map[x][y] == '\n')
				break ;
			y++;
		}
		x++;
	}
	

}
