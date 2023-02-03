/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:02:59 by enogawa           #+#    #+#             */
/*   Updated: 2023/02/03 13:32:59 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	check_alive(t_data *data)
{
	int		i;
	time_t	now;
	time_t	last_eat;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->time);
		last_eat = data->philo[i].last_eat_time;
		pthread_mutex_unlock(&data->time);
		now = get_time();
		if (now - last_eat >= data->time_die
			&& data->eat_count != data->philo_num)
		{
			if (!put_action("died", data->philo, true))
				return (false);
			return (false);
		}
		i++;
	}
	return (true);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		pthread_mutex_lock(&data->check);
		if (data->eat_count == data->philo_num)
		{
			pthread_mutex_unlock(&data->check);
			break ;
		}
		pthread_mutex_unlock(&data->check);
		pthread_mutex_lock(&data->check);
		if (!check_alive(data))
		{
			data->still_alive = false;
			pthread_mutex_unlock(&data->check);
			break ;
		}
		pthread_mutex_unlock(&data->check);
		usleep(50);
	}
	return (NULL);
}
