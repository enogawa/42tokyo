/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:36:53 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/26 05:34:21 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main (int argc, char **argv)
{
    int *num;
    int *dup_num;
    int i;
    int j;
    int k;
    int tmp;
    char **dup;
    t_stacks    *stack_a;
    t_stacks    *new;

    i = 0;
    num = malloc(sizeof(int) * (argc - 1));
    while(argv[i + 1])
    {
        num[i] = push_swap_atoi(argv[i + 1]);
        i++;
    }
    //////////////////////////////test_num
    i = 0;
    dup = malloc(sizeof(char **) * argc - 1);
    dup_num = malloc(sizeof(int) * (argc - 1));
    //printf("dup_num\n");//test_dup_num
    while(argv[i + 1])
    {
        dup[i] = ft_strdup(argv[i + 1]);
        dup_num[i] = push_swap_atoi(dup[i]);
        //printf("%d,", dup_num[i]);//test_dup_num
        i++;
    }
    //printf("\n\n");//test
    j = 0;
    while (j < i)
    {
        k = 0;
        while (k + 1 < i)
        {
            if (num[k] == num[k + 1])
            {
                write(2, "Error\n", 6);
                return (0);
            }
            if(num[k] > num[k + 1])
            {
                tmp = num[k];
                num[k] = num[k + 1];
                num[k + 1] = tmp;
            }
            k++;
        }
        j++;
    }
    //////////////////////////////////test_num_sort
    i = 0;
    while (i < (argc - 1))
    {
        j = 0;
        while(j < (argc - 1))
        {
            if(num[j] == dup_num[i])
            {
                dup_num[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
    //////////////////////////////test_dudp_num_zip
    stack_a = list_new(-1);
    j = 0;
    while (j < i)
    {
        //printf("%d,", i);
        new = list_new(dup_num[j]);
        //printf("new[%d]; %ld,", i, new->data);
        lst_add_back(stack_a, new);
        stack_a = list_mv_back(stack_a);
        printf("stack_a[%d]; %ld\n", j, stack_a->data);
        j++;
    }
    // while (i > 0)
    // {
    //     printf("\n%ld", stack_a->data);
    //     stack_a = stack_a->prev;
    //     i--;
    // }
    return (0);
}


//return(0) -> exit ????
    /////////////////////////////test_num
    // i = 0;
    // printf("num\n");
    // while (i < (argc - 1))
    // {
    //     printf("%d,", num[i]);
    //     i++;
    // }
    // printf("\n\n");

    //////////////////////////////////test_num_sort
    // i = 0;
    // printf("num_sorted\n");
    // while (i < (argc - 1))
    // {
    //     printf("%d,", num[i]);
    //     i++;
    // }
    // printf("\n\n");
    //////////////////////////////test_dudp_num_zip
    // i = 0;
    // printf("dudp_num_zip\n");
    // while(i < (argc - 1))
    // {
    //     printf("%d,", dup_num[i]);
    //     i++;
    // }
