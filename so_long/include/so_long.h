#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <libc.h>
#include <unistd.h>

# include "./ft_printf.h"
# include "./get_next_line.h"
# include "./libft.h"

int		args_error_handler(int argc, char **argv);
int		map_error_handler(char **map);
size_t	ft_strlen_so_long(const char *str);
char	**put_gnl(int fd, int line);

#endif