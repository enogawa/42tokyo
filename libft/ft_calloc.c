/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:33:22 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:10:29 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ans;

	if (n == 0 || size == 0)
	{
		n = 1;
		size = 1;
	}
	if (SIZE_MAX / n < size)
		return (NULL);
	ans = malloc(n * size);
	if (!ans)
		return (NULL);
	ft_bzero(ans, n * size);
	return (ans);
}
/*
int main()
{
	size_t	n1;
	size_t size1;
	n1 = 5;
	size1 = 5;
	size_t	n2;
	size_t size2;
	n2 = 5;
	size2 = 5;
	printf("%zu\n", ft_strlen(ft_calloc(n1, size1)));
	printf("%zu", ft_strlen(calloc(n2, size2)));
}
*/
