/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:27:00 by enogawa           #+#    #+#             */
/*   Updated: 2022/05/20 13:01:26 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_isprint(int	c)
{
	if (32 <= c && c <= 126)
		return (1);
	return (0);
}
/*
int	main()
{
	int	x = 'a';
	ft_isprint(x);
	printf("%d\n", ft_isprint(x));
}
*/
