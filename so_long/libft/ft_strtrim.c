/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:34:51 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/12 17:14:10 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	start_count(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0') && ft_strchr(set, s1[i]) != NULL)
		i++;
	return (i);
}

static size_t	finish_count(char const *s1, char const *set)
{
	size_t	i;
	size_t	len1;

	len1 = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[len1 - 1 - i]) != NULL)
		i++;
	return (len1 - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ans;
	size_t	s_count;
	size_t	f_count;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	s_count = start_count(s1, set);
	f_count = finish_count(s1, set);
	i = 0;
	while (i < s_count)
	{
		s1++;
		i++;
	}
	ans = ft_substr(s1, 0, f_count - s_count);
	return (ans);
}
/*
int	main(void)
{
	char	str1[];
	char	str2[];

	str1[] = "4234eiki42tokyo443";
	str2[] = "43244";
	printf("%s", ft_strtrim(str1, str2));
}
*/
