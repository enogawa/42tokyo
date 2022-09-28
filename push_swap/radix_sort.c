/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:21:10 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/26 07:40:46 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	radix_sort(t_stacks *stack_a)
{
	size_t		bit_len;
	size_t		num_len;
	size_t		shift_num;
	t_stacks	*tmp;

	shift_num = 0;
	tmp = list_mv_back(stack_a);
	bit_len = cmp_times(tmp->data);
	num_len = tmp->data;
	while (bit_len > 0)
	{
		while (num_len > 0)
		{
			if (tmp->data >> shift_num && 0b000000001)
			{
				
			}
			else
			{
				
			}
			shift_num++;
			num_len--;
		}
		bit_len--;
	}
}

// int main()
// {
// 	int	num;

// 	num = cmp_times(10);
// 	printf("%d", num);
// 	return (0);
// }