/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 11:45:42 by enogawa           #+#    #+#             */
/*   Updated: 2022/08/21 11:45:43 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	long int		ans;
	size_t			i;
	int				m;

	ans = 0;
	i = 0;
	m = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		   	 || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			m = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		ans = ans * 10 + str[i] - 48;
		i++;
	}
	return (ans * m);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	m;
	int		i;
	long	num;

	m = '-';
	num = n;
	i = 1;
	if (n < 0)
	{
		num *= -1;
		write(fd, &m, 1);
	}
	while (n / 10 != 0)
	{
		n /= 10;
		i *= 10;
	}
	while (i > 0)
	{
		c = '0' + (num / i);
		write(fd, &c, 1);
		num -= (num / i) * i;
		i /= 10;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
