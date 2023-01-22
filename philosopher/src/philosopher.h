/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:07:25 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/22 19:44:49 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>
# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_philosopher
{
	int					id;
	int					number_eat;
	pthread_mutex_t		*time;
	pthread_mutex_t		eat_num_lock;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		left_fork;
	time_t				last_eat_time;
	pthread_t			thread;
	struct s_data		*data;
}	t_philosopher;

typedef struct s_data
{
	int						philo_num;
	int						time_die;
	int						time_eat;
	int						time_sleep;
	time_t					start_time;
	bool					check_alive;
	pthread_t				monitor;
	pthread_mutex_t			print;
	pthread_mutex_t			check;
	struct s_philosopher	philo[200];
}	t_data;

int		ft_atoi_philo(char *str);
void	*start_philo(void *arg);
void	*monitoring(void *arg);
time_t	get_time(void);
void	put_action(char *action_name, t_philosopher *philo);
bool	eating(t_philosopher *philo);
void	sleeping(t_philosopher *philo);
bool 	ttt(t_data *data);
void	thinking(t_philosopher *philo);

#endif