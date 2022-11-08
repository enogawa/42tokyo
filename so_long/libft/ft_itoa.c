/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:35:31 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:35:03 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(long int i)
{
	size_t	count;

	count = 0;
	if (i == 0)
		count = 1;
	if (i < 0)
	{
		i *= -1;
		count += 1;
	}
	while (i >= 1)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*ans;
	size_t		digit;
	long int	n1;

	n1 = n;
	digit = count_digit(n);
	ans = (char *)malloc((digit + 1) * sizeof(char));
	if (!ans)
		return (NULL);
	ans[digit] = '\0';
	if (n == 0)
		ans[0] = '0';
	if (n < 0)
	{
		ans[0] = '-';
		n1 *= -1;
	}
	while (n1 > 0)
	{
		ans[digit - 1] = n1 % 10 + '0';
		n1 = n1 / 10;
		digit--;
	}
	return (ans);
}
/*
int	main(void)
{
	int	i;

	i = -2147483648;
	printf("%s", ft_itoa(i));
}
*/
