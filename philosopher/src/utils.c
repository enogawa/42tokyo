/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:33:53 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 20:07:28 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	ttt(t_data *data)
{
	bool	tmp;

	// tmp = false;
	pthread_mutex_lock(&data->check);
	tmp = data->check_alive;
	pthread_mutex_unlock(&data->check);
	printf("%d\n", tmp);
	return tmp;
}

time_t	get_time(void)
{
	time_t			time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void	put_action(char *action_name, t_philosopher *philo)
{
	// time_t	time;
	// time = get_time() - philo->data->start_time;
	// printf("1------------%p\n", &philo->data);
	if (!ttt(philo->data))
		return ;
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id,
			action_name);
	// printf("1------------%p\n", &philo->data->start_time);
	pthread_mutex_unlock(&philo->data->print);
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi_philo(char *str)
{
	long int	ans;
	size_t		i;

	ans = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			return (0);
		i++;
	}
	while (str[i])
	{
		ans = ans * 10 + str[i] - 48;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (ans > INT_MAX)
		return (0);
	return (ans);
}

// void	error_return(char *str)
// {
// 	write(1, &str, ft_strlen(str));
// 	write(1, '\n', 1);
// }
