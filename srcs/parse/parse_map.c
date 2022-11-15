/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <mcouppe@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:38:32 by fleitz            #+#    #+#             */
/*   Updated: 2022/11/15 14:55:02 by mcouppe          ###   ########.fr       */
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
	c = map[(int)file->start_pos.y][(int)file->start_pos.x];
	map[(int)file->start_pos.y][(int)file->start_pos.x] = '0';
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if ((map[y][x] == '0' || map[y][x] == c) && rec(map, y, x) == -1)
			{
				ft_printf("Error\nNot enough walls\n");
				return (0);
			}
		}
	}
	map[(int)file->start_pos.y][(int)file->start_pos.x] = c;
	return (1);
}

// get start position and check if only one
static int	start_position(char c, int line, int col, t_file *file)
{
	if (c == 'N')
		file->n += 1;
	else if (c == 'S')
		file->s += 1;
	else if (c == 'E')
		file->e += 1;
	else if (c == 'W')
		file->w += 1;
	else
		return (0);
	file->start_pos.y = line;
	file->start_pos.x = col;
	return (file->n + file->s + file->e + file->w);
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
					return (error_return("Error\nCharacters in map\n", 0));
			}
		}
	}
	if (check_walls(file->map, file) == 0)
		return (0);
	return (1);
}
