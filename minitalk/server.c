#include "minitalk.h"

t_signal	g_signal;

void	get_pid(void)
{
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	ft_putstr_fd("\n", STDOUT_FILENO);
}

void	put_character(int signal)
{
	if (signal == SIGUSR1)
		g_signal.letter = g_signal.letter | (0b100000000 >> g_signal.count);
	if (g_signal.count == 1)
	{
		ft_putchar_fd(g_signal.letter, STDOUT_FILENO);
		g_signal.letter = 0;
		g_signal.count = 8;
		return ;
	}

	g_signal.count--;
}

int	main(void)
{
	g_signal.letter = 0;
	g_signal.count = 8;
	get_pid();
	signal(SIGUSR1, put_character);
	signal(SIGUSR2, put_character);
	while (1)
		pause();
}