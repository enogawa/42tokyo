/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:33:53 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/29 19:31:38 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	destroy_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (data->philo[i].number_eat)
		{
			if (pthread_mutex_destroy(&data->philo->eat_num_lock))
				return (1);
		}
		if (pthread_mutex_destroy(&data->philo[i].left_fork))
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&data->print))
		return (1);
	return (0);
}

time_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

bool	put_action(char *action_name, t_philosopher *philo, bool dead)
{
	if (!dead)
	{
		pthread_mutex_lock(&philo->data->check);
		if (philo->data->eat_count == philo->data->philo_num
			|| !philo->data->still_alive)
		{
			// printf("%d--------------------%d\n", philo->data->eat_count, philo->data->still_alive);
			pthread_mutex_unlock(&philo->data->check);
			return (false);
		}
	}
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time() - philo->data->start_time,
		philo->id, action_name);
	pthread_mutex_unlock(&philo->data->print);
	if (!dead)
		pthread_mutex_unlock(&philo->data->check);
	return (true);
}

static int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int	atoi_philo(char *str)
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
