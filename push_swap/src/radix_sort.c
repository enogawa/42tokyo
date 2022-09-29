/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:21:10 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/29 17:48:10 by enogawa          ###   ########.fr       */
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
	int			i;

	shift_num = 0;
	printf("\nbit; %zu, ", bit_len);//test
	printf("num; %zu", num_len);//test
	while (bit_len-- >= 1)
	{
		i = 0;
		while (i < num_len)
		{
			if (stack_a->data >> shift_num & 0b000000001)
			{
				//ra(&stack_a, 0);
				printf("\n%zu,", shift_num);//test
			}
			else
			{
				//pb(&stack_a, &stack_b);
				pb_count++;	
			}
			stack_a = stack_a->next;
			i++;
		}
		// while (pb_count-- > 0)
		// {
		// 	pa(&stack_a, &stack_b);
		// }
		shift_num++;
	}
}

void	radix_sort(t_stacks *stack_a, int num_len)
{
	size_t		bit_len;

	bit_len = cmp_times(num_len - 1);
	binary_num_radix_sort(stack_a, bit_len, num_len);
}

// int main()
// {
// 	int	num;

// 	num = cmp_times(10);
// 	printf("%d", num);
// 	return (0);
// }