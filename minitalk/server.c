/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:45:38 by enogawa           #+#    #+#             */
/*   Updated: 2022/08/21 11:45:39 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_signal	g_signal;

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
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(1, "\n", 1);
	signal(SIGUSR1, put_character);
	signal(SIGUSR2, put_character);
	while (1)
		pause();
}
