/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:30:26 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:53 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	cast_c;

	len = ft_strlen(str);
	cast_c = (char)c;
	if (cast_c == '\0')
		return ((char *)&str[len]);
	while (len > 0)
	{
		if (str[len - 1] == cast_c)
			return ((char *)&str[len - 1]);
		len--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	src1[];
	int		s1;
	char	src2[];
	int		s2;

	src1[] = "42tokyonogawa";
	s1 = 'e';
	src2[] = "42tokyonogawa";
	s2 = 'e';
	printf("%s\n", ft_strrchr(src1, s1));
	printf("%s", strrchr(src2, s2));
}
*/
