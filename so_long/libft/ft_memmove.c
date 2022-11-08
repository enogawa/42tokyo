/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:28:25 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:16 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t s)
{
	unsigned char	*cast_str1;
	unsigned char	*cast_str2;

	if (!str1 && !str2)
		return (NULL);
	cast_str1 = (unsigned char *)str1;
	cast_str2 = (unsigned char *)str2;
	if (cast_str1 < cast_str2)
		return (ft_memcpy(cast_str1, cast_str2, s));
	else
	{
		while (s > 0)
		{
			cast_str1[s - 1] = cast_str2[s - 1];
			s--;
		}
	}
	return (cast_str1);
}
/*
int	main(void)
{
	char	src1[];
	char	src2[];
	char	src3[];
	char	src4[];

	src1[] = "42tokyo";
	src2[] = "eiki";
	src3[] = "42tokyo";
	src4[] = "eiki";
	ft_memmove(src1, src2, 2);
	memmove(src3, src4, 2);
	printf("%s\n", src1);
	printf("%s", src3);
}
*/
