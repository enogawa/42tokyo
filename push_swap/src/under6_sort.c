/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under6_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:29 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/22 12:29:55 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	u4_sort(t_stacks *stack_a, int num_len)
{
	t_stacks	*nxt_a;

	nxt_a = stack_a->next;
	if (already_sorted(stack_a))
		return ;
	if (num_len == 2)
		ra(&stack_a, 0);
	else
	{
		if (stack_a->data < nxt_a->data && stack_a->data < nxt_a->next->data) //021
		{
	 		sa(&stack_a, 0);
	 		ra(&stack_a, 0);
	 	}
		else if (stack_a->data < nxt_a->data && stack_a->data > nxt_a->next->data)//120
			rra(&stack_a, 0);
		else if (stack_a->data > nxt_a->data && stack_a->data < nxt_a->next->data)//102
			sa(&stack_a, 0);
		else if (stack_a->data > nxt_a->data && stack_a->data > nxt_a->next->data && nxt_a->data < nxt_a->next->data)//201
			ra(&stack_a, 0);
		else if (stack_a->data > nxt_a->data && stack_a->data > nxt_a->next->data && nxt_a->data > nxt_a->next->data)//210
		{
			sa(&stack_a, 0);
			rra(&stack_a, 0);
		}
	}
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
