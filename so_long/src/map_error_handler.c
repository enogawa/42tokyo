#include "so_long.h"

int	wall_error(char	**map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][ft_strlen_so_long(map[i]) - 1] != '1')
		{
			write (2, "invalid wall map\n", 18);
			return (1);
		}
		j = 0;
		while ((i == 0 || !map[i + 1]) && (map[i][j] != '\n' && map[i][j] != '\0'))
		{
			if (map[i][j] != '1')
			{
				write (2, "invalid wall map\n", 18);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int P_E_C_error(char **map)
{
	int *PEC_count;
	int i;
	
	PEC_count = ft_calloc(3, sizeof(int));
	i = 0;
	while (map[i])
	{
		if (ft_strchr(map[i], 'P'))
			PEC_count[0] += 1;
		if (ft_strchr(map[i], 'E'))
			PEC_count[1] += 1;
		if (ft_strchr(map[i], 'C'))
			PEC_count[2] += 1;
		if (PEC_count[0] > 1 || PEC_count[1] > 1)
		{
			write (2, "too much P or E\n", 17);
			// free(PEC_count);
			return (1);
		}
		i++;
	}
	if (PEC_count[0] == 0 || PEC_count[1] == 0 || PEC_count[2] == 0)
	{
		write (2, "not found P, E, or C\n", 22);
		// free(PEC_count);
		return (1);
	}
	free(PEC_count);
	return (0);
}

int	shape_error(char **map)
{
	size_t len;
	int i;

	len = ft_strlen_so_long(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen_so_long(map[i]) != len)
		{
			write (2, "invalid shape of map\n", 22);
			return (1);
		}
		i++;
	}
	return (0);
}

int characters_error(char **map)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != 'C' && map[i][j] != '\n')
			{
				write (2, "invalid characters in map\n", 27);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	map_error_handler(char **map)
{
	if (wall_error(map))
		return (1);
	if (P_E_C_error(map))
		return (1);
	if (shape_error(map))
		return (1);
	if (characters_error(map))
		return (1);
	return(0);
}

