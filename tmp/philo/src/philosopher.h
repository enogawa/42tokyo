/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:07:25 by enogawa           #+#    #+#             */
/*   Updated: 2023/02/03 18:48:25 by enogawa          ###   ########.fr       */
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
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		left_fork;
	time_t				last_eat_time;
	pthread_t			thread;
	struct s_data		*data;
}	t_philosopher;

typedef struct s_data
{
	int						philo_num;
	int						eat_count;
	time_t					time_die;
	time_t					time_eat;
	time_t					time_sleep;
	time_t					start_time;
	bool					still_alive;
	bool					still_hungry;
	pthread_t				monitor;
	pthread_mutex_t			eat_num_lock;
	pthread_mutex_t			time;
	pthread_mutex_t			print;
	pthread_mutex_t			check;
	struct s_philosopher	philo[200];
}	t_data;

int		atoi_philo(char *str);
void	*start_philo(void *arg);
void	*monitoring(void *arg);
int		destroy_philo(t_data *data);
time_t	get_time(void);
bool	put_action(char *action_name, t_philosopher *philo, bool dead);
bool	eating(t_philosopher *philo);
bool	sleeping(t_philosopher *philo);
bool	thinking(t_philosopher *philo);
bool	living_confirmation(t_data *data);
bool	eating_confirmation(t_data *data);

#endif