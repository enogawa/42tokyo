/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:59:34 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/14 18:19:37 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	lst_add_back(t_stacks *stacks, t_stacks *add)
{
	t_stacks	*node;

	if (!stacks || !add)
		return ;
	stacks->next = add;
	add->prev = stacks;
	node = list_mv_head(stacks);
	node = node->prev;
	add->next = node;
	node->prev = add;
}
