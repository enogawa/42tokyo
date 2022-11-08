/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:25:53 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:34:56 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}

/*
int	main(void)
{
	char	x;

	x = '8';
	ft_isdigit(x);
	printf("%d\n", ft_isdigit(x));
	printf("%d", isdigit(x));
}
*/
