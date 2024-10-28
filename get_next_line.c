/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:45 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/10/28 23:39:16 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*set_line(char *str)
{
	int		i;
	int		j;
	char	*str_caract;

	if(!str)
		return(NULL);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str),NULL);
	str_caract = malloc(sizeof(char) * ((ft_strlen(str) - i) + 1));
	if (!str_caract)
	{
		free (str);
		return (NULL);
	}
	j = 0;
	i++;
	while (str[i])
		str_caract[j++] = str[i++];
	str_caract[j] = '\0';
	free(str);
	return (str_caract);
}

char	*take_line(char *str)
{
	int		i;
	char	*line;
	
	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		line[i] = str[i];
		++i;
	}
	if (str[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, char *str)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	while ((!ft_strchr(str, '\n')) && bytes_read != 0)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (free (str), buffer = NULL, NULL);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if(bytes_read < 0)
			return(free(buffer), free(str), NULL);
		if (bytes_read == 0)
			return(free(buffer), str);
		buffer[bytes_read] = '\0';
		str = ft_strjoin(str, buffer);
	}
	return (buffer = NULL , str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (str = NULL);
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	else if(!str[0])
		return(free(str), str = NULL, NULL);
	line = take_line(str);
	if(!line)
		return(free(str), str = NULL, NULL);
	str = set_line(str);
	return (line);
}
