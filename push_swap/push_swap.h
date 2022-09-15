#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>



int	push_swap_atoi(const char *str);
char	*ft_strdup(const char	*str);
size_t	ft_strlen(const char *str);


typedef struct s_stacks{
    long data;
    struct s_stacks *next;
    struct s_stacks *prev;
}t_stacks;

#endif