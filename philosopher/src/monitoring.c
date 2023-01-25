/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:02:59 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/25 09:51:02 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void	everyone_full(t_data *data)
{
	pthread_mutex_lock(&data->check);
	data->still_hungry = false;
	pthread_mutex_unlock(&data->check);
}

static void	inform_die(t_data *data)
{
	pthread_mutex_lock(&data->check);
	data->still_alive = false;
	pthread_mutex_unlock(&data->check);
}

static bool	check_alive(t_data *data)
{
	int		i;
	// time_t	now;
	
	i = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->time);
		// now = get_time();
		if (get_time() - data->philo[i].last_eat_time >= data->time_die)
		{
			pthread_mutex_unlock(&data->time);
			pthread_mutex_lock(&data->print);
			printf("%ld %d died\n", get_time() - data->start_time, data->philo[i].id);
			pthread_mutex_unlock(&data->print);
			return (false);
		}
		pthread_mutex_unlock(&data->time);
		i++;
	}
	return (true);
}

static bool	check_eat_all(t_data *data)
{
	int	i;
	int	eat_times;
	int	num_finished;

	i = 0;
	num_finished = 0;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].eat_num_lock);
		eat_times = data->philo[i].number_eat;
		if (eat_times == 0)
		{
			num_finished++;
			if (num_finished == data->philo_num)
			{
				pthread_mutex_unlock(&data->philo[i].eat_num_lock);
				return (true);
			}
		}
		pthread_mutex_unlock(&data->philo[i].eat_num_lock);
		i++;
	}
	return (false);
}

void	*monitoring(void *arg)
{
	t_data	*data;

	data = (t_data *)arg;
	while (1)
	{
		if (check_eat_all(data))
		{
			everyone_full(data);
			break ;
		}
		if (!check_alive(data))
		{
			inform_die(data);
			break ;
		}
	}
	return (NULL);
}
