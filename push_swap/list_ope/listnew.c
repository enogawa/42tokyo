/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:20:38 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/14 18:21:16 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stacks	*list_new(long num)
{
	t_stacks	*new;

	new = malloc(sizeof(t_stacks));
	if (!new)
		return (NULL);
	*new = (t_stacks){num, NULL, NULL};
	return (new);
}
