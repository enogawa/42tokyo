/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:32:33 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:08 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t s)
{
	size_t			i;
	unsigned char	*str_cast1;
	unsigned char	*str_cast2;

	i = 0;
	if (!s)
		return (0);
	str_cast1 = (unsigned char *)str1;
	str_cast2 = (unsigned char *)str2;
	while (str_cast1[i] == str_cast2[i])
	{
		if ((s - 1) == 0)
			return (0);
		i++;
		s--;
	}
	return (str_cast1[i] - str_cast2[i]);
}
/*
int	main(void)
{
	char	src1[];
	char	src2[];
	int		c;
	char	dest1[];
	char	dest2[];
	int		k;

	src1[] = "abcd";
	src2[] = "abcc";
	c = 4;
	dest1[] = "abcd";
	dest2[] = "abcc";
	k = 4;
	printf("%d\n", ft_memcmp(src1, src2, c));
	printf("%d", memcmp(dest1, dest2, k));
}
*/
