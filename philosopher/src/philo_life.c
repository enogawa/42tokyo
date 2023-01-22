/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogaWa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:43:47 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 16:38:26 by enogaWa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	eating(t_philosopher *philo)
{
	time_t	start;

	pthread_mutex_lock(&philo->data->check);
	if (!ttt(philo->data,0))
		return (false);
	pthread_mutex_unlock(&philo->data->check);
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
		usleep(100);
	pthread_mutex_lock(&philo->eat_num_lock);
	philo->number_eat--;
	// printf("%d, num_eat = %d\n\n", philo->id, philo->number_eat);
	pthread_mutex_unlock(&philo->eat_num_lock);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (true);
}

void	sleeping(t_philosopher *philo)
{
	time_t	start;

	// if (!philo->data->check_alive)
	// 	return ;
	start = get_time();
	put_action("is sleeping", philo);
	while (get_time() - start < philo->data->time_sleep)
	{
		// printf("%d", get_time() - start < philo->data->time_sleep);
		usleep(100);
	}
}

void	thinking(t_philosopher *philo)
{
	// if (!philo->data->check_alive)
	// 	return ;
	put_action("is thinking", philo);
}

void	*start_philo(void	*arg)
{
	t_philosopher	*philo;
	int i = 0;
	// printf("test");
	// (void)arg;
	philo = (t_philosopher *)arg;
	// printf("3333333333333___________%p\n", philo->data);
	// return NULL;
	if (philo->data->philo_num == 1)
		return (NULL);
	if (philo->id % 2 == 0 || philo->id == philo->data->philo_num)
	{
		put_action("is thinking", philo);
		usleep(200);
	}
	while (1)
	{
		if (!eating(philo))
			break ;
		sleeping(philo);
		thinking(philo);
		if (i++ == 30)
			break ;
	}
	// printf("fin\n");
	return (NULL);
}
