#include "minitalk.h"

void	send_str(int pid, char *str)
{
	int	kill_status;
	int	i;
	int	shift_num;

	i = 0;
	while (str[i] != '\0')
	{
		shift_num = 0;
		while (shift_num < 8)
		{
			if(str[i] >> shift_num & 0b000000001)
				kill_status = kill(pid, SIGUSR1);
			else
				kill_status = kill(pid, SIGUSR2);
			if(kill_status == -1)
				write(2, "kill error", 11);
			shift_num++;
			usleep(10000);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		write(2, "invalid argument\n", 18);
		return (0);
	}
	if (ft_strlen(argv[1]) > 7)
	{
		write(2, "too long pid", 13);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	send_str(pid, argv[2]);
}
//test