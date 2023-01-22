/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:02:59 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 20:13:50 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	aaa(t_data *data)
{
	pthread_mutex_lock(&data->check);
	data->check_alive = false;
	pthread_mutex_unlock(&data->check);
}

static int	check_eat_all(t_data *data)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].eat_num_lock);
		tmp = data->philo[i].number_eat;
		if (tmp == 0)
		{
			pthread_mutex_unlock(&data->philo[i].eat_num_lock);
			return (1);
		}
		pthread_mutex_unlock(&data->philo[i].eat_num_lock);
		i++;
	}
	return (0);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_eat_all(data))
		{
			aaa(data);
			// pthread_mutex_lock(&data->check);
			// data->check_alive = false;
			// pthread_mutex_unlock(&data->check);
			break ;
		}
	}
	return (0);
}
