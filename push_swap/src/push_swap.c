/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:20:04 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/13 17:43:01 by enogawa          ###   ########.fr       */
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
        printf("stack_a[%d]; %ld\n", j, stack_a->data);//testtestetstetstetstetsetetstetts
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
                exit (0);
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

    num = check_args(argc, argv);
    num_len = 0;
    while (num[num_len])
        num_len++;
    // num = malloc(sizeof(int) * (argc - 1));
    // while(argv[num_len + 1])
    // {
    //     num[num_len] = push_swap_atoi(argv[num_len + 1]);
    //     num_len++;
    // }
    zipped_num = malloc(sizeof(int) * (num_len));
    zipped_num = compression(num, zipped_num, num_len);
    stack_a = put_num_into_stacks(zipped_num, num_len);
    stack_a = list_mv_head(stack_a);
    if (already_sorted(stack_a))
       return (0);
    if (num_len <= 3)
        u4_sort(stack_a, num_len);
    else if (num_len <= 5)
        u7_sort(stack_a, num_len);
    else
	    radix_sort(stack_a, num_len);
    stack_a = list_mv_head(stack_a);
    printf("ans: ");//test
	command_check(stack_a);//test
	return (0);
}
