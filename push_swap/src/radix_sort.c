/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:21:10 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/28 21:17:45 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

	shift_num = 0;
	while (bit_len-- > 0)
	{
		while (num_len-- > 0)
		{
			if (stack_a->data >> shift_num && 0b000000001)
				ra(&stack_a, 0);
			else
			{
				pb(&stack_a, &stack_b);
				pb_count++;	
			}
			shift_num++;
			stack_a = stack_a->next;
		}
		while (pb_count-- > 0)
		{
			pa(&stack_a, &stack_b);
		}
	}
}

void	radix_sort(t_stacks **stack_a)
{
	size_t		bit_len;
	long		num_len;
	size_t		shift_num;
	t_stacks	*tmp;

	shift_num = 0;
	tmp = list_mv_back(*stack_a);
	// bit_len = cmp_times(tmp->data);
	// num_len = tmp->data;
	// binary_num_radix_sort(stack_a, bit_len, num_len);
}

// int main()
// {
// 	int	num;

// 	num = cmp_times(10);
// 	printf("%d", num);
// 	return (0);
// }