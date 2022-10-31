/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcouppe <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:01:14 by mcouppe           #+#    #+#             */
/*   Updated: 2022/10/31 11:12:05 by mcouppe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_pos(double coord_x, double coord_y, char **map)
{
	int	map_x;
	int	map_y;
	int	i;
	int	j;

	i = -1;
	coord_x = round(coord_x);
	map_x = (int) coord_x;
	coord_y = round(coord_y);
	map_y = (int) coord_y;
	while (map && map[++i] && i <= map_y)
	{
		j = -1;
		while (map[i][++j] && j <= map_x)
		{
			if (i == map_y && j == map_x)
			{
				if (map[i][j] == '1')
					return (1);
				else
					return (0);
			}
		}
	}
	return (-1);
}
