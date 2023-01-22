/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogaWa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:02:59 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 16:38:34 by enogaWa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int check_eat_all(t_data *data)
{
	int i;
	int tmp;

	i = 0;
	// (void)philo;
	while (i < data->philo_num)
	{
		pthread_mutex_lock(&data->philo[i].eat_num_lock);
		tmp = data->philo[i].number_eat;
		pthread_mutex_unlock(&data->philo[i].eat_num_lock);
		// printf("num_eat = %d\n\n", data->philo->number_eat);
		if (!tmp)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void *monitoring(void *arg)
{
	// (void)arg;
	t_data *data;
	// t_philosopher	*philo;

	data = (t_data *)arg;
	// printf("222222222222____________%p\n", data);

	// philo = (t_philosopher *)data->philo;
	// printf("%d\n", data->philo[1].number_eat);
	// printf("_____________________%p_________________\n",data);
	// return(NULL);
	while (1)
	{
		if (check_eat_all(data))
		{
			ttt(data,1);
			// pthread_mutex_lock(&data->check);
			// data->check_alive = false;
			// pthread_mutex_unlock(&data->check);
			break;
		}
	}
	return (0);
}
