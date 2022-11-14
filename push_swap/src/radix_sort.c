/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:21:10 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/14 18:30:21 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	n_pa(t_stacks **stack_a,t_stacks **stack_b, size_t pb_count)
{
	size_t	i;

	i = 0;
	while (i < pb_count)
	{
		pa(stack_a, stack_b);
		i++;
	}
}

int		cmp_times(long	biggest_num)
{
	size_t i;
	
	i = 0;
	while (biggest_num > 0)
	{
		biggest_num /= 2;
		i++;
	}
	return (i);
}

void	binary_num_radix_sort(t_stacks *stack_a, size_t bit_len, size_t num_len)
{
	size_t		shift_num;
	size_t		pb_count;
	t_stacks	*stack_b;
	size_t		i;

	stack_b = list_new(-1);
	shift_num = 0;
	while (shift_num < bit_len)
	{
		i = 0;
		pb_count = 0;
		while (i++ < num_len)
		{
			if (((stack_a->data) >> shift_num) & 1)
			{
				if (stack_a->next->data != -1)
					ra(&stack_a, 0);
			}
			else
			{
				pb(&stack_a, &stack_b);
				pb_count++;
			}
		}
		n_pa(&stack_a, &stack_b, pb_count);
		shift_num++;
	}
	stack_free(&stack_b, 1);
}

void	radix_sort(t_stacks *stack_a, int num_len)
{
	size_t		bit_len;

	bit_len = cmp_times(num_len - 1);
	binary_num_radix_sort(stack_a, bit_len, num_len);
}
