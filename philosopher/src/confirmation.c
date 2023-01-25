/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   confirmation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:40:24 by enogawa           #+#    #+#             */
/*   Updated: 2023/01/25 04:17:51 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

bool	living_confirmation(t_data *data)
{
	bool	dead_or_alive;

	pthread_mutex_lock(&data->check);
	dead_or_alive = data->still_alive;
	pthread_mutex_unlock(&data->check);
	return (dead_or_alive);
}

bool	eating_confirmation(t_data *data)
{
	bool	full_or_hungry;

	pthread_mutex_lock(&data->check);
	full_or_hungry = data->still_hungry;
	pthread_mutex_unlock(&data->check);
	return (full_or_hungry);
}
