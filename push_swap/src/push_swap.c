/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:20:04 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/30 15:15:31 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*put_num_into_stacks(int		*zipped_num, int i)
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
        stack_a = list_mv_foot(stack_a);
        printf("stack_a[%d]; %ld\n", j, stack_a->data);//test
        j++;
    }
    return (stack_a);
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
    int         num_len;
	t_stacks	*stack_a;

    num_len = 0;
    num = malloc(sizeof(int) * (argc - 1));
    while(argv[num_len + 1])
    {
        num[num_len] = push_swap_atoi(argv[num_len + 1]);
        num_len++;
    }
    zipped_num = malloc(sizeof(int) * (argc - 1));
	zipped_num = compression(num, zipped_num, num_len);
	stack_a = put_num_into_stacks(zipped_num, num_len);
    //printf("test; %ld", stack_a->data);
    stack_a = list_mv_head(stack_a);
    if (already_sorted(stack_a))
       return (0);
    // printf("aaa");
	radix_sort(stack_a, num_len);
	return (0);
}
//printf("zipped_num[%d]; %d\n", j, zipped_num[j]);