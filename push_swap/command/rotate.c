/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:50:01 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/30 11:07:58 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stacks **stack_a, int i)
{
	t_stacks *head;
	t_stacks *foot;
	t_stacks *node;

	head =  list_mv_head(*stack_a);
	node = head->prev;
	foot = list_mv_foot(*stack_a);
	head->next->prev = node;
	*stack_a = head->next;
	head->next = node;
	head->prev = foot;
	foot->next = head;
	if (!i)
	{
		write (1, "ra\n", 4);
	}
}

void	rb(t_stacks **stack_b, int i)
{
	t_stacks *head;
	t_stacks *foot;
	t_stacks *node;

	head =  list_mv_head(*stack_b);
	node = head->prev;
	foot = list_mv_foot(*stack_b);
	head->next->prev = node;
	*stack_b = head->next;
	head->next = node;
	head->prev = foot;
	foot->next = head;
	if (!i)
	{
		write (1, "rb\n", 4);
	}
}

void	rr(t_stacks **stack_a, t_stacks **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	write (1, "rr\n", 4);
}