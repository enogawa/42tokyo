/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:29:20 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:36:01 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if ('a' <= c && c <= 'z')
	{
		c = c - ('a' - 'A');
	}
	return (c);
}
/*
int	main(void)
{
	int	s;
	int	c;

	s = '5';
	c = '5';
	s = ft_toupper(s);
	c = toupper(c);
	printf("%c\n", s);
	printf("%c", c);
}
*/