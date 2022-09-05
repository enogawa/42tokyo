/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 12:06:58 by enogawa           #+#    #+#             */
/*   Updated: 2022/08/31 14:04:39 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdint.h>

int		ft_atoi(const char *str);
void	ft_bzero(void	*str, size_t s);
void	*ft_calloc(size_t n, size_t size);
int		ft_isalnum(int	c);
int		ft_isalpha(int c);
int		ft_isascii(int	c);
int		ft_isdigit(int	c);
int		ft_isprint(int	c);
char	*ft_itoa(int n);
void	*ft_memchr(const void	*str, int	c, size_t	s);
int		ft_memcmp(const void *str1, const void *str2, size_t s);
void	*ft_memcpy(void *str1, const void *str2, size_t s);
void	*ft_memmove(void	*str1, const void	*str2, size_t s);
void	*ft_memset(void	*str, int c, size_t s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int	c);
char	*ft_strdup(const char	*str);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t s);
size_t	ft_strlcpy(char *str, const char *src, size_t s);
size_t	ft_strlen(const char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *str, const char *src, size_t c);
char	*ft_strnstr(const char	*str, const char *src, size_t s);
char	*ft_strrchr(const char	*str, int	c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	ft_putendl_fd(char *s, int fd);

#endif
