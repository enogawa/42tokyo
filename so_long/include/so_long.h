/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:59:38 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/26 17:21:21 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <libc.h>
# include <unistd.h>

# include "./ft_printf.h"
# include "./get_next_line.h"
# include "./libft.h"
# include "../minilibx-linux/mlx.h"

# define WINSIZE 50
# define ESC_KEY 65307

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
int		map_error_handler(char **map, t_mlx_data	*mlx_data);
size_t	ft_strlen_so_long(const char *str);
char	**put_gnl(int fd, int line);
int		init_mlx_map(t_mlx_data *mlx_data);
int		destroy_mlx(t_mlx_data *mlx_data);
int		move_maps(int key_num, t_mlx_data *mlx_data);
int		too_much_pe(int *pec_count);
int		is_there_pec(int *pec_count);
void	dfs_map_error(char **dfs_map);
char	**dup_map(char **map, t_mlx_data	*mlx_data);
int		check_e_c(char **dfs_map, int c);
int		ft_strchr_so_long(const char *str, int c);

#endif
