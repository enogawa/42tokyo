/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_so_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:12:54 by enogawa           #+#    #+#             */
/*   Updated: 2022/11/12 17:19:13 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strchr_so_long(const char *str, int c)
{
	size_t	i;
	int		count;
	char	cast_c;

	i = 0;
	count = 0;
	cast_c = (char)c;
	if (cast_c == '\0')
	{
		while (str[i] != '\0')
			i++;
		return (0);
	}
	while (str[i] != '\0')
	{
		if (str[i] == cast_c)
			count++;
		i++;
	}
	return (count);
}
