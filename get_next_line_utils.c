/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:51 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/10/07 21:33:46 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == (char)c)
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strjoin(char  *s1, char  *s2)
{
	size_t	n;
	size_t	i;
	size_t	j;
	char	*str;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2);
	str = (malloc(sizeof(char)* (n + 1)));
	if (!str)
		return (NULL);
	while (s1[i] != '\0' && (i < n))
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0' && (i + j < n))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char *ft_strdup( char *tmp)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(tmp) + 1;
	dst = malloc(sizeof(char) *len);
	if (!dst)
		return (NULL);
	while (len > i)
	{
		dst[i] = tmp[i];
	}
	return (dst);
}
