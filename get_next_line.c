/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:45 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/05/21 20:26:45 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* char	 print_str(char *buffer)
{
	
	return (0);
} */
char	*ft_read(char *buffer, int fd)
{
	int		bytes_read;
	char	*tmp;

	tmp = ft_calloc(sizeof(char)* (BUFFER_SIZE +1), 1);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while(!ft_strchr(tmp, '\n') && bytes_read != 0)
	{
		if (bytes_read < 0)
		{
			free(buffer);
			free(tmp);
			return (NULL);
		}
		tmp[bytes_read + 1] = '\0';
		buffer = ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*buffer;

	line = 0;
	buffer = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		return (NULL);
		free(line);
	}
	buffer = ft_read(buffer, fd);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = ft_strdup(buffer);
	buffer = ft_strdup(line);
	return (line);
}
