/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under7_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 07:40:29 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/02 11:56:36 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	u4_sort(t_stacks *stack_a, int num_len)
{
	if (num_len == 2)
		ra(&stack_a, 0);
	else
	{
		if (stack_a->data == 0 && stack_a->next->data == 2)
		{
			sa(&stack_a, 0);
			ra(&stack_a, 0);
		}
		else if (stack_a->data == 1 && stack_a->next->data == 0)
			sa(&stack_a, 0);
		else if (stack_a->data == 1 && stack_a->next->data == 2)
			rra(&stack_a, 0);
		else if (stack_a->data == 2 && stack_a->next->data == 0)
			ra(&stack_a, 0);
		else if (stack_a->data == 2 && stack_a->next->data == 1)
		{
			sa(&stack_a, 0);
			rra(&stack_a, 0);
		}
	}
	// printf("finaly: ");//test
	// command_check(stack_a);
}

void	u7_sort(t_stacks *stack_a, int num_len)
{
	t_stacks	*stack_b;
	int			i;
	int			j;
	
	stack_b = list_new(-1);
	i = 0;
	// printf("%d", num_len);
	while (num_len - 3 > i)
	{
		while (num_len > j)
		{
			// if (stack_a->data > 3 && stack_a->data != -1 &&
			// 	stack_a->data == num_len - (1 + i))
			if(stack_a->data == num_len - (1 + i))
				pb(&stack_a, &stack_b);	
			else
				ra(&stack_a, 0);
			j++;
		}
		j = 0;
		i++;
	}
	// u4_sort(stack_a, num_len);
	// while (i)
	// {
	// 	pa(&stack_a, &stack_b);
	// 	ra(&stack_a, 0);
	// 	i--;
	// }
}
