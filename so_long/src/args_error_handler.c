#include "so_long.h"

int	args_error_handler(int argc, char **argv)
{
	int len;

	if (argc != 2)
	{
		write (2, "invalid number of args\n", 24);
		return (1);
	}
	len = ft_strlen(argv[1]);
	if (ft_strncmp(argv[1] + (len - 4), ".ber", 4) != 0)
	{
		write (2, "invalid map name\n", 18);
		return (1);
	}
	return(0);
}