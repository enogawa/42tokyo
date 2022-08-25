#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



int	push_swap_atoi(const char *str);
char	*ft_strdup(const char	*str);
size_t	ft_strlen(const char *str);


typedef struct stacks{
    int date;
    struct stacks *next;
    struct stacks *prev;
}stacks;

#endif