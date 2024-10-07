/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:55:03 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/10/07 21:36:18 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <time.h>


char	*get_next_line(int fd);
char	*ft_read(char *buffer, int fd);
char	*set_line(char *rest);
char	*get_line(char *str); 



int	ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup( char *tmp);
size_t	ft_strlen(const char *s);

#endif