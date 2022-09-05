/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:28:10 by enogawa           #+#    #+#             */
/*   Updated: 2022/06/07 13:59:24 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memcpy(void *str1, const void *str2, size_t s)
{
	size_t			i;
	unsigned char	*cast_str1;
	unsigned char	*cast_str2;

	if (!str1 && !str2)
		return (NULL);
	cast_str1 = (unsigned char *)str1;
	cast_str2 = (unsigned char *)str2;
	i = 0;
	while (s > 0)
	{
		cast_str1[i] = cast_str2[i];
		i++;
		s--;
	}
	return (cast_str1);
}
/*
int	main()
{
	char	str[] = "12345678";
	//char	src[] = "abcdefgh";
	char	str1[] = "12345678";
	char	str2[] = "12345678";
	printf("%s\n", ft_memcpy(str+2, str, 3));
	printf("%s\n", memcpy(str1+2, str1, 3));

	printf("%s", memmove(str2+2, str2, 3));
}
*/
