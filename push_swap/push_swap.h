/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 19:08:12 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/26 15:34:39 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include "libft/libft.h"

typedef struct s_stacks{
	long			data;
	struct s_stacks	*next;
	struct s_stacks	*prev;
}t_stacks;

int			push_swap_atoi(const char *str, int *num, char **nums);
char		*ft_strdup_push_swap(const char	*str);
size_t		ft_strlen_push_swap(const char *str);
void		list_init(int	*ziped_num);
t_stacks	*list_new(long num);
void		lst_add_back(t_stacks *stacks, t_stacks *add);
t_stacks	*list_mv_foot(t_stacks *stacks);
t_stacks	*list_mv_head(t_stacks *stacks);
int			already_sorted(t_stacks	*stack_a);
void		radix_sort(t_stacks *stack_a, int num_len);
void		pa(t_stacks **stack_a, t_stacks **stack_b);
void		pb(t_stacks **stack_a, t_stacks **stack_b);
void		rra(t_stacks **stack_a, int i);
void		rra(t_stacks **stack_b, int i);
void		rrr(t_stacks **stack_a, t_stacks **stack_b);
void		ra(t_stacks **stack_a, int i);
void		rb(t_stacks **stack_b, int i);
void		rr(t_stacks **stack_a, t_stacks **stack_b);
void		sa(t_stacks **stacks, int i);
void		sb(t_stacks **stacks, int i);
void		ss(t_stacks **stack_a, t_stacks **stack_b);
void		u4_sort(t_stacks *stack_a, int num_len);
void		u7_sort(t_stacks *stack_a, int num_len);
void		command_check(t_stacks	*stack_a);//test
void		check_push(t_stacks *a, t_stacks *b);//test
void		check_ra(t_stacks	*stack_a, int i);//test
int			*check_args(int argc, char **argv);
void		stack_free(t_stacks **stack, int len);
void		free_nums(char **nums, int flag);

#endif