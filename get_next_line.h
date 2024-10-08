/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:55:03 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/10/10 16:52:50 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*take_line(char *str);
char	*set_line(char *str);

char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *s);

#endif