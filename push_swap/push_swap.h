/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:37:03 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/25 19:43:22 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


typedef struct s_stacks{
    long data;
    struct s_stacks *next;
    struct s_stacks *prev;
}t_stacks;

int 	    push_swap_atoi(const char *str);
char    	*ft_strdup(const char	*str);
size_t  	ft_strlen(const char *str);
void    	list_init(int	*ziped_num);
t_stacks    *list_new(long	num);
void	    lst_add_back(t_stacks *stacks, t_stacks *add);
t_stacks    *list_mv_back(t_stacks *stacks);
t_stacks    *list_mv_prev(t_stacks *stacks);


#endif