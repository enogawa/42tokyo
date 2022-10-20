/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:50:01 by enogawa           #+#    #+#             */
/*   Updated: 2022/10/20 15:50:08 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stacks **stack_a, int i)
{
	t_stacks *head;
	t_stacks *foot;
	t_stacks *node;
	if ((*stack_a)->data == -1)
		*stack_a = (*stack_a)->next;
	head =  list_mv_head(*stack_a);
	//printf("\nhead; %ld\n", head->data);
	node = head->prev;
	//printf("head->next; %ld\n", head->next->data);
	foot = list_mv_foot(*stack_a);
	//printf("foot; %ld\n", foot->data);
	
	head->next->prev = node;
	*stack_a = head->next;
	head->next = node;
	head->prev = foot;
	foot->next = head;
	
	// while ((*stack_a)->data != -1)
	// {
	// 	printf("stack_a; %ld,", (*stack_a)->data);//test
	// 	*stack_a = (*stack_a)->next;
	// }

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

	if ((*stack_b)->data == -1)
		*stack_b = (*stack_b)->next;
	head =  list_mv_head(*stack_b);
	node = head->prev;
	foot = list_mv_foot(*stack_b);
	foot->next = head->next;
	head->next = node;
	node->prev = head;
	head->prev = foot->prev;
	foot->prev = node;
	node->next = foot;
	
	// head->next->prev = node;
	// *stack_b = head->next;
	// head->next = node;
	// head->prev = foot;
	// foot->next = head;
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

void	check_ra(t_stacks	*stack_a, int i)
{
	ra(&stack_a, i);
	command_check(stack_a);
	ra(&stack_a, i);
	command_check(stack_a);
	ra(&stack_a, i);
	command_check(stack_a);
	ra(&stack_a, i);
	command_check(stack_a);
	ra(&stack_a, i);
	command_check(stack_a);
	ra(&stack_a, i);
	command_check(stack_a);
}