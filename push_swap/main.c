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
    printf("dup_num\n");//test_dup_num
    while(argv[i + 1])
    {
        dup[i] = ft_strdup(argv[i + 1]);
        dup_num[i] = push_swap_atoi(dup[i]);
        printf("%d,", dup_num[i]);//test_dup_num
        i++;
    }
    printf("\n\n");//test
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