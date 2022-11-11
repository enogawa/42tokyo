/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:25:42 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/11 19:32:02 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	too_much_pe(int *pec_count)
{
	if (pec_count[0] > 1 || pec_count[1] > 1)
	{
		write(2, "too much P or E\n", 17);
		free(pec_count);
		return (1);
	}
	return (0);
}

int	is_there_pec(int *pec_count)
{
	if (pec_count[0] == 0 || pec_count[1] == 0 || pec_count[2] == 0)
	{
		write(2, "not found P, E, or C\n", 22);
		free(pec_count);
		return (1);
	}
	return (0);
}
