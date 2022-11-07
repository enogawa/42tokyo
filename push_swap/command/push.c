/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:49:55 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/07 11:37:01 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	node_sort_ope_pb(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*head_a;
	t_stacks	*node_a;
	// t_stacks	*head_b;
	t_stacks	*node_b;
	
	if ((*stack_a)->data == -1)
		*stack_a = (*stack_a)->next;
	head_a =  list_mv_head(*stack_a);
	node_a = head_a->prev;
	node_b = *stack_b;
	*stack_a = head_a->next;
	head_a->next->prev = node_a;
	node_a->next = head_a->next;
	head_a->prev = node_b;
	node_b->next = head_a;
	node_b->prev = head_a;
	head_a->next = node_b;
	*stack_b = (*stack_b)->next;
}

void	node_sort_ope_pa(t_stacks **stack_a, t_stacks **stack_b)
{
	// t_stacks	*head_a;
	t_stacks	*node_a;
	t_stacks	*head_b;
	t_stacks	*node_b;

	if ((*stack_b)->data == -1)
		*stack_b = (*stack_b)->next;
	head_b =  list_mv_head(*stack_b);
	node_b = head_b->prev;
	node_a = *stack_a;
	*stack_b = head_b->next;
	(*stack_b)->prev = node_b;
	node_b->next = *stack_b;
	head_b->prev = node_a;
	node_a->next = head_b;
	node_a->prev = head_b;
	head_b->next = node_a;
	*stack_a = (*stack_a)->next;
}

void	pa(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*head_a;
	t_stacks	*node_a;
	t_stacks	*head_b;
	t_stacks	*node_b;

	if ((*stack_b)->data == -1)
		*stack_b = (*stack_b)->next;
	head_b =  list_mv_head(*stack_b);
	node_b = head_b->prev;
	if ((*stack_a)->data == -1)
		node_sort_ope_pa(stack_a, stack_b);
	else
	{
		head_a =  list_mv_head(*stack_a);
		node_a = head_a->prev;
		*stack_a = head_b;
		*stack_b = head_b->next;
		head_b->next->prev = node_b;
		node_b->next = head_b->next;
		head_b->prev = node_a;
		node_a->next = head_b;
		head_b->next = head_a;
		head_a->prev = head_b;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stacks **stack_a, t_stacks **stack_b)
{	
	t_stacks	*head_a;
	t_stacks	*node_a;
	t_stacks	*head_b;
	t_stacks	*node_b;

	if ((*stack_a)->data == -1)
		*stack_a = (*stack_a)->next;
	head_a =  list_mv_head(*stack_a);
	node_a = head_a->prev;
	if ((*stack_b)->data == -1)
		node_sort_ope_pb(stack_a, stack_b);
	else
	{
		head_b =  list_mv_head(*stack_b);
		node_b = head_b->prev;
		*stack_a = head_a->next;
		*stack_b = head_a;
		head_a->next->prev = node_a;
		node_a->next = head_a->next;
		head_a->prev = node_b;
		node_b->next = head_a;
		head_a->next = head_b;
		head_b->prev = head_a;
	}
	write(1, "pb\n", 3);
}
