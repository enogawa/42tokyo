/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:49:57 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/14 18:26:15 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stacks **stack_a, int i)
{
	t_stacks	*head;
	t_stacks	*foot;
	t_stacks	*node;

	if ((*stack_a)->data == -1)
		*stack_a = (*stack_a)->next;
	head = list_mv_head(*stack_a);
	foot = list_mv_foot(*stack_a);
	node = head->prev;
	*stack_a = foot;
	foot->prev->next = node;
	(*stack_a)->prev = node;
	(*stack_a)->next = head;
	head->prev = *stack_a;
	node->prev = foot->prev;
	node->next = *stack_a;
	if (!i)
	{
		write (1, "rra\n", 4);
	}
}

void	rrb(t_stacks **stack_b, int i)
{
	t_stacks	*head;
	t_stacks	*foot;
	t_stacks	*node;

	head = list_mv_head(*stack_b);
	foot = list_mv_foot(*stack_b);
	node = head->prev;
	foot->prev->next = node;
	(*stack_b)->prev = node;
	*stack_b = foot;
	foot->next = head;
	head->prev = foot;
	if (!i)
	{
		write (1, "rrb\n", 4);
	}
}

void	rrr(t_stacks **stack_a, t_stacks **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	write (1, "rrr\n", 4);
	return ;
}
