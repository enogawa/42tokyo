/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogaWa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:43:47 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 10:52:17 by enogaWa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	eating(t_philosopher *philo)
{
	time_t	start;

	if (!philo->data->check_alive)
		return (false);
	pthread_mutex_lock(&philo->left_fork);
	put_action("has taken a fork", philo);
	// if (philo->data->philo_num == 1)
	// {
	// 	pthread_mutex_unlock(&philo->left_fork);
	// 	return (false);
	// }
	pthread_mutex_lock(philo->right_fork);
	put_action("has taken a fork", philo);
	put_action("is eating", philo);
	start = get_time();
	while (get_time() - start < philo->data->time_eat)
		usleep(250);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (true);
}

void	sleeping(t_philosopher *philo)
{
	time_t	start;

	if (!philo->data->check_alive)
		return ;
	start = get_time();
	put_action("is sleeping", philo);
	while (get_time() - start < philo->data->time_sleep)
	{
		// printf("%d", get_time() - start < philo->data->time_sleep);
		usleep(250);
	}
}

void	thinking(t_philosopher *philo)
{
	if (!philo->data->check_alive)
		return ;
	put_action("is thinking", philo);
}

void	*start_philo(void	*arg)
{
	// t_philosopher	*philo;
	// int i = 0;
	printf("test");
	(void)arg;

	// philo = (t_philosopher *)arg;
	// // printf("%d\n", philo->data->time_sleep);
	// // return (NULL);
	// if (philo->data->philo_num == 1)
	// 	return (NULL);
	// // printf("id=%d, ", philo->id);
	// // printf("philo_num=%d", philo->data->philo_num);
	// // philo->data->start_time = get_time();
	// // printf("time: %ld", philo->data->start_time);
	// if (philo->id % 2 == 0 || philo->id == philo->data->philo_num)
	// {
		// put_action("is thinking", philo);
	// 	usleep(200);
	// }
	// while (1)
	// {
	// 	if (!eating(philo))
	// 		break ;
	// 	sleeping(philo);
	// 	thinking(philo);
	// 	if (i++ == 30)
	// 		break ;
	// }
	return (NULL);
}
