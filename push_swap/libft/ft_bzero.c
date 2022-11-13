/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 11:27:52 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/08 19:10:24 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void	*str, size_t s)
{
	ft_memset(str, 0, s);
}
/*
int main()
{
	char	str1[] = "42tokyo";
	size_t	s1 = 2;
	char	ans;
	ans = ft_bzero(str1, s1);
	char	str2[] = "42tokyo";
	size_t	s2 = 2;
	printf("%s\n", ans));
	printf("%s", bzero(str2, s2));
}
*/
