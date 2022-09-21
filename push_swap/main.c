/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:36:53 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/21 17:36:59 by enogawa          ###   ########.fr       */
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
    t_stacks    *a_list;
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
    dup_num[i] = -1;
    t_stacks    *tmp1;
    a_list = list_new(dup_num[0]);
    i = 1;
    while (dup_num[i] != -1)
    {
        new = list_new(dup_num[i]);
        printf("new[i]; %ld,", new->data);
        lst_add_back(a_list, new);
        a_list = list_mv_back(a_list);
        printf("a_list[i]; %ld\n", a_list->data);
        i++;
    }
    while (i > 0)
    {
        printf("%ld,", a_list->data);
        a_list = list_mv_prev(a_list);
        i--;
    }
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