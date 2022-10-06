/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:21:55 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/04 16:20:05 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"

char	**building_map(char **map, char *line, int fd, int lines_nbr)
{
	int	i;

	i = 0;
	while (line && i < lines_nbr)
	{
		map[i] = ft_strdup(line);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}

char	**getmap(char *path)
{
	int		fd;
	char	**map;
	char	*line;
	int		lines_nbr;

	lines_nbr = get_nbr_lines(path) + 1;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	map = malloc(sizeof(char *) * lines_nbr + 1);
	if (!map)
	{
		close(fd);
		return (NULL);
	}
	line = get_next_line(fd);
	map = building_map(map, line, fd, lines_nbr);
	close(fd);
	return (map);
}
