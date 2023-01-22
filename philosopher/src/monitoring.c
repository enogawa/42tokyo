/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogaWa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 04:02:59 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 10:23:30 by enogaWa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

// static int	check_eat_all(t_philosopher *philo)
// {
// 	int	i;

// 	i = 0;
// 	// (void)philo;
// 	while (i < philo->data->philo_num)
// 	{
// 		pthread_mutex_lock(&philo[i].eat_num_lock);
// 		if (!philo[i].number_eat)
// 		{
// 			pthread_mutex_unlock(&philo[i].eat_num_lock);
// 			return (1);
// 		}
// 		pthread_mutex_unlock(&philo[i].eat_num_lock);
// 		i++;
// 	}
// 	return (0);
// }

void	*monitoring(void	*arg)
{
	// (void)arg;
	t_data	*data;

	data = (t_data *)arg;
	printf("%d", data->philo[1].number_eat);
	// while (1)
	// {
	// 	if (check_eat_all(philo))
	// 	{
	// 		philo->data->check_alive = false;
	// 		break ;
	// 	}
	// }
	return (0);
}
