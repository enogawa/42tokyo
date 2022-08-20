/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:29:20 by enogawa           #+#    #+#             */
/*   Updated: 2022/05/23 18:54:36 by enogawa          ###   ########.fr       */
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
int	main()
{
	int	s = '5';
	int	c = '5';
	s = ft_toupper(s);
	c = toupper(c);
	printf("%c\n", s);
	printf("%c", c);

}
*/