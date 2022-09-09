#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <libc.h>
#include <unistd.h>

# include "./ft_printf.h"
# include "./get_next_line.h"
# include "./libft.h"
# include "../mlx_linux/mlx.h"

# define WINSIZE 50


typedef struct s_mlx_data {
	void	*mlx;
	void	*mlx_win;
	void	*wall_image;
	void	*space_image;
	void	*player_image;
	void	*collection_image;
	void	*exit_image;
	char	**map;
	size_t	steps;
	size_t	mlx_width;
	size_t	mlx_hight;
	size_t	player_x;
	size_t	player_y;
	size_t	collection;

}t_mlx_data;


int		args_error_handler(int argc, char **argv);
int		map_error_handler(char **map);
size_t	ft_strlen_so_long(const char *str);
char	**put_gnl(int fd, int line);
void	init_mlx_map(t_mlx_data *mlx_data);
void	mlx_image_init(t_mlx_data	*mlx_data);
void	put_inside_map(t_mlx_data	*mlx_data);

#endif