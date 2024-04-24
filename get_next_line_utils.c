/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:51 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/04/22 23:28:31 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
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
	char	*str;

	if (!s1 || !s2)
		return (0);
	n = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)(malloc(n + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, (char *)s1, n + 1);
	ft_strlcat(str, s2, n + 1);
	return (str);
}
