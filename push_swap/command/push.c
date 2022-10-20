/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:49:55 by enogawa           #+#    #+#             */
/*   Updated: 2022/10/20 16:27:50 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	{
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
	else
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
	{
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



void check_push(t_stacks *a, t_stacks *b)
{
	command_check(a);
	command_check(b);
	pb(&a, &b);
	pb(&a, &b);
	pb(&a, &b);
	command_check(a);
	command_check(b);
	//printf("%ld", a->data);
	pa(&a, &b);
	pa(&a, &b);
	// pa(&a, &b);
	command_check(a);
	command_check(b);
	
	// pb(&a, &b);
	// pb(&a, &b);
	// pb(&a, &b);
	// command_check(a);
	// command_check(b);
	// pa(&a, &b);
	// pa(&a, &b);
	// pa(&a, &b);
	// command_check(a);
	// command_check(b);
	
}


