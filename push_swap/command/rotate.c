/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:50:01 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/28 19:38:33 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_stacks **stack_a, int i)
{
	t_stacks *head;
	t_stacks *foot;

	head = list_mv_prev(*stack_a);
	foot = list_mv_back(*stack_a);
	head->next->prev = NULL;
	*stack_a = head->next;
	head->next = NULL;
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

	head = list_mv_prev(*stack_b);
	foot = list_mv_back(*stack_b);
	head->next->prev = NULL;
	*stack_b = head->next;
	head->next = NULL;
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
	return ;
}