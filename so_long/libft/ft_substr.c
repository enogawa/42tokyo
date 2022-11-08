/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:33:54 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:57 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(&s[start]) < len)
		len = ft_strlen(&s[start]);
	ans = malloc(sizeof(char) * (len + 1));
	if (!ans)
		return (NULL);
	while (i < ft_strlen(s) && len > 0)
	{
		ans[i] = s[start + i];
		i++;
		len--;
	}
	ans[i] = '\0';
	return (ans);
}
/*
int	main(void)
{
	char	src[];
	int		c;
	size_t	s;

	src[] = "42tokyo";
	c = 2;
	s = 5;
	printf("%s\n", ft_substr(src, c, s));
}
*/
