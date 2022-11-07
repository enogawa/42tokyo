/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:50:03 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/07 15:37:32 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stacks **stacks, int i)
{
	// t_stacks	*tmp;
	t_stacks	*node;
	t_stacks	*head;

	// tmp = *stacks;
	// node = (*stacks)->prev;
	// *stacks = (*stacks)->next;
	// node->next = *stacks;
	// (*stacks)->prev = node;
	// tmp->next = node->prev;
	// node->prev->prev = tmp;
	// (*stacks)->next = tmp;
	head = list_mv_head(*stacks);
	node = head->prev;
	*stacks = head->next;
	(*stacks)->next->prev = head;
	head->next = (*stacks)->next;
	(*stacks)->next = head;
	(*stacks)->prev = node;
	node->next = *stacks;
	head->prev = *stacks;
	if (!i)
	{
		write(1, "sa\n", 4);
	}
}

void	sb(t_stacks **stacks, int i)
{
	t_stacks	*tmp;

	tmp = *stacks;
	*stacks = (*stacks)->next;
	(*stacks)->prev = NULL;
	tmp->next = (*stacks)->next;
	(*stacks)->next = tmp;
	if (!i)
	{
		write(1, "sb\n", 4);
	}
}

void	ss(t_stacks **stack_a, t_stacks **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	write(1, "ss\n", 4);
}
