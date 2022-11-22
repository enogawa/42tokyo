/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under6_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:29 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/22 21:45:54 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	three_sort(t_stacks *stack)
{
	t_stacks	*nxt;

	nxt = stack->next;
	if (stack->data < nxt->data
		&& stack->data < nxt->next->data)//021
	{
		sa(&stack, 0);
		ra(&stack, 0);
	}
	else if (stack->data < nxt->data && stack->data > nxt->next->data)//120
		rra(&stack, 0);
	else if (stack->data > nxt->data && stack->data < nxt->next->data)//102
		sa(&stack, 0);
	else if (stack->data > nxt->data && stack->data > nxt->next->data//201
		&& nxt->data < nxt->next->data)
		ra(&stack, 0);
	else if (stack->data > nxt->data && stack->data > nxt->next->data//210
		&& nxt->data > nxt->next->data)
	{
		sa(&stack, 0);
		rra(&stack, 0);
	}
}

void	u4_sort(t_stacks *stack_a, int num_len)
{
	if (already_sorted(stack_a))
		return ;
	if (num_len == 2)
		ra(&stack_a, 0);
	else
		three_sort(stack_a);
}

void	u7_sort(t_stacks *stack_a, int num_len)
{
	t_stacks	*stack_b;
	int			i;
	int			j;

	stack_b = list_new(-1);
	i = 0;
	j = 2;
	if (num_len == 4)
		j = 1;
	while (j > i)
	{
		if (stack_a->data == 0 || stack_a->data == 1)
		{
			pb(&stack_a, &stack_b);
			i++;
		}
		else
			ra(&stack_a, 0);
	}
	u4_sort(stack_a, num_len);
	while (i--)
		pa(&stack_a, &stack_b);
	if (stack_a->data > stack_a->next->data)
		sa(&stack_a, 0);
	stack_free(&stack_b, 1);
}
