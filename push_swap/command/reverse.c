/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:49:57 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/28 19:39:13 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stacks **stack_a, int i)
{
	t_stacks	*head;
	t_stacks	*foot;

	head = list_mv_prev(*stack_a);
	foot = list_mv_back(*stack_a);
	foot->prev->next = NULL;
	(*stack_a)->prev = NULL;
	*stack_a = foot;
	foot->next = head;
	head->prev = foot;
	if (!i)
	{
		write (1, "rra\n", 5);
	}
}

void	rrb(t_stacks **stack_b, int i)
{
	t_stacks	*head;
	t_stacks	*foot;

	head = list_mv_prev(*stack_b);
	foot = list_mv_back(*stack_b);
	foot->prev->next = NULL;
	(*stack_b)->prev = NULL;
	*stack_b = foot;
	foot->next = head;
	head->prev = foot;
	if (!i)
	{
		write (1, "rrb\n", 5);
	}
}

void	rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write (1, "rrr\n", 5);
	return ;
}