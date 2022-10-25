/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:52:12 by mcouppe           #+#    #+#             */
/*   Updated: 2022/01/23 15:40:31 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

static char	*ft_read(char *text, int fd, char *line)
{
	int	to_read;

	to_read = 1;
	while (to_read > 0 && (ft_strchr_gnl(text, '\n') != 1))
	{
		to_read = read(fd, line, BUFFER_SIZE);
		if (to_read == -1)
		{
			free(text);
			free(line);
			return (NULL);
		}
		line[to_read] = '\0';
		text = ft_strjoin_gnl(text, line);
	}
	free(line);
	return (text);
}

static char	*ft_getline(char *text)
{
	int		i;
	int		j;
	int		count;
	char	*result;

	i = 0;
	j = 0;
	count = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		count = 1;
	result = malloc(sizeof(char) * i + 2);
	if (!result)
		return (NULL);
	while (j < i)
	{
		result[j] = text[j];
		j++;
	}
	if (count > 0)
		result[j] = '\n';
	result[j + count] = '\0';
	return (result);
}

static	char	*ft_save(char *text)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	if (text[i] == '\n')
		i++;
	result = malloc(sizeof(char) * (ft_strlen_gnl(text) - i) + 1);
	if (!result)
		return (NULL);
	while (text[i] != '\0')
		result[j++] = text[i++];
	result[j] = '\0';
	free(text);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*text[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	text[fd] = ft_read(text[fd], fd, line);
	if (!text[fd] || text[fd][0] == '\0')
	{
		free(text[fd]);
		text[fd] = NULL;
		return (NULL);
	}
	line = ft_getline(text[fd]);
	text[fd] = ft_save(text[fd]);
	if (!text[fd] || text[fd][0] == '\0')
	{
		free(text[fd]);
		text[fd] = NULL;
	}
	return (line);
}
