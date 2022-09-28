/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:20:04 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/28 21:23:05 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_num_into_stacks(int		*zipped_num, int i)
{
	t_stacks	*stack_a;
	t_stacks	*new;
	int 		j;
	
	stack_a = list_new(-1);
    j = 0;
    while (j < i)
    {
        new = list_new(zipped_num[j]);
        lst_add_back(stack_a, new);
        stack_a = list_mv_back(stack_a);
        printf("stack_a[%d]; %ld\n", j, stack_a->data);//test
        j++;
    }
    stack_a = list_mv_prev(stack_a);//test
    printf("test; %ld", stack_a->data);//test
}

int		*compression(int	*num, int	*zipped_num, int	i)
{
	int j;
	int k;
	int count;
	
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
                return (0);
            }
            if(num[j] > num[k])
				count++;
            k++;
        }
		zipped_num[j] = count;
        j++;
    }
	return (zipped_num);
}

int		main(int argc, char **argv)
{
    int         *num;
    int         *zipped_num;
    int         i;
	t_stacks	*stack_a;

    i = 0;
    num = malloc(sizeof(int) * (argc - 1));
    while(argv[i + 1])
    {
        num[i] = push_swap_atoi(argv[i + 1]);
        i++;
    }
    zipped_num = malloc(sizeof(int) * (argc - 1));
	zipped_num = compression(num, zipped_num, i);
	put_num_into_stacks(zipped_num, i);
    //printf("test; %ld", stack_a->data);
	radix_sort(&stack_a);
	return (0);
}
//printf("zipped_num[%d]; %d\n", j, zipped_num[j]);