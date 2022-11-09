/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:32:18 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:14:31 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*str, int c, size_t	s)
{
	size_t			i;
	unsigned char	*str_cast;
	unsigned char	cast_c;

	i = 0;
	cast_c = (unsigned char)c;
	str_cast = (unsigned char *)str;
	while (i < s)
	{
		if (str_cast[i] == cast_c)
			return (&str_cast[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char	src[] = "42 tokyo";
	int		c = 't';
	int		s = 0;
	char	src2[] = "42 tokyo";
	int		c2 = 't';
	int		s2 = 0;
	printf("%s\n", (char *)ft_memchr(src, c, s));
	printf("%s", (char *)memchr(src2, c2, s2));
}
*/