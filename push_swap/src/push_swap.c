/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:20:04 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/26 15:47:00 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	stack_free(t_stacks	**stack, int len)
{
	t_stacks	*tmp;

	while (len)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
		len--;
	}
}

t_stacks	*put_num_into_stacks(int *zipped_num, int i)
{
	t_stacks	*stack_a;
	t_stacks	*new;
	int			j;

	stack_a = list_new(-1);
	j = 0;
	while (j < i)
	{
		new = list_new(zipped_num[j]);
		lst_add_back(stack_a, new);
		stack_a = list_mv_foot(stack_a);
		j++;
	}
	return (stack_a);
}

int	*compression(int *num, int *zipped_num, int i)
{
	int	j;
	int	k;
	int	count;

	j = 0;
	while (j < i)
	{
		count = 0;
		k = 0;
		while (k < i)
		{
			if (j != k && num[j] == num[k])
			{
				write(2, "Error\n", 6);
				free(zipped_num);
				// free (num);
				exit (0);
			}
			if (num[j] > num[k])
				count++;
			k++;
		}
		zipped_num[j++] = count;
	}
	return (zipped_num);
}

static void	sort_ope(t_stacks	*stack_a, int num_len)
{
	if (num_len <= 3)
		u4_sort(stack_a, num_len);
	else if (num_len <= 5)
		u7_sort(stack_a, num_len);
	else
		radix_sort(stack_a, num_len);
}

int	main(int argc, char	**argv)
{
	int			*num;
	int			*zipped_num;
	int			num_len;
	t_stacks	*stack_a;

	num = check_args(argc, argv);
	num_len = num[0];
	zipped_num = malloc(sizeof(int) * (num_len));
	if (!zipped_num)
		return(1);
	zipped_num = compression(&num[1], zipped_num, num_len);
	free(num);
	stack_a = put_num_into_stacks(zipped_num, num_len);
	free(zipped_num);
	stack_a = list_mv_head(stack_a);
	if (already_sorted(stack_a))
	{
		stack_free(&stack_a, num_len + 1);
		return (1);
	}
	sort_ope(stack_a, num_len);
	stack_a = list_mv_head(stack_a);
	stack_free(&stack_a, num_len + 1);
	return (0);
}
__attribute__((destructor)) static void destructor()
{
	system("leaks -q push_swap");
}
