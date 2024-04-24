/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:51 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/04/24 22:00:01 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char)c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	n;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	n = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)(malloc(n + 1));
	if (!str)
		return (0);
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

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = ft_strlen(s1) + 1;
	dst = (char *)malloc(i);
	if (dst == 0)
		return (0);
	ft_memcpy(dst, s1, i);
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;
	size_t	s_len;

	i = 0;
	if (ft_strlen(s) >= start + len)
		s_len = len;
	else if (start > ft_strlen(s))
		s_len = 0;
	else
		s_len = ft_strlen(s) - start;
	dst = (char *)malloc(s_len + 1);
	if (!dst || !s)
		return (0);
	while (i < s_len)
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
