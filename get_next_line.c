/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnieto-m <mnieto-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 16:54:45 by mnieto-m          #+#    #+#             */
/*   Updated: 2024/10/07 21:34:07 by mnieto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *str)
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

char	*read_line(int fd, char *rest)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!(ft_strchr(rest, '\n')) && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(rest);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		rest = ft_strjoin(rest, buffer);
	}
	free(buffer);
	return (rest);
}

char	*set_line(char *rest)
{
	int		i;
	int		k;
	char	*rest_caract;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	rest_caract = malloc(sizeof(char) * (ft_strlen(rest) - i + 1));
	if (!rest_caract)
		return (NULL);
	k = 0;
	++i;
	while (rest[i])
		rest_caract[k++] = rest[i++];
	rest_caract[k] = '\0';
	free(rest);
	return (rest_caract);
}

char	*get_next_line(int fd)

{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	str = read_line(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = set_line(str);
	return (line);
}

int  main()
{
	int fd;
	char *line;

	fd = open("hola.txt", O_RDONLY);
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}