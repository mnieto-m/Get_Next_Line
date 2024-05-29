/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:51 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/05/21 20:24:54 by mnieto-m         ###   ########.fr       */
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

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (!(!s) && s[i])
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

char	*ft_strjoin(char  *s1, char  *s2)
{
	size_t	n;
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)(ft_calloc(n + 1,1));
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

char *ft_strdup( char *tmp)
{
	char	*dst;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(tmp) + 1;
	dst = (char *)malloc(len);
	if (!dst)
	{
		free(dst);
		return (NULL);
	}
	while (len > i)
	{
		dst[i] = tmp[i];
	}
	free(tmp);
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
void	*ft_calloc(size_t count, size_t size)
{
	char	*a;
	size_t i;

	i = 0;
	if (size != 0 && count > SIZE_MAX / size)
		return (0);
	a = (char *)malloc(count * size);
	if (!a)
		return (0);
	while (i < size * count)
	{
		((char *)a)[i] = 0;
		i++;
	}
	return (a);
}