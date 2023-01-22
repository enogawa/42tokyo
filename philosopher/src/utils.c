/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogaWa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:33:53 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 16:42:41 by enogaWa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool ttt(t_data *data, int flag)
{
	bool tmp;
	pthread_mutex_lock(&data->check);
	if (flag == 0)
	{
		// printf("22222222222222___________%p\n", &data->check_alive);
		tmp = data->check_alive;
		pthread_mutex_unlock(&data->check);
		return tmp;
	}
	else // printf("11111111111111_____________%p\n", &data->check_alive);
		data->check_alive = false;
	pthread_mutex_unlock(&data->check);
	return true;
}
time_t get_time(void)
{
	time_t time;
	struct timeval tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

void put_action(char *action_name, t_philosopher *philo)
{
	// (void)action_name;
	if (!ttt(philo->data, 0))
		return;
	pthread_mutex_lock(&philo->data->print);
	printf("%ld %d %s\n", get_time() - philo->data->start_time, philo->id, action_name);
	pthread_mutex_unlock(&philo->data->print);
}

static int ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

int ft_atoi_philo(char *str)
{
	long int ans;
	size_t i;

	ans = 0;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
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
