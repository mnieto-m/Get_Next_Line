/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:45 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/05/02 17:11:07 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(char *buffer, int fd)
{
	int		bytes_read;
	char	*tmp;
	
	tmp = 0;
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read < 0)
	{
		free(buffer);
		free(tmp);
		return (NULL);
	}
	tmp[bytes_read] = '\0';
	tmp = ft_strdup(buffer);
	free(tmp);
	return (buffer);
}
char	*get_next_line(int fd)
{
	char *line;
	char *buffer;
	int bytes_read;

	line = 0;
	buffer = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_(buffer);
	return(line);
}