/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:26:41 by enogawa           #+#    #+#             */
/*   Updated: 2022/05/23 14:33:16 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
int	ft_isascii(int	c)
{
	if (0 <= c && c <= 127)
		return (1);
	return (0);
}

/*
int	main()
{
	int	x = 0;
	ft_isascii(x);
	printf("%d\n", ft_isascii(x));
}
*/
