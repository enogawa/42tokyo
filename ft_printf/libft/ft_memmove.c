/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:28:25 by enogawa           #+#    #+#             */
/*   Updated: 2022/06/07 13:58:37 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memmove(void	*str1, const void	*str2, size_t	s)
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
int	main()
{
	char	src1[] = "42tokyo";
	char	src2[] = "eiki";
	char	src3[] = "42tokyo";
	char	src4[] = "eiki";
	ft_memmove(src1, src2, 2);
	memmove(src3, src4, 2);
	printf("%s\n", src1);
	printf("%s", src3);
}
*/
