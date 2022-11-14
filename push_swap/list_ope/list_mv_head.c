/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mv_head.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:03:42 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/14 18:18:56 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*list_mv_head(t_stacks *stacks)
{
	if (stacks->data == -1)
	{
		stacks = stacks->next;
		return (stacks);
	}
	while (stacks->prev->data != -1)
	{
		stacks = stacks->prev;
	}
	return (stacks);
}
