/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 00:32:03 by enogawa           #+#    #+#             */
/*   Updated: 2022/09/01 19:24:37 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
int		ft_formats(va_list *ap, const char *format, int i);
int		ft_putnbr(int nbr);
int		ft_put_ptr(uintptr_t num);
int		ft_putstr(char *str);
int		ft_putchar(char c);
int		ft_put_unsigned(unsigned int n);
char	*ft_utoa(unsigned int n);
int		count_digit(unsigned	int num);
int		ft_put_hex(unsigned int num, const char format);
char	*ft_itoa_printf(int n);
size_t	ft_strlen_printf(const char *str);
#endif