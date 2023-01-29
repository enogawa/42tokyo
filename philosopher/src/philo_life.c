/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:43:47 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/29 18:51:51 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static bool	take_fork(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->left_fork);
	if (!put_action("has taken a fork", philo, false))
	{
		pthread_mutex_unlock(&philo->left_fork);
		return (false);
	}
	if (philo->data->philo_num == 1)
	{
		pthread_mutex_unlock(&philo->left_fork);
		return (false);
	}
	pthread_mutex_lock(philo->right_fork);
	if (!put_action("has taken a fork", philo, false))
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (false);
	}
	return (true);
}

bool	eating(t_philosopher *philo)
{
	take_fork(philo);
	if (!put_action("is eating", philo, false))
	{
		pthread_mutex_unlock(&philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (false);
	}
	pthread_mutex_lock(&philo->eat_num_lock);
	philo->number_eat--;
	if (philo->number_eat == 0)
		philo->data->eat_count++;
	pthread_mutex_unlock(&philo->eat_num_lock);
	pthread_mutex_lock(&philo->data->time);
	philo->last_eat_time = get_time();
	pthread_mutex_unlock(&philo->data->time);
	usleep(philo->data->time_eat * 900);
	while (get_time() - philo->last_eat_time < philo->data->time_eat)
		usleep(100);
	pthread_mutex_unlock(&philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (true);
}

bool	sleeping(t_philosopher *philo)
{
	time_t	start;

	if (!put_action("is sleeping", philo, false))
		return (false);
	start = get_time();
	usleep(philo->data->time_sleep * 900);
	while (get_time() - start < philo->data->time_sleep)
		usleep(100);
	return (true);
}

bool	thinking(t_philosopher *philo)
{
	if (!put_action("is thinking", philo, false))
		return (false);
	return (true);
}

void	*start_philo(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0 || philo->id == philo->data->philo_num)
	{
		if (!put_action("is thinking", philo, false))
			return (false);
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
	// printf("----------------%d\n", philo->id);
	return (NULL);
}
// static bool	take_fork(t_philosopher *philo)
// {
// 	pthread_mutex_lock(&philo->left_fork);
// 	put_action("has taken a fork", philo);
// 	if (philo->data->philo_num == 1)
// 	{
// 		pthread_mutex_unlock(&philo->left_fork);
// 		return (false);
// 	}
// 	pthread_mutex_lock(philo->right_fork);
// 	put_action("has taken a fork", philo);
// 	return (true);
// }

// bool	eating(t_philosopher *philo)
// {
// 	pthread_mutex_lock(&philo->data->check);
// 	if (!take_fork(philo) || philo->data->eat_count == philo->data->philo_num
// 		|| !philo->data->still_alive)
// 	{
// 		pthread_mutex_unlock(&philo->data->check);
// 		return (false);
// 	}
// 	put_action("is eating", philo);
// 	pthread_mutex_lock(&philo->eat_num_lock);
// 	philo->number_eat--;
// 	if (philo->number_eat == 0)
// 		philo->data->eat_count++;
// 	pthread_mutex_unlock(&philo->eat_num_lock);
// 	pthread_mutex_unlock(&philo->data->check);
// 	pthread_mutex_lock(&philo->data->time);
// 	philo->last_eat_time = get_time();
// 	pthread_mutex_unlock(&philo->data->time);
// 	usleep(philo->data->time_eat * 900);
// 	while (get_time() - philo->last_eat_time < philo->data->time_eat)
// 		usleep(500);
// 	pthread_mutex_unlock(&philo->left_fork);
// 	pthread_mutex_unlock(philo->right_fork);
// 	return (true);
// }

// bool	sleeping(t_philosopher *philo)
// {
// 	time_t	start;

// 	// put_action("is sleeping", philo);
// 	pthread_mutex_lock(&philo->data->check);
// 	if (philo->data->eat_count == philo->data->philo_num
// 		|| !philo->data->still_alive)
// 	{
// 		pthread_mutex_unlock(&philo->data->check);
// 		return (false);
// 	}
// 	put_action("is sleeping", philo);
// 	pthread_mutex_unlock(&philo->data->check);
// 	start = get_time();
// 	usleep(philo->data->time_sleep * 900);
// 	while (get_time() - start < philo->data->time_sleep)
// 		usleep(500);
// 	return (true);
// }

// bool	thinking(t_philosopher *philo)
// {
// 	pthread_mutex_lock(&philo->data->check);
// 	if (philo->data->eat_count == philo->data->philo_num
// 		|| !philo->data->still_alive)
// 	{
// 		pthread_mutex_unlock(&philo->data->check);
// 		return (false);
// 	}
// 	put_action("is thinking", philo);
// 	pthread_mutex_unlock(&philo->data->check);
// 	return (true);
// }

// void	*start_philo(void *arg)
// {
// 	t_philosopher	*philo;

// 	philo = (t_philosopher *)arg;
// 	if (philo->id % 2 == 0 || philo->id == philo->data->philo_num)
// 		usleep(100);
// 	while (1)
// 	{
// 		if (!eating(philo))
// 			break ;
// 		if (!sleeping(philo))
// 			break ;
// 		if (!thinking(philo))
// 			break ;
// 	}
// 	// printf("fin_%d\n", philo->id);
// 	return (NULL);
// }
