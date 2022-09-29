/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:49:55 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/29 11:47:50 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*head_a;
	t_stacks	*head_b;

	head_a =  list_mv_head(*stack_a);
	head_b =  list_mv_head(*stack_b);
	*stack_a = head_b;
	*stack_b = head_b->next;
	head_b->prev = NULL;
	head_b->next = head_a;
	head_a->prev = head_b;
	write(1, "pa\n", 4);
}

void	pb(t_stacks **stack_a, t_stacks **stack_b)
{
	t_stacks	*head_a;
	t_stacks	*head_b;

	head_a =  list_mv_head(*stack_a);
	head_b =  list_mv_head(*stack_b);
	*stack_b = head_a;
	*stack_a = head_a->next;
	head_a->prev = NULL;
	head_a->next = head_b;
	head_b->prev = head_a;
	write(1, "pb\n", 4);
}




