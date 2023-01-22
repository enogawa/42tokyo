/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogaWa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:45:27 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 16:38:37 by enogaWa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	make_thread(t_data *data)
{
	int	i;

	i = 0;
	data->start_time = get_time();
	while (i < data->philo_num)
	{
		pthread_create(&data->philo[i].thread, NULL,
			&start_philo, &data->philo[i]);
		i++;
	}
	// printf("11111111111____________%p\n", data);
	pthread_create(&data->monitor, NULL, &monitoring, data);
	pthread_join(data->monitor, NULL);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < data->philo_num)
	{
		if (data->philo[i].number_eat)
		{
			if (pthread_mutex_destroy(&data->philo->eat_num_lock))
				return (1);
		}
		if (pthread_mutex_destroy(&data->philo[i].left_fork))
			return (1);
		i++;
	}
	if (pthread_mutex_destroy(&data->print))
		return (1);
	return (0);
}

static int	init_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		data->philo[i].id = i + 1;
		if (i == data->philo_num)
			data->philo[i].right_fork = &data->philo[0].left_fork;
		else
			data->philo[i].right_fork = &data->philo[i + 1].left_fork;
		data->philo[i].last_eat_time = 0;
		data->philo[i].data = data;
		i++;
	}
	data->check_alive = true;
	return (0);
}

static int	argcheck(int argc, char **argv, t_data *data)
{
	int	i;
	// int		num;
	i = 0;
	if (argc != 5 && argc != 6)
		return (1);
	if (!ft_atoi_philo(argv[1]))
		return (1);
	else
		data->philo_num = ft_atoi_philo(argv[1]);
	if (!ft_atoi_philo(argv[2]))
		return (1);
	else
		data->time_die = ft_atoi_philo(argv[2]);
	if (!ft_atoi_philo(argv[3]))
		return (1);
	else
		data->time_eat = ft_atoi_philo(argv[3]);
	if (!ft_atoi_philo(argv[4]))
		return (1);
	else
		data->time_sleep = ft_atoi_philo(argv[4]);
	if (argc == 6)
	{
		if (!ft_atoi_philo(argv[5]))
			return (1);
		else
		{
			while (i < data->philo_num)
			{
				data->philo[i].number_eat = ft_atoi_philo(argv[5]);
				i++;
			}
		}
		// data->number_eat = ft_atoi_philo(argv[5]);
	}

	// num = malloc(sizeof(int) * (argc - 1));
	// if (!num)
	// 	exit(1);
	// while (i < argc - 1)
	// {
	// 	num[i] = ft_atoi_philo(argv[i + 1]);
	// 	if (!num[i])
	// 		return (1);
	// 	i++;
	// }
	// data->philo_num = num[0];
	// data->time_die = num[1];
	// data->time_eat = num[2];
	// data->time_sleep = num[3];
	// if (num[4])
	// 	data->number_eat = num[4];
	// free(num);
	// data->check_alive = 1;
	return (0);
}

static int	make_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (data->philo[i].number_eat)
		{
			// if (pthread_mutex_init(data->philo[i].eat_num_lock, NULL))
			if (pthread_mutex_init(&data->philo->eat_num_lock, NULL))
				return (1);
		}
		if (pthread_mutex_init(&data->philo[i].left_fork, NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	t_data	data;

	// data = malloc(sizeof(t_data));
	// memset(data, 0, sizeof(t_data));
	if (argcheck(argc, argv, &data))
	{
		printf("invalid args");
		return (1);
	}
	if (init_philo(&data))
		return (1);
	if (make_mutex(&data))
		return (1);
	if (make_thread(&data))
		return (1);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
//     system("leaks -q philo");
// }
