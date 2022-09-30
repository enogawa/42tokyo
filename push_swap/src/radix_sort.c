/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 03:21:10 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/30 18:36:43 by enogawa          ###   ########.fr       */
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
	t_stacks	*tmp;
	int			i;

	stack_b = list_new(-1);
	tmp = stack_a;
	//check_push(stack_a, stack_b);
	//printf("\nbit; %zu, ", bit_len);//test
	printf("num; %zu", num_len);//test
	shift_num = 0;
	while (shift_num < bit_len)
	{
		i = 0;
		pb_count = 0;
		while (i++ < num_len)
		{
			if (((tmp->data) >> shift_num) & 1)
				ra(&stack_a, 0);
			else
			{
				pb(&stack_a, &stack_b);
				pb_count++;
			}
			tmp = tmp->next;
		}
		tmp = tmp->next;
		n_pa(&stack_a, &stack_b, pb_count);
		printf("\n");
		command_check(stack_a);//test
		shift_num++;
	}
	printf("ans: ");//test
	command_check(stack_a);//test
}

void command_check(t_stacks	*stack)
{
	t_stacks	*tmp = stack;
	
	if (tmp->data == -1)
	{
		tmp = tmp->next;
	}
	for (t_stacks	*temp = stack;temp->data != -1; temp = temp->next)
		printf("%ld ", temp->data);
	printf("\n\n");
}
/* ------------------------------------------------------
while (pb_count-- > 0)
{
	//pa(&stack_a, &stack_b);
	//printf(", pa");
} 
------------------------------------------------------ */ 


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