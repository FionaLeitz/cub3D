/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:07:15 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/06 14:55:15 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3disaster.h"
/*
	get the lenght of each lines wich can give the horizontal size but 
	here it's implemented for maps like so_long so only rectangular
	to improve with cub map, we will need to recover the value during the parsing
	exemple for a map doing something like :

	1111111111111			111111
	1000000000001			100001
	1000000000011			100001
	100000000001111111111111100001
	100000000000000000000000000001
	111111111111111111111111111111
*/
int	get_len_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i] && line[i] != '\n')
		i++;
	return (i);
}

/*
	get the nbr of lines aka the vertical size aka the y 
*/
int	get_nbr_lines(char *path)
{
	int		fd;
	int		linecount;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	linecount = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		linecount++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (linecount);
}


