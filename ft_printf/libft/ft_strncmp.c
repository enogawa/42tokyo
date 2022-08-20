/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:30:44 by enogawa           #+#    #+#             */
/*   Updated: 2022/06/07 14:17:21 by enogawa          ###   ########.fr       */
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
int	main()
{
	char	str1[] = "ab";
	char	src1[] = "abcee";
	int		c1 = 5;
	char	str2[] = "ab";
	char	src2[] = "abcee";
	int		c2 = 5;
	printf("%d\n", ft_strncmp(str1, src1, c1));
	printf("%d", strncmp(str2, src2, c2));
}
*/
