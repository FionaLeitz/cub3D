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

#include "cub3d.h"


static int	recursive(char **map, char c, int x, int y)
{
	if (map[x][y] == ' ' || map[x][y] == '\0')
		return (-1);
	if (map[x][y] == '0' || map[x][y] == c)
		map[x][y] = '2';
	if (map[x + 1] != NULL && map[x + 1][y] != '1' && map[x + 1][y] != '2')
		if (recursive(map, c, x + 1, y) == -1)
			return (-1);
	if (map[x][y + 1] != '1' && map[x][y + 1] != '2')
		if (recursive(map, c, x, y + 1) == -1)
			return (-1);
	if (map[x - 1][y] != '1' && map[x - 1][y] != '2')
		if (recursive(map, c, x - 1, y) == -1)
			return (-1);
	if (map[x][y - 1] != '1' && map[x][y - 1] != '2')
		if (recursive(map, c, x, y - 1) == -1)
			return (-1);
	return (0);
}

static int	check_walls(char **map, t_file *file)
{
	char	c;
	int		x;
	int		y;

	x = file->start_x;
	y = file->start_y;
	c = map[x][y];
	if (recursive(map, c, x, y) == -1)
	{
		ft_printf("Error walls\n");
		return (0);
	}
	int	count = -1;
	while (map[++count])
		ft_printf("%s\n", map[count]);
	return (1);
}

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
	file->start_x = line;
	file->start_y = col;
	return (file->N + file->S + file->E + file->W);
}

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
				{
					ft_printf("Error in map\n");
					return (0);
				}
			}
		}
	}
	if (check_walls(file->map, file) == 0)
		return (0);
	return (1);
}
