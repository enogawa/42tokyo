#include "ft_printf.h"

size_t	count_num_digit(long int i)
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

char	*ft_itoa_printf(int n)
{
	char		*ans;
	size_t		digit;
	long int	n1;

	n1 = n;
	digit = count_num_digit(n);
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

size_t	ft_strlen_printf(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
