/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:45:27 by enogawa           #+#    #+#             */
/*   Updated: 2023/02/04 07:02:42 by enogawa          ###   ########.fr       */
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
		data->philo[i].last_eat_time = data->start_time;
		pthread_create(&data->philo[i].thread, NULL,
			&start_philo, &data->philo[i]);
		i++;
	}
	pthread_create(&data->monitor, NULL, &monitoring, data);
	pthread_join(data->monitor, NULL);
	i = 0;
	while (i < data->philo_num)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
	if (destroy_philo(data))
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
		if (i == data->philo_num - 1)
			data->philo[i].right_fork = &data->philo[0].left_fork;
		else
			data->philo[i].right_fork = &data->philo[(i + 1)].left_fork;
		data->philo[i].last_eat_time = 0;
		data->philo[i].data = data;
		i++;
	}
	data->still_alive = true;
	data->still_hungry = true;
	data->eat_count = 0;
	return (0);
}

static int	argcheck(int argc, char **argv, t_data *data)
{
	int	i;

	if ((argc != 5 && argc != 6) || !atoi_philo(argv[1]) || \
		!atoi_philo(argv[2]) || !atoi_philo(argv[3]) || !atoi_philo(argv[4])
		|| (argc == 6 && !atoi_philo(argv[5])))
		return (1);
	else
	{
		data->philo_num = atoi_philo(argv[1]);
		data->time_die = atoi_philo(argv[2]);
		data->time_eat = atoi_philo(argv[3]);
		data->time_sleep = atoi_philo(argv[4]);
	}
	if (data->philo_num > 200)
		return (1);
	i = 0;
	if (argc == 6)
	{
		while (i < data->philo_num)
			data->philo[i++].number_eat = atoi_philo(argv[5]);
	}
	while (i < data->philo_num)
		data->philo[i++].number_eat = -1;
	return (0);
}

static int	make_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_num)
	{
		if (pthread_mutex_init(&data->philo[i].left_fork, NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print, NULL))
		return (1);
	if (pthread_mutex_init(&data->check, NULL))
		return (1);
	if (pthread_mutex_init(&data->time, NULL))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

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
