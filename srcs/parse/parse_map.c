/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleitz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:38:32 by fleitz            #+#    #+#             */
/*   Updated: 2022/10/05 10:38:35 by fleitz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

// recursive to check walls
static int	rec(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == '2')
		return (0);
	if (map[y][x] == '0')
		map[y][x] = '2';
	if (map[y + 1] == NULL || y == 0 || x == 0 || map[y][x + 1] == '\0'
		|| map[y][x] == ' ' || (int)ft_strlen(map[y + 1]) < x)
		return (-1);
	if (rec(map, y - 1, x) != 0 || rec(map, y + 1, x) != 0
		|| rec(map, y, x - 1) != 0 || rec(map, y, x + 1) != 0
		|| rec(map, y + 1, x + 1) != 0 || rec(map, y - 1, x + 1) != 0
		|| rec(map, y + 1, x - 1) != 0 || rec(map, y - 1, x - 1) != 0)
		return (-1);
	return (0);
}

// check if map is closed with walls
static int	check_walls(char **map, t_file *file)
{
	char	c;
	int		y;
	int		x;

	y = -1;
	c = map[file->start_y][file->start_x];
	map[file->start_y][file->start_x] = '0';
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if ((map[y][x] == '0' || map[y][x] == c) && rec(map, y, x) == -1)
			{
				ft_printf("Error walls\n");
				return (0);
			}
		}
	}
	map[file->start_y][file->start_x] = c;
	// int	count = -1;
	// while (map[++count])
	// 	ft_printf("%s\n", map[count]);
	return (1);
}

// get start position and check if onlx one
static int	start_position(char c, int line, int col, t_file *file)
{
	if (c == 'N')
		file->N += 1;
	else if (c == 'S')
		file->S += 1;
	else if (c == 'E')
		file->E += 1;
	else if (c == 'W')
		file->W += 1;
	file->start_y = line;
	file->start_x = col;
	return (file->N + file->S + file->E + file->W);
}

// check if characters are valids in map
int	map_characters(t_file *file)
{
	int	line;
	int	col;

	line = -1;
	while (file->map[++line])
	{
		if (file->map[line][ft_strlen(file->map[line]) - 1] == '\n')
			file->map[line][ft_strlen(file->map[line]) - 1] = '\0';
		col = -1;
		while (file->map[line][++col])
		{
			if (file->map[line][col] != ' ' && file->map[line][col] != '1'
				&& file->map[line][col] != '0')
			{
				if (start_position(file->map[line][col], line, col, file) != 1)
					return (error_return("Error in map\n", 0));
			}
		}
	}
	if (check_walls(file->map, file) == 0)
		return (0);
	return (1);
}
