/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:31:43 by enogawa           #+#    #+#             */
/*   Updated: 2022/08/20 11:58:28 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	ft_put_hex(unsigned int num, char format)
{
	int	len;

	len = 0;
	if (num >= 16)
	{
		len += ft_put_hex(num / 16, format);
	}
	if (format == 'x')
		len += write(1, &"0123456789abcdef"[num % 16], 1);
	else if (format == 'X')
		len += write(1, &"0123456789ABCDEF"[num % 16], 1);
	return (len);
}

int	count_digit(unsigned	int num)
{
	int	count;

	count = 0;
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	return (count);
}

char	*ft_utoa(unsigned int n)
{
	char	*num;
	int		digit;

	digit = count_digit(n);
	num = (char *)malloc(sizeof(char) * (digit + 1));
	if (!num)
		return (0);
	num[digit] = '\0';
	while (n != 0)
	{
		num[digit - 1] = n % 10 + '0';
		n = n / 10;
		digit--;
	}
	return (num);
}

int	ft_put_unsigned(unsigned int n)
{
	int		len;
	char	*num;

	len = 0;
	if (n == 0)
		len += write(1, "0", 1);
	else
	{
		num = ft_utoa(n);
		len += ft_putstr(num);
		free(num);
	}
	return (len);
}
