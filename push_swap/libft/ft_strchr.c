/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:30:10 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:17:33 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	cast_c;

	i = 0;
	cast_c = (char)c;
	if (cast_c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return ((char *)&str[i]);
	}
	while (str[i] != '\0')
	{
		if (str[i] == cast_c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main()
{
	char	src1[] = "42tokyo";
	int		c1 = 't';
	char	src2[] = "42tokyo";
	int		c2 = 't';
	printf("%s\n", ft_strchr(src1, c1));
	printf("%s", strchr(src2, c2));
}
*/
