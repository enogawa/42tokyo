/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:28:41 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:41 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *str, const char *src, size_t s)
{
	if ((ft_strlen(src) + 1) < s)
	{
		ft_memcpy(str, src, (ft_strlen(src) + 1));
	}
	else if (s != 0)
	{
		ft_memcpy(str, src, (s - 1));
		str[s - 1] = '\0';
	}
	return (ft_strlen(src));
}
/*
int	main(void)
{
	char	str1[30];
	char	src1[30];
	int		s1;
	char	str2[30];
	char	src2[30];
	int		s2;

	str1[30] = "abcde";
	src1[30] = "12345";
	s1 = 3;
	str2[30] = "abcde";
	src2[30] = "12345";
	s2 = 3;
	printf("%lu\n", ft_strlcpy(str1, src1, s1));
	printf("%s\n", str1);
	printf("%lu", strlcpy(str2, src2, s2));
}
*/
