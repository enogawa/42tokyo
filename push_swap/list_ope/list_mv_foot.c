/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mv_foot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:19:57 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/14 18:19:58 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*list_mv_foot(t_stacks *stacks)
{
	if (stacks->data == -1)
	{
		stacks = stacks->prev;
		return (stacks);
	}
	while (stacks->next->data != -1)
	{
		stacks = stacks->next;
	}
	return (stacks);
}
