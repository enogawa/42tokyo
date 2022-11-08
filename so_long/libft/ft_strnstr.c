/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:32:50 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:52 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *src, size_t s)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (src[0] == '\0')
		return ((char *)str);
	while (i < s && str[i] != '\0')
	{
		k = 0;
		while (i + k < s && str[i + k] == src[k])
		{
			k++;
			if (src[k] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	*str;
	char	*src;
	size_t	s;

	str = "aaabcdaabc";
	src = "aabc";
	s = 50;
	printf("%s\n", ft_strnstr(str, NULL, 0));
	printf("%s", strnstr("aaabcdaabc", NULL, 0));
}
*/