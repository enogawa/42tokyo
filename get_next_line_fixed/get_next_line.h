/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enogawa <enogawa@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 15:54:03 by enogawa           #+#    #+#             */
/*   Updated: 2022/07/18 14:31:23 by enogawa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strchr(const char *str, int	c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*join_array(char const *s1, char const *s2, char *ans);
char	*ft_strdup(const char	*str);
char	*read_line(int fd, char *save);
char	*get_line(char *save);
char	*rest_str(char *save);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
#endif