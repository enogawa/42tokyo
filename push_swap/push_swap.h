#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



int	ft_atoi(const char *str);


typedef struct stacks{
    int date;
    struct stacks *next;
    struct stacks *prev;
}stacks;

#endif