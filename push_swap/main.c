#include "push_swap.h"

int main (int argc, char **argv)
{
    int *num;
    int i;
    int j;
    int k;
    int tmp;

    i = 0;
    num = malloc(sizeof(int) * (argc - 1));
    while (argv[i + 1])
    {
        num[i] = ft_atoi(argv[i + 1]);
        i++;
    }

    //test
    // k = 0;
    // while (k < i)
    // {
    //     printf("%d,", num[k]);
    //     k++;
    // }
    // printf("\n\n");
    //test

    j = 0;
    while (j < i)
    {
        k = 0;
        while (k < i)
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

    //test
    k = 0;
    while (k < i)
    {
        printf("%d,", num[k]);
        k++;
    }
    //test

    return (0);
}