/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:51 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/10/28 23:46:38 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s || !c)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] != (unsigned char)c)
		return (0);
	return ((char *)&s[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	int		i;
	int		j;
	char	*str;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (!s2)
		return (NULL);
	str = (malloc(sizeof(char) * (l1 + l2 + 1)));
	if (!str)
		return (NULL);
	str[l1 + l2] = '\0';
	i = -1;
	while (++i < (int)l1)
		str[i] = s1[i];
	free(s1);
	j = -1;
	while (++j < (int)l2)
		str[i++] = s2[j];
	free(s2);
	return (str);
}
