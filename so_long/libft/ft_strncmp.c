/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:30:44 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:49 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str, const char *src, size_t c)
{
	size_t			i;
	unsigned char	*cast_str;
	unsigned char	*cast_src;

	i = 0;
	cast_str = (unsigned char *)str;
	cast_src = (unsigned char *)src;
	if (!c)
		return (0);
	while (cast_str[i] == cast_src[i])
	{
		if (cast_str[i] == '\0' || (c == 1))
			return (0);
		i++;
		c--;
	}
	return (cast_str[i] - cast_src[i]);
}
/*
int	main(void)
{
	char	str1[];
	char	src1[];
	int		c1;
	char	str2[];
	char	src2[];
	int		c2;

	str1[] = "ab";
	src1[] = "abcee";
	c1 = 5;
	str2[] = "ab";
	src2[] = "abcee";
	c2 = 5;
	printf("%d\n", ft_strncmp(str1, src1, c1));
	printf("%d", strncmp(str2, src2, c2));
}
*/
