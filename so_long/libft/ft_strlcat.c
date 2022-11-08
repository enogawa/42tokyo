/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:28:59 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:39 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnlen(const char *str, size_t s)
{
	size_t	len;

	len = 0;
	while (s > 0 && str[len] != '\0')
	{
		len++;
		s--;
	}
	return (len);
}

size_t	ft_strlcat(char *dst, const char *src, size_t s)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strnlen(dst, s);
	if (dst_len >= s)
		return (src_len + s);
	while (src[i] != '\0' && dst_len + 1 + i < s)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
/*
int	main(void)
{
	char	dst1[20];
	char	dst2[20];
	char	src1[20];
	char	src2[20];

    dst1[20] = "abcde";
    dst2[20] = "abcde";
	src1[20] = "12345";
	src2[20] = "12345";
    printf("ft_strlcat:%zu\n", ft_strlcat(NULL, src1, 0));
    printf("strlcat:%zu\n", strlcat(NULL, src1, 0));
	printf("%s,", dst1);
	printf("%s", dst2);
}
*/