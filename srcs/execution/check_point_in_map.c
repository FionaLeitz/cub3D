/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_point_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 13:05:13 by mcouppe           #+#    #+#             */
/*   Updated: 2022/11/14 13:09:15 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_point_in_map(int map_x, int map_y, char **map)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (map && map[++y])
	{
		if (y == map_y)
		{
			while (map[y][++x])
			{
				if (x == map_x && map[y][x] != '\0')
					return (1);
			}
		}
	}
	return (0);
}
