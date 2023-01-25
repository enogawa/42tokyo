/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:43:47 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/25 10:58:01 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	eating(t_philosopher *philo)
{
	time_t	time;
	
	if (!eating_confirmation(philo->data) || !living_confirmation(philo->data))
		return (false);
	pthread_mutex_lock(&philo->left_fork);//left
	put_action("has taken a fork", philo);
	if (philo->data->philo_num == 1)
	{
		pthread_mutex_unlock(&philo->left_fork);
		return (false);
	}
	pthread_mutex_lock(philo->right_fork);//right
	put_action("has taken a fork", philo);
	put_action("is eating", philo);
	time = get_time();
	pthread_mutex_lock(&philo->data->time);
	philo->last_eat_time = time;
	pthread_mutex_unlock(&philo->data->time);
	usleep(philo->data->time_eat * 900);
	while (get_time() - philo->last_eat_time < philo->data->time_eat)
		usleep(100);
	pthread_mutex_lock(&philo->eat_num_lock);
	philo->number_eat--;
	pthread_mutex_unlock(&philo->eat_num_lock);
	if (!eating_confirmation(philo->data))
		return (false);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (true);
}

bool	sleeping(t_philosopher *philo)
{
	time_t	start;

	if (!eating_confirmation(philo->data) || !living_confirmation(philo->data))
		return (false);
	put_action("is sleeping", philo);
	start = get_time();
	usleep(philo->data->time_sleep * 900);
	while (get_time() - start < philo->data->time_sleep)
		usleep(100);
	return (true);
}

bool	thinking(t_philosopher *philo)
{
	if (!eating_confirmation(philo->data) || !living_confirmation(philo->data))
		return (false);
	put_action("is thinking", philo);
	return (true);
}

void	*start_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0 || philo->id == philo->data->philo_num)
	{
		// put_action("is thinking", philo);
		usleep(100);
	}
	while (1)
	{
		if (!eating(philo))
			break ;
		if (!sleeping(philo))
			break ;
		if (!thinking(philo))
			break ;
	}
	printf("fin_%d\n", philo->id);
	return (NULL);
}
