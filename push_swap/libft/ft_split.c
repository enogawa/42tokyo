/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:35:12 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/13 22:05:14 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	split_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1]))
			count++;
		i++;
	}
	return (count);
}

static size_t	array_range(char const *s, char c)
{
	size_t	i;
	size_t	range;

	i = 0;
	range = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			range++;
			if (s[i + 1] == c || s[i + 1] == '\0')
				return (range);
		}
		i++;
	}
	return (range);
}

static char	**malloc_error(char **ans, size_t x)
{
	while (x > 0)
	{
		x--;
		free(ans[x]);
	}
	free(ans);
	return (NULL);
}

static char	**cpy_array(char const *s, char **ans, char c)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (*s)
	{
		while (s[i] == c)
			i++;
		s = s + i;
		if (*s)
		{
			ans[x] = ft_substr(s, 0, array_range(s, c));
			if (!ans[x])
				return (malloc_error(ans, x));
			x++;
		}
		s = s + array_range(s, c);
		i = 0;
	}
	ans[x] = NULL;
	return (ans);
}

char	**ft_split(char const *s, char c)
{
	char	**ans;

	if (!s)
		return (NULL);
	ans = malloc((split_count(s, c) + 1) * sizeof(char *));
	if (!ans)
		return (NULL);
	return (cpy_array(s, ans, c));
}

// int main()
// {
// 	char str[] = "//eiki//42//tokyo//";
// 	char c = '/';
// 	char **ans;
// 	int i = 0;

// 	ans = ft_split(str, c);
// 	while (ans[i])
// 	{
// 		printf("%s\n", ans[i]);
// 		i++;
// 	}
// }