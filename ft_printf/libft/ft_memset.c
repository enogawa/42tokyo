/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:27:35 by enogawa           #+#    #+#             */
/*   Updated: 2022/05/25 15:59:51 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void	*ft_memset(void	*str, int c, size_t s)
{
	size_t			i;
	unsigned char	*str_cast;
	unsigned char	c_cast;

	str_cast = (unsigned char *)str;
	c_cast = (unsigned char)c;
	i = 0;
	while (s > 0)
	{
		str_cast[i] = c_cast;
		i++;
		s--;
	}
	return (str);
}
/*
int	main()
{
	char str1[] = "42tokyo";
	char str2[] = "42tokyo";
	printf("%s", ft_memset(str1, 'a', 2));
	printf("%s", memset(str2, 'a', 2));
}
*/
